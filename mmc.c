//
//  $Id: mmc.c 96 2008-10-10 15:29:59Z jcw $
//  $Revision: 96 $
//  $Author: jcw $
//  $Date: 2008-10-10 11:29:59 -0400 (Fri, 10 Oct 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/mmc/mmc.c $
//

/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2005
 *
 *    File name   : mmc.c
 *    Description : MMC
 *
 *    History :
 *    1. Data        : July 1, 2005
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *    $Revision: 96 $
 *
 * (C) Joel Winarske, 2006,2007                                        
**************************************************************************/

#include "mmc.h"

#define MMC_RET_ERROR(Res)          do { mmcLastError = Res; return (MmcCardError); } while (0)
#define MMC_RET_DATA_ERR(Res)       do { mmcLastError = Res; return (MmcDataError); } while (0)

#define CSD_GET_TRAN_SPEED_EXP()      (mmcSdCsd [ 3] & 0x07)
#define CSD_GET_TRAN_SPEED_MANT()    ((mmcSdCsd [ 3] & 0xF8) >> 3)
#define CSD_GET_NSAC()                (mmcSdCsd [ 2])
#define CSD_GET_TAAC_EXP()            (mmcSdCsd [ 1] & 0x7)
#define CSD_GET_TAAC_MANT()          ((mmcSdCsd [ 1] & 0xF8) >> 3)
#define CSD_GET_R2W_FACTOR()         ((mmcSdCsd [12] & 0x1C) >> 2)
#define CSD_GET_READ_BL_LEN()         (mmcSdCsd [ 5] & 0x0F)
#define CSD_GET_C_SIZE()            (((mmcSdCsd [ 6] & 0x03) << 10) + (mmcSdCsd [7] << 2) + ((mmcSdCsd [8] & 0xc0) >> 6))
#define CSD_GET_C_SIZE_MULT()       (((mmcSdCsd [ 9] & 0x03) << 1) + ((mmcSdCsd [10] & 0x80) >> 7))
#define CSD_GET_PERM_WRITE_PROTECT() ((mmcSdCsd [14] & 0x20) >> 5)
#define CSD_GET_TMP_WRITE_PROTECT()  ((mmcSdCsd [14] & 0x10) >> 4)

static const mmcCommands_t mmcCmd [CMD_END] =
{
  { 0x40, MmcNoArg,     MmcR1 }, // CMD0
  { 0x41, MmcNoArg,     MmcR1 }, // CMD1
  { 0x49, MmcNoArg,     MmcR1 }, // CMD9
  { 0x4A, MmcNoArg,     MmcR1 }, // CMD10
  { 0x4C, MmcNoArg,     MmcR1 }, // CMD12
  { 0x4D, MmcNoArg,     MmcR2 }, // CMD13
  { 0x50, MmcBlockLen,  MmcR1 }, // CMD16
  { 0x51, MmcDataAdd,   MmcR1 }, // CMD17
  { 0x52, MmcDataAdd,   MmcR1 }, // CMD18
  { 0x58, MmcDataAdd,   MmcR1 }, // CMD24
  { 0x59, MmcDataAdd,   MmcR1 }, // CMD25
  { 0x5B, MmcNoArg,     MmcR1 }, // CMD27
  { 0x5C, MmcDataAdd,   MmcR1b}, // CMD28
  { 0x5D, MmcDataAdd,   MmcR1b}, // CMD29
  { 0x5E, MmcDataAdd,   MmcR1 }, // CMD30
  { 0x60, MmcDataAdd,   MmcR1 }, // CMD32
  { 0x61, MmcDataAdd,   MmcR1 }, // CMD33
  { 0x62, MmcDataAdd,   MmcR1 }, // CMD34
  { 0x63, MmcDataAdd,   MmcR1 }, // CMD35
  { 0x64, MmcDataAdd,   MmcR1 }, // CMD36
  { 0x65, MmcDataAdd,   MmcR1 }, // CMD37
  { 0x66, MmcDummyWord, MmcR1b}, // CMD38
  { 0x6A, MmcDummyWord, MmcR1b}, // CMD42
  { 0x77, MmcNoArg,     MmcR1 }, // CMD55
  { 0x78, MmcNoArg,     MmcR1 }, // CMD56
  { 0x7A, MmcNoArg,     MmcR3 }, // CMD58
  { 0x7B, MmcDummyWord, MmcR1 }, // CMD59
  { 0x69, MmcNoArg,     MmcR1 } // ACMD41
};

static mmcDiskStatus_t mmcDiskStatus;
static unsigned int mmcLastError; 
static unsigned int Twr;
static unsigned char mmcSdCsd [16];

static const unsigned int tran_exp [] = 
{
  10000,    100000,   1000000,  10000000,
  0,        0,        0,        0
};

static const unsigned char tran_mant [] = 
{
  0,  10, 12, 13, 15, 20, 25, 30,
  35, 40, 45, 50, 55, 60, 70, 80,
};

static const unsigned int taac_exp [] = 
{
  1,  10, 100,  1000, 10000,  100000, 1000000, 10000000,
};

static const unsigned int taac_mant [] = 
{
  0,  10, 12, 13, 15, 20, 25, 30,
  35, 40, 45, 50, 55, 60, 70, 80,
};

static const unsigned int vdd_values [] =
{
  500, 1000, 5000, 10000, 25000, 35000, 60000, 100000
};


static unsigned int mmcSendCmd (mmcSpiCmdInd_t commandIndex, unsigned int arg)
{
  unsigned int ch = 0xff;
  unsigned int i;

  //
  //  Send command code
  //
  ssp_write_byte(mmcCmd [commandIndex].txData);

  //
  //  Send command's arguments
  //
  if (mmcCmd [commandIndex].arg == MmcNoArg)
  {
    ssp_write_byte(0x00);
    ssp_write_byte(0x00);
    ssp_write_byte(0x00);
    ssp_write_byte(0x00);
  }
  else
  {
    ssp_write_byte(arg >> 24);
    ssp_write_byte(arg >> 16);
    ssp_write_byte(arg >> 8);
    ssp_write_byte(arg);
  }

  //
  //  Send CRC
  //
  if (commandIndex == CMD0)
    ssp_write_byte(0x95);
  else
    ssp_write_byte(0xff);

  for (i = 9; i && (ch == 0xff); --i) 
    ch = ssp_write_byte(0xff);

  if (i == 0)
  {
    return ((unsigned int) -1);
  }

  switch (mmcCmd [commandIndex].resp)
  {
    case MmcR1b :
      {
        unsigned int busy;

        for (busy = 0, i = Twr; i && (busy != 0xff); --i)
          busy = ssp_write_byte(0xff);
      }
      return (ch);

    case MmcR1 :
      return (ch);

    case MmcR2 :
      arg  = ((unsigned int) ch << 8) & 0x0000ff00;
      arg |= ssp_write_byte(0xff) & 0xff;
      return (arg);

    case MmcR3 :
    default:
      arg  = ((unsigned int) ch << 24) & 0xff000000;
      arg |= ((unsigned int) ssp_write_byte(0xff) << 16) & 0x00ff0000;
      arg |= ((unsigned int) ssp_write_byte(0xff) << 8 ) & 0x0000ff00;
      arg |= ssp_write_byte(0xff) & 0xff;
      return (arg);
  }
}

static unsigned int mmcSetBlockLen (unsigned int length)
{
  unsigned int res = mmcSendCmd(CMD16, length);
  return res;
}

static void mmcCSDImplement (void)
{
	#if 0
  unsigned int frequency;

  //
  // Calculate SPI max clock
  //
  frequency = mmcTransfExp [CSD_GET_TRAN_SPEED_EXP ()] * mmcCsdMant [CSD_GET_TRAN_SPEED_MANT ()];

  if (frequency > 20000000)
    frequency = 20000000;

  frequency = sspSetClockFreq (frequency);

  if (mmcDiskStatus.diskType == DISKTYPE_MMC)
  {
    Tnac = mmmcAccessTime [CSD_GET_TAAC_EXP ()] * mmcAccessTimeMant [CSD_GET_TAAC_MANT ()];
    Tnac = frequency / Tnac;
    Tnac += 1 << (CSD_GET_NSAC () + 4);
    Tnac *= 10;
    Twr   = Tnac * CSD_GET_R2W_FACTOR ();
  }
  else
  {
    Tnac = frequency / SD_READ_TIME_OUT;
    Twr  = frequency / SD_WRITE_TIME_OUT;
  }
	#endif

  mmcDiskStatus.blockSize = 1 << CSD_GET_READ_BL_LEN ();
  mmcDiskStatus.blockNumber = (CSD_GET_C_SIZE () + 1) * (4 << CSD_GET_C_SIZE_MULT ());
  mmcDiskStatus.writeProtect = sspHardwareWriteProtected () | CSD_GET_PERM_WRITE_PROTECT () | CSD_GET_TMP_WRITE_PROTECT ();
}

mmcState_t mmcReadCardInfo (unsigned char *pData, mmcSpiCmdInd_t command)
{
	unsigned int i;
	unsigned int res;

	switch (command)
	{
		case CMD9 :
		case CMD10 :
			break;

		default:
			return (MmmcParameterError);
	}

	ssp_write_byte (0xff);

	if ((res = mmcSendCmd (command, 0)) == MMC_OK)
	{
		for (i = 8; i ; --i)
		{
			if (((res = ssp_write_byte (0xff)) | MMC_DATA_ERR_TOKEN) == MMC_DATA_ERR_TOKEN)
			{
				MMC_RET_DATA_ERR (res);
			}
			else if (res == MMC_DATA_TOKEN)
			{
				for (i = 0; i <16 ; ++i)
				{
					*pData++ = ssp_write_byte (0xff);
				}
				//
				// CRC receive
				//
				ssp_write_byte (0xff);
				ssp_write_byte (0xff);
				return (MmcOk);
			}
		}
	}

	MMC_RET_ERROR (res);
}

mmcState_t mmcInitMedia (void)
{
	unsigned int i;
	unsigned int res;
	
	//
	//  Power up cycles.  After power up at least 74 clock cycles are required 
	//  prior to starting bus communication
	//
	for (i = 0; i < 2; i++)
	{
		for (res = 10; res; --res)
		{
			ssp_write_byte(0xff);
		}

		//
		//  CMD0 (Go to IDLE) to put MMC in SPI mode
		//
		res = mmcSendCmd(CMD0, 0);
		if (res == MMC_IDLE_STATE)
		{
			break;
		}
	}

	if (res != MMC_IDLE_STATE)
	{
		return (MmcNoResponse);
	}
	
	//
	//  Determine card type as SD or MMC
	//
	mmcDiskStatus.diskType = DISKTYPE_MMC;

	for (i = 100; i; --i)
	{
		ssp_write_byte (0xff);
		res = mmcSendCmd (CMD55, 0);

		ssp_write_byte (0xff);
		res = mmcSendCmd (ACMD41, 0);

		if (res & MMC_ILLEGAL_CMD)
		{
			//
			//  MMC card may be CMD1 for MMC Init sequence will be complete within 500ms
			//
			for (i = 100; i; --i)
			{
				ssp_write_byte (0xff);
				res = mmcSendCmd (CMD1, 0);

				if (res == MMC_OK)
					break;

				delay_loop (50);
			}
			break;
		}

		if (res == MMC_OK)
		{
			mmcDiskStatus.diskType = DISKTYPE_SD;
			break;
		}

		delay_loop (50);
	}

	if (i == 0)
	{
		return (MmcNoResponse);
	}
	
	//
	//  Read CSD.  CSD must always be valid
	//
  if ((res = mmcReadCardInfo (mmcSdCsd, CMD9)) != MmcOk)
	{
		return (MmcNoResponse);
	}
	else
	{
		#if 1
	  csd_11_t *p = (csd_11_t *) mmcSdCsd;
		static char buf[100];

    snprintf(buf, sizeof(buf)-1, "\n\r");
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "sizeof (csd_11_t)     : %lu\n\r",        sizeof (csd_11_t));
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "CSD structure version : 1.%d\n\r",       p->csd_structure);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "MMC protocol version  : %d\n\r",         p->mmc_prot);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "TAAC                  : %d\n\r",         (taac_exp [p->tran_speed_exp] * taac_mant [p->tran_speed_value] + 9) / 10);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "NSAC                  : %d\n\r",         p->nsac * 100);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "TRAN_SPEED            : %d Mhz\n\r",     (tran_exp [p->tran_speed_exp] * tran_mant [p->tran_speed_value]));
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "CCC                   : 0x%03x\n\r",     (p->ccc_hi << 4) | p->ccc_lo);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "READ_BL_LEN           : %d (%d)\n\r",    p->read_bl_len, 1 << p->read_bl_len);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "READ_BL_PARTIAL       : %d\n\r",         p->read_bl_partial);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "WRITE_BL_LEN          : %d (%d)\n\r",    (p->write_bl_len_hi << 2) | p->write_bl_len_lo, 1 << ((p->write_bl_len_hi << 2) | p->write_bl_len_lo));
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "WRITE_BL_PARTIAL      : %d\n\r",         p->write_bl_partial);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "WRITE_BLK_MISALIGN    : %d\n\r",         p->write_blk_misalign);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "READ_BLK_MISALIGN     : %d\n\r",         p->read_blk_misalign);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "DSR_IMP               : %d\n\r",         p->dsr_imp);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "VDD_R_CURR_MIN        : %d (%d ua)\n\r", p->vdd_r_curr_min, vdd_values [p->vdd_r_curr_min]);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "VDD_R_CURR_MAX        : %d (%d ua)\n\r", p->vdd_r_curr_max, vdd_values [p->vdd_r_curr_max]);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "VDD_W_CURR_MIN        : %d (%d ua)\n\r", p->vdd_w_curr_min, vdd_values [p->vdd_w_curr_min]);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "VDD_W_CURR_MAX        : %d (%d ua)\n\r", p->vdd_w_curr_max, vdd_values [p->vdd_w_curr_max]);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "ERASE_GRP_SIZE        : %d\n\r",         ((p->erase_grp_size_hi << 2) | p->erase_grp_size_lo) + 1);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "ERASE_GRP_MULT        : %d\n\r",         p->erase_grp_mult + 1);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "WP_GRP_SIZE           : %d\n\r",         p->wp_grp_size + 1);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "WP_GRP_ENABLE         : %d\n\r",         p->wp_grp_enable);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "DEFAULT_ECC           : %d\n\r",         p->default_ecc);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "R2W_FACTOR            : %d (%d:1)\n\r",  p->r2w_factor, 1 << p->r2w_factor);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "COPY                  : %d\n\r",         p->copy);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "PERM_WRITE_PROTECT    : %d\n\r",         p->perm_write_protect);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "TMP_WRITE_PROTECT     : %d\n\r",         p->tmp_write_protect);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "ECC                   : %d\n\r",         p->ecc);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "C_SIZE                : %d\n\r",         (p->c_size_hi << 10) | (p->c_size_mid << 2) | p->c_size_lo);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "C_SIZE_MULT           : %d\n\r",         (p->c_size_mult_hi << 1) | p->c_size_mult_lo);
		uart0_send(buf, strlen(buf));
    snprintf(buf, sizeof(buf)-1, "MEDIA_SIZE            : %u\n\r",         (unsigned int) (((p->c_size_hi << 10) | (p->c_size_mid << 2) | p->c_size_lo) + 1) *
                                                    (unsigned int) (4 << ((p->c_size_mult_hi << 1) | p->c_size_mult_lo)) *
                                                    (unsigned int) (1 << (p->read_bl_len)));
		uart0_send(buf, strlen(buf));
		#endif
	}

	//
	//  Implement CSD data, and set block size
	//
	mmcCSDImplement();
	mmcSetBlockLen(mmcDiskStatus.blockSize);
		
	return MmcOk;
}



