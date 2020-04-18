#pragma once
#include "Paddle.h"
#include "Ball.h"
#include <SDL.h>

enum class GameInputAI
{
	PLAYER2_DOWN,
	PLAYER2_UP
};

class AI_enemy
{   
    public:
        AI_enemy(SDL_Rect *rectBall, SDL_Rect *rectPaddle, bool *left);
        bool logic(GameInputAI button);

    private:
        SDL_Rect *ball, *paddle;
        bool *isLeft;
};