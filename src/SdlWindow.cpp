#include "SdlWindow.h"
#include "stdio.h"

bool SdlWindow::init(const char* title)
{
	if ((this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)) == nullptr)
		return false;
	printf("Created window\n");

	if ((this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == nullptr)
		return false;
	printf("Created renderer\n");

	return true;
}

SdlWindow::~SdlWindow()
{
	if (this->renderer != nullptr)
	{
		printf("Destroying renderer\n");
		SDL_DestroyRenderer(this->renderer);
	}
	if (this->window != nullptr)
	{
		printf("Destroying window\n");
		SDL_DestroyWindow(this->window);
	}
}

SDL_Window* SdlWindow::getWindow()
{
	return this->window;
}

SDL_Renderer* SdlWindow::getRenderer()
{
	return this->renderer;
}
