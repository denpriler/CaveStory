#include <SDL.h>
#include <iostream>
#include "Graphics.h"

Graphics::Graphics()
{
	// #[https://wiki.libsdl.org/SDL2/SDL_CreateWindowAndRenderer]
	if (SDL_CreateWindowAndRenderer(640, 480, NULL, &_window, &_renderer) < 0) {
		std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
	}
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}
