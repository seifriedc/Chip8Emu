#include <stdio.h>
#include "Screen.h"

int main()
{
	Screen screen;

	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		screen.drawPixel(i,SCREEN_HEIGHT/2);
		SDL_Delay(100);
	}
	return 0;
}