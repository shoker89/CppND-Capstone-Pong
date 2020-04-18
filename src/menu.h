#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Menu
{
public:
    Menu(){};
    void draw( SDL_Renderer* renderer);
private:
    std::string mainText ="Pong!\n";
};