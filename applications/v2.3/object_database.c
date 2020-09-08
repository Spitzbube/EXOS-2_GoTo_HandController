
/* 34e4 - todo */
int flash_get_famous_star_data(int a, Struct_FamousStarData* b)
{
	unsigned char buf[51];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;
	
	if ((a == 0) && (a > 33))
	{
		return 0;
	}
	
	r6 = (a - 1) / 10;
	r7 = ((a - 1) % 10) * 51;

	flash_read((unsigned short)(0x00 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 10; i++)
	{
		b->bData_0[i] = buf[i];
	}
	b->bData_0[10] = 0;
	b->bData_0[11] = 0;

	for (i = 10; i < 20; i++)
	{
		b->bData_12[i-10] = buf[i];
	}
	b->bData_12[10] = 0;
	b->bData_12[11] = 0;
	
	b->Data_24 = buf[20] * 10000 + buf[21] * 100 + buf[22];

	for (i = 23; i < 35; i++)
	{
		b->bData_28[i-22] = buf[i];
	}
	b->bData_28[0] = ' ';
	b->bData_28[13] = 0;

	for (i = 35; i < 43; i++)
	{
		b->bData_42[i-35] = buf[i];
	}
	b->bData_42[8] = 0;
	b->bData_42[9] = 0;
	
	if (buf[43] >= 0x80)
	{
		b->fData_52 = 0x80 - buf[43] - buf[44] / 10.0;
	}
	else
	{
		b->fData_52 = buf[43] + buf[44] / 10.0;
	}
	
	b->fRightAscension = buf[45] + buf[46] / 60.0 + buf[47] / 3600.00;
	
	if (buf[48] >= 0x80)
	{
		b->fDeclination = 0x80 - buf[48] - buf[49] / 60.0 - buf[50] / 3600.0;
	}
	else
	{
		b->fDeclination = buf[48] + buf[49] / 60.0 + buf[50] / 3600.0;
	}
	
	return 1;
}

/* 38dc - todo */
int flash_get_constellation_data(int a, Struct_ConstellationData* b)
{
	unsigned char buf[38];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;

	if ((a == 0) && (a > 33))
	{
		return 0;
	}
	
	r6 = (a - 1) / 13;
	r7 = ((a - 1) % 13) * 38;

	flash_read((unsigned short)(0x04 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 3; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[3] = ' ';
	b->bData_0[4] = 0;

	for (i = 3; i < 22; i++)
	{
		b->bData_5[i-3] = buf[i];
	}
	
	b->bData_5[19] = ' ';
	b->bData_5[20] = 0;
	
	for (i = 22; i < 30; i++)
	{
		b->bData_26[i-22] = buf[i];
	}
	
	b->bData_26[8] = 0;
	b->bData_26[9] = 0;
	
	b->fRightAscension = buf[30] + buf[31] / 60.0;
	
	if (buf[32] >= 0x80)
	{
		b->fDeclination = 0x80 - buf[32] - buf[33] / 100.0;
	}
	else
	{
		b->fDeclination = buf[32] + buf[33] / 100.0;
	}
	
	b->wArea = buf[34] * 100 + buf[35];
	
	b->bData_46 = buf[36];
	b->bQuantity = buf[37];
	
	return 1;
}

/* 3b58 - todo */
int flash_get_messier_data(int a, Struct_MessierData* b)
{
	unsigned char buf[124];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;

	if ((a == 0) && (a > 110))
	{
		return 0;
	}
	
	r6 = (a - 1) / 4;
	r7 = ((a - 1) % 4) * 124;
	
	flash_read((unsigned short)(0x0b + r6), r7, sizeof(buf), buf);

	b->wData_0 = buf[0] * 100 + buf[1];
	b->fRightAscension = buf[2] + buf[3] / 60.0 + buf[4] / 3600.0;
	
	if (buf[5] >= 0x80)
	{
		b->fDeclination = 0x80 - buf[5] - buf[6] / 60.0 - buf[7] / 3600.0; 
	}
	else
	{
		b->fDeclination = buf[5] + buf[6] / 60.0 + buf[7] / 3600.0; 
	}
	
	b->fData_12 = buf[8] + buf[9] / 10.0;
	
	b->dData_16 = buf[10] * 10000.0 + buf[11] * 100.0 + buf[12] + buf[13] / 10.0;
	
	for (i = 14; i < 20; i++)
	{
		b->bData_24[i-14] = buf[i];
	}
	
	b->bData_24[6] = 0;
	b->bData_24[7] = 0;

	for (i = 20; i < 34; i++)
	{
		b->bData_32[i-20] = buf[i];
	}
	
	b->bData_32[14] = ' ';
	b->bData_32[15] = 0;

	for (i = 34; i < 44; i++)
	{
		b->bData_48[i-34] = buf[i];
	}
	
	b->bData_48[10] = 0;
	b->bData_48[11] = 0;

	for (i = 44; i < 68; i++)
	{
		b->bData_60[i-44] = buf[i];
	}
	
	b->bData_60[24] = ' ';
	b->bData_60[25] = 0;
	
	for (i = 68; i < 90; i++)
	{
		b->bData_86[i-68] = buf[i];
	}
	
	b->bData_86[22] = 0; //Bug
	b->bData_86[23] = 0; //Bug
	
	for (i = 90; i < 124; i++)
	{
		b->bData_108[i-90] = buf[i];
	}
	
	b->bData_108[34] = ' ';
	b->bData_108[35] = 0;
	
	return 1;
}

/* 4028 - todo */
int flash_get_bright_star_data(int a, Struct_BrightStarData* b)
{
	unsigned char buf[24];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;

	if ((a == 0) && (a > 167))
	{
		return 0;
	}
	
	r6 = (a - 1) / 22;
	r7 = ((a - 1) % 22) * 24;
	
	flash_read((unsigned short)(0x27 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 16; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[16] = ' ';
	b->bData_0[17] = 0;
	
	b->fRightAscension = buf[16] + buf[17] / 60.0 + buf[18] / 3600.0;
	
	if (buf[19] >= 0x80)
	{
		b->fDeclination = 0x80 - buf[19] - buf[20] / 60.0 - buf[21] / 3600.0;
	}
	else
	{
		b->fDeclination = buf[19] + buf[20] / 60.0 + buf[21] / 3600.0;
	}

	if (buf[22] >= 0x80)
	{
		b->fData_28 = 0x80 - buf[22] - buf[23] / 100.0;
	}
	else
	{
		b->fData_28 = buf[22] + buf[23] / 100.0;
	}
		
	return 1;
}

/* 435c - todo */
int flash_get_sh2_data(int a, Struct_Sh2Data* b)
{
	unsigned char buf[6];
	unsigned short r6;
	unsigned short r7;

	if ((a == 0) && (a > 313))
	{
		return 0;
	}
	
	r6 = (a - 1) / 88;
	r7 = ((a - 1) % 88) * 6;
	
	flash_read((unsigned short)(0x2f + r6), r7, sizeof(buf), buf);
	
	b->fRightAscension = buf[0] + buf[1] / 60.0 + buf[2] / 3600.0;
	
	if (buf[3] >= 0x80)
	{
		b->fDeclination = 0x80 - buf[3] - buf[4] / 60.0 - buf[5] / 3600.0;
	}
	else
	{
		b->fDeclination = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	}

	return 1;
}

/* 4594 - todo */
int flash_get_ic_data(int a, Struct_ICData* b)
{
	unsigned char buf[19];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;
	
	if ((a == 0) && (a > 5386))
	{
		return 0;
	}
	
	r6 = (a - 1) / 27;
	r7 = ((a - 1) % 27) * 19;
	
	flash_read((unsigned short)(0x33 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 3; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[3] = ' ';
	b->bData_0[4] = 0;
	
	b->fRightAscension = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	
	if (buf[6] >= 0x80)
	{
		b->fDeclination = 0x80 - buf[6] - buf[7] / 60.0 - buf[8] / 3600.0;
	}
	else
	{
		b->fDeclination = buf[6] + buf[7] / 60.0 + buf[8] / 3600.0;
	}
	
	b->fData_16 = buf[9] + buf[10] / 10.0;
	
	for (i = 11; i < 19; i++)
	{
		b->bData_20[i-11] = buf[i];
	}

	b->bData_0[8] = ' '; //bug!
	b->bData_0[9] = 0; //bug!

	return 1;
}

/* 4894 - todo */
int flash_get_ngc_data(int a, Struct_NGCData* b)
{
	unsigned char buf[19];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;
	
	if ((a == 0) && (a > 7840))
	{
		return 0;
	}
	
	r6 = (a - 1) / 27;
	r7 = ((a - 1) % 27) * 19;
	
	flash_read((unsigned short)(0xfb + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 3; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[3] = ' ';
	b->bData_0[4] = 0;
	
	b->fRightAscension = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	
	if (buf[6] >= 0x80)
	{
		b->fDeclination = 0x80 - buf[6] - buf[7] / 60.0 - buf[8] / 3600.0;
	}
	else
	{
		b->fDeclination = buf[6] + buf[7] / 60.0 + buf[8] / 3600.0;
	}
	
	b->fData_16 = buf[9] + buf[10] / 10.0;
	
	for (i = 11; i < 19; i++)
	{
		b->bData_20[i-11] = buf[i];
	}

	b->bData_0[8] = ' '; //bug!
	b->bData_0[9] = 0; //bug!

	return 1;
}

/* 4b94 - complete */
int flash_get_sao_data(unsigned int a, Struct_SAOData* b)
{
	unsigned char buf[6];
	unsigned short r6;
	unsigned short r7;

	if ((a == 0) && (a > 258997))
	{
		return 0;
	}
	
	r6 = (a - 1) / 88;
	r7 = ((a - 1) % 88) * 6;
	
	flash_read((unsigned short)(0x21e + r6), r7, sizeof(buf), buf);
	
	b->ra = buf[0] + buf[1] / 60.0 + buf[2] / 3600.0;
	
	if (buf[3] >= 0x80)
	{
		b->dec = 0x80 - buf[3] - buf[4] / 60.0 - buf[5] / 3600.0;
	}
	else
	{
		b->dec = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	}
	
	return 1;
}

