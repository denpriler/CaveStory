#pragma once

#include <map>
#include <vector>
#include <functional>
#include <SDL.h>

/*
* Input class holds keys for pricessing in scope of one frame only.
*/
class Input
{
private:
	// Holding keys to process after frame
	std::map<SDL_Scancode, bool> _keysPressed;
	std::map<SDL_Scancode, bool> _keysReleased;

	// Keys event listeners
	std::map<SDL_Scancode, std::vector<std::function<void()>>> _onKeyDownListeners;
	std::map<SDL_Scancode, std::vector<std::function<void()>>> _onKeyUpListeners;

public:
	void OnKeyDownEvent(const SDL_Event& event);
	void OnKeyUpEvent(const SDL_Event& event);

	// Subscribe on key event methods
	void SubscribeOnKeyDownEvent(const SDL_Scancode& key, const std::function<void()>& callback);
	void SubscribeOnKeyUpEvent(const SDL_Scancode& key, const std::function<void()>& callback);
};

