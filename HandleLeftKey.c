

/* 583dc - todo */
void func_583dc(void)
{
}

/* 58620 - todo */
void func_58620(void)
{
}

/* 58854 - todo */
void func_58854(void)
{
}

/* 58adc - todo */
void func_58adc(void)
{
}

/* 58b68 - todo */
void func_58b68(void)
{
}

/* 58c0c - todo */
void func_58c0c(void)
{
}

/* 58c60 - todo */
void func_58c60(void)
{
}

/* 58d20 - todo */
void func_58d20(void)
{
}

/* 58dc0 - todo */
void func_58dc0(void)
{
}

/* 58e64 - todo */
void func_58e64(void)
{
}

/* 591b8 - todo */
void func_591b8(void)
{
}

/* 5939c - todo */
void func_5939c(void)
{
}

/* 59440 - todo */
void func_59440(void)
{
}

/* 59534 - todo */
void func_59534(void)
{
}

/* 59610 - todo */
void func_59610(void)
{
	switch (wData_40002eda)
	{
		case 1:
			//0x5963c
			wData_40002eda = 10;
			break;
		
		case 10:
			//0x59650
			wData_40002eda = 100;
			break;
		
		case 100:
			//0x59664
			wData_40002eda = 1000;
			break;
		
		case 1000:
			//0x59678
			wData_40002eda = 10000;
			break;
		
		default:
			//0x5968c
			break;
	}
}

/* 5969c - todo */
void HandleLeftKey(void)
{
	func_59610();
	
	switch (Data_40002c64_MenuContextId)
	{
		case 29001:
			//0x598c0
		case 204:
			//0x598c8
			func_59534();
			break;
		
		case 29002:
			//0x598d0
		case 205:
			//0x598d8
		case 208:
			//0x598dc
		case 207:
			//0x598e0
			func_59440();
			break;
		
		case 203:
			//0x598e8
		case 206:
			//0x598f0
			bData_4000318a--;
			if (bData_4000318a < 6)
			{
				bData_4000318a = 13;
			}
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x59924
		case 11102:
			//0x5992c
		case 11202:
			//0x59930
		case 22111:
			//0x59934
		case 24002:
			//0x59938
		case 25002:
			//0x5993c
		case 23022:
			//0x59940
		case 23013:
			//0x59944
		case 23014:
			//0x59948
		case 23015:
			//0x5994c
		case 23016:
			//0x59950
		case 23017:
			//0x59954
			if (bData_400034a9 == 0)
			{
				if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
				{
					//59984
					Data_40003408 = -1;
					bData_40003200 = 0;
					//->0x59a1c
				}
				else
				{
					//0x599a0
					if (bData_40002c1a == 1)
					{
						//599b0
						func_57414(1, 3, bData_40002e7d);
						//->0x59a1c
					}
					else
					{
						//0x599c8
						func_57414(3, 3, bData_40002e7d);
						//->0x59a1c
					}
				}
			}
			else
			{
				//0x599e0
				if (bData_40002c1a == 1)
				{
					//599f0
					func_57414(1, 3, bData_40002e7d);
				}
				else
				{
					//0x59a08
					func_57414(3, 3, bData_40002e7d);
				}
			}
			//-> 0x59dc4
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x59a20
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				//59a34
				Data_40003408 = -1;
				bData_40003200 = 0;
			}
			//0x59a4c -> 0x59dc4
			break;
		
		case 11101:
			//0x59a50
			dData_40002dc8 = dData_40002dc0;
		
			if (bData_40002c1a == 1)
			{
				//59a74
				func_57414(1, 3, 3);
				
				bData_40002edd = 2;
			}
			else
			{
				//0x59a94
				func_57414(3, 3, 3);
				
				bData_40002edd = 0;
			}
			//0x59ab0
			Data_40002eb0 = 1;
			bData_40003188 = 2;
			Data_40002c64_MenuContextId = 11103;
			break;
		
		case 11103:
			//0x59ad8
			if (bData_40003188 == 1)
			{
				if (bData_40002c1a == 1)
				{
					//59afc
					func_57414(1, 3, bData_40002e7d);
				}
				else
				{
					//0x59b14
					func_57414(3, 3, bData_40002e7d);
				}
			}
			//0x59b28 -> 0x59dc4
			break;
		
		case 48001:
			//0x59b2c
			func_5939c();
			break;
		
		case 41001:
			//0x59b38
			func_591b8();
			break;
		
		case 43002:
			//0x59b44
			func_58e64();
			break;
		
		case 201:
			//0x59b50
		case 202:
			//0x59b58
		case 101:
			//0x59b5c
			switch (bData_4000319a_SkyLandTargetId)
			{
				case 1:
					//0x59b98
					bData_4000319a_SkyLandTargetId = 3;
					break;
				
				case 3:
					//0x59bac
					bData_4000319a_SkyLandTargetId = 2;
					break;
				
				case 2:
					//0x59bc0
					bData_4000319a_SkyLandTargetId = 1;
					break;
				
				case 4:
					//0x59bd4
					bData_4000319a_SkyLandTargetId = 6;
					break;
				
				case 6:
					//0x59be8
					bData_4000319a_SkyLandTargetId = 5;
					break;
				
				case 5:
					//0x59bfc
					bData_4000319a_SkyLandTargetId = 4;
					break;
				
				case 7:
					//0x59c10
					bData_4000319a_SkyLandTargetId = 9;
					break;
				
				case 9:
					//0x59c24
					bData_4000319a_SkyLandTargetId = 8;
					break;
				
				case 8:
					//0x59c38
					bData_4000319a_SkyLandTargetId = 7;
					break;
				#if 0
				default:
					//0x59c4c
					break;
				#endif
			}
			break;
		
		case 47011:
			//0x59c54
			func_58dc0();
			break;
		
		case 33001:
			//0x59c60
			if (Data_40003168_LunarPhaseMonth > 0)
			{
				Data_40003168_LunarPhaseMonth--;
			}
			else
			{
				//0x59c8c
				Data_40003168_LunarPhaseMonth = 12;
			}
			break;
		
		case 34001:
			//0x59c9c
			func_58d20();
			break;
		
		case 35001:
			//0x59ca8
			func_58c60();
			break;
		
		case 360022:
			//0x59cb4
		case 370022:
			//0x59cbc
			func_58c0c();
			break;
		
		case 370023:
			//0x59cc4
			func_58b68();
			break;
		
		case 360021:
			//0x59cd0
		case 370021:
			//0x59cd8
			func_58adc();
			break;
		
		case 43011:
			//0x59ce0
			lcd_display_clear();
			func_58854();		
			//break;
		case 211001:
			//0x59cf0
			switch (bData_40003262)
			{
				case 1:
					//59d00
					func_58620();
					break;
				
				default:
					break;
			}
			break;
		
		case 28001:
			//0x59d1c
			switch (bData_40003263)
			{
				case 1:
					//0x59d3c
				case 3:
					//0x59d44
					func_583dc();
					break;
								
				default:
					//0x59d4c
					break;
			}
			break;
		
		case 42001:
			//0x59d5c
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42002;
				bData_40002c6a = 0;
			}
			//0x59d88
			break;
		
		case 42002:
			//0x59d8c
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42001;
				bData_40002c6a = 1;
			}
			break;
		
		default:
			//0x59dbc
			break;
	}
}

