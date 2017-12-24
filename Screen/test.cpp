#include <stdio.h>
#include "Screen.h"

int main()
{
	Screen screen;


	SDL_Delay(1000);

	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		screen.buffer[i][SCREEN_HEIGHT/2] = 1;
		screen.blit();

		SDL_Delay(10);
	}

	SDL_Delay(1000);
	return 0;
}