#pragma once
#include <SDL.h>

#include "SdlSession.h"

const int WINDOW_WIDTH = 480;
const int WINDOW_HEIGHT = 360;

class SdlWindow
{
	public:
		~SdlWindow();
		bool init(const char* title);
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};
