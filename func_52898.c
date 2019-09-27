

/* 52898 - todo */
void func_52898(void)
{
	//TODO
	
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
}

