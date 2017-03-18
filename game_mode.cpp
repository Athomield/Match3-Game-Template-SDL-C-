#include "headers/game_mode.h"

GameMode::GameMode()
{
	mWidth = 4;
	mHeight = 5;
	
	mCombo = 1;
	mBlockScore = 50;
	
	mObjectiveDone = false;
	
	mHasScore = true;
	mGoalScore = 20000;
	mCurrentScore = 0;
	
	mMaxMoves = 25;
	mCurrentMoves = mMaxMoves;
	
	mHasTimer = false;
	mMaxTimer = 25;
	mCurrentTimer = mMaxTimer;
	
	mDestroyBlocks = false;
}

int GameMode::GetWidth()
{
	return mWidth;
}

int GameMode::GetBlockScore()
{
	return mBlockScore;
}

float GameMode::GetCombo()
{
	return mCombo;
}

void GameMode::ModifyCombo(float _amt)
{
	mCombo += _amt;
}

void GameMode::ResetCombo()
{
	mCombo = 1;
}

int GameMode::GetHeight()
{
	return mHeight;
}

void GameMode::Update(double deltaTime)
{
	mCurrentTimer -= deltaTime;
	UpdateObjective();
}

void GameMode::UpdateObjective()
{
	mObjectiveDone = (mHasScore && (mCurrentScore >= mGoalScore)); /*&&
		(mHasTimer && (mCurrentTimer < mMaxTimer))*/
		
	if(mDestroyBlocks)
	{
		for(std::map<Block::Type,int>::iterator itr = mNumberOfBlocksToDestroy.begin()
				; itr != mNumberOfBlocksToDestroy.end(); itr++)
		{
			if(itr->second > 0)
			{
				mObjectiveDone &= false;
			}
		}
	}
}

bool GameMode::GameWon()
{
	return mObjectiveDone;
}

void GameMode::DecrementMoves()
{
	mCurrentMoves--;
}

int GameMode::GetCurrentMoves()
{
	return mCurrentMoves;
}

int GameMode::GetMaxMoves()
{
	return mMaxMoves;
}

void GameMode::ModifyScore(int _amt)
{
	mCurrentScore += _amt;
}

int GameMode::GetCurrentScore()
{
	return mCurrentScore;
}

int GameMode::GetCurrentTimer()
{
	return mCurrentTimer;
}
