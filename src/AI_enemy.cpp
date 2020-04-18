#include "AI_enemy.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>

AI_enemy::AI_enemy(SDL_Rect *rectBall, SDL_Rect *rectPaddle, bool *left)
{
    ball = rectBall;
    paddle = rectPaddle;
    isLeft = left;
    
}

bool AI_enemy::logic(GameInputAI button)
{

    if (ball->x > 50)
    {
        if ( (ball->y < paddle->y) && *isLeft && button == GameInputAI::PLAYER2_UP)
            return true;
        if ((ball->y > paddle->y) && *isLeft && button == GameInputAI::PLAYER2_DOWN)
            return true;
    }

    return false;
}