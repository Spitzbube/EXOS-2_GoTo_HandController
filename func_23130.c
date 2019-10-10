

/* 22060 - todo */
void func_22060(int a, float* b, float* c)
{
	switch (a)
	{
		case 0:
			//0x220a4
			*b = dData_400032d0;
			*c = dData_400032d8;
			Data_4000314c = "Mercury                ";
			Data_40003140 = Data_40000380;
			//->0x22450
			break;
		
		case 1:
			//0x220e4
			*b = dData_400032e0;
			*c = dData_400032e8;
			Data_4000314c = "Venus                    ";
			Data_40003140 = Data_4000038a;
			//->0x22450
			break;
		
		case 2:
			//0x22124
			*b = dData_400032f0;
			*c = dData_400032f8;
			Data_4000314c = "Mars                      ";
			Data_40003140 = Data_40000394;
			//->0x22450
			break;
		
		case 3:
			//0x22164
			*b = dData_40003300;
			*c = dData_40003308;
			Data_4000314c = "Jupiter                  ";
			Data_40003140 = Data_4000039e;
			//->0x22450
			break;
		
		case 4:
			//0x221a4
			*b = dData_40003310;
			*c = dData_40003318;
			Data_4000314c = "Saturn                     ";
			Data_40003140 = Data_400003a8;
			//->0x22450
			break;
		
		case 5:
			//0x221e4
			*b = dData_40003320;
			*c = dData_40003328;
			Data_4000314c = "Uranus                      ";
			Data_40003140 = Data_400003b2;
			//->0x22450
			break;
		
		case 6:
			//0x22224
			*b = dData_40003330;
			*c = dData_40003338;
			Data_4000314c = "Neptune                       ";
			Data_40003140 = Data_400003ba;
			//->0x22450
			break;
		
		case 7:
			//0x22388
			*b = dData_40003340;
			*c = dData_40003348;
			Data_4000314c = "Pluto                      ";
			Data_40003140 = Data_400003c2;
			//->0x22450
			break;
		
		case 8:
			//0x223c8
			*b = dData_400032b0;
			*c = dData_400032b8;
			Data_4000314c = "Sun                     ";
			Data_40003140 = Data_400003ca;
			//->0x22450
			break;
		
		case 9:
			//0x22408
			*b = dData_400032c0;
			*c = dData_400032c8;
			Data_4000314c = "Moon                       ";
			Data_40003140 = Data_400003d4;
			//->0x22450
			break;
		
		default:
			//0x22448
			break;
	}
}

/* 23130 - todo */
void func_23130(void)
{
	switch (bData_40003196)
	{
		case 1:
			//0x2315c
			bData_40003197 = 1;
			break;
		
		case 2:
			//0x23170
			bData_40003197 = 2;
			break;
		
		case 3:
			//0x23184
			bData_40003197 = 2;
			break;
		
		case 4:
			//0x23198
			bData_40003197 = 2;
			break;
		
		case 5:
			//0x231ac
			bData_40003197 = 2;
			break;
		
		default:
			//0x231c0
			break;
	}
}

/* 240e8 - todo */
void func_240e8(unsigned char a, int b)
{
	switch (a)
	{
		case 1:
			//0x24134
			bData_40002eb5 = b;
			
			func_22060(bData_40002eb5, &fData_40002cd0, &fData_40002d18);
		
			for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
			{
				//0x24164
				Data_4000410e[bData_40002f1d] = Data_4000314c[bData_40002f1d];
			}
			//->0x24568
			break;
		
		case 2:
			//0x241b0
			bData_40002ece = b;
		
			func_38dc(bData_40002ece, &Data_40003dd4);
		
			sprintf(Data_4000410e, "Constellation %d          ", bData_40002ece);
			//->0x24568
			break;
		
		case 3:
			//0x241e4
			bData_40002ed2 = b;
		
			func_34e4(bData_40002ed2, &Data_40003d94);

			for (bData_40002f1d = 0; bData_40002f1d < 13; bData_40002f1d++)
			{
				//0x24210
				Data_4000410e[bData_40002f1d] = Data_40003db0[bData_40002f1d+1];
			}
			//->0x24568
			break;
		
		case 4:
			//0x2425c
			wData_40002eb8_MessierNr = b; 
		
			func_3b58(wData_40002eb8_MessierNr & 0xFF, &Data_40003e08);
		
			sprintf(Data_4000410e, "Messier %d                  ", wData_40002eb8_MessierNr);
			//->0x24568
			break;
		
		case 5:
			//0x24290	
			wData_40002eba_NGCNr = b; 
		
			func_4894(wData_40002eba_NGCNr, &Data_40003ee0);
		
			sprintf(Data_4000410e, "NGC %d                        ", wData_40002eba_NGCNr);
			//->0x24568
			break;
		
		case 6:
			//0x242c4
			wData_40002ebc_ICNr = b; 
		
			func_4594(wData_40002ebc_ICNr, &Data_40003ec0);
		
			sprintf(Data_4000410e, "IC %d                         ", wData_40002ebc_ICNr);
			//->0x24568
			break;
		
		case 7:
			//0x242f8
			wData_40002ebe_ShNr = b; 
		
			func_435c(wData_40002ebe_ShNr, &Data_40003350);
		
			sprintf(Data_4000410e, "Sh %d                           ", wData_40002ebe_ShNr);
			//->0x24568
			break;
		
		case 8:
			//0x2432c
			wData_40002ec0 = b; 
		
			func_4028(wData_40002ec0 & 0xFF, &Data_40003ea0);

			sprintf(Data_4000410e, "Bright %d                         ", wData_40002ec0);
			//->0x24568
			break;
		
		case 9:
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


