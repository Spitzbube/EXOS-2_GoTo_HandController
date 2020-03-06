//
//  $Id: mmc.h 42 2008-10-04 18:40:36Z jcw $
//  $Revision: 42 $
//  $Author: jcw $
//  $Date: 2008-10-04 14:40:36 -0400 (Sat, 04 Oct 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/mmc/mmc.h $
//

/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : mmc.h
 *    Description : define MMC module
 *
 *    History :
 *    1. Data        : July 1, 2005
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *    $Revision: 42 $
**************************************************************************/

#define MMC_OK              0x00
#define MMC_IDLE_STATE      0x01
#define MMC_ERASE_RST       0x02
#define MMC_ILLEGAL_CMD     0x04
#define MMC_CRC_ERROR       0x08
#define MMC_ERASE_ERROR     0x10
#define MMC_ADD_ERROR       0x20
#define MMC_PARAM_ERROR     0x40

#define MMC_DATA_TOKEN      0xfe
#define MMC_DATA_ERR_TOKEN  0x1f
#define MMC_STOP_TRAN       0xfd

typedef enum
{
  MmcOk = 0, 
  MmcNoPresent, 
  MmcNoResponse, 
  MmcCardError, 
  MmcDataError,
  MmcUknowError, 
  MmmcParameterError, 
  MmcMiscompare
} 
mmcState_t;

typedef enum
{
  CMD0 = 0, // Resets the MultiMediaCard
  CMD1,     // Activates the card initialization process
  CMD9,     // Asks the selected card to send its card-specific data (CSD)
  CMD10,    // Asks the selected card to send its card identification (CID)
  CMD12,    // Stop transmission on multiple block read
  CMD13,    // Asks the selected card to send its status register
  CMD16,    // Selects a block length (in bytes) for all following block commands (read and write)
  CMD17,    // Reads a block of the size selected by the SET_BLOCKLEN command
  CMD18,    // Continuously transfers data blocks from card to host until interrupted by a Stop command or the requested number of data blocks transmitted
  CMD24,    // Writes a block of the size selected by the SET_BLOCKLEN command
  CMD25,    // Continuously writes blocks of data until a "Stop Tran" token or the requested number of blocks received
  CMD27,    // Programming of the programmable bits of the CSD
  CMD28,    // If the card has write protection features, this command sets the write protection bit of the addressed group. The properties of write protection are coded in the card specific data (WP_GRP_SIZE).
  CMD29,    // If the card has write protection features, this command clears the write protection bit of the addressed group
  CMD30,    // If the card has write protection features, this command asks the card to send the status of the write protection bits
  CMD32,    // Sets the address of the first sector of the erase group
  CMD33,    // Sets the address of the last sector in a continuous range within the selected erase group, or the address of a single sector to be selected for erase
  CMD34,    // Removes one previously selected sector from the erase selection
  CMD35,    // Sets the address of the first erase group within a range to be selected for erase
  CMD36,    // Sets the address of the last erase group within a continuous range to be selected for erase
  CMD37,    // Removes one previously selected erase group from the erase selection.
  CMD38,    // Erases all previously selected sectors
  CMD42,    // Used to set/reset the password or lock/unlock the card. The size of the Data Block is defined by the SET_BLOCK_LEN command
  CMD55,    // Notifies the card that the next command is an application specific command rather than a standard command.
  CMD56,    // Used either to transfer a Data Block to the card or to get a Data Block from the card for general purpose/application specific commands. The size of the Data Block is defined with SET_BLOCK_LEN command
  CMD58,    // Reads the OCR register of a card
  CMD59,    // Turns the CRC option on or off. A ?1? in the CRC option bit will turn the option on, a ?0? will turn it off
  ACMD41,   // Activates the card?s initialization process (Only for SD)
  CMD_END   // End of commands index
} 
mmcSpiCmdInd_t;

typedef enum
{
  MmcNoArg = 0,
  MmcBlockLen,
  MmcDataAdd, 
  MmcDummyWord
} 
mmcAgmType_t;

typedef enum
{
  MmcR1 = 0,
  MmcR1b,
  MmcR2,
  MmcR3
} 
mmcRespType_t;

typedef struct
{
  unsigned char txData;
  mmcAgmType_t  arg;
  mmcRespType_t resp;
} 
mmcCommands_t;

typedef enum
{
  DISKTYPE_MMC = 0, 
  DISKTYPE_SD, 
  DISKTYPE_UNKNOWN,
} 
diskType_e;

typedef struct
{
  unsigned int  blockNumber;
  unsigned int  blockSize;
  diskType_e diskType;
  int writeProtect;
} 
mmcDiskStatus_t;

typedef struct csd_11_s
{
  unsigned int not_used_1          : 2;   // 0..1  [121:120]   0x44
  unsigned int mmc_prot            : 4;   // 2..5  [125:122]
  unsigned int csd_structure       : 2;   // 6..7  [127:126]

  unsigned int taac_exp            : 3;   // 0..2  [114:112]   0x26
  unsigned int taac_value          : 4;   // 3..6  [118:115]
  unsigned int taac_rsvd           : 1;   // 7..7  [119:119]

  unsigned int nsac                : 8;   // 0..7  [111:104]   0x00

  unsigned int tran_speed_exp      : 3;   // 0..2  [98:96]     0x2a
  unsigned int tran_speed_value    : 4;   // 3..6  [102:99]
  unsigned int tran_speed_rsvd     : 1;   // 7..7  [103:103]

  unsigned int ccc_hi              : 8;   // 0..7  [95:88]     0x1f

  unsigned int read_bl_len         : 4;   // 0..3  [83:80]     0xf9
  unsigned int ccc_lo              : 4;   // 4..7  [87:84]

  unsigned int c_size_hi           : 2;   // 0..1  [73:72]     0x83
  unsigned int not_used_2          : 2;   // 2..3  [75:74]
  unsigned int dsr_imp             : 1;   // 4..4  [76:76]
  unsigned int read_blk_misalign   : 1;   // 5..5  [77:77]
  unsigned int write_blk_misalign  : 1;   // 6..6  [78:78]
  unsigned int read_bl_partial     : 1;   // 7..7  [79:79]

  unsigned int c_size_mid          : 8;   // 0..7  [71:64]     0xd3

  unsigned int vdd_r_curr_max      : 3;   // 0..1  [58:56]     0xe3
  unsigned int vdd_r_curr_min      : 3;   // 2..5  [61:59]
  unsigned int c_size_lo           : 2;   // 6..7  [63:62]

  unsigned int c_size_mult_hi      : 2;   // 0..1  [49:48]     0x91
  unsigned int vdd_w_curr_max      : 3;   // 2..4  [52:50]
  unsigned int vdd_w_curr_min      : 3;   // 4..7  [55:53]

  unsigned int erase_grp_size_lo   : 2;   // 0..1  [41:40]     0x83
  unsigned int erase_grp_mult      : 5;   // 2..6  [46:42]
  unsigned int c_size_mult_lo      : 1;   // 7..7  [47:47]

  unsigned int wp_grp_size         : 5;   // 0..4  [36:32]     0xff
  unsigned int erase_grp_size_hi   : 3;   // 5..7  [39:37]

  unsigned int write_bl_len_hi     : 2;   // 0..1  [25:24]     0x92
  unsigned int r2w_factor          : 3;   // 2..4  [28:26]
  unsigned int default_ecc         : 2;   // 5..6  [30:29]

  unsigned int wp_grp_enable       : 1;   // 7..7  [31:31]     
  unsigned int not_used_3          : 5;   // 0..4  [20:16]     0x40

  unsigned int write_bl_partial    : 1;   // 5..5  [21:21]
  unsigned int write_bl_len_lo     : 2;   // 6..7  [23:22]

  unsigned int ecc                 : 2;   // 0..1  [9:8]       0x40
  unsigned int not_used_5          : 2;   // 2..3  [11:10]
  unsigned int tmp_write_protect   : 1;   // 4..4  [12:12]
  unsigned int perm_write_protect  : 1;   // 5..5  [13:13]
  unsigned int copy                : 1;   // 6..6  [14:14]
  unsigned int not_used_4          : 1;   // 7..7  [15:15]

  unsigned int notused_6           : 1;   // 0..0  [0:0]       0x67
  unsigned int crc                 : 7;   // 1..7  [7:1]
}
__attribute__ ((packed)) csd_11_t;
