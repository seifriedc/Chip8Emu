#include <SDL2/SDL.h>
#include <stdio.h>

#ifndef SCREEN_H
#define SCREEN_H

// For the actual screen of the CHIP-8 processor, we should store the screen buffer directly in this file-- then, we'll access
// it directly from the CHIP-8.c simulator, and blit() the screen as necessary.

//Screen dimension constants
const int SCREEN_WIDTH = 64;
const int SCREEN_HEIGHT = 32;

class Screen
{
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	public:
		Screen();
		void drawPixel(int x, int y);
		void clearScreen();
		
	private:
		bool init();
};


















#endif
