

/* 52898 - todo */
void HandleEnterKey(void)
{
	switch (Data_40002c64)
	{
		case 0:
			//0x52e68
			if (Data_40004128.bData_364 == 0)
			{
				//52e7c
				func_c8f4();
			}
			else
			{
				//0x52e84
				Data_40002c64 = 1000; //Telescope Align
			}
			//->0x563b8
			break;
		
		case 3:
			//0x52e94
			break;
		
		case 101:
			//0x52eb8
			break;
		
		case 102:
			//0x52ed0
			break;
		
		case 1:
			//0x53164
			break;
		
		case 1000:
			//0x53698
			break;
		
		case 2000:
			//0x536d0
			break;
		
		case 3000:
			//0x53708
			break;
		
		case 4000:
			//0x53740
			break;
		
		case 3600:
			//0x53778
			break;
		
		case 3700:
			//0x53798
			break;
		
		case 3800: //Display Illumination
			//0x537b8
			Data_40002c64 = 380011;
			//->0x563b8
			break;
		
		case 4600:
			//0x537e0
			break;
		
		case 4700:
			//0x538b4
			break;
		
		case 1100:
			//0x538c8
			Data_40002c5c = 1;
			bData_40002c60 = 1;
			bData_40002c61 = 1;
			bData_40002c62 = 0;
		
			bData_400034a8 = func_58ec(func_7f30(1, 0, Data_40004128.dData_48), 
				Data_40004128.dData_56,
				(void*)Data_40004a68, Data_40003a14, Data_40003b2c); 
		
			Data_40002c64 = 12001;
			//->0x563b8
			break;
		
		case 1200:
			//0x53960
			Data_40002c5c = 2;
			bData_40002c60 = 1;
			bData_40002c61 = 1;
			bData_40002c62 = 0;
		
			bData_400034a8 = func_58ec(func_7f30(1, 0, Data_40004128.dData_48), 
				Data_40004128.dData_56,
				(void*)Data_40004a68, Data_40003a14, Data_40003b2c); 
		
			Data_40002c64 = 12001;
			//->0x563b8
			break;
		
		case 1300:
			//0x539fc
			break;
		
		case 12001:
			//0x53b68
			break;
		
		case 1400:
			//0x53f94
			break;
		
		case 1401:
			//0x53fd4
			break;
		
		case 1402:
			//0x53ffc
			break;
		
		case 1403:
			//0x54064
			break;
		
		case 1500:
			//0x54080
			break;
		
		case 1600:
			//0x54094
			break;
		
		case 11102:
			//0x540a8
			break;
		
		case 11103:
			//0x540bc
			break;
		
		case 11101:
			//0x54200
			break;
		
		case 1700:
			//0x54270
			break;
		
		case 11202:
			//0x54284
			break;
		
		case 11203:
			//0x54298
			break;
		
		case 11201:
			//0x54338
			break;
		
		case 2100:
			//0x543a8
			break;
		
		case 22001:
			//0x543d8
			break;
		
		case 22112:
			//0x544a8
			break;
		
		case 2200:
			//0x5454c
			break;
		
		case 24001:
			//0x5457c
			break;
		
		case 2300:
			//0x5461c
			break;
		
		case 25001:
			//0x5464c
			break;
		
		case 2400:
			//0x546ec
			break;
		
		case 23012:
			//0x54728
			break;
		
		case 23002: //???
			//0x54740
			break;
		
		case 2500:
			//0x548e4
			break;
		
		case 23003:
			//0x5491c
			break;
		
		case 2600:
			//0x549bc
			break;
		
		case 23004:
			//0x549f4
			break;
		
		case 2700:
			//0x54a94
			break;
		
		case 23005:
			//0x54acc
			break;
		
		case 2800:
			//0x54b6c
			break;
		
		case 23006:
			//0x54ba4
			break;
		
		case 2900:
			//0x54c48
			break;

		case 23007:
			//0x54c80
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);

			dData_40002cc8 = Data_40003358_SAORecord.fData_0;
			dData_40002d10 = Data_40003358_SAORecord.fData_4;
			bData_40002e88 = 1;
			
			func_b64c(dData_40002cc8, dData_40002d10);
			
			bData_40002f0d = 9;
			Data_40002f10 = Data_40002ec4_SAONr;
			
			func_268c(bData_40002f0d, Data_40002f10);
			func_394();
			
			Data_40002c64 = 23017;
			//->0x563b8
		
		case 2110:
			//0x54d20
			break;
		
		case 201:
			//0x54d40
			break;
		
		case 203:
			//0x54d64
			break;
		
		case 204:
			//0x54d6c
			break;
		
		case 205:
			//0x54d70
			break;
		
		case 2120:
			//0x54d84
			break;
		
		case 29001:
			//0x54da8
			break;
		
		case 29002:
			//0x54db4
			break;
		
		case 2130:
			//0x54dc0
			break;
		
		case 202:
			//0x54de0
			break;
		
		case 206:
			//0x54e04
			break;
		
		case 207:
			//0x54e0c
			break;
		
		case 208:
			//0x54e10
			break;
		
		case 4400:
			//0x54e24
			break;
		
		case 45001:
			//0x54e38
			break;
		
		case 45002:
			//0x54f98
			break;
		
		case 4500:
			//0x54fc4
			break;
		
		case 46001:
			//0x54fd8
			break;
		
		case 46002:
			//0x54ff8
			break;
		
		case 4800:
			//0x55018
			break;
		
		case 49001: //???
			//0x5502c
			break;
		
		case 49002:
			//0x55084
			break;
		
		case 49003:
			//0x550dc
			break;
		
		case 49004:
			//0x55134
			break;
		
		case 49005:
			//0x5518c
			break;
		
		case 4801:
			//0x551e4
			break;
		
		case 4802:
			//0x5521c
			break;
		
		case 4803:
			//0x55254
			break;
		
		case 4804:
			//0x55288
			break;
		
		case 4805:
			//0x552d0
			break;
		
		case 48001:
			//0x552e4
			break;
		
		case 48051: //???
			//0x55364
			break;
		
		case 48052:
			//0x55490
			break;
		
		case 48053:
			//0x554bc
			break;
		
		case 48054:
			//0x554e8
			break;
		
		case 48055:
			//0x55514
			break;
		
		case 48056:
			//0x55540
			break;
		
		case 48057:
			//0x5556c
			break;
		
		case 48058:
			//0x55598
			break;
		
		case 3900:
			//0x555c4
			break;
		
		case 3100:
			//0x555e8
			break;
		
		case 41001:
			//0x556d8
			break;
		
		case 42001:
			//0x5589c		
		case 42002: //????
			//0x558a4
			if (bData_40002f1e == 1)
			{
				Data_40002c64 = 4301;
			}
			else
			{
				func_7950(1);
				Data_40002c64 = 4200; //Daylight Saving?
			}
			break;
		
		case 4301:
			//0x558dc
			break;
		
		case 43011:
			//0x5590c
			break;
		
		case 4302:
			//0x55a08
			break;
		
		case 43002: //????
			//0x55d84
			func_5104c();
			break;
		
		case 4900:
			//0x55d90
			Data_40002c64 = 100;
			break;
		
		case 100:
			//0x55da4
			break;
		
		case 47011: //????
			//0x55db0
			break;
		
		case 3200:
			//0x55dbc
			Data_40002c64 = 29001;
			bData_4000318a = 6;
			func_50048();
			bData_40003162 = 1;
			break;
		
		case 32001:
			//0x55dec
			break;
		
		case 3300:
			//0x55e00
			Data_40002c64 = 33001;
			func_50018();
			break;
		
		case 3400: //Timer
			//0x55e18
			if (Data_40003214 != 0)
			{
				Data_40002c64 = 34002;
			}
			else
			{
				//0x55e3c
				Data_40002c64 = 34001;
				bData_4000318a = 1;
			}
			break;
			
		case 34001:
			//0x55e58
			break;
			
		case 34002:
			//0x55ec0
			break;
			
		case 3500:
			//0x55ee0
			break;
		
		case 35001:
			//0x55f20
			break;
		
		case 35002:
			//0x55f2c
			break;
		
		case 3601:
			//0x55f4c
			break;
		
		case 360021:
			//0x55f60
			break;
		
		case 360022:
			//0x55f68
			break;
		
		case 370021:
			//0x56048
			break;
		
		case 370022:
			//0x56050
			break;
		
		case 370023:
			//0x56054
			break;
		
		case 360023:
			//0x562f8
			break;
		
		case 3801:
			//0x5634c
			break;
		
		case 380011:
			//0x56360
			break;
		
		case 3802:
			//0x5636c
			break;
		
		//TODO
	}	
}

