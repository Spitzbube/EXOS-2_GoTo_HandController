
/* 5f230 - todo */
void HandleMinusKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 1:
			//0x5f9e0
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 5000:
			//0x5f9f4
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 101:
			//0x5fa08
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 102:
			//0x5fa1c
			Data_40002c64_MenuContextId = 101;
			break;
		
		case 3:
			//0x5fa30
			bData_40003210 = 1;
			bData_40003211 = 0;
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 12001:
			//0x5fa58: One / Two / Three Star Align
			if (bData_40002c62 != 0)
			{
				//5fa6c
				Data_40004128.bData_364 = 1;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7e8(0, 1, 1, 21, "                     ");
				func_7e8(0, 2, 1, 21, "                     ");
				func_7e8(0, 3, 1, 21, "                     ");
				func_7e8(0, 4, 1, 21, "This Align Canceled  ");
				func_7e8(0, 5, 1, 21, "                     ");
				func_7e8(0, 6, 1, 21, "                     ");
				func_7e8(0, 7, 1, 21, "                     ");
				func_7e8(0, 8, 1, 21, "                     ");
				
				func_659c(1000);
				func_7950(2);
				func_659c(100);
				
				Data_40002c64_MenuContextId = 0;
			}
			else
			{
				//0x5fb8c
				switch (Data_40002c5c)
				{
					case 1:
						//0x5fbb0
						Data_40002c64_MenuContextId = 1100;
						break;
					
					case 2:
						//0x5fbc4
						Data_40002c64_MenuContextId = 1200;
						break;
					
					case 3:
						//0x5fbd8
						Data_40002c64_MenuContextId = 1300;
						break;
					
					default:
						//0x5fbec
						break;
				}
			}
			//->0x60d48
			break;
		
		case 1000:
			//0x5fbfc
			Data_40002c64_MenuContextId = 0;
			//->0x60d48
			break;
		
		case 2000:
			//0x5fc10
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 3000:
			//0x5fc24
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 4000:
			//0x5fc38
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 1100:
			//0x5fc4c
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case 1200:
			//0x5fc60
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case 1300:
			//0x5fc74
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case 1400:
			//0x5fc88
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case 1500:
			//0x5fc9c
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case 1600:
			//0x5fcb0
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case 1700:
			//0x5fcc4
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case 2100:
			//0x5fcd8
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2200:
			//0x5fcec
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2300:
			//0x5fd00
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2400:
			//0x5fd14
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2500:
			//0x5fd28
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2600:
			//0x5fd3c
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2700:
			//0x5fd50
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2800:
			//0x5fd64
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2900:
			//0x5fd78
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2110:
			//0x5fdd8
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2120:
			//0x5fdec
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 2130:
			//0x5fe00
			Data_40002c64_MenuContextId = 2000;
			break;
		
		case 3100:
			//0x5fe14
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3200:
			//0x5fe28
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3300:
			//0x5fe3c
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3400:
			//0x5fe50
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3500:
			//0x5fe64
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3600:
			//0x5fe78
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3700:
			//0x5fe8c
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3800:
			//0x5fea0
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 3900:
			//0x5feb4
			Data_40002c64_MenuContextId = 3000;
			break;
		
		case 4100:
			//0x5fec8
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4200:
			//0x5fedc: Daylight Saving
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4300:
			//0x5fef0
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4400:
			//0x5ff04
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4500:
			//0x5ff18
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4600:
			//0x5ff2c
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4700:
			//0x5ff40
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4800:
			//0x5ff54
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4900:
			//0x5ff68
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 1401:
			//0x5ff7c
			bData_400031ea = 0;
		case 1402:
			//0x5ff90
		case 1403:
			//0x5ff94
			Data_40002c64_MenuContextId = 1400; //->Target Sync
			break;
		
		case 2801:
			//0x5ffa4
			Data_40002c64_MenuContextId = 2110; //->User-def Object
			break;
		
		case 2802:
			//0x5ffb8
			Data_40002c64_MenuContextId = 2110;
			break;
		
		case 2803:
			//0x5ffcc
			Data_40002c64_MenuContextId = 2110;
			break;
		
		case 2804:
			//0x5ffe0
			Data_40002c64_MenuContextId = 2110;
			break;
		
		case 21101:
			//0x5fff4
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case 21102:
			//0x60008
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case 21103:
			//0x6001c
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case 34001:
			//0x60030
			Data_40002c64_MenuContextId = 3400;
			break;
		
		case 34002:
			//0x60044
			Data_40002c64_MenuContextId = 3400;
			break;
		
		case 35001:
			//0x60058
			Data_40002c64_MenuContextId = 3500;
			break;
		
		case 35002:
			//0x6006c
			Data_40002c64_MenuContextId = 3500;
			break;
		
		case 360021:
			//0x60080
		case 360022:
			//0x60088
			Data_40002c64_MenuContextId = 3700;
			break;
		
		case 370021:
			//0x60098
		case 370022:
			//0x600a0
		case 370023:
			//0x600a4
			Data_40002c64_MenuContextId = 3600;
			break;
		
		case 3602:
			//0x600b4
			Data_40002c64_MenuContextId = 3600;
			break;
		
		case 3801:
			//0x600c8
			Data_40002c64_MenuContextId = 3800;
			break;
		
		case 3802:
			//0x600dc
			Data_40002c64_MenuContextId = 3800;
			break;
		
		case 4301:
			//0x600f0
		case 4302:
			//0x600f8
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = 4300;
			}
			else
			{
				//0x60118
				Data_40002c64_MenuContextId = 42001;
			}
			break;
		
		case 4801:
			//0x60128
			Data_40002c64_MenuContextId = 4700; //->Tracking Rate
			break;
		
		case 4802:
			//0x6013c
			Data_40002c64_MenuContextId = 4700;
			break;
		
		case 4803:
			//0x60150
			Data_40002c64_MenuContextId = 4700;
			break;
		
		case 4804:
			//0x60164
			Data_40002c64_MenuContextId = 4700;
			break;
		
		case 4805:
			//0x60178
			Data_40002c64_MenuContextId = 4700;
			break;
		
		case 45001:
			//0x6018c
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case 45002:
			//0x601a0
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case 46001:
			//0x601b4
			Data_40002c64_MenuContextId = 4500;
			break;
		
		case 46002:
			//0x601c8
			Data_40002c64_MenuContextId = 4500;
			break;
		
		case 18001:
			//0x601dc
			Data_40002c64_MenuContextId = 1500;
			break;
		
		case 11102:
			//0x601f0
			Data_40002c64_MenuContextId = 1600;
			break;
		
		case 11101:
			//0x60204
			func_5f0c0();
		
			Data_40002c64_MenuContextId = 11102;
			Data_40002eb0 = 0;
			break;
		
		case 11202:
			//0x60228
			Data_40002c64_MenuContextId = 1700;
			break;
		
		case 11201:
			//0x6023c
			func_5f0c0();
		
			Data_40002c64_MenuContextId = 11202;
			Data_40002eb0 = 0;
			break;
		
		case 31001:
			//0x60260
			Data_40002c64_MenuContextId = 3100;
			break;
		
		case 26001:
			//0x60274
			Data_40002c64_MenuContextId = 2600;
			break;
		
		case 27001:
			//0x60288
			Data_40002c64_MenuContextId = 2700;
			break;
		
		case 22001:
			//0x6029c
			Data_40002c64_MenuContextId = 2100;
			break;
		
		case 22111:
			//0x602b0
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x602e0
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 22001;
			}
			else
			{
				//0x60300
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 22112:
			//0x60328
			Data_40002c64_MenuContextId = 22001;
			break;
		
		case 24001:
			//0x6033c
			Data_40002c64_MenuContextId = 2200;
			break;
		
		case 24002:
			//0x60350
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//60380
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 24001;
			}
			else
			{
				//0x603a0
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;

		case 25001:
			//0x603c8
			Data_40002c64_MenuContextId = 2300;
			break;
			
		case 25002:
			//0x603dc
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x6040c
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 25001;
			}
			else
			{
				//6042c
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 23012:
			//0x60454
			Data_40002c64_MenuContextId = 2400;
			break;
		
		case 23002:
			//0x60468
			Data_40002c64_MenuContextId = 23012;
			break;
		
		case 23022:
			//0x60480
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x604b0
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 23002;
			}
			else
			{
				//0x604d0
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 23003:
			//0x604f8
			Data_40002c64_MenuContextId = 2500;
			break;
		
		case 23013:
			//0x6050c
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x6053c
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 23003;
			}
			else
			{
				//0x6055c
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 23004:
			//0x60584
			Data_40002c64_MenuContextId = 2600;
			break;
		
		case 23014:
			//0x60598
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x605c8
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 23004;
			}
			else
			{
				//0x605e8
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 23005:
			//0x60610
			Data_40002c64_MenuContextId = 2700;
			break;
		
		case 23015:
			//0x60624
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x60654
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 23005;
			}
			else
			{
				//0x60674
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 23006:
			//0x6069c
			Data_40002c64_MenuContextId = 2800;
			break;
		
		case 23016:
			//0x606b0
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x606e0
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 23006;
			}
			else
			{
				//0x60700
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 23007:
			//0x60728
			Data_40002c64_MenuContextId = 2900;
			break;
		
		case 23017:
			//0x6073c
			bData_40003432 = 0;
		
			if ((bData_40002e8a == 5) || (bData_40002e8a == 3))
			{
				//0x6076c
				func_394();
				
				Data_40004128.bData_357 = 0;
				Data_40002c64_MenuContextId = 23007;
			}
			else
			{
				//0x6078c
				bData_40002e8a = 5;
				
				func_b4f0();
				
				bData_40002e8c = 0;
				
				func_7950(2);
			}
			//->0x60d48
			break;
		
		case 201:
			//0x607b4
			Data_40002c64_MenuContextId = 2110;
			break;
		
		case 203:
			//0x607c8
		case 204:
			//0x607d0
		case 205:
			//0x607d4
			Data_40002c64_MenuContextId = 201;
			break;
		
		case 29001:
			//0x607e4
			if (bData_40003162 == 0)
			{
				Data_40002c64_MenuContextId = 2120;
			}
			else
			{
				//0x60808
				Data_40002c64_MenuContextId = 3200;
			}
			break;
		
		case 29002:
			//0x60818
			if (bData_40003162 == 0)
			{
				Data_40002c64_MenuContextId = 2120;
			}
			else
			{
				//0x6083c
				Data_40002c64_MenuContextId = 3200;
			}
			break;
		
		case 202:
			//0x6084c
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case 206:
			//0x60860
		case 207:
			//0x60868
		case 208:
			//0x6086c
			Data_40002c64_MenuContextId = 202;
			break;
		
		case 360111:
			//0x6087c
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 360112:
			//0x60890
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 360113:
			//0x608a4
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 380011:
			//0x608b8
			Data_40002c64_MenuContextId = 3800;
			break;
		
		case 42001:
			//0x608cc
		case 42002:
			//0x608d4
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = 4200;
			}
			else
			{
				//0x608f4
				func_6518();
				
				sprintf(Data_400037ec, "%04d-%02d-%02d",
					Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
				sprintf(Data_40003150, "%02d:%02d:%02d",
					bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
				
				sprintf(Data_40002655, "%04d-%02d-%02d",
					Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
				sprintf(Data_40002660, "%02d:%02d:%02d",
					bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
				
				bData_4000318a = 1;
				bData_40002e78 = 0;
				
				Data_40002c64_MenuContextId = 41001;
			}
			//0x609bc -> 0x60d48
			break;
		
		case 211001:
			//0x609c0
			switch (bData_40003262)
			{
				case 0:
					//0x609e8
					Data_40002c64_MenuContextId = 21101;
					break;
				
				case 1:
					//0x609fc
					Data_40002c64_MenuContextId = 21102;
					break;
				
				case 2:
					//0x60a10
					Data_40002c64_MenuContextId = 21103;
					break;
				
				default:
					//0x60a24
					break;
			}
			break;
		
		case 28001:
			//0x60a34
			switch (bData_40003263)
			{
				case 0:
					//0x60a64
					Data_40002c64_MenuContextId = 2801;
					break;
				
				case 1:
					//0x60a78
					Data_40002c64_MenuContextId = 2802;
					break;
				
				case 2:
					//0x60b8c
					Data_40002c64_MenuContextId = 2803;
					break;
				
				case 3:
					//0x60ba0
					Data_40002c64_MenuContextId = 2804;
					break;
				
				default:
					//0x60bb4
					break;
				
			}
			break;
		
		case 49001:
			//0x60bc4
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49002:
			//0x60bd8
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49003:
			//0x60bec
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49004:
			//0x60c00
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49005:
			//0x60c14
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 48001:
			//0x60c28
			Data_40002c64_MenuContextId = 4804;
			break;
		
		case 48051:
			//0x60c3c
		case 48052:
			//0x60c44
		case 48053:
			//0x60c48
		case 48054:
			//0x60c4c
		case 48055:
			//0x60c50
		case 48056:
			//0x60c54
		case 48057:
			//0x60c58
		case 48058:
			//0x60c5c
			Data_40002c64_MenuContextId = 4805;
			break;
		
		case 360011: //???
			//0x60c6c
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 41001:
			//0x60c80
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = 4100;
			}
			break;
		
		case 43011:
			//0x60ca4
			Data_40002c64_MenuContextId = 4301;
			break;
		
		case 43002:
			//0x60cb8
			Data_40002c64_MenuContextId = 4302;
			break;
		
		case 100:
			//0x60ccc: Reset -> Cancel
			Data_40002c64_MenuContextId = 4900; //Reset
			break;
		
		case 47011:
			//0x60ce0
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = 4600;
			}
			else
			{
				//0x60d04
				Data_40002c64_MenuContextId = 4301;
			}
			break;
		
		case 32001:
			//0x60d14
			Data_40002c64_MenuContextId = 29001;
			break;
		
		case 33001:
			//0x60d28
			Data_40002c64_MenuContextId = 3300;
			break;
		
		default:
			//60d3c
			func_b4d0();
			break;
	}
}

