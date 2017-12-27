#include <SDL2/SDL.h>
#include <stdio.h>

#include "Screen.h"

// Implement the constructor for a screen.
Screen::Screen()
{
	// Start the initialization process
	if (init());
		printf("DEBUG_SCREEN: The screen has been successfully initialized.\n");
}

bool Screen::init()
{
	// Initialize the SDL library. In this case, it'll simply be for video.
	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
		return false;

	// Then, we'll create the window.
	gWindow = SDL_CreateWindow( "CHIP-8 Emulator", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * SCALE_FACTOR, SCREEN_HEIGHT * SCALE_FACTOR, SDL_WINDOW_SHOWN );

	if (gWindow == NULL)
		return false;	// Something went wrong in the creation of the window.

	// Then, we'll create the renderer.
	gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

	/*
		Originally, I viewed the CHIP-8 display as something of which the display itself would be black,
		and the pixels when triggered would be white. For the sake of simplicity of code (and testing),
		I'm going to simply use a white background with black activated pixels.
	*/

	// Initialize the buffer
	fillBuffer(0);

	/*
	struct SDL_Rect blackBackground;
	blackBackground.x=0;
	blackBackground.y=0;
	blackBackground.w=SCREEN_WIDTH;
	blackBackground.h=SCREEN_HEIGHT;
	
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderFillRect( gRenderer, &blackBackground);
	SDL_RenderPresent(gRenderer);
	*/

	blit();

	// Since the CHIP-8 screen is only capable of black and white colors,
	// we will restrict our drawing ability to WHITE pixels only.
	//						renderer	r 	g 	b 	 transparency (255 is opaque)
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

	// Write the "black background" for the screen.
	return true;
}


void Screen::drawPixel(int x, int y)
{
	/*
	SDL_RenderDrawPoint(gRenderer, x, y);
	SDL_RenderPresent(gRenderer);
	*/
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

void Screen::blit()
{
	// Clear the renderer of whatever might have been there before.
	// Shouldn't need to clear the renderer if we are writing our whole screen out to it
	// SDL_RenderClear(gRenderer);

	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			if (buffer[x][y] != 0)
			{
				// Pixel is in use, so therefore, we'll need to change the color to BLACK.
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
			}
			else
			{
				// The pixel is not in use. We'll draw WHITE onto this pixel then.
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
			}

			/*
			for (int i = 0; i < SCALE_FACTOR * SCALE_FACTOR; i++)
			{
				SDL_RenderDrawPoint(gRenderer, (x*SCALE_FACTOR) + i/SCALE_FACTOR, (y*SCALE_FACTOR) + i%SCALE_FACTOR);
			}
			*/
			struct SDL_Rect s = {x*SCALE_FACTOR,y*SCALE_FACTOR,SCALE_FACTOR,SCALE_FACTOR};
			SDL_RenderFillRect(gRenderer, &s);
		}
	}
	SDL_RenderPresent(gRenderer);
}

void Screen::fillBuffer(int i)
{
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			buffer[x][y] = i;
		}
	}
}

void Screen::delay(int milliseconds)
{
	SDL_Delay(milliseconds);
}