

/* 60ed0 - todo */
void HandleHelpKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 0:
			//0x611f8
			Data_40002c64_MenuContextId = 500; //Main Screen Help Pages
			bHelpActive = 1;
		
			lcd_display_clear();
		
			bData_40002c59_MainScreenHelpPage = 1;
			//->0x61ec0
			break;

		case 1000:
			//0x61228
			Data_40002c64_MenuContextId = 501; //Telescope align
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2000:
			//0x6124c
			Data_40002c64_MenuContextId = 502; //Target navigation
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3000:
			//0x61270
			Data_40002c64_MenuContextId = 503; //Utilities Commands
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4000:
			//0x61294
			Data_40002c64_MenuContextId = 504; //Parameter Setup
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
				
		case 1100: //1000 = Telescope align
			//0x612b8
			Data_40002c64_MenuContextId = 505; //One star align
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1200:
			//0x612dc
			Data_40002c64_MenuContextId = 506; //Two stars align
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1300:
			//0x61300
			Data_40002c64_MenuContextId = 507; //Three star align
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1400:
			//0x61324
			Data_40002c64_MenuContextId = 508; //Target Sync
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1500:
			//0x61348
			Data_40002c64_MenuContextId = 509; //Pole-Axis Deviation
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1600:
			//0x6136c
			Data_40002c64_MenuContextId = 510; //RA Bklash Correction
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1700:
			//0x61390
			Data_40002c64_MenuContextId = 511; //DEC Bklash Correction
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2100: //2000 = Target navigation
			//0x613b4
			Data_40002c64_MenuContextId = 516; //Solar System
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2200:
			//0x613d8
			Data_40002c64_MenuContextId = 517; //Constellation
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2300:
			//0x613fc
			Data_40002c64_MenuContextId = 518; //Famous Star
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2400:
			//0x61420
			Data_40002c64_MenuContextId = 519; //Messier Catalogue
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2500:
			//0x61444
			Data_40002c64_MenuContextId = 520; //NGC Deep Sky
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2600:
			//0x61468
			Data_40002c64_MenuContextId = 521; //IC Deep Sky
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2700:
			//0x6148c
			Data_40002c64_MenuContextId = 522; //Sh2 Deep Sky
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2800:
			//0x614b0
			Data_40002c64_MenuContextId = 523; //Bright Stars
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2900:
			//0x614d4
			Data_40002c64_MenuContextId = 524; //SAO Star
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2110:
			//0x614f8
			Data_40002c64_MenuContextId = 525; //User-def Object
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2120:
			//0x6151c
			Data_40002c64_MenuContextId = 526; //Specify Ra Dec
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2130:
			//0x61540
			Data_40002c64_MenuContextId = 527; //Landmarks
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3100: //3000 = Utilities Commands
			//0x61564
			Data_40002c64_MenuContextId = 528; //Current Objects
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3200:
			//0x61588
			Data_40002c64_MenuContextId = 529; //Object Rise/Set
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3300:
			//0x615ac
			Data_40002c64_MenuContextId = 530; //Lunar Phase
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3400:
			//0x615d0
			Data_40002c64_MenuContextId = 531; //Timer
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3500:
			//0x615f4
			Data_40002c64_MenuContextId = 532; //Alarm
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3600:
			//0x61618
			Data_40002c64_MenuContextId = 533; //Field Angle Cal
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3700:
			//0x6163c
			Data_40002c64_MenuContextId = 534; //Magify Power Cal
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3800:
			//0x61660
			Data_40002c64_MenuContextId = 535; //Illumination
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3900:
			//0x61684
			Data_40002c64_MenuContextId = 537; //Parkzen
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4100:
			//0x616a8
			Data_40002c64_MenuContextId = 538; //Time and Date
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4200:
			//0x616cc
			Data_40002c64_MenuContextId = 539; //Daylight Saving
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4300:
			//0x616f0
			Data_40002c64_MenuContextId = 540; //Site Setting
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4400:
			//0x61714
			Data_40002c64_MenuContextId = 541; //Sky/ Land
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4500:
			//0x61738
			Data_40002c64_MenuContextId = 542; //AZ/EQ
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4600:
			//0x6175c
			Data_40002c64_MenuContextId = 543; //Telescope Zero
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4700:
			//0x61780
			Data_40002c64_MenuContextId = 544; //Tracking Rate
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4800:
			//0x617a4
			Data_40002c64_MenuContextId = 545; //Language
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4900:
			//0x617c8
			Data_40002c64_MenuContextId = 546; //Reset
			bHelpActive = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 500:
			//0x617ec
			Data_40002c64_MenuContextId = 0;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 501: //0x1f5
			//0x6180c: Telescope align?
			Data_40002c64_MenuContextId = 1000;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 502:
			//0x61830: Target navigation?
			Data_40002c64_MenuContextId = 2000;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 503:
			//0x61854: Utilities Commands?
			Data_40002c64_MenuContextId = 3000;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 504: //0x1f8
			//0x61878: Parameter Setup?
			Data_40002c64_MenuContextId = 4000;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 505:
			//0x6189c
			Data_40002c64_MenuContextId = 1100;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 506:
			//0x618c0
			Data_40002c64_MenuContextId = 1200;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 507:
			//0x618e4
			Data_40002c64_MenuContextId = 1300;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 508:
			//0x61908
			Data_40002c64_MenuContextId = 1400;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 509: //0x1fd
			//0x6192c: Pole-Axis Deviation?
			Data_40002c64_MenuContextId = 1500;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;

		case 510:
			//0x61950
			Data_40002c64_MenuContextId = 1600;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 511:
			//0x61974
			Data_40002c64_MenuContextId = 1700;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 516:
			//0x61998
			Data_40002c64_MenuContextId = 2100;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 517:
			//0x619bc
			Data_40002c64_MenuContextId = 2200;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 518:
			//0x619e0
			Data_40002c64_MenuContextId = 2300;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 519:
			//0x61a04
			Data_40002c64_MenuContextId = 2400;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;

		case 520:
			//0x61a28
			Data_40002c64_MenuContextId = 2500;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 521:
			//0x61a4c
			Data_40002c64_MenuContextId = 2600;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 522:
			//0x61b60
			Data_40002c64_MenuContextId = 2700;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 523:
			//0x61b84
			Data_40002c64_MenuContextId = 2800;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 524: //0x20c
			//0x61ba8
			Data_40002c64_MenuContextId = 2900;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 525:
			//0x61bcc
			Data_40002c64_MenuContextId = 2110;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 526:
			//0x61bf0
			Data_40002c64_MenuContextId = 2120;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 527:
			//0x61c14
			Data_40002c64_MenuContextId = 2130;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 528:
			//0x61c38
			Data_40002c64_MenuContextId = 3100;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 529:
			//0x61c5c
			Data_40002c64_MenuContextId = 3200;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 530:
			//0x61c80
			Data_40002c64_MenuContextId = 3300;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 531:
			//0x61ca4
			Data_40002c64_MenuContextId = 3400;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 532:
			//0x61cc8
			Data_40002c64_MenuContextId = 3500;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 533:
			//0x61cec
			Data_40002c64_MenuContextId = 3600;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 534:
			//0x61d10
			Data_40002c64_MenuContextId = 3700;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 535:
			//0x61d34
			Data_40002c64_MenuContextId = 3800;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		#if 0
		case 536:
			//0x61ec0
			break;
		#endif
		
		case 537:
			//0x61d58
			Data_40002c64_MenuContextId = 3900;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 538:
			//0x61d7c
			Data_40002c64_MenuContextId = 4100;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 539:
			//0x61da0
			Data_40002c64_MenuContextId = 4200;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 540:
			//0x61dc4
			Data_40002c64_MenuContextId = 4300;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 541:
			//0x61de8
			Data_40002c64_MenuContextId = 4400;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 542:
			//0x61e0c
			Data_40002c64_MenuContextId = 4500;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 543:
			//0x61e30
			Data_40002c64_MenuContextId = 4600;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 544:
			//0x61e54
			Data_40002c64_MenuContextId = 4700;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 545:
			//0x61e78
			Data_40002c64_MenuContextId = 4800;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;

		case 546: //0x222
			//0x61e9c
			Data_40002c64_MenuContextId = 4900;
			bHelpActive = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		#if 0
		default:
			//0x61ec0
			break;
		#endif
	}
}

