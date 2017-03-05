#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "scene.h"
#include <vector> 
#include "sprite.h"
#include "label.h"
//#include "block.h" included in game mode
#include "game_mode.h"

class GameScene : public Scene //main scene containing the actual game
{
private:
	bool doCalculations;
	std::vector<Sprite*> sprites;
	std::vector<Block*> blocks;
	Block* block1 = NULL;
	Block* block2 = NULL;
	SDL_Rect blocksOffset;
	
	GameMode mGameMode;
	
	Sprite* mBackgroundSprite;
	
	Label* scoreLabel = NULL;
	Label* movesLabel = NULL;
	Label* timerLabel = NULL;
	
public:
	GameScene();
	virtual ~GameScene();
	virtual void init();
	virtual void update(double deltaTime);
	virtual void handleInput(SDL_Event e);
	virtual void render(Window* window);
	virtual void exit();
	virtual void goToScene(Scene*& activeScene);
	
	bool PreCalculatePositioning();
	bool PreCalculateMoves();
	void CalculatePositioning();
	Block* GetBlockAt(int x, int y);
	void CheckBottomSides(Block* block);
	void AddSprite(Sprite* sta);
	void DeleteSprite(Sprite* std);
	
	int gridWidth;
	int gridHeight;
	
	int blockDimention;
	float blockScaleFactor;
};

#endif