#pragma once

enum class GameInputButton
{
	PLAYER1_DOWN,
	PLAYER1_UP,
	PLAYER2_DOWN,
	PLAYER2_UP,
	INPUT_TOTAL
};

class InputManager
{
	public:
		InputManager();
		void handleKeyDown(int keyCode);
		void handleKeyUp(int keyCode);
		bool isButtonDown(GameInputButton button);
	private:
		bool inputButtonsDown[(int) GameInputButton::INPUT_TOTAL];
		int getButtonIndex(int keyCode);
};
