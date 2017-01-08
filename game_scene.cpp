#include "headers/game_scene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	exit();
}

void GameScene::init()
{
	srand(time(NULL));
	doCalculations = true;
	
	gridWidth = 4;
	gridHeight = 5;
	
	blockScaleFactor = 0.3f;
	blockDimention = 200 * blockScaleFactor;
	
	blocksOffset = {50,150,0,0};
	
	for(int x = 0; x < gridWidth;x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{
			AddSprite(new Sprite("../resources/empty_block.png",x * blockDimention, y * blockDimention, blockScaleFactor));
		}
	}
	
	for (int y = 0; y < gridHeight; y++)
	{
		for (int x = 0; x < gridWidth;x++)
		{
			if((x == 0 || x == 3) && (y == 1 || y == 3))
			{
				Block* bta = new Block(x * blockDimention, y * blockDimention, blockScaleFactor,Block::SpawnType::SpawnStatic);
				AddSprite(bta);
				blocks.push_back(bta); 
				
				bta = NULL;
			}
			else
			{
				Block* bta = new Block(x * blockDimention, y * blockDimention, blockScaleFactor);
				AddSprite(bta);
				blocks.push_back(bta); 
				
				bta = NULL;
			}
			
		}
	}

}

bool GameScene::PreCalculatePositioning() //This function checks for matches after a switch of two blocks
									//returns true if there are any
{
	for (int y = 0; y < gridHeight; y++)
	{
		for (int x = 0; x < gridWidth;x++)
		{
			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
			if(GetBlockAt(x,y) != NULL && GetBlockAt(x+1,y) != NULL && GetBlockAt(x+2,y) != NULL )
			{
				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x+1,y)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x+2,y)->GetType())
				{
					return true;
				}
			}
		}
	}
	
	//Vertical Check
	for (int x = 0; x < gridWidth;x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{
			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
			if(GetBlockAt(x,y) != NULL && GetBlockAt(x,y+1) != NULL && GetBlockAt(x,y+2) != NULL )
			{
				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+1)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+2)->GetType())
				{
					return true;
				}
			}
		}
	}
	
	return false;
}

void GameScene::CalculatePositioning()
{
		//Horizontal Check
	for (int y = 0; y < gridHeight; y++)
	{
		for (int x = 0; x < gridWidth;x++)
		{
			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
			if(GetBlockAt(x,y) != NULL && GetBlockAt(x+1,y) != NULL && GetBlockAt(x+2,y) != NULL )
			{
				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x+1,y)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x+2,y)->GetType())
				{
					std::cout << "H: Deleted at (" << x*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y)->GetType() << std::endl;
					std::cout << "H: Deleted at (" << (x+1)*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x+1,y)->GetType() << std::endl;
					std::cout << "H: Deleted at (" << (x+2)*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x+2,y)->GetType() << std::endl;
				
					DeleteSprite(GetBlockAt(x,y));
					DeleteSprite(GetBlockAt(x+1,y));
					DeleteSprite(GetBlockAt(x+2,y));
				}
			}
		}
	}
	
	//Vertical Check
	for (int x = 0; x < gridWidth;x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{
			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
			if(GetBlockAt(x,y) != NULL && GetBlockAt(x,y+1) != NULL && GetBlockAt(x,y+2) != NULL )
			{
				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+1)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+2)->GetType())
				{
					std::cout << "V: Deleted at (" << x*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y)->GetType() << std::endl;
					std::cout << "V: Deleted at (" << (x)*GetBlockAt(x,y)->GetTransformRect()->w << "," << (y+1)*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y+1)->GetType() << std::endl;
					std::cout << "V: Deleted at (" << (x)*GetBlockAt(x,y)->GetTransformRect()->w << "," << (y+2)*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y+2)->GetType() << std::endl;
				
					DeleteSprite(GetBlockAt(x,y));
					DeleteSprite(GetBlockAt(x,y+1));
					DeleteSprite(GetBlockAt(x,y+2));
				}
			}
		}
	}
}

void GameScene::update(double deltaTime)
{
	for(int i = 0; i < blocks.size();i++)
	{
		blocks[i]->Update(deltaTime);
	}
	
	for (int y = -7; y < -6; y++)//Generate blocks off-screen that will fall from up-top
	{
		for (int x = 0; x < gridWidth;x++)
		{
			if(GetBlockAt(x,y) == NULL)
			{
				Block* bta = new Block(x * blockDimention, y * blockDimention, blockScaleFactor);
				AddSprite(bta);
				blocks.push_back(bta); 
				bta = NULL;
			}
		}
	}
	
	for (int y = gridHeight-2; y >= -7; y--) //line before last
	{
		for (int x = gridWidth-1; x >= 0;x--)
		{
			if(GetBlockAt(x,y) != NULL)
			{
				int k = 0;
				while(GetBlockAt(x,y+k+1) == NULL && y+k+1 != gridHeight) //god knows why it's y+k+1 but works
				{
					if(y < gridHeight - k)
						k++;
				}
				
				if(GetBlockAt(x,y)->GetType()!= Block::Type::Static) //empty blocks are static, they do not need a destination position
					GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+k)*GetBlockAt(x,y)->GetTransformRect()->h);
			
			}
		}
	}
	
	for(int i = 0; i < blocks.size(); i++)
	{
		doCalculations = true;
		if(blocks[i]->IsMoving())
		{
			doCalculations = false;
			break;
		}
	}
	
	if(doCalculations)
	{
		CalculatePositioning();
		
		for(int i = 0; i < blocks.size(); i++)
		{
			CheckBottomSides(blocks[i]);
		}
	}
}

void GameScene::render(Window* window)
{
	SDL_SetRenderDrawColor( window->GetRenderer(), 0x00, 0x00, 0x00, 0x00 );
			//Clear screen
	SDL_RenderClear( window->GetRenderer() );
	
	for(int i = 0; i < sprites.size(); i++)
	{
		SDL_Rect adjustedRect = {sprites[i]->GetTransformRect()->x + blocksOffset.x,sprites[i]->GetTransformRect()->y + blocksOffset.y,
		sprites[i]->GetTransformRect()->w,sprites[i]->GetTransformRect()->h};
		
		SDL_RenderCopy( window->GetRenderer(),sprites[i]->GetTexture(),NULL,&adjustedRect); 
	}
	//Update screen
	SDL_RenderPresent( window->GetRenderer() );
}

void GameScene::handleInput(SDL_Event e)
{
	int x,y;
	SDL_GetMouseState(&x,&y);
	if(e.type == SDL_MOUSEBUTTONDOWN && doCalculations)
	{
		int N = blocks.size();

		for(int i = 0; i < N; i++)
		{
			if(blocks[i] != NULL)
			{
				if(blocks[i]->GetType() != Block::Type::Static &&
					blocks[i]->GetYCoord() >= 0)
				{
					if(x > blocks[i]->GetDesiredXPos() + blocksOffset.x && x < blocks[i]->GetDesiredXPos() + blocksOffset.x + blocks[i]->GetTransformRect()->w
					&& y > blocks[i]->GetDesiredYPos() + blocksOffset.y && y < blocks[i]->GetDesiredYPos() + blocksOffset.y + blocks[i]->GetTransformRect()->h)
					{
						//std::cout << "Clicked on " << blocks[i]->GetDesiredXPos() << "," << blocks[i]->GetDesiredYPos() << std::endl;
						
						if(block1 == NULL)
						{
							block1 = blocks[i];
							std::cout << "B1 " << block1->GetXCoord() << "," << block1->GetYCoord() << " SET " << std::endl;
							
							break;
						}
						else if(block2 == NULL && block1 != NULL)
						{
							block2 = blocks[i];
							std::cout << "B2 " << block2->GetXCoord() << "," << block2->GetYCoord() << " SET " << std::endl;

							if(
							(block2->GetXCoord() == block1->GetXCoord() + 1 && 
							block2->GetYCoord() == block1->GetYCoord()) || 
							
							(block2->GetXCoord() == block1->GetXCoord() - 1 && 
							block2->GetYCoord() == block1->GetYCoord()) || 
							
							(block2->GetYCoord() == block1->GetYCoord() + 1 && 
							block2->GetXCoord() == block1->GetXCoord()) || 
							
							(block2->GetYCoord() == block1->GetYCoord() - 1 &&
							block2->GetXCoord() == block1->GetXCoord())
							)
							{
								std::cout << "Switching" << std::endl;
								int x = block2->GetXPos();
								int y = block2->GetYPos();
								block2->SetPos(block1->GetXPos(), block1->GetYPos());
								block2->SetDesiredPos(block1->GetXPos(), block1->GetYPos());
								
								block1->SetPos(x,y);
								block1->SetDesiredPos(x,y);
								
								if(PreCalculatePositioning() == true)
								{
									block1 = NULL;
									block2 = NULL;
									break;
								}
								else 
								{
									std::cout << "No matches found" << std::endl;
									int x = block2->GetXPos();
									int y = block2->GetYPos();
									block2->SetPos(block1->GetXPos(), block1->GetYPos());
									block2->SetDesiredPos(block1->GetXPos(), block1->GetYPos());
									
									block1->SetPos(x,y);
									block1->SetDesiredPos(x,y);
									
									block1 = NULL;
									block2 = NULL;
								}
							}
							else
							{
								std::cout << "Block out of bounds" << std::endl;

								block1 = NULL;
								block2 = NULL;
								break;
							}

						}
					}
				}
			}
		}
	}
	
	for(int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->HandleEvents(e);
	}
}

void GameScene::CheckBottomSides(Block* block) //if the block is empty and you must get
{
	/*
	if( (GetBlockAt(block->GetXCoord()-1,block->GetYCoord()+1) == NULL)
		&& (GetBlockAt(block->GetXCoord(),block->GetYCoord()+1) != NULL))
		{
			if(block->GetXCoord() > 0)
			{
				block->SetDesiredPos(block->GetXCoord()-1,block->GetYCoord()+1);
				std::cout << "Found one" << std::endl;
			}
			
		}
	else if( (GetBlockAt(block->GetXCoord()+1,block->GetYCoord()+1) == NULL)
		&& (GetBlockAt(block->GetXCoord(),block->GetYCoord()+1) != NULL) )
		{
			if(block->GetXCoord() < gridWidth -1)
			{	
				block->SetDesiredPos(block->GetXCoord()+1,block->GetYCoord()+1);
			}
		}
	*/
	
	if (GetBlockAt(block->GetXCoord()-1,block->GetYCoord()) != NULL)
	{	
		if(GetBlockAt(block->GetXCoord()-1,block->GetYCoord())->GetType()
			== Block::Type::Static)
		{
			if(GetBlockAt(block->GetXCoord()-1,block->GetYCoord()+1) == NULL 
			&& block->GetYCoord() < gridHeight - 1)
			{
				block->SetDesiredPos(block->GetXPos()-block->GetTransformRect()->w
				,block->GetYPos()+block->GetTransformRect()->h);
			}
		}
	}
	
	if(GetBlockAt(block->GetXCoord()+1,block->GetYCoord()) != NULL)
	{
		if(GetBlockAt(block->GetXCoord()+1,block->GetYCoord())->GetType()
			== Block::Type::Static)
		{
			if(GetBlockAt(block->GetXCoord()+1,block->GetYCoord()+1) == NULL 
			&& block->GetYCoord() < gridHeight - 1)
			{
				block->SetDesiredPos(block->GetXPos()+block->GetTransformRect()->w
				,block->GetYPos()+block->GetTransformRect()->h);
				std::cout << "Found one " << std::endl;
			}
		}
	}
}

Block* GameScene::GetBlockAt(int x, int y)
{
	Block* bl = NULL;
	int N = blocks.size();
	
	for(int i = 0; i < N; i++)
	{
		if(blocks[i] != NULL)
		{
//			if(blocks[i]->GetXPos() == (x * blocks[i]->GetTransformRect()->w ) && blocks[i]->GetYPos() == (y * blocks[i]->GetTransformRect()->h))
//			{
//				bl = blocks[i];
//			}
			if(blocks[i]->GetDesiredXPos() == (x * blocks[i]->GetTransformRect()->w ) && blocks[i]->GetDesiredYPos() == (y * blocks[i]->GetTransformRect()->h))
			{
				bl = blocks[i];
			}
		}
	}
	
	return bl;
}

void GameScene::AddSprite(Sprite* sta)
{
	sprites.push_back(sta);
}

void GameScene::DeleteSprite(Sprite* std)
{
	for(int i = 0; i < sprites.size(); i++)
	{	
		if(sprites[i] == std)
		{
			sprites.erase(sprites.begin() + i);
		}
	}
	
	int Nb = blocks.size();
	
	for(int i = 0; i < Nb; i++)
	{	
		if(blocks[i] != NULL)
		{
			if(blocks[i] == std)
			{
				blocks.erase(blocks.begin() + i);
			}
		}
	}
}

void GameScene::exit()
{
	for(int i = 0; i < sprites.size();i++)
	{
		delete sprites[i];
	}
}

void GameScene::goToScene(Scene*& activeScene)
{
	
}
