#include "Input.h"

void Input::OnKeyDownEvent(const SDL_Event& event)
{
	if (event.key.repeat == 0) {
		_keysPressed[event.key.keysym.scancode] = true;

		for (auto callback : _onKeyDownListeners[event.key.keysym.scancode])
			callback();
	}
}

void Input::OnKeyUpEvent(const SDL_Event& event)
{
	_keysReleased[event.key.keysym.scancode] = true;

	for (auto callback : _onKeyUpListeners[event.key.keysym.scancode])
		callback();
}

void Input::SubscribeOnKeyDownEvent(const SDL_Scancode& key, const std::function<void()> &callback)
{
	_onKeyDownListeners[key].emplace_back(callback);
}

void Input::SubscribeOnKeyUpEvent(const SDL_Scancode& key, const std::function<void()>& callback)
{
	_onKeyUpListeners[key].emplace_back(callback);
}
