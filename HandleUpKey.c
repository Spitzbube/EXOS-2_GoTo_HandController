

/* 5d1ac - todo */
void HandleUpKey(void)
{
	switch (Data_40002c64)
	{
		//TODO
		
		case 500:
			//0x5d914: Main Screen Help Pages
			if (bData_40002c59_MainScreenHelpPage == 1)
			{
				bData_40002c59_MainScreenHelpPage = 10;
			}
			else
			{
				bData_40002c59_MainScreenHelpPage--;
			}
			//->0x5f0b4
			break;
			
		case 1200:
			//0x5d9e4
			func_5a57c(0, 11);
			Data_40002c64 = 1100;
			//->0x5f0b4
			break;
		
		//TODO
		
		case 380011:
			//0x5edfc: Background light
			if (Data_40003248_CurrentDisplayPWM == 0)
			{
				//5ee10
				setDisplayPWM(63);
				Data_40003248_CurrentDisplayPWM = 63;
			}
			else if (Data_40003248_CurrentDisplayPWM == 63)
			{
				//5ee38
				setDisplayPWM(127);
				Data_40003248_CurrentDisplayPWM = 127;
			}
			else if (Data_40003248_CurrentDisplayPWM == 127)
			{
				//5ee38
				setDisplayPWM(191);
				Data_40003248_CurrentDisplayPWM = 191;
			}
			else
			{
				//0x5ee78
				setDisplayPWM(255);
				Data_40003248_CurrentDisplayPWM = 255;
			}
			//->0x5f0b4
			break;
	}
}
