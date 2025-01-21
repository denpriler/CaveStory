#include <SDL.h>
#include <iostream>
#include "Game.h"
#include "Graphics.h"

Game::Game()
{
	// #[https://wiki.libsdl.org/SDL2/SDL_Init]
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return;
	}

	loop();
}

Game::~Game()
{
	// #[https://wiki.libsdl.org/SDL2/SDL_Quit]
	SDL_Quit();
}

void Game::loop()
{
	Graphics graphics;
	SDL_Event event;

	while (true) {
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			return;
		default:
			break;
		}
	}
}
