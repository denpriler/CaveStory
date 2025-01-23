#pragma once

#include <SDL.h>
#include <map>
#include <string>

// Some neccesary SDL declarations
struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
private:
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

	std::map<std::string, SDL_Surface*> _spriteSheets;
public:
	Graphics();
	~Graphics();

	bool IsReady();

	SDL_Surface* loadSpriteSheet(const std::string& filtePath);
	bool blitSurface(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination);

	void flip();
	void clear();

	SDL_Renderer* getRenderer() const;
};

