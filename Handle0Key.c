
extern double func_7f30(int a, int b, double sp192);

/* 69348 - todo */
void Handle0Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x6958c
			if (bData_400034a9 == 0)
			{
				if (bData_40002e7a == 0)
				{
					if (bData_40002e89 == 0)
					{
						bData_40002e89 = 1;
						
						func_b4f0();
						//->0x69780
					}
					else
					{
						//0x695d4
						bData_40002e89 = 0;

						func_acdc(dData_40002dc0 + dData_400033e8,
							dData_40002df8 + dData_400033f0,
							&dData_40002c88, &dData_40002c90);
						
						func_b64c(dData_40002c88, dData_40002c90);
						
						bData_400034cc = 1;
						
						func_b594();
						//->0x69780
					}
				} //if (bData_40002e7a == 0)
				else
				{
					//0x69658
					if (bData_40002e89 == 0)
					{
						bData_40002e89 = 1;
						
						func_b4f0();
						//->0x69780
					}
					else
					{
						//0x6967c
						bData_40002e89 = 0;
						dData_40002c90 = dData_40002d98;
						
						dData_40002c88 = func_7f30(1, 0, Data_40004128.geographicLongitude) - 
							dData_40002d78;
						
						dData_40002c88 += dData_400033e8;
						//->0x6970c
						while (dData_40002c88 >= 24)
						{
							dData_40002c88 -= 24;
						}
						
						while (dData_40002c88 < 0)
						{
							dData_40002c88 += 24;
						}
						
						func_b64c(dData_40002c88, dData_40002c90);
						
						bData_400034cc = 1;
						
						func_b594();
					}
				}
			} //if (bData_400034a9 == 0)
			//0x69780 -> 0x6a0d4
			break;
		
		case 11102:
			//0x69784
		case 11202:
			//0x6978c
		case 11103:
			//0x69790
		case 11203:
			//0x69794
			if (bData_40002e89 == 0)
			{
				bData_40002e89 = 1;
				
				func_b4f0();
			}
			else
			{
				//0x697b8
				bData_40002e89 = 0;
				
				func_b594();
			}
			//->0x6a0d4
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x697cc
			if (Data_40004128.Data_352 == 0)
			{
				Data_40004128.Data_352 = 1;
			}
			else
			{
				Data_40004128.Data_352 = 0;
			}
			break;
		
		case 101:
			//0x69800
			break;
		
		case 5000:
			//0x69834
			break;
		
		case 22111:
			//0x69848
			break;
		
		case 24002:
			//0x69850
			break;
		
		case 25002:
			//0x69854
			break;
		
		case 23022:
			//0x69858
			break;
		
		case 23013:
			//0x6985c
			break;
		
		case 23014:
			//0x69860
			break;
		
		case 23015:
			//0x69864
			break;
		
		case 23016:
			//0x69868
			break;
		
		case 23017:
			//0x6986c
			break;
		
		case 23012:
			//0x698b4
		case 23002:
			//0x698bc
			break;
		
		case 23003:
			//0x6993c
		
		case 23004:
			//0x699c8
			break;
		
		case 23005:
			//0x69a54
			break;
		
		case 23006:
			//0x69ae0
			break;
		
		case 23007:
			//0x69b64
			break;
		
		case 29001:
			//0x69bf0
			break;
		
		case 204:
			//0x69bf8
			break;
		
		case 207:
			//0x69c2c
			break;
		
		case 29002:
			//0x69c64
			break;
		
		case 205:
			//0x69c6c
			break;
		
		case 208:
			//0x69c70
			break;
		
		case 203:
			//0x69d30
			break;
		
		case 206:
			//0x69d38
			break;
		
		case 48001:
			//0x69e54
			break;
		
		case 41001:
			//0x69f18
			break;
		
		case 43002:
			//0x69f90
			break;
		
		case 47011:
			//0x69fa0
			break;
		
		case 34001:
			//0x69fb0
			break;
		
		case 35001:
			//0x69fe8
			break;
		
		case 360021:
			//0x6a020
			break;
		
		case 370021:
			//0x6a028
			break;
		
		case 360022:
			//0x6a05c
			break;
		
		case 370022:
			//0x6a064
			break;
		
		case 370023:
			//0x6a098
			break;
		
		case 211001:
			//0x6a0bc
			break;
		
		default:
			//0x6a0cc
			break;
	}
}

