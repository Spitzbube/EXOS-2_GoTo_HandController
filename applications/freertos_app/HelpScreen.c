
/* 1e228 - todo */
void DisplayHelpScreen(void)
{
	if (g_iMenuContextIdNew != g_iMenuContextIdOld)
	{
		g_iMenuContextIdOld = g_iMenuContextIdNew;
	}

	switch (Data_40002c64_MenuContextId - 500)
	{
		case 0:
			//0x1e328: 500 = Main Screen Help Pages
			switch (bData_40002c59_MainScreenHelpPage)
			{
				case 1:
					//0x1e36c
					lcd_display_string(0, 1, 1, 21, "*Key:                  ");
					lcd_display_string(0, 3, 1, 21, "Press the key to cha- ");
					lcd_display_string(0, 5, 1, 21, "-nge LED illuminance. ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;

				case 2:
					//0x1e3e4
					lcd_display_string(0, 1, 1, 21, "Green Key:             ");
					lcd_display_string(0, 3, 1, 21, "Press the key to show ");
					lcd_display_string(0, 5, 1, 21, "and select hitoric    ");
					lcd_display_string(0, 7, 1, 21, "target quickly.       ");
					//->0x1eb90
					break;

				case 3:
					//0x1e580
					lcd_display_string(0, 1, 1, 21, "Red Key:               ");
					lcd_display_string(0, 3, 1, 21, "Show function menu    ");
					lcd_display_string(0, 5, 1, 21, "or Enter.             ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;

				case 4:
					//0x1e5f8
					lcd_display_string(0, 1, 1, 21, "Yellow Key:            ");
					lcd_display_string(0, 3, 1, 21, "Press the key to stop ");
					lcd_display_string(0, 5, 1, 21, "or abandon or quit.   ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;

				case 5:
					//0x1e670
					lcd_display_string(0, 1, 1, 21, "Arrow Keys:            ");
					lcd_display_string(0, 3, 1, 21, "Slew the telescope    ");
					lcd_display_string(0, 5, 1, 21, "or Scroll in menu.    ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;

				case 6:
					//0x1e6e8
					lcd_display_string(0, 1, 1, 21, "Number Keys:            ");
					lcd_display_string(0, 3, 1, 21, "Press to input digits  ");
					lcd_display_string(0, 5, 1, 21, "0 to 9, input letter   ");
					lcd_display_string(0, 7, 1, 21, "or Change slew speed.  ");
					//->0x1eb90
					break;

				case 7:
					//0x1e89c
					lcd_display_string(0, 1, 1, 21, "Stop Key:               ");
					lcd_display_string(0, 3, 1, 21, "Press to pause when    ");
					lcd_display_string(0, 5, 1, 21, "telescope in tracking, ");
					lcd_display_string(0, 7, 1, 21, "moving or slewing.     ");
					//->0x1eb90
					break;

				case 8:
					//0x1e914
					lcd_display_string(0, 1, 1, 21, "Help Key:               ");
					lcd_display_string(0, 3, 1, 21, "Show help file         ");
					lcd_display_string(0, 5, 1, 21, "can be used in all     ");
					lcd_display_string(0, 7, 1, 21, "levels menu.           ");
					//->0x1eb90
					break;

				case 9:
					//0x1e98c
					lcd_display_string(0, 1, 1, 21, "F+(1 to 9):             ");
					lcd_display_string(0, 3, 1, 21, "Show historic target   ");
					lcd_display_string(0, 5, 1, 21, "                       ");
					lcd_display_string(0, 7, 1, 21, "                       ");
					//->0x1eb90
					break;

				case 10:
					//0x1eb18
					lcd_display_string(0, 1, 1, 21, "F+0                     ");
					lcd_display_string(0, 3, 1, 21, "Open or close key      ");
					lcd_display_string(0, 5, 1, 21, "beep                   ");
					lcd_display_string(0, 7, 1, 21, "                       ");
					//->0x1eb90
					break;
				#if 0
				default:
					//0x1eb90
					break;
				#endif
			}
			//->0x20a50
			break;

		case 1:
			//0x1eb98: 501 = Telescope Align
			lcd_display_string(0, 1, 1, 21, "Telescope align:      ");
			lcd_display_string(0, 3, 1, 21, "Align Telescop point ");
			lcd_display_string(0, 5, 1, 21, "Pole-axis aim and    ");
			lcd_display_string(0, 7, 1, 21, "correct Backlash.    ");
			//->0x20a50
			break;

		case 2:
			//0x1ec10
			lcd_display_string(0, 1, 1, 21, "Target navigation:    ");
			lcd_display_string(0, 3, 1, 21, "Select Target from   ");
			lcd_display_string(0, 5, 1, 21, "database or input    ");
			lcd_display_string(0, 7, 1, 21, "data.                ");
			//->0x20a50
			break;

		case 3:
			//0x1ed94
			lcd_display_string(0, 1, 1, 21, "Utilities Commands:   ");
			lcd_display_string(0, 3, 1, 21, "Some tools in common ");
			lcd_display_string(0, 5, 1, 21, "use.                 ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;

		case 4:
			//0x1ee0c
			lcd_display_string(0, 1, 1, 21, "Parameter Setup:      ");
			lcd_display_string(0, 3, 1, 21, "Setup some parameter ");
			lcd_display_string(0, 5, 1, 21, "in system.           ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;

		case 5:
			//0x1ee84
			lcd_display_string(0, 1, 1, 21, "One star align:       ");
			lcd_display_string(0, 3, 1, 21, "Select one star align");
			lcd_display_string(0, 5, 1, 21, "the telescope point  ");
			lcd_display_string(0, 7, 1, 21, "by hand.             ");
			//->0x20a50
			break;

		case 6:
			//0x1f004
			lcd_display_string(0, 1, 1, 21, "Two stars align:      ");
			lcd_display_string(0, 3, 1, 21, "Select two star align");
			lcd_display_string(0, 5, 1, 21, "the telescope point  ");
			lcd_display_string(0, 7, 1, 21, "by hand.             ");
			//->0x20a50
			break;

		case 7:
			//0x1f07c
			lcd_display_string(0, 1, 1, 21, "Three star align:      ");
			lcd_display_string(0, 3, 1, 21, "Select three stars    ");
			lcd_display_string(0, 5, 1, 21, "align the telescope   ");
			lcd_display_string(0, 7, 1, 21, "point by hand.        ");
			//->0x20a50
			break;

		case 8:
			//0x1f0f4
			lcd_display_string(0, 1, 1, 21, "Target Sync:           ");
			lcd_display_string(0, 3, 1, 21, "Synchronizing the     ");
			lcd_display_string(0, 5, 1, 21, "target parameter with ");
			lcd_display_string(0, 7, 1, 21, "thetelescope point.   ");
			//->0x20a50
			break;

		case 9:
			//0x1f16c
			lcd_display_string(0, 1, 1, 21, "Pole-Axis Deviation:     ");
			lcd_display_string(0, 3, 1, 21, "Show the Pole-Axis      ");
			lcd_display_string(0, 5, 1, 21, "practice Deviation      ");
			lcd_display_string(0, 7, 1, 21, "through the align.      ");
			//->0x20a50
			break;

		case 10:
			//0x1f344
			lcd_display_string(0, 1, 1, 21, "RA Bklash Correction:     ");
			lcd_display_string(0, 3, 1, 21, "Correct the backlash     ");
			lcd_display_string(0, 5, 1, 21, "in RA motor gear.        ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;

		case 11:
			//0x1f3bc
			lcd_display_string(0, 1, 1, 21, "DEC Bklash Correction:    ");
			lcd_display_string(0, 3, 1, 21, "Correct the backlash     ");
			lcd_display_string(0, 5, 1, 21, "in DED motor gear.       ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;

		case 16:
			//0x1f434
			lcd_display_string(0, 1, 1, 21, "Solar System:            ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto      ");
			lcd_display_string(0, 5, 1, 21, "point at Planet, Sun,   ");
			lcd_display_string(0, 7, 1, 21, "Moon.                   ");
			//->0x20a50
			break;

		case 17:
			//0x1f5c4
			lcd_display_string(0, 1, 1, 21, "Constellation:         ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto     ");
			lcd_display_string(0, 5, 1, 21, "point at Constell-     ");
			lcd_display_string(0, 7, 1, 21, "ation.                  ");
			//->0x20a50
			break;

		case 18:
			//0x1f63c
			lcd_display_string(0, 1, 1, 21, "Famous Star:           ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all famous   ");
			lcd_display_string(0, 7, 1, 21, "stars.                ");
			//->0x20a50
			break;

		case 19:
			//0x1f6b4
			lcd_display_string(0, 1, 1, 21, "Messier Catalogue:     ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars in ");
			lcd_display_string(0, 7, 1, 21, "Messier Catalogue.    ");
			//->0x20a50
			break;

		case 20:
			//0x1f838
			lcd_display_string(0, 1, 1, 21, "NGC Deep Sky:           ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in NGC deep sky.      ");
			//->0x20a50
			break;

		case 21:
			//0x1f8b0
			lcd_display_string(0, 1, 1, 21, "IC Deep Sky:           ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in IC deep sky.       ");
			//->0x20a50
			break;

		case 22:
			//0x1f928
			lcd_display_string(0, 1, 1, 21, "Sh2 Deep Sky:          ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in Sh2 Deep Sky.      ");
			//->0x20a50
			break;

		case 23:
			//0x1f9a0
			lcd_display_string(0, 1, 1, 21, "Bright Stars:         ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto   ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in Bright Stars.      ");
			//->0x20a50
			break;

		case 24:
			//0x1fa18
			lcd_display_string(0, 1, 1, 21, "SAO Star:              ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto   ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in SAO Star.         ");
			//->0x20a50
			break;

		case 25:
			//0x1fbb4
			lcd_display_string(0, 1, 1, 21, "User-def Object:        ");
			lcd_display_string(0, 3, 1, 21, "Input sky target        ");
			lcd_display_string(0, 5, 1, 21, "parameter and save it.  ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;

		case 26:
			//0x1fc2c
			lcd_display_string(0, 1, 1, 21, "Specify Ra Dec:           ");
			lcd_display_string(0, 3, 1, 21, "Input Target R.a and    ");
			lcd_display_string(0, 5, 1, 21, "Des ,then point to it.   ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;

		case 27:
			//0x1fca4
			lcd_display_string(0, 1, 1, 21, "Landmarks:             ");
			lcd_display_string(0, 3, 1, 21, "Input land target     ");
			lcd_display_string(0, 5, 1, 21, "parameter and save it. ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;

		case 28:
			//0x1fd1c
			lcd_display_string(0, 1, 1, 21, "Current Objects:      ");
			lcd_display_string(0, 3, 1, 21, "Give planet's,solar  ");
			lcd_display_string(0, 5, 1, 21, "and lunar rise,      ");
			lcd_display_string(0, 7, 1, 21, "transit and set time. ");
			//->0x20a50
			break;

		case 29:
			//0x1feec
			lcd_display_string(0, 1, 1, 21, "Object Rise/Set:       ");
			lcd_display_string(0, 3, 1, 21, "calculate star rise,  ");
			lcd_display_string(0, 5, 1, 21, "transit and set time. ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 30:
			//0x1ff64
			lcd_display_string(0, 1, 1, 21, "Lunar Phase:         ");
			lcd_display_string(0, 3, 1, 21, "Show the lunar phase ");
			lcd_display_string(0, 5, 1, 21, "                     ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;

		case 31:
			//0x1ffdc
			lcd_display_string(0, 1, 1, 21, "Timer:                 ");
			lcd_display_string(0, 3, 1, 21, "Count down reminder  ");
			lcd_display_string(0, 5, 1, 21, "                      ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;

		case 32:
			//0x20054
			lcd_display_string(0, 1, 1, 21, "Alarm:                  ");
			lcd_display_string(0, 3, 1, 21, "Timeing alarm.         ");
			lcd_display_string(0, 5, 1, 21, "                       ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;

		case 33:
			//0x200cc
			lcd_display_string(0, 1, 1, 21, "Field Angle Cal:        ");
			lcd_display_string(0, 3, 1, 21, "Calculate the teles- ");
			lcd_display_string(0, 5, 1, 21, "cope's field angel.  ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;

		case 34:
			//0x2025c
			lcd_display_string(0, 1, 1, 21, "Magify Power Cal:      ");
			lcd_display_string(0, 3, 1, 21, "Calculate the teles-  ");
			lcd_display_string(0, 5, 1, 21, "cope's magify power.  ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 35:
			//0x202d4
			lcd_display_string(0, 1, 1, 21, "Illumination:          ");
			lcd_display_string(0, 3, 1, 21, "Set screen illumina-  ");
			lcd_display_string(0, 5, 1, 21, "tion.                 ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 37:
			//0x2034c
			lcd_display_string(0, 1, 1, 21, "Parkzen:               ");
			lcd_display_string(0, 3, 1, 21, "Slew telescope to     ");
			lcd_display_string(0, 5, 1, 21, "Original Position.    ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 38:
			//0x203c4
			lcd_display_string(0, 1, 1, 21, "Time and Date:         ");
			lcd_display_string(0, 3, 1, 21, "Set local time and   ");
			lcd_display_string(0, 5, 1, 21, "data for system.      ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 39:
			//0x2055c
			lcd_display_string(0, 1, 1, 21, "Daylight Saving:        ");
			lcd_display_string(0, 3, 1, 21, "Set Daylight Saving.   ");
			lcd_display_string(0, 5, 1, 21, "                       ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;

		case 40:
			//0x205d4
			lcd_display_string(0, 1, 1, 21, "Site Setting:            ");
			lcd_display_string(0, 3, 1, 21, "Select local site       ");
			lcd_display_string(0, 5, 1, 21, "from database or        ");
			lcd_display_string(0, 7, 1, 21, "input data.             ");
			//->0x20a50
			break;

		case 41:
			//0x2064c
			lcd_display_string(0, 1, 1, 21, "Sky/ Land:             ");
			lcd_display_string(0, 3, 1, 21, "Select sky or land    ");
			lcd_display_string(0, 5, 1, 21, "mode                  ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 42:
			//0x206c4
			lcd_display_string(0, 1, 1, 21, "AZ/EQ:                 ");
			lcd_display_string(0, 3, 1, 21, "Set mount mode to be  ");
			lcd_display_string(0, 5, 1, 21, "AZ or EQ mode.        ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 43:
			//0x20870
			lcd_display_string(0, 1, 1, 21, "Telescope Zero:        ");
			lcd_display_string(0, 3, 1, 21, "Set telescope Origin- ");
			lcd_display_string(0, 5, 1, 21, "al Position.          ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 44:
			//0x208e8
			lcd_display_string(0, 1, 1, 21, "Tracking Rate:         ");
			lcd_display_string(0, 3, 1, 21, "Set telescope track   ");
			lcd_display_string(0, 5, 1, 21, "speed.                ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;

		case 45:
			//0x20960
			lcd_display_string(0, 1, 1, 21, "Language:             ");
			lcd_display_string(0, 3, 1, 21, "Select the menu      ");
			lcd_display_string(0, 5, 1, 21, "language.            ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;

		case 46:
			//0x209d8
			lcd_display_string(0, 1, 1, 21, "Reset:                ");
			lcd_display_string(0, 3, 1, 21, "All parameter resume ");
			lcd_display_string(0, 5, 1, 21, "to the leave factory ");
			lcd_display_string(0, 7, 1, 21, "state.               ");
			//->0x20a50
			break;
		#if 0
		default:
			//0x20a50
			break;
		#endif
	}
}

