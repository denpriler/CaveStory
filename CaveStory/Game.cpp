#include <SDL.h>
#include <iostream>
#include "Game.h"
#include "Graphics.h"
#include "Input.h"

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

		Input input;
		globalActions(input);

		initPlayer(graphics, input);

		SDL_Event event;
		while (_isGameLoop) {
			if (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_KEYDOWN:
					input.OnKeyDownEvent(event);

					break;

				case SDL_KEYUP:
					input.OnKeyUpEvent(event);

					break;

				case SDL_QUIT:
					_isGameLoop = false;

					break;

				default:
					break;
				}
			}

			draw(graphics);
		}
	}
}

void Game::globalActions(Input& input)
{
	// Subscribe on ESC key to exit
	input.SubscribeOnKeyDownEvent(
		SDL_SCANCODE_ESCAPE,
		[&]() { _isGameLoop = false; }
	);
}

void Game::draw(Graphics& graphics)
{
	// Clear all render
	graphics.clear();

	// Here goes updates
	_player.draw(graphics, 640 / 2, 480 / 2);

	// Actually rendering what's updated
	graphics.flip();
}

void Game::initPlayer(Graphics& graphics, Input& input)
{
	_player = Sprite(graphics, "data/sprites/MyChar.pbm", 0, 0, 16, 16);
}
