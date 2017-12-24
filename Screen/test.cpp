#include <stdio.h>
#include "Screen.h"

int main()
{
	Screen screen;

	while(1)
	{
		for (int i = 0; i < SCREEN_WIDTH; i++)
		{
			if (i == 50)
			{
				screen.clearScreen();
			}

			screen.drawPixel(i,SCREEN_HEIGHT/2);
			SDL_Delay(1);
		}
	}
	return 0;
}