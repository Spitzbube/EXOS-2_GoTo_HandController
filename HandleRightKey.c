

/* 57c1c - todo */
void HandleRightKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 29001:
			//0x57e3c
		case 204:
			//0x57e44
			func_57b40();
			break;
		
		case 29002:
			//0x57e4c
		case 205:
			//0x57e54
		case 208:
			//0x57e58
		case 207:
			//0x57e5c
			func_57a4c();
			break;
		
		case 203:
			//0x57e64
		case 206:
			//0x57e6c
			bData_4000318a++;
			if (bData_4000318a > 13)
			{
				bData_4000318a = 6;
			}
			//->0x583d0
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x57ea0
		case 11102:
			//0x57ea8
		case 11202:
			//0x57eac
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x57eb0
		case 24002:
			//0x57eb4
		case 25002:
			//0x57eb8
		case 23022:
			//0x57ebc
		case 23013:
			//0x57ec0
		case 23014:
			//0x57ec4
		case 23015:
			//0x57ec8
		case 23016:
			//0x57ecc
		case 23017:
			//0x57ed0
			if (bData_400034a9 == 0)
			{
				//57ee0
				if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
				{
					//57f00
					Data_40003408 = 1;
					bData_40003200 = 0;
				}
				else
				{
					//0x57f1c
					if (bData_40002c1a == 1)
					{
						//57f2c
						func_57414(1, 4, bData_40002e7d_RotatingSpeed);
					}
					else
					{
						//0x57f44
						func_57414(3, 4, bData_40002e7d_RotatingSpeed);
					}
				}
			}
			else
			{
				//0x57f5c
				if (bData_40002c1a == 1)
				{
					//57f6c
					func_57414(1, 4, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x57f84
					func_57414(3, 4, bData_40002e7d_RotatingSpeed);
				}
			}
			//0x57f98 -> 0x583d0
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x57f9c
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				//57fb0
				Data_40003408 = 1;
				bData_40003200 = 0;
			}
			break;
		
		case 11101:
			//0x57fcc
			dData_40002dc8 = dData_40002dc0;
			if (bData_40002c1a == 1)
			{
				//57ff0
				func_57414(1, 4, MENU_ROTATING_SPEED_8); //3);
				
				bData_40002edd = 2;
			}
			else
			{
				//0x58010
				func_57414(3, 4, MENU_ROTATING_SPEED_8); //3);
				
				bData_40002edd = 0;
			}
			//0x5802c
			Data_40002eb0 = 1;
			bData_40003188 = 1;
			Data_40002c64_MenuContextId = 11103;
			break;
		
		case 11103:
			//0x58050
			if (bData_40003188 == 2)
			{
				//58064
				if (bData_40002c1a == 1)
				{
					//58074
					func_57414(1, 4, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x58120
					func_57414(3, 4, bData_40002e7d_RotatingSpeed);
				}
			}
			//0x58134
			//break; //Fall through?
		
		case 48001:
			//0x58138
			func_57370();
			break;
		
		case 41001:
			//0x58140
			func_5718c();
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x5814c
			func_56e50();
			break;
		
		case 201:
			//0x58158		
		case 202:
			//0x58160
		case 101:
			//0x58164
			switch (bData_4000319a_SkyLandTargetId)
			{
				case 1:
					//0x581a0
					bData_4000319a_SkyLandTargetId = 2;
					break;
				
				case 2:
					//0x581b4
					bData_4000319a_SkyLandTargetId = 3;
					break;
				
				case 3:
					//0x581c8
					bData_4000319a_SkyLandTargetId = 1;
					break;
				
				case 4:
					//0x581dc
					bData_4000319a_SkyLandTargetId = 5;
					break;
				
				case 5:
					//0x581f0
					bData_4000319a_SkyLandTargetId = 6;
					break;
				
				case 6:
					//0x58204
					bData_4000319a_SkyLandTargetId = 4;
					break;
				
				case 7:
					//0x58218
					bData_4000319a_SkyLandTargetId = 8;
					break;
				
				case 8:
					//0x5822c
					bData_4000319a_SkyLandTargetId = 9;
					break;
				
				case 9:
					//0x58240
					bData_4000319a_SkyLandTargetId = 7;
					break;
				
				#if 0
				default:
					//0x58254
					break;
				#endif
			}
			break;
		
		case 47011:
			//0x5825c
			func_56dac();
			break;
		
		case 33001:
			//0x58268
			if (Data_40003168_LunarPhaseMonth < 12)
			{
				Data_40003168_LunarPhaseMonth++;
			}
			else
			{
				Data_40003168_LunarPhaseMonth = 0;
			}
			break;
		
		case 34001:
			//0x582a4
			func_56d0c();
			break;
		
		case 35001:
			//0x582b0
			func_56c4c();
			break;
		
		case 360022:
			//0x582bc
		case 370022:
			//0x582c4
			func_56bf8();
			break;
		
		case 370023:
			//0x582cc
			func_56b54();
			break;
		
		case 360021:
			//0x582d8
		case 370021:
			//0x582e0
			func_56ac8();
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x582e8
			lcd_display_clear();
			func_56840(); //->Next city
			break;
		
		case 211001:
			//0x582f8
			switch (bData_40003262)
			{
				case 1:
					//5830c
					func_5660c();
					break;
				
				default:
					break;
			}			
			break;
		
		case 28001:
			//0x58328
			switch (bData_40003263)
			{
				case 1:
					//0x58348
				case 3:
					//0x58350
					func_563c8();
					break;
								
				default:
					//0x59d4c
					break;
			}
			break;
		
		case 42001:
			//0x58368
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42002;
				bData_40002c6a = 0;
			}
			break;
		
		case 42002:
			//0x58398
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42001;
				bData_40002c6a = 1;
			}
			break;
		
		default:
			//0x583c8
			break;
	}
}

