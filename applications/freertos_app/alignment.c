

typedef struct
{
	double dData_0; //0
	double dData_8; //8
	double dData_16; //16
	double dData_24; //24
	double dData_32; //32 sp336;
	double dData_40; //40 sp344;
	double dData_48; //48 sp352;
	double dData_56; //56 sp360;
	double dData_64; //64 sp368;
	double dData_72; //72 sp376;
	double dData_80; //80 sp384;
	double dData_88; //88 sp392;
} Struct_b7f4_1;

/* b7f4 - todo */
void func_b7f4(Struct_b7f4_1 a/*sp336*/, Struct_b7f4* r4/*sp400*/)
{
	double sp288 = 0.0174532925200000001153544104682;
	double sp280;
	double sp272;
	double sp264;
	double sp256;
	double sp248;
	double sp240;
	double sp232;
	double sp224;
	double sp216;
	double sp208;
	double sp200;
	double sp192;
	double sp184;
	double sp176;
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	double sp80;
	double sp72;
	double sp64;
	double sp56;
	double sp48;

	sp280 = a.dData_32/*sp336*/ * sp288;
	sp272 = a.dData_40/*sp344*/ * sp288;
	sp264 = a.dData_64/*sp368*/ * sp288;
	sp256 = a.dData_72/*sp376*/ * sp288;
	sp248 = a.dData_48; //sp352;
	sp232 = a.dData_80; //sp384;
	sp240 = a.dData_56; //sp360;
	sp224 = a.dData_88; //sp392;
	sp216 = 1.0;
	sp208 = sin(sp280) * sin(sp272) / cos(sp272);
	sp200 = cos(sp280) * sin(sp272) / cos(sp272);
	sp192 = 1.0;
	sp184 = sin(sp264) * sin(sp256) / cos(sp256);
	sp176 = cos(sp264) * sin(sp256) / cos(sp256);
	sp168 = 1.0;
	sp160 = cos(sp280);
	sp152 = sin(sp280) * -1.0;
	sp144 = 1.0;
	sp136 = cos(sp264);
	sp128 = sin(sp264) * -1.0;
	sp120 = sp232 - sp248;
	sp112 = sp184 - sp208;
	sp104 = sp176 - sp200;
	sp96 = sp224 - sp240;
	sp88 = sp136 - sp160;
	sp80 = sp128 - sp152;

	sp56 = (sp120 * sp88 - sp112 * sp96) / (sp88 * sp104 - sp80 * sp112);
	sp48 = (sp120 * sp80 - sp104 * sp96) / (sp80 * sp112 - sp88 * sp104);
	sp72 = sp248 - sp208 * sp48 - sp200 * sp56;
	sp64 = sp240 - sp160 * sp48 - sp152 * sp56;

	sp56 = 0.0;
	sp48 = 0.0;
	sp72 = a.dData_80; //sp384;
	sp64 = a.dData_88; //sp392;
	r4->dData_32 = sp72;
	r4->dData_40 = sp64;
	r4->dData_24 = sp56;
	r4->dData_16 = sp48;
	r4->dData_8 = 0.0;
	r4->dData_0 = 0.0;
}

/* be8c - todo */
void func_be8c(Struct_b7f4_1 a/*sp304*/, Struct_b7f4* r4/*sp400*/)
{
	double sp288 = 0.0174532925200000001153544104682;
	double sp280;
	double sp272;
	double sp264;
	double sp256;
	double sp248;
	double sp240;
	double sp232;
	double sp224;
	double sp216;
	double sp208;
	double sp200;
	double sp192;
	double sp184;
	double sp176;
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	double sp80;
	double sp72;
	double sp64;
	double sp56;
	double sp48;

	sp280 = a.dData_0/*sp304*/ * sp288;
	sp272 = a.dData_8/*sp312*/ * sp288;
	sp264 = a.dData_32/*sp336*/ * sp288;
	sp256 = a.dData_40/*sp344*/ * sp288;
	sp248 = a.dData_16; //sp320;
	sp232 = a.dData_48; //sp352;
	sp240 = a.dData_24; //sp328;
	sp224 = a.dData_56; //sp360;
	sp216 = 1.0;
	sp208 = sin(sp280) * sin(sp272) / cos(sp272);
	sp200 = cos(sp280) * sin(sp272) / cos(sp272);
	sp192 = 1.0;
	sp184 = sin(sp264) * sin(sp256) / cos(sp256);
	sp176 = cos(sp264) * sin(sp256) / cos(sp256);
	sp168 = 1.0;
	sp160 = cos(sp280);
	sp152 = sin(sp280) * -1.0;
	sp144 = 1.0;
	sp136 = cos(sp264);
	sp128 = sin(sp264) * -1.0;
	sp120 = sp232 - sp248;
	sp112 = sp184 - sp208;
	sp104 = sp176 - sp200;
	sp96 = sp224 - sp240;
	sp88 = sp136 - sp160;
	sp80 = sp128 - sp152;

	sp56 = (sp120 * sp88 - sp112 * sp96) / (sp88 * sp104 - sp80 * sp112);
	sp48 = (sp120 * sp80 - sp104 * sp96) / (sp80 * sp112 - sp88 * sp104);
	sp72 = sp248 - sp208 * sp48 - sp200 * sp56;
	sp64 = sp240 - sp160 * sp48 - sp152 * sp56;
	sp56 = 0.0;
	sp48 = 0.0;
	sp72 = a.dData_80; //sp384;
	sp64 = a.dData_88; //sp392;
	r4->dData_32 = sp72;
	r4->dData_40 = sp64;
	r4->dData_24 = sp56;
	r4->dData_16 = sp48;
	r4->dData_8 = 0.0;
	r4->dData_0 = 0.0;
}

/* c510 - todo */
void func_c510(Struct_b7f4_1 a/*sp336*/, Struct_b7f4* ip/*sp96*/)
{
	ip->dData_32 = a.dData_16; //sp16
	ip->dData_40 = a.dData_24; //sp24;
	ip->dData_24 = 0.0;
	ip->dData_16 = 0.0;
	ip->dData_8 = 0.0;
	ip->dData_0 = 0.0;
}

/* c57c - todo */
void func_c57c(void)
{
	#if 0
	double sp136;
	double sp144;
	double sp152;
	double sp160;
	double sp168;
	double sp176;
	double sp184;
	double sp192;
	double sp200;
	double sp208;
	double sp216;
	double sp224;
	#else
	Struct_b7f4_1 sp136;
	#endif
	Struct_b7f4 sp88;

	int r4 = 0;

	if (Data_40004128.alignmentStarIndex < Data_40004128.numAlignmentStars)
	{
		Data_40004128.bData_344 = 0;
		Data_40004128.bData_345 = 0;
		Data_40004128.Data_348 = 0;

		switch (Data_40004128.alignmentStarIndex)
		{
			case 0:
				//c5d8
				Data_40004128.dObjRectascension = Data_40004128.dFirstAlignmentStarRa;
				Data_40004128.dObjDeclination = Data_40004128.dFirstAlignmentStarDec;
				break;

			case 1:
				//c60c
				Data_40004128.dObjRectascension = Data_40004128.dSecondAlignmentStarRa;
				Data_40004128.dObjDeclination = Data_40004128.dSecondAlignmentStarDec;
				break;

			case 2:
				//c640
				Data_40004128.dObjRectascension = Data_40004128.dThirdAlignmentStarRa;
				Data_40004128.dObjDeclination = Data_40004128.dThirdAlignmentStarDec;
				break;

			default:
				break;
		}
		//c678
		//c680 -> c8e8
	}
	else
	{
		//c684
		r4 = Data_40004128.numAlignmentStars;

		sp136.dData_0 /*sp136*/ = Data_40004128.dData_424;
		sp136.dData_8 /*sp144*/ = Data_40004128.dData_432;
		sp136.dData_16 /*sp152*/ = Data_40004128.dData_440;
		sp136.dData_24 /*sp160*/ = Data_40004128.dData_448;
		sp136.dData_32 /*sp168*/ = Data_40004128.dData_456;
		sp136.dData_40 /*sp176*/ = Data_40004128.dData_464;
		sp136.dData_48 /*sp184*/ = Data_40004128.dData_472;
		sp136.dData_56 /*sp192*/ = Data_40004128.dData_480;
		sp136.dData_64 /*sp200*/ = Data_40004128.dData_488;
		sp136.dData_72 /*sp208*/ = Data_40004128.dData_496;
		sp136.dData_80 /*sp216*/ = Data_40004128.dData_504;
		sp136.dData_88 /*sp224*/ = Data_40004128.dData_512;

		switch (r4)
		{
			case 1:
				//c798
				func_c510(sp136, &sp88);
				break;

			case 2:
				//c7c4
				func_be8c(sp136, &sp88);
				break;

			case 3:
				//c7f0
				func_b7f4(sp136, &sp88);
				break;

			default:
				break;
		}
		//c81c
		//c828
		Data_40004380.dData_32 = sp88.dData_32; //sp120
		Data_40004380.dData_40 = sp88.dData_40; //sp128
		Data_40004380.dData_8 = sp88.dData_8; //sp96
		Data_40004380.dData_0 = sp88.dData_0; //sp88
		Data_40004380.dData_24 = sp88.dData_24; //sp112
		Data_40004380.dData_16 = sp88.dData_16; //sp104

		Data_40004128.bAlignmentComplete = 1;

		dData_400033d8 = 0.0;
		dData_400033e0 = 0.0;
		dData_40003420 = 0.0;
		dData_40003428 = 0.0;

		bData_40003200 = 1;
		bData_40003201 = 1;
	}
}

/* c8f4 - complete */
void ProcessNextAlignmentStar(void)
{
	if ((Data_40004128.bAlignmentComplete == 0) &&
		(Data_40004128.dData_304 == 2.0) &&
		(Data_40004128.dData_312 == 2.0))
	{
		//c940
		Data_40004128.alignmentStarIndex++;

		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			//c964
			switch (Data_40004128.alignmentStarIndex)
			{
				case 1:
					//0xc988
					Data_40004128.dData_424 = 180.0 + Data_40004128.dData_112;
					Data_40004128.dData_432 = 90.0 - Data_40004128.dData_120;
					Data_40004128.dData_440 = Data_40004128.dOffsetRa;
					Data_40004128.dData_448 = -1.0 * Data_40004128.dOffsetDec;
					//->0xcb2c
					break;

				case 2:
					//0xca14
					Data_40004128.dData_456 = 180.0 + Data_40004128.dData_112;
					Data_40004128.dData_464 = 90.0 - Data_40004128.dData_120;
					Data_40004128.dData_472 = Data_40004128.dOffsetRa;
					Data_40004128.dData_480 = -1.0 * Data_40004128.dOffsetDec;
					//->0xcb2c
					break;

				case 3:
					//0xca9c
					Data_40004128.dData_488 = 180.0 + Data_40004128.dData_112;
					Data_40004128.dData_496 = 90.0 - Data_40004128.dData_120;
					Data_40004128.dData_504 = Data_40004128.dOffsetRa;
					Data_40004128.dData_512 = -1.0 * Data_40004128.dOffsetDec;
					//->0xcb2c
					break;

				default:
					//0xcb24
					break;
			}
			//->0xcdc8
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0xcb30
			switch (Data_40004128.alignmentStarIndex)
			{
				case 1:
					//0xcb54
					Data_40004128.dData_424 = 180.0 + 15.0 * Data_40004128.dData_88;
					if (Data_40004128.dData_424 > 360.0)
					{
						Data_40004128.dData_424 -= 360.0;
					}
					Data_40004128.dData_432 = Data_40004128.dObjDeclination;
					Data_40004128.dData_440 = Data_40004128.dOffsetRa;
					Data_40004128.dData_448 = -1.0 * Data_40004128.dOffsetDec;
					//->0xcdc4
					break;

				case 2:
					//0xcc20
					Data_40004128.dData_456 = 180.0 + 15.0 * Data_40004128.dData_88;
					if (Data_40004128.dData_456 > 360.0)
					{
						Data_40004128.dData_456 -= 360.0;
					}
					Data_40004128.dData_464 = Data_40004128.dObjDeclination;
					Data_40004128.dData_472 = Data_40004128.dOffsetRa;
					Data_40004128.dData_480 = -1.0 * Data_40004128.dOffsetDec;
					//->0xcdc4
					break;

				case 3:
					//0xccec
					Data_40004128.dData_488 = 180.0 + 15.0 * Data_40004128.dData_88;
					if (Data_40004128.dData_488 > 360.0)
					{
						Data_40004128.dData_488 -= 360.0;
					}
					Data_40004128.dData_496 = Data_40004128.dObjDeclination;
					Data_40004128.dData_504 = Data_40004128.dOffsetRa;
					Data_40004128.dData_512 = -1.0 * Data_40004128.dOffsetDec;
					//->0xcdc4
					break;

				default:
					//0xcdbc
					break;
			}
		}
	}
}

/* cdd0 - todo */
void func_cdd0(void)
{
	unsigned char strStarNames[28][10];
	unsigned char sp16[28][22];

	Data_40004128.numAlignmentStars = 2;
	Data_40004128.bAlignmentComplete = 0;
	Data_40004128.alignmentStarIndex = 0;

	numVisibleAlignmentStars = GetCurrentAlignStars(
		get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude),
		Data_40004128.geographicLatitude, Data_40004a68_CurrentAlignStarEquatorialCoord, strStarNames, sp16);

	#if 0
	Data_40004128.dFirstAlignmentStarRa = Data_40004a68_CurrentAlignStarEquatorialCoord[0][0];
	Data_40004128.dFirstAlignmentStarDec = Data_40004a68_CurrentAlignStarEquatorialCoord[0][1];
	Data_40004128.dSecondAlignmentStarRa = Data_40004a68_CurrentAlignStarEquatorialCoord[1][0];
	Data_40004128.dSecondAlignmentStarDec = Data_40004a68_CurrentAlignStarEquatorialCoord[1][1];
	#else
	Data_40004128.dFirstAlignmentStarRa = Data_40004a68_CurrentAlignStarEquatorialCoord[0];
	Data_40004128.dFirstAlignmentStarDec = Data_40004a68_CurrentAlignStarEquatorialCoord[1];
	Data_40004128.dSecondAlignmentStarRa = Data_40004a68_CurrentAlignStarEquatorialCoord[2];
	Data_40004128.dSecondAlignmentStarDec = Data_40004a68_CurrentAlignStarEquatorialCoord[3];
	#endif

	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;

	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;

	func_75c4();
}

/* cf8c - todo */
void StartOneStarAlignment(void)
{
	Data_40004128.numAlignmentStars = 1;
	Data_40004128.bAlignmentComplete = 0;
	Data_40004128.alignmentStarIndex = 0;

	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;

	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;

	func_75c4();
}

/* d07c - todo */
void StartTwoStarAlignment(void)
{
	Data_40004128.numAlignmentStars = 2;
	Data_40004128.bAlignmentComplete = 0;
	Data_40004128.alignmentStarIndex = 0;

	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;

	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;

	func_75c4();
}

/* d16c - todo */
void StartThreeStarAlignment(void)
{
	Data_40004128.numAlignmentStars = 3;
	Data_40004128.bAlignmentComplete = 0;
	Data_40004128.alignmentStarIndex = 0;

	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;

	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;

	func_75c4();
}

