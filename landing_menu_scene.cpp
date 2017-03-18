#include "headers/landing_menu_scene.h"

void LandingMenuScene::init()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			AddSprite(new Sprite("../resources/tileable_background.png",x*512*.5,y*512*.5,.5));	
		}
	}
	Sprite* landing_button = new Sprite("../resources/gui_landing_start_button.png",0,0,.5);
	
	landing_button->SetPos(Window::width/2 - landing_button->GetTransformRect()->w/2,
	Window::height/1.5 - landing_button->GetTransformRect()->h/2);
	
	landingPlayButton = landing_button;
	
	AddSprite(landing_button);
}

void LandingMenuScene::update(double deltaTime)
{
	
}

void LandingMenuScene::handleInput(SDL_Event e)
{
	int mouseX,mouseY;
	SDL_GetMouseState(&mouseX,&mouseY);
	
	if(e.type == SDL_MOUSEBUTTONDOWN)
	{
		if(mouseX > landingPlayButton->GetTransformRect()->x &&
		mouseX < landingPlayButton->GetTransformRect()->x + landingPlayButton->GetTransformRect()->w
		&& mouseY > landingPlayButton->GetTransformRect()->y &&
		mouseY < landingPlayButton->GetTransformRect()->y + landingPlayButton->GetTransformRect()->h)
		nextScene = new GameScene();
	}
}

void LandingMenuScene::render(Window* window)
{
	SDL_SetRenderDrawColor( window->GetRenderer(), 0x00, 0x00, 0x00, 0x00 );
			//Clear screen
	SDL_RenderClear( window->GetRenderer() );
	
	for(int i = 0; i < sprites.size(); i++)
	{
		SDL_Rect adjustedRect = {sprites[i]->GetTransformRect()->x,sprites[i]->GetTransformRect()->y
		,sprites[i]->GetTransformRect()->w,sprites[i]->GetTransformRect()->h};
		
		SDL_RenderCopy( window->GetRenderer(),sprites[i]->GetTexture(),NULL,&adjustedRect); 
	}
	//Update screen
	SDL_RenderPresent( window->GetRenderer() );
}

void LandingMenuScene::exit()
{
	for(int i = 0; i < sprites.size();i++)
	{
		delete sprites[i];
	}
}

void LandingMenuScene::AddSprite(Sprite* sta)
{
	sprites.push_back(sta);
}

LandingMenuScene::~LandingMenuScene()
{
	exit();
}

LandingMenuScene::LandingMenuScene()
{
}

void LandingMenuScene::goToScene(Scene*& activeScene)
{
	if(nextScene == NULL || activeScene == nextScene) return;
	activeScene->exit();
	activeScene = nextScene;
	activeScene->init();
}