#include "headers/game.h"

Game::Game()
{
	//srand(time(NULL));
	mWindow = new Window();
	mScene = new LandingMenuScene();
	mScene->init();
	//doCalculations = true;
	
//	blocksOffset = {50,150,0,0};
//	
//	for(int x = 0; x < 5;x++)
//	{
//		for (int y = 0; y < 7; y++)
//		{
//			AddSprite(new Sprite("../resources/empty_block.png",x * 60, y * 60, 0.3f));
//		}
//	}
//	
//	for (int y = 0; y < 7; y++)
//	{
//		for (int x = 0; x < 5;x++)
//		{
//			Block* bta = new Block(x * 60, y * 60, 0.3f);
//			AddSprite(bta);
//			blocks.push_back(bta); 
//			
//			bta = NULL;
//		}
//	}

	/*	
		int indexOfBlockType = -1;
	int lastY = blocks[0]->GetYPos()+1;
	int k = 1; // coumbo counter
	for (int y = 0; y < 7; y++)
	{
		k = 1;
		for (int x = 0; x < 5;x++)
		{
			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
			
			std::cout << k << std::endl;
			if(GetBlockAt(x,y) != NULL)
			{
				if(GetBlockAt(x,y)->GetType() == indexOfBlockType)
				{
					k++;
					
					if(GetBlockAt(x,y)->GetXPos() == 4*GetBlockAt(x,y)->GetTransformRect()->w)
					{
						if(k == 3 || k >= 4)
						{	
							DeleteSprite(GetBlockAt(x,y));
							DeleteSprite(GetBlockAt(x-1,y));
							DeleteSprite(GetBlockAt(x-2,y));
							
						}
						k = 1;
					}
				}
				else
				{
					if(lastY != GetBlockAt(x,y)->GetYPos())
					{
						k = 1;
						lastY = GetBlockAt(x,y)->GetYPos();
					}
					
					if(k == 3 || k >= 4)
					{	
						DeleteSprite(GetBlockAt(x-1,y));
						DeleteSprite(GetBlockAt(x-2,y));
						DeleteSprite(GetBlockAt(x-3,y));
					}
					
					indexOfBlockType = GetBlockAt(x,y)->GetType();
					k = 1;
				}
			}
		}
	}
	*/
	
	/*
	for(int x = 0; x < blocks.size();x++)
	{		
		if(blocks[x]->GetType() == indexOfBlockType && lastY == blocks[x]->GetYPos())
		{
			k++;
			
			if(x == blocks.size() - 1)
			{
				if(k == 3 || k == 4)
				{
					DeleteSprite(blocks[x - 3]);
					DeleteSprite(blocks[x - 2]);
					DeleteSprite(blocks[x - 1]);
					std::cout << "Deleted of type : " << blocks[x - 1]->GetType() << "," 
					<< blocks[x - 2]->GetType() << "," << blocks[x - 3]->GetType() << std::endl;
				}
			}
		}
		else
		{
			if(k == 3 || k == 4)
			{
				DeleteSprite(blocks[x - 3]);
				DeleteSprite(blocks[x - 2]);
				DeleteSprite(blocks[x - 1]);
				std::cout << "Deleted of type : " << blocks[x - 1]->GetType() << "," << blocks[x - 2]->GetType() << "," << blocks[x - 3]->GetType() << std::endl;
			}
			
			lastY = blocks[x]->GetYPos();
			indexOfBlockType = blocks[x]->GetType();
			k = 1;
		}
	}
	*/
	
	Update();
}

Game::~Game()
{
	Clean();
}

//bool Game::PreCalculatePositioning() //This function checks for matches after a switch of two blocks
//									//returns true if there are any
//{
//	bool test = false;
//	for (int y = 0; y < 7; y++)
//	{
//		for (int x = 0; x < 5;x++)
//		{
//			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
//			if(GetBlockAt(x,y) != NULL && GetBlockAt(x+1,y) != NULL && GetBlockAt(x+2,y) != NULL )
//			{
//				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x+1,y)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x+2,y)->GetType())
//				{
//					test = true;
//				}
//			}
//		}
//	}
//	
//	//Vertical Check
//	for (int x = 0; x < 5;x++)
//	{
//		for (int y = 0; y < 7; y++)
//		{
//			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
//			if(GetBlockAt(x,y) != NULL && GetBlockAt(x,y+1) != NULL && GetBlockAt(x,y+2) != NULL )
//			{
//				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+1)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+2)->GetType())
//				{
//					test = true;
//				}
//			}
//		}
//	}
//	
//	return test;
//}

//void Game::CalculatePositioning()
//{
//		//Horizontal Check
//	for (int y = 0; y < 7; y++)
//	{
//		for (int x = 0; x < 5;x++)
//		{
//			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
//			if(GetBlockAt(x,y) != NULL && GetBlockAt(x+1,y) != NULL && GetBlockAt(x+2,y) != NULL )
//			{
//				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x+1,y)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x+2,y)->GetType())
//				{
//					std::cout << "H: Deleted at (" << x*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y)->GetType() << std::endl;
//					std::cout << "H: Deleted at (" << (x+1)*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x+1,y)->GetType() << std::endl;
//					std::cout << "H: Deleted at (" << (x+2)*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x+2,y)->GetType() << std::endl;
//				
//					DeleteSprite(GetBlockAt(x,y));
//					DeleteSprite(GetBlockAt(x+1,y));
//					DeleteSprite(GetBlockAt(x+2,y));
//				}
//			}
//		}
//	}
//	
//	//Vertical Check
//	for (int x = 0; x < 5;x++)
//	{
//		for (int y = 0; y < 7; y++)
//		{
//			//std::cout << GetBlockAt(x,y)->GetXPos() << "," << GetBlockAt(x,y)->GetYPos() << std::endl;
//			if(GetBlockAt(x,y) != NULL && GetBlockAt(x,y+1) != NULL && GetBlockAt(x,y+2) != NULL )
//			{
//				if(GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+1)->GetType() && GetBlockAt(x,y)->GetType() == GetBlockAt(x,y+2)->GetType())
//				{
//					std::cout << "V: Deleted at (" << x*GetBlockAt(x,y)->GetTransformRect()->w << "," << y*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y)->GetType() << std::endl;
//					std::cout << "V: Deleted at (" << (x)*GetBlockAt(x,y)->GetTransformRect()->w << "," << (y+1)*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y+1)->GetType() << std::endl;
//					std::cout << "V: Deleted at (" << (x)*GetBlockAt(x,y)->GetTransformRect()->w << "," << (y+2)*GetBlockAt(x,y)->GetTransformRect()->h << ") Of type : " <<  GetBlockAt(x,y+2)->GetType() << std::endl;
//				
//					DeleteSprite(GetBlockAt(x,y));
//					DeleteSprite(GetBlockAt(x,y+1));
//					DeleteSprite(GetBlockAt(x,y+2));
//				}
//			}
//		}
//	}
//}

void Game::Update()
{
	bool quit = false;
	Uint32 lastTime = 0, currentTime = SDL_GetTicks();
	double deltaTime = 0;

	//While application is running
	while( !quit )
	{
		lastTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (double)(currentTime - lastTime)/1000;

		HandleEvents(&quit);
		
		mScene->update(deltaTime);
		mScene->goToScene(mScene);
//		for(int i = 0; i < blocks.size();i++)
//		{
//			blocks[i]->Update(deltaTime);
//		}	
		
//		for (int y = -7; y < -6; y++)//Generate blocks off-screen that will fall from up-top
//		{
//			for (int x = 0; x < 5;x++)
//			{
//				if(GetBlockAt(x,y) == NULL)
//				{
//					Block* bta = new Block(x * 60, y * 60, 0.3f);
//					AddSprite(bta);
//					blocks.push_back(bta); 
//					bta = NULL;
//				}
//			}
//		}
//		
//		for (int y = 5; y >= -7; y--) //line before last
//		{
//			for (int x = 4; x >= 0;x--)
//			{
//				if(GetBlockAt(x,y) != NULL)
//				{
//					int k = 0;
//					while(GetBlockAt(x,y+k+1) == NULL && y+k+1 != 7)
//					{
//						if(y < 7 - k)
//							k++;
//					}
//					GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+k)*GetBlockAt(x,y)->GetTransformRect()->h);
//					//{
//					/*if(GetBlockAt(x,y+1) == NULL)
//					{
//						if(GetBlockAt(x,y+2) == NULL && y < 5)
//						{
//							if(GetBlockAt(x,y+3) == NULL && y < 4)
//							{
//								if(GetBlockAt(x,y+4) == NULL && y < 3)
//								{
//									if(GetBlockAt(x,y+5) == NULL && y < 2)
//									{
//										if(GetBlockAt(x,y+6) == NULL && y < 1)
//										{
//											if(GetBlockAt(x,y+7) == NULL && y < 0)
//											{
//												if(GetBlockAt(x,y+8) == NULL && y < -1)
//												{
//													if(GetBlockAt(x,y+9) == NULL && y < -1)
//													{
//														if(GetBlockAt(x,y+10) == NULL && y < -1)
//														{
//															GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+10)*GetBlockAt(x,y)->GetTransformRect()->h);
//														}
//														else
//														{
//															GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+9)*GetBlockAt(x,y)->GetTransformRect()->h);
//														}
//													}
//													else
//													{
//														GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+8)*GetBlockAt(x,y)->GetTransformRect()->h);
//													}
//												}
//												else
//												{
//													GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+7)*GetBlockAt(x,y)->GetTransformRect()->h);
//												}
//											}
//											else
//											{
//												GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+6)*GetBlockAt(x,y)->GetTransformRect()->h);
//											}
//										}
//										else
//										{
//											GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+5)*GetBlockAt(x,y)->GetTransformRect()->h);
//										}
//									}
//									else
//									{
//										GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+4)*GetBlockAt(x,y)->GetTransformRect()->h);
//									}
//								}
//								else
//								{
//									GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+3)*GetBlockAt(x,y)->GetTransformRect()->h);
//								}
//							}
//							else
//							{
//								GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+2)*GetBlockAt(x,y)->GetTransformRect()->h);
//							}
//						}
//						else
//						{
//							GetBlockAt(x,y)->SetDesiredPos(x * GetBlockAt(x,y)->GetTransformRect()->w, (y+1)*GetBlockAt(x,y)->GetTransformRect()->h);
//						}
//					}*/
//					//}
//				}
//			}
//		}
//		
//		for(int i = 0; i < blocks.size(); i++)
//		{
//			doCalculations = true;
//			if(blocks[i]->IsMoving())
//			{
//				doCalculations = false;
//				break;
//			}
//		}
//		
//		if(doCalculations)
//		{
//			CalculatePositioning();
//		}
	
		Render();	
		//std::cout << blocks.size() << std::endl;
	}
}

void Game::Render()
{
//	SDL_SetRenderDrawColor( mWindow->GetRenderer(), 0x00, 0x00, 0x00, 0x00 );
//			//Clear screen
//	SDL_RenderClear( mWindow->GetRenderer() );
//	
//	for(int i = 0; i < sprites.size(); i++)
//	{
//		SDL_Rect adjustedRect = {sprites[i]->GetTransformRect()->x + blocksOffset.x,sprites[i]->GetTransformRect()->y + blocksOffset.y,
//		sprites[i]->GetTransformRect()->w,sprites[i]->GetTransformRect()->h};
//		
//		SDL_RenderCopy( mWindow->GetRenderer(),sprites[i]->GetTexture(),NULL,&adjustedRect); 
//	}
//	//Update screen
//	SDL_RenderPresent( mWindow->GetRenderer() );
	mScene->render(mWindow);
}

void Game::HandleEvents(bool* quit)
{
	SDL_Event e;
		//Handle events on queue
	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			*quit = true;
		}
		mScene->handleInput(e);
		//std::cout << block1 << "," << block2 << std::endl;
		
//		int x,y;
//		SDL_GetMouseState(&x,&y);
//		if(e.type == SDL_MOUSEBUTTONDOWN && doCalculations)
//		{
//			int N = blocks.size();
//	
//			for(int i = 0; i < N; i++)
//			{
//				if(blocks[i] != NULL)
//				{
//					if(x > blocks[i]->GetDesiredXPos() + blocksOffset.x && x < blocks[i]->GetDesiredXPos() + blocksOffset.x + blocks[i]->GetTransformRect()->w
//					&& y > blocks[i]->GetDesiredYPos() + blocksOffset.y && y < blocks[i]->GetDesiredYPos() + blocksOffset.y + blocks[i]->GetTransformRect()->h)
//					{
//						//std::cout << "Clicked on " << blocks[i]->GetDesiredXPos() << "," << blocks[i]->GetDesiredYPos() << std::endl;
//						
//						if(block1 == NULL)
//						{
//							block1 = blocks[i];
//							std::cout << "B1 " << block1->GetXCoord() << "," << block1->GetYCoord() << " SET " << std::endl;
//							break;
//						}
//						else if(block2 == NULL && block1 != NULL)
//						{
//							block2 = blocks[i];
//							std::cout << "B2 " << block2->GetXCoord() << "," << block2->GetYCoord() << " SET " << std::endl;
//
//							if(
//							(block2->GetXCoord() == block1->GetXCoord() + 1 && 
//							block2->GetYCoord() == block1->GetYCoord()) || 
//							
//							(block2->GetXCoord() == block1->GetXCoord() - 1 && 
//							block2->GetYCoord() == block1->GetYCoord()) || 
//							
//							(block2->GetYCoord() == block1->GetYCoord() + 1 && 
//							block2->GetXCoord() == block1->GetXCoord()) || 
//							
//							(block2->GetYCoord() == block1->GetYCoord() - 1 &&
//							block2->GetXCoord() == block1->GetXCoord())
//							)
//							{
//								std::cout << "Switching" << std::endl;
//								int x = block2->GetXPos();
//								int y = block2->GetYPos();
//								block2->SetPos(block1->GetXPos(), block1->GetYPos());
//								block2->SetDesiredPos(block1->GetXPos(), block1->GetYPos());
//								
//								block1->SetPos(x,y);
//								block1->SetDesiredPos(x,y);
//								
//								if(PreCalculatePositioning() == true)
//								{
//									block1 = NULL;
//									block2 = NULL;
//									break;
//								}
//								else 
//								{
//									std::cout << "No matches found" << std::endl;
//									int x = block2->GetXPos();
//									int y = block2->GetYPos();
//									block2->SetPos(block1->GetXPos(), block1->GetYPos());
//									block2->SetDesiredPos(block1->GetXPos(), block1->GetYPos());
//									
//									block1->SetPos(x,y);
//									block1->SetDesiredPos(x,y);
//									
//									block1 = NULL;
//									block2 = NULL;
//								}
//							}
//							else
//							{
//								std::cout << "Block out of bounds" << std::endl;
//
//								block1 = NULL;
//								block2 = NULL;
//								break;
//							}
//
//						}
//					}
//				}
//			}
//		}
//		
//		for(int i = 0; i < sprites.size(); i++)
//		{
//			sprites[i]->HandleEvents(e);
//		}
		
	}
}

//Block* Game::GetBlockAt(int x, int y)
//{
//	Block* bl = NULL;
//	int N = blocks.size();
//	
//	for(int i = 0; i < N; i++)
//	{
//		if(blocks[i] != NULL)
//		{
////			if(blocks[i]->GetXPos() == (x * blocks[i]->GetTransformRect()->w ) && blocks[i]->GetYPos() == (y * blocks[i]->GetTransformRect()->h))
////			{
////				bl = blocks[i];
////			}
//			if(blocks[i]->GetDesiredXPos() == (x * blocks[i]->GetTransformRect()->w ) && blocks[i]->GetDesiredYPos() == (y * blocks[i]->GetTransformRect()->h))
//			{
//				bl = blocks[i];
//			}
//		}
//	}
//	
//	return bl;
//}
//
//void Game::AddSprite(Sprite* sta)
//{
//	sprites.push_back(sta);
//}
//
//void Game::DeleteSprite(Sprite* std)
//{
//	for(int i = 0; i < sprites.size(); i++)
//	{	
//		if(sprites[i] == std)
//		{
//			sprites.erase(sprites.begin() + i);
//		}
//	}
//	
//	int Nb = blocks.size();
//	
//	for(int i = 0; i < Nb; i++)
//	{	
//		if(blocks[i] != NULL)
//		{
//			if(blocks[i] == std)
//			{
//				blocks.erase(blocks.begin() + i);
//			}
//		}
//	}
//}

void Game::Clean()
{
	delete mWindow;
	delete mScene;
//	for(int i = 0; i < sprites.size();i++)
//	{
//		delete sprites[i];
//	}
}
