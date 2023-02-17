#include <iostream>
#include <3ds.h>

int main(int argc, char* argv[])
{
	// Iniitialize libraries
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
	romfsInit();
	
	std::cout << "Hello, world!" << std::endl;
	
	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
	}

	romfsExit();
	gfxExit();
	return 0;
}
