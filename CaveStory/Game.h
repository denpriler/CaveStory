#pragma once

#include "Sprite.h"

class Graphics;
class Input;

class Game
{
public:
	Game();
	~Game();

	void loop();
	void globalActions(Input& input);
	void draw(Graphics& graphics);

private:
	bool _isGameLoop = false;

	Sprite _player = Sprite();

private:
	void initPlayer(Graphics& graphics, Input& input);
};

