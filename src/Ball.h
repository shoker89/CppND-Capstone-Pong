#pragma once

#include <SDL.h>
#include <SDL_mixer.h>

#include "Score.h"
#include "Paddle.h"

class Ball
{
	public:
		Ball(Score* player1Score, Score* player2Score, Paddle* paddle1, Paddle* paddle2);
		void run();
		void draw(SDL_Renderer*);
		

	private:
		SDL_Rect rect;
		int xVel;
		int yVel;
		Score* player1Score;
		Score* player2Score;
		Paddle* paddle1;
		Paddle* paddle2;

		void resetPosition();
		void resetVelocities();
		void handlePaddleCollision(const SDL_Rect* paddleRect, bool isLeft);
		void setXVel(const int xVel);
		void setYVel(const int yVel);
	
	// Initialize sound effects
		Mix_Chunk* paddleHitSound = Mix_LoadWAV("../sound/paddle.wav");
		Mix_Chunk* scoreSound = Mix_LoadWAV("../sound/score.wav");
		Mix_Chunk* wallHitSound = Mix_LoadWAV("../sound/wall.wav");
};
