#include "headers/block.h"

Block::Block(int x, int y, float scale) : Sprite("../resources/empty_block.png",x,y,scale)
{
	int randomNumber = rand() %  4;
	switch(randomNumber)
	{
		case 0:
			SetTexture("../resources/apple_block.png");
			mType = Apple;
			break;
		case 1:
			SetTexture("../resources/orange_block.png");
			mType = Orange;
			break;
		case 2:
			SetTexture("../resources/banana_block.png");
			mType = Banana;
			break;
		case 3:
			SetTexture("../resources/resin_block.png");
			mType = Grape;
			break;
	}
	
	mX = x;
	mY = y;
	desiredXPos = x;
	desiredYPos = y;
	mDropVelocity = 100;
	mIsMoving = false;
	isTiltRight = false;
	animationTimer = 0;
}

void Block::Update(double deltaTime)
{
	mDropVelocity += 700 * deltaTime; //acceleration over time
	int tempY = (int)mY; //maybe dis will change in the futur

	if(desiredYPos != tempY)
	{
		mY += mDropVelocity * deltaTime;
		mIsMoving = true;
		if(abs(tempY - desiredYPos) < 8)
		{
			mY = desiredYPos;	
			mIsMoving = false;
		}
	}
	else
	{
		mIsMoving = false;
		mDropVelocity = 100;
	}

	//TiltRight(deltaTime);
	//mX = mX - mWidth*mXScaleFactor*4*sin(SDL_GetTicks()/100) * deltaTime;
}


int Block::GetDesiredXPos()
{
	return desiredXPos;
}

int Block::GetDesiredYPos()
{
	return desiredYPos;
}

void Block::TiltRight(double deltaTime)
{
	float distance;
	
	if(SDL_GetTicks() > animationTimer)
	{
		animationTimer = SDL_GetTicks() + 1000;
		distance = 0;
	}
	
//	std::cout << animationTimer << std::endl;
	
	if(isTiltRight && animationTimer > SDL_GetTicks())
	{
		if(distance <= 30)
		{
			mX += 100*deltaTime;
			distance += 100*deltaTime;	
		}
		else if(distance >= 0)
		{
			mX -= 100*deltaTime;	
			distance -= 100*deltaTime;	
		}
	}
}

void Block::StartTiltRight()
{
	isTiltRight = true;
}

void Block::SetDesiredPos(int x, int y)
{
	desiredXPos = x;
	desiredYPos = y;
}

int Block::GetXPos()
{
	int temp = (int)mX;
	return temp;
}

int Block::GetYPos()
{
	int temp = (int)mY;
	return temp;
}

bool Block::IsMoving()
{
	return mIsMoving;
}

Block::Type Block::GetType()
{
	return mType;
}

Block::~Block()
{
	
}
int Block::GetYCoord()
{
	return (int)(mY /(int)(mHeight*mYScaleFactor));
}

int Block::GetXCoord()
{
	return (int)(mX/(int)(mWidth*mXScaleFactor));
}
