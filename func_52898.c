

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
		
			//TODO

		#if 0
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
			
			Data_40002c64 = 0x59e9; //23017
			//->0x563b8
		#endif
		
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
		
		case 3800: //Display Illumination
			//0x537b8
			Data_40002c64 = 380011;
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
		
		//TODO
	}	
}

