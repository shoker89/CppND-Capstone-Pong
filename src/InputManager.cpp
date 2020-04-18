#include <SDL.h>

#include "InputManager.h"

InputManager::InputManager()
{
	for (int i = 0; i < (int)GameInputButton::INPUT_TOTAL; i++)
	{
		inputButtonsDown[i] = false;
	}
}

void InputManager::handleKeyDown(int keyCode)
{
	int buttonIndex;
	if ((buttonIndex = getButtonIndex(keyCode)) != -1)
		this->inputButtonsDown[buttonIndex] = true;
}

void InputManager::handleKeyUp(int keyCode)
{
	int buttonIndex;
	if ((buttonIndex = getButtonIndex(keyCode)) != -1)
		this->inputButtonsDown[buttonIndex] = false;
}

int InputManager::getButtonIndex(int keyCode)
{
	switch (keyCode)
	{
		case SDLK_UP:
			return (int)GameInputButton::PLAYER2_UP;
		case SDLK_DOWN:
			return (int)GameInputButton::PLAYER2_DOWN;
		case SDLK_w:
			return (int)GameInputButton::PLAYER1_UP;
		case SDLK_s:
			return (int)GameInputButton::PLAYER1_DOWN;
		default:
			return -1;
	}
}

bool InputManager::isButtonDown(GameInputButton button)
{
	if (button == GameInputButton::INPUT_TOTAL)
		return false;
	return this->inputButtonsDown[(int)button];
}
