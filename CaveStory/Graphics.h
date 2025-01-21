#pragma once

// Some neccesary SDL declarations
struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
private:
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
public:
	Graphics();
	~Graphics();
};

