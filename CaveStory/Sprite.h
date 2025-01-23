#pragma once

#include <SDL.h>
#include <string>

class Graphics;

class Sprite
{
public:
	Sprite() = default;
	Sprite(
		Graphics &graphics,
		const std::string& filePath,
		int sourceX,
		int sourceY,
		int sourceWidth,
		int sourceHeight
	);

	void draw(Graphics& graphics, int x, int y);

	int getX() const;
	int getY() const;

private:
	SDL_Rect _rect;
	SDL_Texture* _spriteSheet;
};

