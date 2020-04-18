#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class Score
{
	public:
		Score(int x, int y);
		void draw(TTF_Font*, SDL_Renderer*);
		void increment();
	private:
		int x;
		int y;
		int value;
};
