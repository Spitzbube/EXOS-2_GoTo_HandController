
/* 5969c - todo */
void HandleLeftKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 204:
			//0x598c8
			break;
		
		case 205:
			//0x598d8
			break;
		
		case 208:
			//0x598dc
			break;
		
		case 207:
			//0x598e0
			break;
		
		case 203:
			//0x598e8
			break;
		
		case 206:
			//0x598f0
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x59924
			break;
		
		case 11202:
			//0x59930
			break;
		
		case 23022:
			//0x59940
			break;
		
		case 23013:
			//0x59944
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
			break;
		
		case 201:
			//0x59b50
			break;
		
		case 202:
			//0x59b58
			break;
		
		case 101:
			//0x59b5c
			break;
		
		default:
			//0x59dbc
			break;
	}
}

