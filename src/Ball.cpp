#include "Ball.h"
#include "SdlWindow.h"
#include <iostream>

const int BALL_SIZE = 10;
const int MAX_X = WINDOW_WIDTH - BALL_SIZE;
const int MAX_Y = WINDOW_HEIGHT - BALL_SIZE;

const int START_POSX = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
const int START_POSY = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;

const int STARTING_X_SPEED = 3;
const int STARTING_Y_SPEED = 3;

const int MAX_X_SPEED = 10;
const int MAX_Y_SPEED = 4;

Ball::Ball(Score* player1Score, Score* player2Score, Paddle* paddle1, Paddle* paddle2)
{
	resetPosition();
	this->rect.w = BALL_SIZE;
	this->rect.h = BALL_SIZE;
	this->xVel = -STARTING_X_SPEED;
	this->yVel = -STARTING_Y_SPEED;

	this->player1Score = player1Score;
	this->player2Score = player2Score;

	this->paddle1 = paddle1;
	this->paddle2 = paddle2;
}

void Ball::run()
{
	this->rect.y += this->yVel;
	if (this->rect.y < 0)
	{
		this->rect.y -= this->rect.y;
		setYVel(-this->yVel);

		//play wall hit sound
		Mix_PlayChannel(-1, wallHitSound, 0);
	}
	else if (this->rect.y >= MAX_Y)
	{
		this->rect.y -= (this->rect.y - MAX_Y) * 2;
		setYVel(-this->yVel);

		//play wall hit sound
		Mix_PlayChannel(-1, wallHitSound, 0);
	}

	this->rect.x += this->xVel;
	if (this->rect.x < 0)
	{
		resetPosition();
		setXVel(-this->xVel);
		resetVelocities();
		left = true;
		this->player2Score->increment();

		//play score sound
		Mix_PlayChannel(-1, scoreSound, 0);
	}
	else if (this->rect.x >= MAX_X)
	{
		resetPosition();
		setXVel(-this->xVel);
		resetVelocities();
		this->player1Score->increment();

		//play score sound
		Mix_PlayChannel(-1, scoreSound, 0);
	}

	const SDL_Rect* paddle1Rect = this->paddle1->getRect();
	if (SDL_HasIntersection(&this->rect, this->paddle1->getRect()))
	{
		handlePaddleCollision(paddle1Rect, true);
		left = true;
		//play paddle hit sound
		Mix_PlayChannel(-1, paddleHitSound, 0);
	}
	else
	{
		const SDL_Rect* paddle2Rect = this->paddle2->getRect();
		if (SDL_HasIntersection(&this->rect, paddle2Rect))
		{
			handlePaddleCollision(paddle2Rect, false);
			left = false;			
			//play paddle hit sound
			Mix_PlayChannel(-1, paddleHitSound, 0);
		}
	}
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xDD, 0xFF, 0x0, 0xFF);	
	SDL_RenderFillRect(renderer, &this->rect);
}

void Ball::resetPosition()
{
	this->rect.x = START_POSX;
	this->rect.y = START_POSY;
}

void Ball::resetVelocities()
{
	this->xVel = this->xVel > 0 ? STARTING_X_SPEED : -STARTING_X_SPEED;
	this->yVel = this->yVel > 0 ? STARTING_Y_SPEED : -STARTING_Y_SPEED;
}

void Ball::handlePaddleCollision(const SDL_Rect* paddleRect, bool isLeft)
{
	SDL_Rect intersection;
	SDL_IntersectRect(paddleRect, &this->rect, &intersection);
	int correctionMult = isLeft ? 1 : -1;
	this->rect.x += correctionMult * intersection.w * 2;

	setXVel(-(this->xVel + (this->xVel > 0 ? 1 : -1)));

	int impactCenterY = intersection.y + intersection.h / 2;
	int paddleCenterY = paddleRect->y + paddleRect->h / 2;
	setYVel((impactCenterY - paddleCenterY) * MAX_Y_SPEED / (PADDLE_HEIGHT/2));
}

void Ball::setXVel(const int xVel)
{
	this->xVel = xVel;
	if (this->xVel > MAX_X_SPEED)
		this->xVel = MAX_X_SPEED;
	else if (this->xVel < -MAX_X_SPEED)
		this->xVel = -MAX_X_SPEED;
}

void Ball::setYVel(const int yVel)
{
	this->yVel = yVel;
	if (this->yVel > MAX_Y_SPEED)
		this->yVel = MAX_Y_SPEED;
	else if (this->yVel < -MAX_Y_SPEED)
		this->yVel = -MAX_Y_SPEED;
}
