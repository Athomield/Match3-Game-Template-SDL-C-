#include "headers/block.h"

Block::Block(int x, int y, float scale,SpawnType spawnType) : Sprite("../resources/empty_block.png",x,y,scale)
{
	if(spawnType == SpawnRandom)
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
	}
	else if(spawnType == SpawnStatic)
	{
		SetTexture("../resources/static_block.png");
		mType = Static;
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
	int tempX = (int)mX;
	
	if((desiredYPos != tempY || desiredXPos != tempX) && mType != Static)
	{
		if(desiredYPos != tempY)
		{
			mY += mDropVelocity * deltaTime;
			mIsMoving = true;
			
			if(abs(tempY - desiredYPos) < 8)
			{
				mY = desiredYPos;	
				//mIsMoving = false;
			}
		}
		
		if(desiredXPos != tempX)
		{
			if(tempX < desiredXPos)
			{
				mX += 400 * deltaTime;
			}
			else if(tempX > desiredXPos)
			{
				mX -= 400 * deltaTime;
			}
			
			mIsMoving = true;
			
			if(abs(tempX - desiredXPos) < 8)
			{
				mX = desiredXPos;	
				//mIsMoving = false;
			}
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
