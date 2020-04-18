#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <SDL_mixer.h>

#include "SdlSession.h"

SdlSession::SdlSession()
{
	this->initialized = false;
	this->ttfInitialized = false;
}

SdlSession::~SdlSession()
{
	if (this->ttfInitialized)
	{
		printf("Quitting SDL_ttf\n");
		TTF_Quit();
	}
	if (this->initialized)
	{
		printf("Quitting SDL\n");
		SDL_Quit();
	}
}


bool SdlSession::init()
{
	printf("Initializing SDL\n");
	if (!(this->initialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == 0))
	{
		printf("Failed to initialize SDL\n");
		return false;
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	
	
	printf("Initialized SDL video and sound\n");

	printf("Initializing SDL_ttf\n");
	if (!(this->ttfInitialized = TTF_Init() == 0))
	{
		printf("Failed to initialize SDL_ttf\n");
		return false;
	}
	printf("Initialized SDL_ttf\n");

	return true;
}
