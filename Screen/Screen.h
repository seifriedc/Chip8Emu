#include <SDL2/SDL.h>
#include <stdio.h>

#ifndef SCREEN_H
#define SCREEN_H

// For the actual screen of the CHIP-8 processor, we should store the screen buffer directly in this file-- then, we'll access
// it directly from the CHIP-8.c simulator, and blit() the screen as necessary.

//Screen dimension constants
const int SCREEN_WIDTH = 64;
const int SCREEN_HEIGHT = 32;
const int SCALE_FACTOR = 15;

class Screen
{

	// The screen buffer will represent every pixel on the display.
	// If the value at a specified X and Y is 0, the pixel is not set, any other value than 0, it is.
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	public:
		char buffer[SCREEN_WIDTH][SCREEN_HEIGHT];
		Screen();
		void drawPixel(int x, int y);
		void blit();
		void clearScreen();
		
	private:
		bool init();
		void fillBuffer(int i);
};


















#endif
