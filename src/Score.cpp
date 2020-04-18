#include <SDL_ttf.h>
#include <string>

#include "Score.h"

const SDL_Color color{0xFF, 0xFF, 0xFF, 0xFF};

Score::Score(int x, int y)
{
	this->x = x;
	this->y = y;
	this->value = 0;
}

void Score::draw(TTF_Font* font, SDL_Renderer* renderer)
{
	SDL_Surface *surface;
	if ((surface = TTF_RenderText_Solid(font, std::to_string(this->value).c_str(), color)) == nullptr)
	{
		return;
	}

	SDL_Texture *texture;
	if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) != nullptr)
	{
		SDL_Rect dstrect = {this->x, this->y, surface->w, surface->h};
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_DestroyTexture(texture);
	}
	SDL_FreeSurface(surface);
}

void Score::increment()
{
	this->value++;
}
