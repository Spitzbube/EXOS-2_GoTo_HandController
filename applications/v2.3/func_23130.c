

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
					Data_40003360 = strOneStarAlign;
					Data_40003364 = strTwoStarAlign;
					Data_40003368 = strThreeStarAlign;
					Data_4000336c = strTargetSync;
					Data_40003370 = strPoleAxisDev;
					Data_40003374 = strRaBklashCorr;
					Data_40003378 = strDecBklashCorr;
					Data_4000337c = strAlignmentSpare1;
					//->0x227ac
					break;
				
				case 2:
					//0x22548
					Data_40003360 = strTwoStarAlign;
					Data_40003364 = strThreeStarAlign;
					Data_40003368 = strTargetSync;
					Data_4000336c = strPoleAxisDev;
					Data_40003370 = strRaBklashCorr;
					Data_40003374 = strDecBklashCorr;
					Data_40003378 = strAlignmentSpare1;
					Data_4000337c = strAlignmentSpare2;
					//->0x227ac
					break;
				
				case 3:
					//0x225d0
					Data_40003360 = strThreeStarAlign;
					Data_40003364 = strTargetSync;
					Data_40003368 = strPoleAxisDev;
					Data_4000336c = strRaBklashCorr;
					Data_40003370 = strDecBklashCorr;
					Data_40003374 = strAlignmentSpare1;
					Data_40003378 = strAlignmentSpare2;
					Data_4000337c = strAlignmentSpare3;
					//->0x227ac
					break;
				
				case 4:
					//0x22658
					Data_40003360 = strTargetSync;
					Data_40003364 = strPoleAxisDev;
					Data_40003368 = strRaBklashCorr;
					Data_4000336c = strDecBklashCorr;
					Data_40003370 = strAlignmentSpare1;
					Data_40003374 = strAlignmentSpare2;
					Data_40003378 = strAlignmentSpare3;
					Data_4000337c = strAlignmentSpare4;
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
					Data_40003360 = strSolarSystem;
					Data_40003364 = strConstellation;
					Data_40003368 = strFamousStar;
					Data_4000336c = g_pcstrMessierCatalogue;
					Data_40003370 = g_pcstrNGCCatalogue;
					Data_40003374 = g_pcstrICCatalogue;
					Data_40003378 = g_pcstrSh2Catalogue;
					Data_4000337c = g_pcstrBrightStarCatalogue;
					//->0x22a8c
					break;
				
				case 2:
					//0x22864
					Data_40003360 = strConstellation;
					Data_40003364 = strFamousStar;
					Data_40003368 = g_pcstrMessierCatalogue;
					Data_4000336c = g_pcstrNGCCatalogue;
					Data_40003370 = g_pcstrICCatalogue;
					Data_40003374 = g_pcstrSh2Catalogue;
					Data_40003378 = g_pcstrBrightStarCatalogue;
					Data_4000337c = g_pcstrSAOStarCatalogue;
					//->0x22a8c
					break;
				
				case 3:
					//0x228ec
					Data_40003360 = strFamousStar;
					Data_40003364 = g_pcstrMessierCatalogue;
					Data_40003368 = g_pcstrNGCCatalogue;
					Data_4000336c = g_pcstrICCatalogue;
					Data_40003370 = g_pcstrSh2Catalogue;
					Data_40003374 = g_pcstrBrightStarCatalogue;
					Data_40003378 = g_pcstrSAOStarCatalogue;
					Data_4000337c = g_pcstrCustomerObjects;
					//->0x22a8c
					break;
				
				case 4:
					//0x22974
					Data_40003360 = g_pcstrMessierCatalogue;
					Data_40003364 = g_pcstrNGCCatalogue;
					Data_40003368 = g_pcstrICCatalogue;
					Data_4000336c = g_pcstrSh2Catalogue;
					Data_40003370 = g_pcstrBrightStarCatalogue;
					Data_40003374 = g_pcstrSAOStarCatalogue;
					Data_40003378 = g_pcstrCustomerObjects;
					Data_4000337c = g_pcstrInputRAandDEC;
					//->0x22a8c
					break;
				
				case 5:
					//0x229fc
					Data_40003360 = g_pcstrNGCCatalogue;
					Data_40003364 = g_pcstrICCatalogue;
					Data_40003368 = g_pcstrSh2Catalogue;
					Data_4000336c = g_pcstrBrightStarCatalogue;
					Data_40003370 = g_pcstrSAOStarCatalogue;
					Data_40003374 = g_pcstrCustomerObjects;
					Data_40003378 = g_pcstrInputRAandDEC;
					Data_4000337c = g_pcstrCustomLandGoal;
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
					Data_40003360 = strCurrentObjects;
					Data_40003364 = Data_40002f90;
					Data_40003368 = Data_40002f94;
					Data_4000336c = Data_40002f98;
					Data_40003370 = Data_40002f9c;
					Data_40003374 = Data_40002fa0;
					Data_40003378 = Data_40002fa4;
					Data_4000337c = Data_40002fa8;
					//->0x22c54
					break;
				
				case 2:
					//0x22b3c
					Data_40003360 = Data_40002f90;
					Data_40003364 = Data_40002f94;
					Data_40003368 = Data_40002f98;
					Data_4000336c = Data_40002f9c;
					Data_40003370 = Data_40002fa0;
					Data_40003374 = Data_40002fa4;
					Data_40003378 = Data_40002fa8;
					Data_4000337c = strParkposition;
					//->0x22c54
					break;
				
				case 3:
					//0x22bc4
					Data_40003360 = Data_40002f94;
					Data_40003364 = Data_40002f98;
					Data_40003368 = Data_40002f9c;
					Data_4000336c = Data_40002fa0;
					Data_40003370 = Data_40002fa4;
					Data_40003374 = Data_40002fa8;
					Data_40003378 = strParkposition;
					Data_4000337c = Data_40002fb0;
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
				case 1:
					//0x22c7c
					Data_40003360 = strTimeAndDate;
					Data_40003364 = Data_40002fb8;
					Data_40003368 = Data_40002fbc;
					Data_4000336c = Data_40002fc0;
					Data_40003370 = Data_40002fc4;
					Data_40003374 = strTelescopeMount;
					Data_40003378 = strTrackingRate;
					Data_4000337c = Data_40002fd0;
					//->0x22e1c
					break;
				
				case 2:
					//0x22d04
					Data_40003360 = Data_40002fb8;
					Data_40003364 = Data_40002fbc;
					Data_40003368 = Data_40002fc0;
					Data_4000336c = Data_40002fc4;
					Data_40003370 = strTelescopeMount;
					Data_40003374 = strTrackingRate;
					Data_40003378 = Data_40002fd0;
					Data_4000337c = strReset;
					//->0x22e1c
					break;
				
				case 3:
					//0x22d8c
					Data_40003360 = Data_40002fbc;
					Data_40003364 = Data_40002fc0;
					Data_40003368 = Data_40002fc4;
					Data_4000336c = strTelescopeMount;
					Data_40003370 = strTrackingRate;
					Data_40003374 = Data_40002fd0;
					Data_40003378 = strReset;
					Data_4000337c = Data_40002fd8;
					//->0x22e1c
					break;
				
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
					Data_40003360 = Data_40002fdc;
					Data_40003364 = Data_40002fe0;
					Data_40003368 = Data_40002fe4;
					Data_4000336c = Data_40002fe8;
					Data_40003370 = Data_40002fec;
					Data_40003374 = Data_40002ff0;
					Data_40003378 = Data_40002ff4;
					Data_4000337c = Data_40002ff8;
					//->0x23074
					break;
				
				case 2:
					//0x22ed4
					Data_40003360 = Data_40002fe0;
					Data_40003364 = Data_40002fe4;
					Data_40003368 = Data_40002fe8;
					Data_4000336c = Data_40002fec;
					Data_40003370 = Data_40002ff0;
					Data_40003374 = Data_40002ff4;
					Data_40003378 = Data_40002ff8;
					Data_4000337c = Data_40002ffc;
					//->0x23074
					break;
				
				case 3:
					//0x22f5c
					Data_40003360 = Data_40002fe4;
					Data_40003364 = Data_40002fe8;
					Data_40003368 = Data_40002fec;
					Data_4000336c = Data_40002ff0;
					Data_40003370 = Data_40002ff4;
					Data_40003374 = Data_40002ff8;
					Data_40003378 = Data_40002ffc;
					Data_4000337c = Data_40003000;
					//->0x23074
					break;
				
				case 4:
					//0x22fe4
					Data_40003360 = Data_40002fe8;
					Data_40003364 = Data_40002fec;
					Data_40003368 = Data_40002ff0;
					Data_4000336c = Data_40002ff4;
					Data_40003370 = Data_40002ff8;
					Data_40003374 = Data_40002ffc;
					Data_40003378 = Data_40003000;
					Data_4000337c = Data_40003004;
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
					Data_40003360 = Data_40003008;
					Data_40003364 = Data_4000300c;
					Data_40003368 = Data_40003010;
					Data_4000336c = Data_40003014;
					Data_40003370 = Data_40003018;
					Data_40003374 = Data_4000301c;
					Data_40003378 = Data_40003020;
					Data_4000337c = Data_40003024;
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
			//0x2320c: Telescope Align
			switch (b)
			{
				case 1:
					//0x23240
					g_pcstrFourLineMenu1 = strOneStarAlign;
					g_pcstrFourLineMenu2 = strTwoStarAlign;
					g_pcstrFourLineMenu3 = strThreeStarAlign;
					g_pcstrFourLineMenu4 = strTargetSync;
					break;

				case 2:
					//0x23288
					g_pcstrFourLineMenu1 = strTwoStarAlign;
					g_pcstrFourLineMenu2 = strThreeStarAlign;
					g_pcstrFourLineMenu3 = strTargetSync;
					g_pcstrFourLineMenu4 = strPoleAxisDev;
					break;
				
				case 3:
					//0x232d0
					g_pcstrFourLineMenu1 = strThreeStarAlign;
					g_pcstrFourLineMenu2 = strTargetSync;
					g_pcstrFourLineMenu3 = strPoleAxisDev;
					g_pcstrFourLineMenu4 = strRaBklashCorr;
					break;
				
				case 4:
					//0x23318
					g_pcstrFourLineMenu1 = strTargetSync;
					g_pcstrFourLineMenu2 = strPoleAxisDev;
					g_pcstrFourLineMenu3 = strRaBklashCorr;
					g_pcstrFourLineMenu4 = strDecBklashCorr;
					break;
				
				case 5:
					//0x23360
					g_pcstrFourLineMenu1 = strPoleAxisDev;
					g_pcstrFourLineMenu2 = strRaBklashCorr;
					g_pcstrFourLineMenu3 = strDecBklashCorr;
					g_pcstrFourLineMenu4 = strAlignmentSpare1;
					break;
				
				case 6:
					//0x233a8
					g_pcstrFourLineMenu1 = strRaBklashCorr;
					g_pcstrFourLineMenu2 = strDecBklashCorr;
					g_pcstrFourLineMenu3 = strAlignmentSpare1;
					g_pcstrFourLineMenu4 = strAlignmentSpare2;
					break;
				
				case 7:
					//0x233f0
					g_pcstrFourLineMenu1 = strDecBklashCorr;
					g_pcstrFourLineMenu2 = strAlignmentSpare1;
					g_pcstrFourLineMenu3 = strAlignmentSpare2;
					g_pcstrFourLineMenu4 = strAlignmentSpare3;
					break;
				
				case 8:
					//0x23438
					g_pcstrFourLineMenu1 = strAlignmentSpare1;
					g_pcstrFourLineMenu2 = strAlignmentSpare2;
					g_pcstrFourLineMenu3 = strAlignmentSpare3;
					g_pcstrFourLineMenu4 = strAlignmentSpare4;
					break;
				
				default:
					//0x23480
					break;
			}
			break;
		
		case 12:
			//0x23490: Navigation
			switch (b)
			{
				case 1:
					//0x234c8
					g_pcstrFourLineMenu1 = strSolarSystem;
					g_pcstrFourLineMenu2 = strConstellation;
					g_pcstrFourLineMenu3 = strFamousStar;
					g_pcstrFourLineMenu4 = g_pcstrMessierCatalogue;
					break;

				case 2:
					//0x23510
					g_pcstrFourLineMenu1 = strConstellation;
					g_pcstrFourLineMenu2 = strFamousStar;
					g_pcstrFourLineMenu3 = g_pcstrMessierCatalogue;
					g_pcstrFourLineMenu4 = g_pcstrNGCCatalogue;
					break;
				
				case 3:
					//0x23558
					g_pcstrFourLineMenu1 = strFamousStar;
					g_pcstrFourLineMenu2 = g_pcstrMessierCatalogue;
					g_pcstrFourLineMenu3 = g_pcstrNGCCatalogue;
					g_pcstrFourLineMenu4 = g_pcstrICCatalogue;
					break;
				
				case 4:
					//0x235a0
					g_pcstrFourLineMenu1 = g_pcstrMessierCatalogue;
					g_pcstrFourLineMenu2 = g_pcstrNGCCatalogue;
					g_pcstrFourLineMenu3 = g_pcstrICCatalogue;
					g_pcstrFourLineMenu4 = g_pcstrSh2Catalogue;
					break;
				
				case 5:
					//0x235e8
					g_pcstrFourLineMenu1 = g_pcstrNGCCatalogue;
					g_pcstrFourLineMenu2 = g_pcstrICCatalogue;
					g_pcstrFourLineMenu3 = g_pcstrSh2Catalogue;
					g_pcstrFourLineMenu4 = g_pcstrBrightStarCatalogue;
					break;
				
				case 6:
					//0x23630
					g_pcstrFourLineMenu1 = g_pcstrICCatalogue;
					g_pcstrFourLineMenu2 = g_pcstrSh2Catalogue;
					g_pcstrFourLineMenu3 = g_pcstrBrightStarCatalogue;
					g_pcstrFourLineMenu4 = g_pcstrSAOStarCatalogue;
					break;
				
				case 7:
					//0x23678
					g_pcstrFourLineMenu1 = g_pcstrSh2Catalogue;
					g_pcstrFourLineMenu2 = g_pcstrBrightStarCatalogue;
					g_pcstrFourLineMenu3 = g_pcstrSAOStarCatalogue;
					g_pcstrFourLineMenu4 = g_pcstrCustomerObjects;
					break;
				
				case 8:
					//0x237a4
					g_pcstrFourLineMenu1 = g_pcstrBrightStarCatalogue;
					g_pcstrFourLineMenu2 = g_pcstrSAOStarCatalogue;
					g_pcstrFourLineMenu3 = g_pcstrCustomerObjects;
					g_pcstrFourLineMenu4 = g_pcstrInputRAandDEC;
					break;

				case 9:
					//0x237ec
					g_pcstrFourLineMenu1 = g_pcstrSAOStarCatalogue;
					g_pcstrFourLineMenu2 = g_pcstrCustomerObjects;
					g_pcstrFourLineMenu3 = g_pcstrInputRAandDEC;
					g_pcstrFourLineMenu4 = g_pcstrCustomLandGoal;
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
					g_pcstrFourLineMenu1 = strCurrentObjects;
					g_pcstrFourLineMenu2 = Data_40002f90;
					g_pcstrFourLineMenu3 = Data_40002f94;
					g_pcstrFourLineMenu4 = Data_40002f98;
					break;

				case 2:
					//0x238bc
					g_pcstrFourLineMenu1 = Data_40002f90;
					g_pcstrFourLineMenu2 = Data_40002f94;
					g_pcstrFourLineMenu3 = Data_40002f98;
					g_pcstrFourLineMenu4 = Data_40002f9c;
					break;
				
				case 3:
					//0x23904
					g_pcstrFourLineMenu1 = Data_40002f94;
					g_pcstrFourLineMenu2 = Data_40002f98;
					g_pcstrFourLineMenu3 = Data_40002f9c;
					g_pcstrFourLineMenu4 = Data_40002fa0;
					break;
				
				case 4:
					//0x2394c
					g_pcstrFourLineMenu1 = Data_40002f98;
					g_pcstrFourLineMenu2 = Data_40002f9c;
					g_pcstrFourLineMenu3 = Data_40002fa0;
					g_pcstrFourLineMenu4 = Data_40002fa4;
					break;
				
				case 5:
					//0x23994
					g_pcstrFourLineMenu1 = Data_40002f9c;
					g_pcstrFourLineMenu2 = Data_40002fa0;
					g_pcstrFourLineMenu3 = Data_40002fa4;
					g_pcstrFourLineMenu4 = Data_40002fa8;
					break;
				
				case 6:
					//0x239dc
					g_pcstrFourLineMenu1 = Data_40002fa0;
					g_pcstrFourLineMenu2 = Data_40002fa4;
					g_pcstrFourLineMenu3 = Data_40002fa8;
					g_pcstrFourLineMenu4 = strParkposition;
					break;
				
				case 7:
					//0x23a24
					g_pcstrFourLineMenu1 = Data_40002fa4;
					g_pcstrFourLineMenu2 = Data_40002fa8;
					g_pcstrFourLineMenu3 = strParkposition;
					g_pcstrFourLineMenu4 = Data_40002fb0;
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
					g_pcstrFourLineMenu1 = strTimeAndDate;
					g_pcstrFourLineMenu2 = Data_40002fb8;
					g_pcstrFourLineMenu3 = Data_40002fbc;
					g_pcstrFourLineMenu4 = Data_40002fc0;
					break;

				case 2:
					//0x23af4
					g_pcstrFourLineMenu1 = Data_40002fb8;
					g_pcstrFourLineMenu2 = Data_40002fbc;
					g_pcstrFourLineMenu3 = Data_40002fc0;
					g_pcstrFourLineMenu4 = Data_40002fc4;
					break;
				
				case 3:
					//0x23b3c
					g_pcstrFourLineMenu1 = Data_40002fbc;
					g_pcstrFourLineMenu2 = Data_40002fc0;
					g_pcstrFourLineMenu3 = Data_40002fc4;
					g_pcstrFourLineMenu4 = strTelescopeMount;
					break;
				
				case 4:
					//0x23b84
					g_pcstrFourLineMenu1 = Data_40002fc0;
					g_pcstrFourLineMenu2 = Data_40002fc4;
					g_pcstrFourLineMenu3 = strTelescopeMount;
					g_pcstrFourLineMenu4 = strTrackingRate;
					break;
				
				case 5:
					//0x23bcc
					g_pcstrFourLineMenu1 = Data_40002fc4;
					g_pcstrFourLineMenu2 = strTelescopeMount;
					g_pcstrFourLineMenu3 = strTrackingRate;
					g_pcstrFourLineMenu4 = Data_40002fd0;
					break;
				
				case 6:
					//0x23c14
					g_pcstrFourLineMenu1 = strTelescopeMount;
					g_pcstrFourLineMenu2 = strTrackingRate;
					g_pcstrFourLineMenu3 = Data_40002fd0;
					g_pcstrFourLineMenu4 = strReset;
					break;
				
				case 7:
					//0x23c5c
					g_pcstrFourLineMenu1 = strTrackingRate;
					g_pcstrFourLineMenu2 = Data_40002fd0;
					g_pcstrFourLineMenu3 = strReset;
					g_pcstrFourLineMenu4 = Data_40002fd8;
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
					g_pcstrFourLineMenu1 = Data_40002fdc;
					g_pcstrFourLineMenu2 = Data_40002fe0;
					g_pcstrFourLineMenu3 = Data_40002fe4;
					g_pcstrFourLineMenu4 = Data_40002fe8;
					break;

				case 2:
					//0x23d30
					g_pcstrFourLineMenu1 = Data_40002fe0;
					g_pcstrFourLineMenu2 = Data_40002fe4;
					g_pcstrFourLineMenu3 = Data_40002fe8;
					g_pcstrFourLineMenu4 = Data_40002fec;
					break;
				
				case 3:
					//0x23d78
					g_pcstrFourLineMenu1 = Data_40002fe4;
					g_pcstrFourLineMenu2 = Data_40002fe8;
					g_pcstrFourLineMenu3 = Data_40002fec;
					g_pcstrFourLineMenu4 = Data_40002ff0;
					break;
				
				case 4:
					//0x23dc0
					g_pcstrFourLineMenu1 = Data_40002fe8;
					g_pcstrFourLineMenu2 = Data_40002fec;
					g_pcstrFourLineMenu3 = Data_40002ff0;
					g_pcstrFourLineMenu4 = Data_40002ff4;
					break;
				
				case 5:
					//0x23e08
					g_pcstrFourLineMenu1 = Data_40002fec;
					g_pcstrFourLineMenu2 = Data_40002ff0;
					g_pcstrFourLineMenu3 = Data_40002ff4;
					g_pcstrFourLineMenu4 = Data_40002ff8;
					break;
				
				case 6:
					//0x23e50
					g_pcstrFourLineMenu1 = Data_40002ff0;
					g_pcstrFourLineMenu2 = Data_40002ff4;
					g_pcstrFourLineMenu3 = Data_40002ff8;
					g_pcstrFourLineMenu4 = Data_40002ffc;
					break;
				
				case 7:
					//0x23e98
					g_pcstrFourLineMenu1 = Data_40002ff4;
					g_pcstrFourLineMenu2 = Data_40002ff8;
					g_pcstrFourLineMenu3 = Data_40002ffc;
					g_pcstrFourLineMenu4 = Data_40003000;
					break;

				case 8:
					//0x23ee0
					g_pcstrFourLineMenu1 = Data_40002ff8;
					g_pcstrFourLineMenu2 = Data_40002ffc;
					g_pcstrFourLineMenu3 = Data_40003000;
					g_pcstrFourLineMenu4 = Data_40003004;
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
					g_pcstrFourLineMenu1 = Data_40003008;
					g_pcstrFourLineMenu2 = Data_4000300c;
					g_pcstrFourLineMenu3 = Data_40003010;
					g_pcstrFourLineMenu4 = Data_40003014;
					break;

				case 2:
					//0x23fa8
					g_pcstrFourLineMenu1 = Data_4000300c;
					g_pcstrFourLineMenu2 = Data_40003010;
					g_pcstrFourLineMenu3 = Data_40003014;
					g_pcstrFourLineMenu4 = Data_40003018;
					break;
				
				case 3:
					//0x23ff0
					g_pcstrFourLineMenu1 = Data_40003010;
					g_pcstrFourLineMenu2 = Data_40003014;
					g_pcstrFourLineMenu3 = Data_40003018;
					g_pcstrFourLineMenu4 = Data_4000301c;
					break;
				
				case 4:
					//0x24038
					g_pcstrFourLineMenu1 = Data_40003014;
					g_pcstrFourLineMenu2 = Data_40003018;
					g_pcstrFourLineMenu3 = Data_4000301c;
					g_pcstrFourLineMenu4 = Data_40003020;
					break;
				
				case 5:
					//0x24080
					g_pcstrFourLineMenu1 = Data_40003018;
					g_pcstrFourLineMenu2 = Data_4000301c;
					g_pcstrFourLineMenu3 = Data_40003020;
					g_pcstrFourLineMenu4 = Data_40003024;
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

