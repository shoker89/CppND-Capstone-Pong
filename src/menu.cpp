#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "menu.h"

SDL_Color color{0xFF, 0xFF, 0xFF, 0xFF};

void Menu::draw(SDL_Renderer* renderer)
{

    //STRING PONG!////////////////////////////////////////////////////////////
    TTF_Font* Sans = TTF_OpenFont("../font/Roboto.ttf", 150);

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "Pong!!!", color);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; 
    Message_rect.x = 150; 
    Message_rect.y = 15;
    Message_rect.w = 150; 
    Message_rect.h = 150;

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    ///////////////////////////////////////////////////////////////////////
    //STRING F1////////////////////////////////////////////////////////////
    Sans = TTF_OpenFont("../font/Roboto.ttf", 40);

    surfaceMessage = TTF_RenderText_Solid(Sans, "Press F1 - Player1 VS Player2", color);
    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    Message_rect.x = 30; 
    Message_rect.y = 200;
    Message_rect.w = 400; 
    Message_rect.h = 50;

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    //////////////////////////////////////////////////////////////////////////
    //STRING F2///////////////////////////////////////////////////////////////
    surfaceMessage = TTF_RenderText_Solid(Sans, "Press F2 - Player1 vs CPU", color);
    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    Message_rect.x = 30; 
    Message_rect.y = 300;
    Message_rect.w = 400; 
    Message_rect.h = 50;

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);



    SDL_RenderPresent(renderer);
}