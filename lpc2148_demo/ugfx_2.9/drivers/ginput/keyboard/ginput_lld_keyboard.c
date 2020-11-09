
#include "gfx.h"


#if GFX_USE_GINPUT && GINPUT_NEED_KEYBOARD
	#define GKEYBOARD_DRIVER_VMT		GKEYBOARDVMT_My
	#include "../../../src/ginput/ginput_driver_keyboard.h"

	static gBool Win32KeyboardInit(GKeyboard *k, unsigned driverinstance) {
		(void)	driverinstance;

#if 0
		// Only one please
		if (keyboard)
			return gFalse;

		keyboard = k;
#endif
		return gTrue;
	}

	static int Win32KeyboardGetData(GKeyboard *k, gU8 *pch, int sz) {
#if 0
		int		i, j;
		(void)	k;

		if (!keypos)
			return 0;

		for(i = 0; i < keypos && i < sz; i++)
			pch[i] = keybuffer[i];
		keypos -= i;
		for(j=0; j < keypos; j++)
			keybuffer[j] = keybuffer[i+j];
		return i;
#else
		return 0;
#endif
	}

	const GKeyboardVMT const GKEYBOARD_DRIVER_VMT[1] = {{
		{
			GDRIVER_TYPE_KEYBOARD,
			GKEYBOARD_VFLG_NOPOLL,			//  GKEYBOARD_VFLG_DYNAMICONLY
			sizeof(GKeyboard),
			_gkeyboardInitDriver, _gkeyboardPostInitDriver, _gkeyboardDeInitDriver
		},

#if 0
	 	// The Win32 keyboard layout
		#if GKEYBOARD_WIN32_NO_LAYOUT
			0,
		#else
			GKEYBOARD_WIN32_DEFAULT_LAYOUT,
		#endif
#else
			0,
#endif

		Win32KeyboardInit,		// init
		0,						// deinit
		Win32KeyboardGetData,	// getdata
		0						// putdata		void	(*putdata)(GKeyboard *k, char ch);		Optional
	}};

#endif
