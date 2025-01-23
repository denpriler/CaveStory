#include "Sprite.h"
#include "Graphics.h"

Sprite::Sprite(
	Graphics& graphics,
	const std::string& filePath,
	int sourceX,
	int sourceY,
	int sourceWidth,
	int sourceHeight
	)
{

	_rect.x = sourceX;
	_rect.y = sourceY;
	_rect.w = sourceWidth;
	_rect.h = sourceHeight;

	_spriteSheet = SDL_CreateTextureFromSurface(
			graphics.getRenderer(),
			graphics.loadSpriteSheet(filePath)
		);
}

void Sprite::draw(Graphics& graphics, int x, int y)
{
	SDL_Rect destination = { x, y, _rect.w, _rect.h };

	graphics.blitSurface(
		_spriteSheet,
		&_rect,
		&destination
	);
}

int Sprite::getX() const
{
	return _rect.x;
}

int Sprite::getY() const
{
	return _rect.y;
}
