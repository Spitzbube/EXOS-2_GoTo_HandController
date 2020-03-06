
void ssp_init(void)
{
	unsigned char i, dummy;

	//SSP Control Register 0: SCR = 35, CPOL = 1, CPHA = 1, FRF = SPI, DSS = 8bit
	SSPCR0 = (35 << 8) | (1 << 7) | (1 << 6) | (0 << 4) | (7 << 0);

	//SSP Control Register 1: MST, SSP Enable
	SSPCR1 |= (1 << 1);

	//SSP Clock Prescale Register
	SSPCPSR = 0x2;

	//Clear the Rx Fifo
	for (i = 0; i < 8; i++)
	{
		dummy = SSPDR;
	}

#if 0 // Not needed since P0.20 is already configured as SSEL1
	IO0DIR |= (1 << 20);
	IO0CLR = (1 << 20);
#endif
}

unsigned char ssp_write_byte(unsigned char b)
{	
	while ( !(SSPSR & (1 << 1)/*TNF*/) );
	SSPDR = b;
	while (!(SSPSR & (1 << 2)/*RNE*/));
	b = SSPDR;

	return b;
}

int sspHardwareCardPresent (void)
{
	#if 0
  return (GPIO1_FIOPIN & GPIO_IO_P25) ? 0 : 1;
	#else
	return 1;
	#endif
}

int sspHardwareWriteProtected (void)
{
  if (!sspHardwareCardPresent ())
    return 1;

	#if 0
  return (GPIO1_FIOPIN & GPIO_IO_P24) ? 1 : 0;
	#else
	return 0;
	#endif
}

