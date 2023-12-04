#include "MacUILib.h"

print_ptr MacUILib_printf;

#ifdef WINDOWS

	#include <conio.h>
	
	void MacUILib_init(void)
	{
		MacUILib_printf = &printf;
	}

	void MacUILib_init_sync(void)
	{
		// Nothing different.  Win allows scanf() to be used with conio.h anyways.
		MacUILib_printf = &printf;
	}

	void MacUILib_Delay(int usec)
	{
		usleep(usec);
	}
	
	int MacUILib_hasChar(void)
	{
		return _kbhit();
	}
	
	char MacUILib_getChar(void)
	{
		return _getch();
	}
	
	void MacUILib_clearScreen(void)
	{
		system("cls");
	}
	
	void MacUILib_uninit(void)
	{
		// No implementation required
		MacUILib_printf("\nYou ate yourself. Game Over!\n");
		MacUILib_printf("\nPress Any Key to Shut Down\n");
		getchar();
	}
	
#endif

	