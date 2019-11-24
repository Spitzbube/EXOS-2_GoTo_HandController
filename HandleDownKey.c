
/* 5ab50 - todo */
void HandleDownKey(void)
{
	switch (Data_40002c64)
	{
		case 1:
			//0x5b27c
			if (bData_4000316e_FocusLineOn8LineDisplay == bData_40002f14_RecentTargetCount)
			{
				bData_4000316e_FocusLineOn8LineDisplay = 1;
			}
			else
			{
				bData_4000316e_FocusLineOn8LineDisplay++;
			}
			//->0x5ca8c
			break;
		
		case 500:
			//0x5b2c0: Main Screen Help Pages
			func_394();
		
			if (bData_40002c59_MainScreenHelpPage == 10)
			{
				bData_40002c59_MainScreenHelpPage = 1;
			}
			else
			{
				bData_40002c59_MainScreenHelpPage++;
			}
			//->0x5ca8c
			break;
			
		case 1000:
			//0x5b300: Telescope Align
			Data_40002c64 = 2000; //Navigation
			//->0x5ca8c
			break;
		
		case 2000:
			//0x5b314
			Data_40002c64 = 3000;
			break;
		
		case 3000:
			//0x5b328
			Data_40002c64 = 4000;
			break;
		
		case 4000:
			//0x5b33c
			Data_40002c64 = 1000;
			break;
		
		case 1100:
			//0x5b350
			func_5a57c(1, 11);
			Data_40002c64 = 1200;
			break;
		
		case 1200:
			//0x5b370
			func_5a57c(1, 11);
			Data_40002c64 = 1300;
			break;
		
		case 1300:
			//0x5b390
			func_5a57c(1, 11);
			Data_40002c64 = 1400;
			break;
		
		case 1400:
			//0x5b3b0
			func_5a57c(1, 11);
			Data_40002c64 = 1500;
			break;
		
		case 1500:
			//0x5b3d0
			func_5a57c(1, 11);
			Data_40002c64 = 1600;
			break;
		
		case 1600:
			//0x5b3f0
			func_5a57c(1, 11);
			Data_40002c64 = 1700;
			break;
		
		case 1700:
			//0x5b410: DEC Bklash Correction
			bData_40003173 = 1;
			bData_40003171 = 1;
			bData_40003172 = 1;
			bData_40003170 = 1;
			Data_40002c64 = 1100; //One star align
			break;
		
		case 2100:
			//0x5b448
			func_5a57c(1, 12);
			Data_40002c64 = 2200;
			break;
		
		case 2200:
			//0x5b468
			func_5a57c(1, 12);
			Data_40002c64 = 2300;
			break;
		
		case 2300:
			//0x5b488
			func_5a57c(1, 12);
			Data_40002c64 = 2400;
			break;
		
		case 2400:
			//0x5b4a8
			func_5a57c(1, 12);
			Data_40002c64 = 2500;
			break;
		
		case 2500:
			//0x5b4c8
			func_5a57c(1, 12);
			Data_40002c64 = 2600;
			break;
		
		case 2600:
			//0x5b4e8
			func_5a57c(1, 12);
			Data_40002c64 = 2700;
			break;
		
		case 2700:
			//0x5b508
			func_5a57c(1, 12);
			Data_40002c64 = 2800;
			break;
		
		case 2800:
			//0x5b528
			func_5a57c(1, 12);
			Data_40002c64 = 2900;
			break;
		
		case 2900:
			//0x5b548
			func_5a57c(1, 12);
			Data_40002c64 = 2110;
			break;
		
		case 2110:
			//0x5b568
			func_5a57c(1, 12);
			Data_40002c64 = 2120;
			break;
		
		case 2120:
			//0x5b588
			func_5a57c(1, 12);
			Data_40002c64 = 2130;
			break;
		
		case 2130:
			//0x5b5a8
			bData_40003177 = 1;
			bData_40003175 = 1;
			bData_40003176 = 1;
			bData_40003174 = 1;
			Data_40002c64 = 2100;
			break;
		
		case 3100:
			//0x5b5e0
			func_5a57c(1, 13);
			Data_40002c64 = 3200;
			break;
		
		case 3200:
			//0x5b600
			func_5a57c(1, 13);
			Data_40002c64 = 3300;
			break;
		
		case 3300:
			//0x5b620
			func_5a57c(1, 13);
			Data_40002c64 = 3400;
			break;
		
		case 3400:
			//0x5b640
			func_5a57c(1, 13);
			Data_40002c64 = 3500;
			break;
		
		case 3500:
			//0x5b660
			func_5a57c(1, 13);
			Data_40002c64 = 3600;
			break;
		
		case 3600:
			//0x5b680
			func_5a57c(1, 13);
			Data_40002c64 = 3700;
			break;
		
		case 3700:
			//0x5b6a0
			func_5a57c(1, 13);
			Data_40002c64 = 3800;
			break;
		
		case 3800:
			//0x5b6c0
			func_5a57c(1, 13);
			Data_40002c64 = 3900;
			break;
		
		case 3900:
			//0x5b6e0
			bData_4000317b = 1;
			bData_40003179 = 1;
			bData_4000317a = 1;
			bData_40003178 = 1;
			Data_40002c64 = 3100;
			break;
		
		case 4100:
			//0x5b718
			func_5a57c(1, 14);
			Data_40002c64 = 4200;
			break;
		
		case 4200:
			//0x5b738
			func_5a57c(1, 14);
			Data_40002c64 = 4300;
			break;
		
		case 4300:
			//0x5b758
			func_5a57c(1, 14);
			Data_40002c64 = 4400;
			break;
		
		case 4400:
			//0x5b778
			func_5a57c(1, 14);
			Data_40002c64 = 4500;
			break;
		
		case 4500:
			//0x5b798
			func_5a57c(1, 14);
			Data_40002c64 = 4600;
			break;
		
		case 4600:
			//0x5b7b8
			func_5a57c(1, 14);
			Data_40002c64 = 4700;
			break;
		
		case 4700:
			//0x5b7d8
			func_5a57c(1, 14);
			Data_40002c64 = 4800;
			break;
		
		case 4800:
			//0x5b7f8
			func_5a57c(1, 14);
			Data_40002c64 = 4900;
			break;
		
		case 4900:
			//0x5b818
			bData_4000317f = 1;
			bData_4000317d = 1;
			bData_4000317e = 1;
			bData_4000317c = 1;
			Data_40002c64 = 4100;
			break;
		
		case 1402:
			//0x5b850
			Data_40002c64 = 1403;
			break;
		
		case 1403:
			//0x5b864
			Data_40002c64 = 1402;
			break;
		
		case 22011:
			//0x5b878
			bData_40003182 = 1;
			bData_40003180 = 1;
			Data_40002c64 = 2201;
			break;
		
		case 2301:
			//0x5b8a0
			Data_40002c64 = 2302;
			break;
		
		case 2302:
			//0x5b8c0
			Data_40002c64 = 2303;
			break;
		
		case 2303:
			//0x5b8e0
			func_5a57c(1, 23);
			Data_40002c64 = 2304;
			break;
		
		case 2304:
			//0x5b900
			func_5a57c(1, 23);
			Data_40002c64 = 2305;
			break;
		
		case 2305:
			//0x5b920
			func_5a57c(1, 23);
			Data_40002c64 = 2306;
			break;
		
		case 2306:
			//0x5b940
			func_5a57c(1, 23);
			Data_40002c64 = 2307;
			break;
		
		case 2307:
			//0x5b960
			func_5a57c(1, 23);
			Data_40002c64 = 2308;
			break;
		
		case 2308:
			//0x5b980
			bData_40003186 = 1;
			bData_40003184 = 1;
			Data_40002c64 = 2301;
			break;
		
		case 2501:
			//0x5b9a8
			Data_40002c64 = 2502;
			break;
		
		case 2502:
			//0x5b9bc
			Data_40002c64 = 2503;
			break;
		
		case 2503:
			//0x5b9d0
			Data_40002c64 = 2501;
			break;
		
		case 2801:
			//0x5b9e4
			Data_40002c64 = 2802;
			break;
		
		case 2802:
			//0x5b9f8
			Data_40002c64 = 2803;
			break;
		
		case 2803:
			//0x5ba0c
			Data_40002c64 = 2804;
			break;
		
		case 2804:
			//0x5ba20
			Data_40002c64 = 2801;
			break;
		
		case 21101:
			//0x5ba34
			Data_40002c64 = 21102;
			break;
		
		case 21102:
			//0x5ba48
			Data_40002c64 = 21103;
			break;
		
		case 21103:
			//0x5ba5c
			Data_40002c64 = 21101;
			break;
		
		case 3601:
			//0x5ba70
			Data_40002c64 = 3602;
			break;
		
		case 3602:
			//0x5ba84
			Data_40002c64 = 3601;
			break;
		
		case 3801:
			//0x5ba98
			Data_40002c64 = 3802;
			break;
		
		case 3802:
			//0x5baac
			Data_40002c64 = 3801;
			break;
		
		case 4301:
			//0x5bbc0
			Data_40002c64 = 4302;
			break;
		
		case 4302:
			//0x5bbd4
			Data_40002c64 = 4301;
			break;
		
		case 4801:
			//0x5bbe8
			Data_40002c64 = 4802;
			break;
		
		case 4802:
			//0x5bbfc
			Data_40002c64 = 4803;
			break;
		
		case 4803:
			//0x5bc10
			Data_40002c64 = 4804;
			break;
		
		case 4804:
			//0x5bc24
			Data_40002c64 = 4805;
			break;
		
		case 4805:
			//0x5bc38
			Data_40002c64 = 4801;
			break;
		
		case 48051:
			//0x5bc4c
			Data_40002c64 = 48052;
			break;
		
		case 48052:
			//0x5bc60
			Data_40002c64 = 48053;
			break;
		
		case 48053:
			//0x5bc74
			Data_40002c64 = 48054;
			break;
		
		case 48054:
			//0x5bc88
			Data_40002c64 = 48055;
			break;
		
		case 48055:
			//0x5bc9c
			Data_40002c64 = 48056;
			break;
		
		case 48056:
			//0x5bcb0
			Data_40002c64 = 48057;
			break;
		
		case 48057:
			//0x5bcc4
			Data_40002c64 = 48058;
			break;
		
		case 48058:
			//0x5bcd8
			Data_40002c64 = 48051;
			break;
		
		case 0:
			//0x5bcec
		case 11102:
			//0x5bcf4
		case 11202:
			//0x5bcf8
		case 22111:
			//0x5bcfc
		case 24002:
			//0x5bd00
		case 25002:
			//0x5bd04
		case 23022:
			//0x5bd08
		case 23013:
			//0x5bd0c
		case 23014:
			//0x5bd10
		case 23015:
			//0x5bd14
		case 23016:
			//0x5bd18
		case 23017:
			//0x5bd1c
		
			//TODO
		
			break;
		
		case 11201:
			//0x5bde8
			break;
		
		case 11203:
			//0x5be6c
			break;
		
		case 45001:
			//0x5beb8
			break;
		
		case 45002:
			//0x5becc
			break;
		
		case 46001:
			//0x5bee0
			break;
		
		case 46002:
			//0x5bef4
			break;
		
		case 49001:
			//0x5bf08
			break;
		
		case 49002:
			//0x5bf1c
			break;
		
		case 49003:
			//0x5bf30
			break;
		
		case 49004:
			//0x5bf44
			break;
		
		case 49005:
			//0x5bf58
			break;
		
		case 21001:
			//0x5bf6c
			break;
		
		case 22001:
			//0x5bfb4
			break;
		
		case 31001:
			//0x5bfc0
			break;
		
		case 24001:
			//0x5bff4
			break;
		
		case 25001:
			//0x5c030
			break;
		
		case 23012:
			//0x5c06c
			break;
		
		case 23002:
			//0x5c074
			break;
		
		case 23003:
			//0x5c0b0
			break;
		
		case 23004:
			//0x5c0f4
			break;
		
		case 23005:
			//0x5c138
			break;
		
		case 23006:
			//0x5c17c
			break;
		
		case 23007:
			//0x5c1bc
			break;
		
		case 203:
			//0x5c1fc
			break;
		
		case 204:
			//0x5c21c
			break;
		
		case 205:
			//0x5c23c
			break;
		
		case 201:
			//0x5c25c
			break;
		
		case 202:
			//0x5c264
			break;
		
		case 101:
			//0x5c268
			break;
		
		case 29001:
			//0x5c360
		
		case 29002:
			//0x5c380
			break;
		
		case 206:
			//0x5c3a0
			break;
		
		case 207:
			//0x5c3c0
			break;
		
		case 208:
			//0x5c3e0
			break;
		
		case 41001:
			//0x5c400
			break;
		
		case 43021:
			//0x5c440
			break;
		
		case 43022:
			//0x5c454
			break;
		
		case 43023:
			//0x5c468
			break;
		
		case 43024:
			//0x5c47c
			break;
		
		case 43002:
			//0x5c490
			break;
		
		case 47011:
			//0x5c4e4
			break;
		
		case 33001:
			//0x5c558
			break;
		
		case 12001:
			//0x5c674
			break;
		
		case 360021:
			//0x5c6e4
			break;
		
		case 360022:
			//0x5c704
			break;
		
		case 370021:
			//0x5c724
			break;
		
		case 370022:
			//0x5c744
			break;
		
		case 370023:
			//0x5c764
			break;
		
		case 360111:
			//0x5c784
			break;
		
		case 360112:
			//0x5c798
			break;
		
		case 360113:
			//0x5c7ac
			break;
		
		case 380011:
			//0x5c7c0
			break;
		
		case 43011:
			//0x5c854
			break;
		
		case 211001:
			//0x5c864
			break;
		
		case 28001:
			//0x5c93c
			break;
		
		case 42001:
			//0x5ca24
			break;
		
		case 42002:
			//0x5ca54
			break;
	}
}

