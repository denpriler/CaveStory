#pragma once

class Graphics;

class Game
{
public:
	Game();
	~Game();

	void loop();

private:
	bool _isGameLoop = false;
};

