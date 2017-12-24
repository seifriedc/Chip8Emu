#include <SDL2/SDL.h>
#include <stdio.h>

#include "Screen.h"

// Implement the constructor for a screen.
Screen::Screen()
{
	// Start the initialization process
	if (init());
		printf("DEBUG_SCREEN: The screen has been successfully initialized.");
}

bool Screen::init()
{
	// Initialize the SDL library. In this case, it'll simply be for video.
	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
		return false;

	// Then, we'll create the window.
	gWindow = SDL_CreateWindow( "CHIP-8 Emulator", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	if (gWindow == NULL)
		return false;	// Something went wrong in the creation of the window.

	// Then, we'll create the renderer.
	gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

	// We need to fill the screen with black

	struct SDL_Rect blackBackground;
	blackBackground.x=0;
	blackBackground.y=0;
	blackBackground.w=SCREEN_WIDTH;
	blackBackground.h=SCREEN_HEIGHT;

	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderFillRect( gRenderer, &blackBackground);
	SDL_RenderPresent(gRenderer);

	// Since the CHIP-8 screen is only capable of black and white colors,
	// we will restrict our drawing ability to WHITE pixels only.
	//						renderer	r 	g 	b 	 transparency (255 is opaque)
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

	// Write the "black background" for the screen.
	return true;
}

void Screen::drawPixel(int x, int y)
{
	SDL_RenderDrawPoint(gRenderer, x, y);
	SDL_RenderPresent(gRenderer);
}

void Screen::clearScreen()
{
	struct SDL_Rect blackBackground;
	blackBackground.x=0;
	blackBackground.y=0;
	blackBackground.w=SCREEN_WIDTH;
	blackBackground.h=SCREEN_HEIGHT;

	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderFillRect( gRenderer, &blackBackground);
	SDL_RenderPresent(gRenderer);
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
}