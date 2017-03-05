#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "block.h"
#include <map>
#include <string>

class GameMode
{
private:

	int mWidth;
	int mHeight;
	
	bool mObjectiveDone;
	bool mGameLost;
	
	int mMaxMoves;
	int mCurrentMoves;
	
	bool mHasScore; 
	int mGoalScore;
	int mCurrentScore;
	
	bool mHasTimer;
	double mMaxTimer;
	double mCurrentTimer;
	
	int mBlockScore; //score earned for destroying one block 
	float mCombo;
	
	bool mDestroyBlocks;
	std::map<Block::Type,int> mNumberOfBlocksToDestroy;
	
public:
	GameMode();
	
	int GetWidth();
	int GetHeight();
	
	void Update(double deltaTime);
	
	void UpdateObjective();
	
	int GetBlockScore();
	
	float GetCombo();
	void ModifyCombo(float _amt);
	void ResetCombo();
	
	void IncreaseScore(int amt);
	
	int GetGoalScore();
	int GetCurrentScore();
	
	int GetCurrentMoves();
	int GetMaxMoves();
	
	int GetCurrentTimer();
	
	void DecrementMoves();
	
	bool GameWon();
	
	void ModifyScore(int _amt);
	
};

#endif