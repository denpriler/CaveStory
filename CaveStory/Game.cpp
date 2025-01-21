#include <SDL.h>
#include <iostream>
#include "Game.h"
#include "Graphics.h"

Game::Game()
{
	// #[https://wiki.libsdl.org/SDL2/SDL_Init]
	_isGameLoop = SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0;
	if (!_isGameLoop) {
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
	}
}

Game::~Game()
{
	// #[https://wiki.libsdl.org/SDL2/SDL_Quit]
	SDL_Quit();
}

void Game::loop()
{
	if (_isGameLoop) {
		Graphics graphics;
		if (!graphics.IsReady()) return;

		SDL_Event event;

		while (_isGameLoop) {
			SDL_PollEvent(&event);
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					_isGameLoop = false;
				break;
			case SDL_QUIT:
				_isGameLoop = false;
				break;
			default:
				break;
			}
		}
	}
}
