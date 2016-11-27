#ifndef GAME_H
#define GAME_H

#include <vector> 
#include "scene.h"
#include "game_scene.h"

class Window;

class Game
{
	private:
		Window* mWindow;
//		std::vector<Sprite*> sprites;
//		std::vector<Block*> blocks;
		Scene* mScene = NULL;
	public:
		Game();
		~Game();
//		Block* block1 = NULL;
//		Block* block2 = NULL;
//		//Block* GetBlockAt(int x, int y);
//		SDL_Rect blocksOffset;
		//void CalculatePositioning();
		//bool PreCalculatePositioning();
		void Render();
		void Update();
		void HandleEvents(bool* quit);
		//void AddSprite(Sprite* sta);
		//void DeleteSprite(Sprite* std);
		void Clean();
};

#endif
