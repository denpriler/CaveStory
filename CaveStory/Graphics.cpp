#include <iostream>
#include <SDL_image.h>
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

bool Graphics::IsReady()
{
	return _window && _renderer;
}

SDL_Surface* Graphics::loadSpriteSheet(const std::string& filtePath)
{
	if (_spriteSheets.count(filtePath) == 0) {
		_spriteSheets[filtePath] = IMG_Load(filtePath.c_str());

		if (_spriteSheets[filtePath] == NULL) {
			std::cerr << "Error on texture loading (" << filtePath << "): " << SDL_GetError() << std::endl;
		}
	}
	return _spriteSheets[filtePath];
}

bool Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination)
{
	if (SDL_RenderCopy(_renderer, texture, source, destination) != 0) {
		std::cerr << "Error on texture rendering: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Graphics::flip()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::clear()
{
	if (SDL_RenderClear(_renderer) != 0) {
		std::cerr << "Error while render clear: " << SDL_GetError() << std::endl;
	}
}

SDL_Renderer* Graphics::getRenderer() const
{
	return _renderer;
}
