

/* 2245c - todo */
void PrepareEightLineMenuScroll(int a, int b)
{
	switch (a)
	{
		case 11:
			//0x22498: Telescope Align
			switch (b)
			{
				case 1:
					//0x224c0
					g_pcstrMenuLine1 = strOneStarAlign;
					g_pcstrMenuLine2 = strTwoStarAlign;
					g_pcstrMenuLine3 = strThreeStarAlign;
					g_pcstrMenuLine4 = strTargetSync;
					g_pcstrMenuLine5 = strPoleAxisDev;
					g_pcstrMenuLine6 = strRaBklashCorr;
					g_pcstrMenuLine7 = strDecBklashCorr;
					g_pcstrMenuLine8 = strAlignmentSpare1;
					//->0x227ac
					break;
				
				case 2:
					//0x22548
					g_pcstrMenuLine1 = strTwoStarAlign;
					g_pcstrMenuLine2 = strThreeStarAlign;
					g_pcstrMenuLine3 = strTargetSync;
					g_pcstrMenuLine4 = strPoleAxisDev;
					g_pcstrMenuLine5 = strRaBklashCorr;
					g_pcstrMenuLine6 = strDecBklashCorr;
					g_pcstrMenuLine7 = strAlignmentSpare1;
					g_pcstrMenuLine8 = strAlignmentSpare2;
					//->0x227ac
					break;
				
				case 3:
					//0x225d0
					g_pcstrMenuLine1 = strThreeStarAlign;
					g_pcstrMenuLine2 = strTargetSync;
					g_pcstrMenuLine3 = strPoleAxisDev;
					g_pcstrMenuLine4 = strRaBklashCorr;
					g_pcstrMenuLine5 = strDecBklashCorr;
					g_pcstrMenuLine6 = strAlignmentSpare1;
					g_pcstrMenuLine7 = strAlignmentSpare2;
					g_pcstrMenuLine8 = strAlignmentSpare3;
					//->0x227ac
					break;
				
				case 4:
					//0x22658
					g_pcstrMenuLine1 = strTargetSync;
					g_pcstrMenuLine2 = strPoleAxisDev;
					g_pcstrMenuLine3 = strRaBklashCorr;
					g_pcstrMenuLine4 = strDecBklashCorr;
					g_pcstrMenuLine5 = strAlignmentSpare1;
					g_pcstrMenuLine6 = strAlignmentSpare2;
					g_pcstrMenuLine7 = strAlignmentSpare3;
					g_pcstrMenuLine8 = strAlignmentSpare4;
					//->0x227ac
					break;
				
				default:
					//227a4
					break;
			}
			//->0x23128
			break;
		
		case 12:
			//0x227b4: Navigation
			switch (b)
			{
				case 1:
					//0x227dc
					g_pcstrMenuLine1 = strSolarSystem;
					g_pcstrMenuLine2 = strConstellation;
					g_pcstrMenuLine3 = strFamousStar;
					g_pcstrMenuLine4 = g_pcstrMessierCatalogue;
					g_pcstrMenuLine5 = g_pcstrNGCCatalogue;
					g_pcstrMenuLine6 = g_pcstrICCatalogue;
					g_pcstrMenuLine7 = g_pcstrSh2Catalogue;
					g_pcstrMenuLine8 = g_pcstrBrightStarCatalogue;
					//->0x22a8c
					break;
				
				case 2:
					//0x22864
					g_pcstrMenuLine1 = strConstellation;
					g_pcstrMenuLine2 = strFamousStar;
					g_pcstrMenuLine3 = g_pcstrMessierCatalogue;
					g_pcstrMenuLine4 = g_pcstrNGCCatalogue;
					g_pcstrMenuLine5 = g_pcstrICCatalogue;
					g_pcstrMenuLine6 = g_pcstrSh2Catalogue;
					g_pcstrMenuLine7 = g_pcstrBrightStarCatalogue;
					g_pcstrMenuLine8 = g_pcstrSAOStarCatalogue;
					//->0x22a8c
					break;
				
				case 3:
					//0x228ec
					g_pcstrMenuLine1 = strFamousStar;
					g_pcstrMenuLine2 = g_pcstrMessierCatalogue;
					g_pcstrMenuLine3 = g_pcstrNGCCatalogue;
					g_pcstrMenuLine4 = g_pcstrICCatalogue;
					g_pcstrMenuLine5 = g_pcstrSh2Catalogue;
					g_pcstrMenuLine6 = g_pcstrBrightStarCatalogue;
					g_pcstrMenuLine7 = g_pcstrSAOStarCatalogue;
					g_pcstrMenuLine8 = g_pcstrCustomerObjects;
					//->0x22a8c
					break;
				
				case 4:
					//0x22974
					g_pcstrMenuLine1 = g_pcstrMessierCatalogue;
					g_pcstrMenuLine2 = g_pcstrNGCCatalogue;
					g_pcstrMenuLine3 = g_pcstrICCatalogue;
					g_pcstrMenuLine4 = g_pcstrSh2Catalogue;
					g_pcstrMenuLine5 = g_pcstrBrightStarCatalogue;
					g_pcstrMenuLine6 = g_pcstrSAOStarCatalogue;
					g_pcstrMenuLine7 = g_pcstrCustomerObjects;
					g_pcstrMenuLine8 = g_pcstrInputRAandDEC;
					//->0x22a8c
					break;
				
				case 5:
					//0x229fc
					g_pcstrMenuLine1 = g_pcstrNGCCatalogue;
					g_pcstrMenuLine2 = g_pcstrICCatalogue;
					g_pcstrMenuLine3 = g_pcstrSh2Catalogue;
					g_pcstrMenuLine4 = g_pcstrBrightStarCatalogue;
					g_pcstrMenuLine5 = g_pcstrSAOStarCatalogue;
					g_pcstrMenuLine6 = g_pcstrCustomerObjects;
					g_pcstrMenuLine7 = g_pcstrInputRAandDEC;
					g_pcstrMenuLine8 = g_pcstrCustomLandGoal;
					//->0x22a8c
					break;
				
				default:
					//0x22a84
					break;
			}
			break;
		
		case 13:
			//0x22a94: Utilities
			switch (b)
			{
				case 1:
					//0x22ab4
					g_pcstrMenuLine1 = strCurrentObjects;
					g_pcstrMenuLine2 = Data_40002f90;
					g_pcstrMenuLine3 = Data_40002f94;
					g_pcstrMenuLine4 = Data_40002f98;
					g_pcstrMenuLine5 = Data_40002f9c;
					g_pcstrMenuLine6 = Data_40002fa0;
					g_pcstrMenuLine7 = Data_40002fa4;
					g_pcstrMenuLine8 = Data_40002fa8;
					//->0x22c54
					break;
				
				case 2:
					//0x22b3c
					g_pcstrMenuLine1 = Data_40002f90;
					g_pcstrMenuLine2 = Data_40002f94;
					g_pcstrMenuLine3 = Data_40002f98;
					g_pcstrMenuLine4 = Data_40002f9c;
					g_pcstrMenuLine5 = Data_40002fa0;
					g_pcstrMenuLine6 = Data_40002fa4;
					g_pcstrMenuLine7 = Data_40002fa8;
					g_pcstrMenuLine8 = strParkposition;
					//->0x22c54
					break;
				
				case 3:
					//0x22bc4
					g_pcstrMenuLine1 = Data_40002f94;
					g_pcstrMenuLine2 = Data_40002f98;
					g_pcstrMenuLine3 = Data_40002f9c;
					g_pcstrMenuLine4 = Data_40002fa0;
					g_pcstrMenuLine5 = Data_40002fa4;
					g_pcstrMenuLine6 = Data_40002fa8;
					g_pcstrMenuLine7 = strParkposition;
					g_pcstrMenuLine8 = Data_40002fb0;
					//->0x22c54
					break;
				
				default:
					//0x22c4c
					break;				
			}
			break;
		
		case 14:
			//0x22c5c: Setup
			switch (b)
			{
#if 0
				case 1:
					//0x22c7c
					g_pcstrMenuLine1 = strTimeAndDate;
					g_pcstrMenuLine2 = g_pcstrDaylightSaving;
					g_pcstrMenuLine3 = g_pcstrEngSiteSetting;
					g_pcstrMenuLine4 = g_pcstrSkyLand;
					g_pcstrMenuLine5 = g_pcstrAzEqu;
					g_pcstrMenuLine6 = strTelescopeMount;
					g_pcstrMenuLine7 = strTrackingRate;
					g_pcstrMenuLine8 = g_pcstrLanguage;
					//->0x22e1c
					break;
				
				case 2:
					//0x22d04
					g_pcstrMenuLine1 = g_pcstrDaylightSaving;
					g_pcstrMenuLine2 = g_pcstrEngSiteSetting;
					g_pcstrMenuLine3 = g_pcstrSkyLand;
					g_pcstrMenuLine4 = g_pcstrAzEqu;
					g_pcstrMenuLine5 = strTelescopeMount;
					g_pcstrMenuLine6 = strTrackingRate;
					g_pcstrMenuLine7 = g_pcstrLanguage;
					g_pcstrMenuLine8 = strReset;
					//->0x22e1c
					break;
				
				case 3:
					//0x22d8c
					g_pcstrMenuLine1 = g_pcstrEngSiteSetting;
					g_pcstrMenuLine2 = g_pcstrSkyLand;
					g_pcstrMenuLine3 = g_pcstrAzEqu;
					g_pcstrMenuLine4 = strTelescopeMount;
					g_pcstrMenuLine5 = strTrackingRate;
					g_pcstrMenuLine6 = g_pcstrLanguage;
					g_pcstrMenuLine7 = strReset;
					g_pcstrMenuLine8 = g_pcstrSetupSpare1;
					//->0x22e1c
					break;
#else
				case 1:
					//0x22c7c
					g_pcstrMenuLine1 = strTimeAndDate;
					g_pcstrMenuLine2 = g_pcstrDaylightSaving;
					g_pcstrMenuLine3 = g_pcstrEngSiteSetting;
					g_pcstrMenuLine4 = strTelescopeMount;
					g_pcstrMenuLine5 = strTrackingRate;
					g_pcstrMenuLine6 = g_pcstrLanguage;
					g_pcstrMenuLine7 = strReset;
					g_pcstrMenuLine8 = g_pcstrSetupSpare1;
					//->0x22e1c
					break;

				case 2:
					//0x22d04
					g_pcstrMenuLine1 = g_pcstrDaylightSaving;
					g_pcstrMenuLine2 = g_pcstrEngSiteSetting;
					g_pcstrMenuLine3 = strTelescopeMount;
					g_pcstrMenuLine4 = strTrackingRate;
					g_pcstrMenuLine5 = g_pcstrLanguage;
					g_pcstrMenuLine6 = strReset;
					g_pcstrMenuLine7 = g_pcstrSetupSpare1;
					g_pcstrMenuLine8 = g_pcstrSetupSpare2;
					//->0x22e1c
					break;

				case 3:
					//0x22d8c
					g_pcstrMenuLine1 = g_pcstrEngSiteSetting;
					g_pcstrMenuLine2 = strTelescopeMount;
					g_pcstrMenuLine3 = strTrackingRate;
					g_pcstrMenuLine4 = g_pcstrLanguage;
					g_pcstrMenuLine5 = strReset;
					g_pcstrMenuLine6 = g_pcstrSetupSpare1;
					g_pcstrMenuLine7 = g_pcstrSetupSpare2;
					g_pcstrMenuLine8 = g_pcstrSetupSpare3;
					//->0x22e1c
					break;
#endif
				
				default:
					//0x22e14
					break;
			}
			break;
		
		case 22:
			//0x22e24
			switch (b)
			{
				case 1:
					//0x22e4c
					g_pcstrMenuLine1 = Data_40002fdc;
					g_pcstrMenuLine2 = Data_40002fe0;
					g_pcstrMenuLine3 = Data_40002fe4;
					g_pcstrMenuLine4 = Data_40002fe8;
					g_pcstrMenuLine5 = Data_40002fec;
					g_pcstrMenuLine6 = Data_40002ff0;
					g_pcstrMenuLine7 = Data_40002ff4;
					g_pcstrMenuLine8 = Data_40002ff8;
					//->0x23074
					break;
				
				case 2:
					//0x22ed4
					g_pcstrMenuLine1 = Data_40002fe0;
					g_pcstrMenuLine2 = Data_40002fe4;
					g_pcstrMenuLine3 = Data_40002fe8;
					g_pcstrMenuLine4 = Data_40002fec;
					g_pcstrMenuLine5 = Data_40002ff0;
					g_pcstrMenuLine6 = Data_40002ff4;
					g_pcstrMenuLine7 = Data_40002ff8;
					g_pcstrMenuLine8 = Data_40002ffc;
					//->0x23074
					break;
				
				case 3:
					//0x22f5c
					g_pcstrMenuLine1 = Data_40002fe4;
					g_pcstrMenuLine2 = Data_40002fe8;
					g_pcstrMenuLine3 = Data_40002fec;
					g_pcstrMenuLine4 = Data_40002ff0;
					g_pcstrMenuLine5 = Data_40002ff4;
					g_pcstrMenuLine6 = Data_40002ff8;
					g_pcstrMenuLine7 = Data_40002ffc;
					g_pcstrMenuLine8 = Data_40003000;
					//->0x23074
					break;
				
				case 4:
					//0x22fe4
					g_pcstrMenuLine1 = Data_40002fe8;
					g_pcstrMenuLine2 = Data_40002fec;
					g_pcstrMenuLine3 = Data_40002ff0;
					g_pcstrMenuLine4 = Data_40002ff4;
					g_pcstrMenuLine5 = Data_40002ff8;
					g_pcstrMenuLine6 = Data_40002ffc;
					g_pcstrMenuLine7 = Data_40003000;
					g_pcstrMenuLine8 = Data_40003004;
					//->0x23074
					break;
				
				default:
					//0x2306c
					break;
			}
			break;
		
		case 23:
			//0x2307c
			switch (b)
			{
				case 1:
					//23088
					g_pcstrMenuLine1 = Data_40003008;
					g_pcstrMenuLine2 = Data_4000300c;
					g_pcstrMenuLine3 = Data_40003010;
					g_pcstrMenuLine4 = Data_40003014;
					g_pcstrMenuLine5 = Data_40003018;
					g_pcstrMenuLine6 = Data_4000301c;
					g_pcstrMenuLine7 = Data_40003020;
					g_pcstrMenuLine8 = Data_40003024;
					//->0x23074
					break;
				
				default:
					//0x23110
					break;
			}
			break;
			
		default:
			break;
	}
}

/* 23130 - todo */
void AdaptDisplayLinesPerMenuLine(void)
{
	//Set Number of Menu Lines depending on Language?
	switch (bData_40003196_CurrentLanguage)
	{
		case MENU_LANGUAGE_ENGLISH: //1:
			//0x2315c
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_LANGUAGE_GERMAN: //2:
			//0x23170
			bData_40003197_DisplayLinesPerMenuLine = 2;
			break;
		
		case MENU_LANGUAGE_FRENCH: //3:
			//0x23184
			bData_40003197_DisplayLinesPerMenuLine = 2;
			break;
		
		case MENU_LANGUAGE_ITALIAN: //4:
			//0x23198
			bData_40003197_DisplayLinesPerMenuLine = 2;
			break;
		
		case MENU_LANGUAGE_SPANISH: //5:
			//0x231ac
			bData_40003197_DisplayLinesPerMenuLine = 2;
			break;
		
		default:
			//0x231c0
			break;
	}
}

/* 231d0 - todo */
void PrepareFourLineMenuScroll(int a, int b)
{
	switch (a)
	{
		case 11:
			//0x2320c
			switch (b)
			{
				case 1:
					//0x23240
					g_pcstrBigMenuLine1 = strOneStarAlign;
					g_pcstrBigMenuLine2 = strTwoStarAlign;
					g_pcstrBigMenuLine3 = strThreeStarAlign;
					g_pcstrBigMenuLine4 = strTargetSync;
					break;

				case 2:
					//0x23288
					g_pcstrBigMenuLine1 = strTwoStarAlign;
					g_pcstrBigMenuLine2 = strThreeStarAlign;
					g_pcstrBigMenuLine3 = strTargetSync;
					g_pcstrBigMenuLine4 = strPoleAxisDev;
					break;
				
				case 3:
					//0x232d0
					g_pcstrBigMenuLine1 = strThreeStarAlign;
					g_pcstrBigMenuLine2 = strTargetSync;
					g_pcstrBigMenuLine3 = strPoleAxisDev;
					g_pcstrBigMenuLine4 = strRaBklashCorr;
					break;
				
				case 4:
					//0x23318
					g_pcstrBigMenuLine1 = strTargetSync;
					g_pcstrBigMenuLine2 = strPoleAxisDev;
					g_pcstrBigMenuLine3 = strRaBklashCorr;
					g_pcstrBigMenuLine4 = strDecBklashCorr;
					break;
				
				case 5:
					//0x23360
					g_pcstrBigMenuLine1 = strPoleAxisDev;
					g_pcstrBigMenuLine2 = strRaBklashCorr;
					g_pcstrBigMenuLine3 = strDecBklashCorr;
					g_pcstrBigMenuLine4 = strAlignmentSpare1;
					break;
				
				case 6:
					//0x233a8
					g_pcstrBigMenuLine1 = strRaBklashCorr;
					g_pcstrBigMenuLine2 = strDecBklashCorr;
					g_pcstrBigMenuLine3 = strAlignmentSpare1;
					g_pcstrBigMenuLine4 = strAlignmentSpare2;
					break;
				
				case 7:
					//0x233f0
					g_pcstrBigMenuLine1 = strDecBklashCorr;
					g_pcstrBigMenuLine2 = strAlignmentSpare1;
					g_pcstrBigMenuLine3 = strAlignmentSpare2;
					g_pcstrBigMenuLine4 = strAlignmentSpare3;
					break;
				
				case 8:
					//0x23438
					g_pcstrBigMenuLine1 = strAlignmentSpare1;
					g_pcstrBigMenuLine2 = strAlignmentSpare2;
					g_pcstrBigMenuLine3 = strAlignmentSpare3;
					g_pcstrBigMenuLine4 = strAlignmentSpare4;
					break;
				
				default:
					//0x23480
					break;
			}
			break;
		
		case 12:
			//0x23490
			switch (b)
			{
				case 1:
					//0x234c8
					g_pcstrBigMenuLine1 = strSolarSystem;
					g_pcstrBigMenuLine2 = strConstellation;
					g_pcstrBigMenuLine3 = strFamousStar;
					g_pcstrBigMenuLine4 = g_pcstrMessierCatalogue;
					break;

				case 2:
					//0x23510
					g_pcstrBigMenuLine1 = strConstellation;
					g_pcstrBigMenuLine2 = strFamousStar;
					g_pcstrBigMenuLine3 = g_pcstrMessierCatalogue;
					g_pcstrBigMenuLine4 = g_pcstrNGCCatalogue;
					break;
				
				case 3:
					//0x23558
					g_pcstrBigMenuLine1 = strFamousStar;
					g_pcstrBigMenuLine2 = g_pcstrMessierCatalogue;
					g_pcstrBigMenuLine3 = g_pcstrNGCCatalogue;
					g_pcstrBigMenuLine4 = g_pcstrICCatalogue;
					break;
				
				case 4:
					//0x235a0
					g_pcstrBigMenuLine1 = g_pcstrMessierCatalogue;
					g_pcstrBigMenuLine2 = g_pcstrNGCCatalogue;
					g_pcstrBigMenuLine3 = g_pcstrICCatalogue;
					g_pcstrBigMenuLine4 = g_pcstrSh2Catalogue;
					break;
				
				case 5:
					//0x235e8
					g_pcstrBigMenuLine1 = g_pcstrNGCCatalogue;
					g_pcstrBigMenuLine2 = g_pcstrICCatalogue;
					g_pcstrBigMenuLine3 = g_pcstrSh2Catalogue;
					g_pcstrBigMenuLine4 = g_pcstrBrightStarCatalogue;
					break;
				
				case 6:
					//0x23630
					g_pcstrBigMenuLine1 = g_pcstrICCatalogue;
					g_pcstrBigMenuLine2 = g_pcstrSh2Catalogue;
					g_pcstrBigMenuLine3 = g_pcstrBrightStarCatalogue;
					g_pcstrBigMenuLine4 = g_pcstrSAOStarCatalogue;
					break;
				
				case 7:
					//0x23678
					g_pcstrBigMenuLine1 = g_pcstrSh2Catalogue;
					g_pcstrBigMenuLine2 = g_pcstrBrightStarCatalogue;
					g_pcstrBigMenuLine3 = g_pcstrSAOStarCatalogue;
					g_pcstrBigMenuLine4 = g_pcstrCustomerObjects;
					break;
				
				case 8:
					//0x237a4
					g_pcstrBigMenuLine1 = g_pcstrBrightStarCatalogue;
					g_pcstrBigMenuLine2 = g_pcstrSAOStarCatalogue;
					g_pcstrBigMenuLine3 = g_pcstrCustomerObjects;
					g_pcstrBigMenuLine4 = g_pcstrInputRAandDEC;
					break;

				case 9:
					//0x237ec
					g_pcstrBigMenuLine1 = g_pcstrSAOStarCatalogue;
					g_pcstrBigMenuLine2 = g_pcstrCustomerObjects;
					g_pcstrBigMenuLine3 = g_pcstrInputRAandDEC;
					g_pcstrBigMenuLine4 = g_pcstrCustomLandGoal;
					break;
				
				default:
					//0x23834
					break;
			}
			break;
		
		case 13:
			//0x23844
			switch (b)
			{
				case 1:
					//0x23874
					g_pcstrBigMenuLine1 = strCurrentObjects;
					g_pcstrBigMenuLine2 = Data_40002f90;
					g_pcstrBigMenuLine3 = Data_40002f94;
					g_pcstrBigMenuLine4 = Data_40002f98;
					break;

				case 2:
					//0x238bc
					g_pcstrBigMenuLine1 = Data_40002f90;
					g_pcstrBigMenuLine2 = Data_40002f94;
					g_pcstrBigMenuLine3 = Data_40002f98;
					g_pcstrBigMenuLine4 = Data_40002f9c;
					break;
				
				case 3:
					//0x23904
					g_pcstrBigMenuLine1 = Data_40002f94;
					g_pcstrBigMenuLine2 = Data_40002f98;
					g_pcstrBigMenuLine3 = Data_40002f9c;
					g_pcstrBigMenuLine4 = Data_40002fa0;
					break;
				
				case 4:
					//0x2394c
					g_pcstrBigMenuLine1 = Data_40002f98;
					g_pcstrBigMenuLine2 = Data_40002f9c;
					g_pcstrBigMenuLine3 = Data_40002fa0;
					g_pcstrBigMenuLine4 = Data_40002fa4;
					break;
				
				case 5:
					//0x23994
					g_pcstrBigMenuLine1 = Data_40002f9c;
					g_pcstrBigMenuLine2 = Data_40002fa0;
					g_pcstrBigMenuLine3 = Data_40002fa4;
					g_pcstrBigMenuLine4 = Data_40002fa8;
					break;
				
				case 6:
					//0x239dc
					g_pcstrBigMenuLine1 = Data_40002fa0;
					g_pcstrBigMenuLine2 = Data_40002fa4;
					g_pcstrBigMenuLine3 = Data_40002fa8;
					g_pcstrBigMenuLine4 = strParkposition;
					break;
				
				case 7:
					//0x23a24
					g_pcstrBigMenuLine1 = Data_40002fa4;
					g_pcstrBigMenuLine2 = Data_40002fa8;
					g_pcstrBigMenuLine3 = strParkposition;
					g_pcstrBigMenuLine4 = Data_40002fb0;
					break;
				
				default:
					//0x23a6c
					break;
			}
			break;
		
		case 14:
			//0x23a7c - Setup
			switch (b)
			{
				case 1:
					//0x23aac
					g_pcstrBigMenuLine1 = strTimeAndDate;
					g_pcstrBigMenuLine2 = g_pcstrDaylightSaving;
					g_pcstrBigMenuLine3 = g_pcstrEngSiteSetting;
					g_pcstrBigMenuLine4 = g_pcstrSkyLand;
					break;

				case 2:
					//0x23af4
					g_pcstrBigMenuLine1 = g_pcstrDaylightSaving;
					g_pcstrBigMenuLine2 = g_pcstrEngSiteSetting;
					g_pcstrBigMenuLine3 = g_pcstrSkyLand;
					g_pcstrBigMenuLine4 = g_pcstrAzEqu;
					break;
				
				case 3:
					//0x23b3c
					g_pcstrBigMenuLine1 = g_pcstrEngSiteSetting;
					g_pcstrBigMenuLine2 = g_pcstrSkyLand;
					g_pcstrBigMenuLine3 = g_pcstrAzEqu;
					g_pcstrBigMenuLine4 = strTelescopeMount;
					break;
				
				case 4:
					//0x23b84
					g_pcstrBigMenuLine1 = g_pcstrSkyLand;
					g_pcstrBigMenuLine2 = g_pcstrAzEqu;
					g_pcstrBigMenuLine3 = strTelescopeMount;
					g_pcstrBigMenuLine4 = strTrackingRate;
					break;
				
				case 5:
					//0x23bcc
					g_pcstrBigMenuLine1 = g_pcstrAzEqu;
					g_pcstrBigMenuLine2 = strTelescopeMount;
					g_pcstrBigMenuLine3 = strTrackingRate;
					g_pcstrBigMenuLine4 = g_pcstrLanguage;
					break;
				
				case 6:
					//0x23c14
					g_pcstrBigMenuLine1 = strTelescopeMount;
					g_pcstrBigMenuLine2 = strTrackingRate;
					g_pcstrBigMenuLine3 = g_pcstrLanguage;
					g_pcstrBigMenuLine4 = strReset;
					break;
				
				case 7:
					//0x23c5c
					g_pcstrBigMenuLine1 = strTrackingRate;
					g_pcstrBigMenuLine2 = g_pcstrLanguage;
					g_pcstrBigMenuLine3 = strReset;
					g_pcstrBigMenuLine4 = g_pcstrSetupSpare1;
					break;
				
				default:
					//0x23ca4
					break;
			}
			break;
		
		case 22:
			//0x23cb4
			switch (b)
			{
				case 1:
					//0x23ce8
					g_pcstrBigMenuLine1 = Data_40002fdc;
					g_pcstrBigMenuLine2 = Data_40002fe0;
					g_pcstrBigMenuLine3 = Data_40002fe4;
					g_pcstrBigMenuLine4 = Data_40002fe8;
					break;

				case 2:
					//0x23d30
					g_pcstrBigMenuLine1 = Data_40002fe0;
					g_pcstrBigMenuLine2 = Data_40002fe4;
					g_pcstrBigMenuLine3 = Data_40002fe8;
					g_pcstrBigMenuLine4 = Data_40002fec;
					break;
				
				case 3:
					//0x23d78
					g_pcstrBigMenuLine1 = Data_40002fe4;
					g_pcstrBigMenuLine2 = Data_40002fe8;
					g_pcstrBigMenuLine3 = Data_40002fec;
					g_pcstrBigMenuLine4 = Data_40002ff0;
					break;
				
				case 4:
					//0x23dc0
					g_pcstrBigMenuLine1 = Data_40002fe8;
					g_pcstrBigMenuLine2 = Data_40002fec;
					g_pcstrBigMenuLine3 = Data_40002ff0;
					g_pcstrBigMenuLine4 = Data_40002ff4;
					break;
				
				case 5:
					//0x23e08
					g_pcstrBigMenuLine1 = Data_40002fec;
					g_pcstrBigMenuLine2 = Data_40002ff0;
					g_pcstrBigMenuLine3 = Data_40002ff4;
					g_pcstrBigMenuLine4 = Data_40002ff8;
					break;
				
				case 6:
					//0x23e50
					g_pcstrBigMenuLine1 = Data_40002ff0;
					g_pcstrBigMenuLine2 = Data_40002ff4;
					g_pcstrBigMenuLine3 = Data_40002ff8;
					g_pcstrBigMenuLine4 = Data_40002ffc;
					break;
				
				case 7:
					//0x23e98
					g_pcstrBigMenuLine1 = Data_40002ff4;
					g_pcstrBigMenuLine2 = Data_40002ff8;
					g_pcstrBigMenuLine3 = Data_40002ffc;
					g_pcstrBigMenuLine4 = Data_40003000;
					break;

				case 8:
					//0x23ee0
					g_pcstrBigMenuLine1 = Data_40002ff8;
					g_pcstrBigMenuLine2 = Data_40002ffc;
					g_pcstrBigMenuLine3 = Data_40003000;
					g_pcstrBigMenuLine4 = Data_40003004;
					break;
				
				default:
					//0x23f28
					break;
			}
			break;
		
		case 23:
			//0x23f38
			switch (b)
			{
				case 1:
					//0x23f60
					g_pcstrBigMenuLine1 = Data_40003008;
					g_pcstrBigMenuLine2 = Data_4000300c;
					g_pcstrBigMenuLine3 = Data_40003010;
					g_pcstrBigMenuLine4 = Data_40003014;
					break;

				case 2:
					//0x23fa8
					g_pcstrBigMenuLine1 = Data_4000300c;
					g_pcstrBigMenuLine2 = Data_40003010;
					g_pcstrBigMenuLine3 = Data_40003014;
					g_pcstrBigMenuLine4 = Data_40003018;
					break;
				
				case 3:
					//0x23ff0
					g_pcstrBigMenuLine1 = Data_40003010;
					g_pcstrBigMenuLine2 = Data_40003014;
					g_pcstrBigMenuLine3 = Data_40003018;
					g_pcstrBigMenuLine4 = Data_4000301c;
					break;
				
				case 4:
					//0x24038
					g_pcstrBigMenuLine1 = Data_40003014;
					g_pcstrBigMenuLine2 = Data_40003018;
					g_pcstrBigMenuLine3 = Data_4000301c;
					g_pcstrBigMenuLine4 = Data_40003020;
					break;
				
				case 5:
					//0x24080
					g_pcstrBigMenuLine1 = Data_40003018;
					g_pcstrBigMenuLine2 = Data_4000301c;
					g_pcstrBigMenuLine3 = Data_40003020;
					g_pcstrBigMenuLine4 = Data_40003024;
					break;
				
				default:
					//0x240c8
					break;
			}
			break;
		
		default:
			//0x240d8
			break;
	}
}

/* 240e8 - todo */
void func_240e8(unsigned char a, int b)
{
	switch (a)
	{
		case MENU_RECENT_TARGET_SOLAR_SYSTEM: //1:
			//0x24134
			bData_40002eb5_SolarSystemObjectNr = b;
			
			get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
				&fData_40002cd0_ObjectRightAscension, 
				&fData_40002d18_ObjectDeclination);
		
			for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
			{
				//0x24164
				Data_4000410e[bData_40002f1d] = Data_4000314c_SolarSystemObjectName[bData_40002f1d];
			}
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_CONSTELLATION: //2:
			//0x241b0: Constellation
			bData_40002ece_ConstellationNr = b;
		
			flash_get_constellation_data(bData_40002ece_ConstellationNr, 
				&Data_40003dd4_FlashConstellationData);
		
			sprintf(Data_4000410e, "Constellation %d          ", bData_40002ece_ConstellationNr);
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_FAMOUS_STAR: //3:
			//0x241e4
			bData_40002ed2_FamousStarNr = b;
		
			flash_get_famous_star_data(bData_40002ed2_FamousStarNr, 
				&Data_40003d94_FlashFamousStarData);

			for (bData_40002f1d = 0; bData_40002f1d < 13; bData_40002f1d++)
			{
				//0x24210
				Data_4000410e[bData_40002f1d] = ((char*)&Data_40003d94_FlashFamousStarData.bData_28)[bData_40002f1d+1];
			}
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_MESSIER: //4:
			//0x2425c
			wData_40002eb8_MessierNr = b; 
		
			flash_get_messier_data(wData_40002eb8_MessierNr & 0xFF, &Data_40003e08_FlashMessierData);
		
			sprintf(Data_4000410e, "Messier %d                  ", wData_40002eb8_MessierNr);
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_NGC: //5:
			//0x24290	
			wData_40002eba_NGCNr = b; 
		
			flash_get_ngc_data(wData_40002eba_NGCNr, &Data_40003ee0_FlashNGCData);
		
			sprintf(Data_4000410e, "NGC %d                        ", wData_40002eba_NGCNr);
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_IC: //6:
			//0x242c4
			wData_40002ebc_ICNr = b; 
		
			flash_get_ic_data(wData_40002ebc_ICNr, &Data_40003ec0_FlashICData);
		
			sprintf(Data_4000410e, "IC %d                         ", wData_40002ebc_ICNr);
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_SH2: //7:
			//0x242f8
			wData_40002ebe_ShNr = b; 
		
			flash_get_sh2_data(wData_40002ebe_ShNr, &Data_40003350_FlashSh2Data);
		
			sprintf(Data_4000410e, "Sh %d                           ", wData_40002ebe_ShNr);
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_BRIGHT_STAR: //8:
			//0x2432c
			wData_40002ec0_BrightStarNr = b; 
		
			flash_get_bright_star_data(wData_40002ec0_BrightStarNr & 0xFF, &Data_40003ea0_FlashBrightStarData);

			sprintf(Data_4000410e, "Bright %d                         ", wData_40002ec0_BrightStarNr);
			//->0x24568
			break;
		
		case MENU_RECENT_TARGET_SAO_CAT: //9:
			//0x24478
			Data_40002ec4_SAONr = b; 
		
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);
		
			sprintf(Data_4000410e, "SAO %d                          ", Data_40002ec4_SAONr);
			//->0x24568
			break;
		
		case 10:
			//0x244a8 
			func_5218(b & 0xFF, &Data_40003f50);
			sprintf(Data_4000410e, "Sky F%d                 ", b);
			//->0x24568
			break;
		
		case 11:
			//0x244cc
			func_5218(b & 0xFF, &Data_40003f50);
		
			Data_400033a0 = "My Input Data                ";
		
			for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
			{
				//0x244f8
				Data_4000410e[bData_40002f1d] = Data_400033a0[bData_40002f1d];
			}
			//->0x24568		
			break;
		
		case 12:
			//0x24544 
			func_54e0(b & 0xFF, &Data_40003f64);
			sprintf(Data_4000410e, "Land F%d                   ", b);
			break;

		#if 0
		default:
			//0x24568
			break;
		#endif
	}
}

