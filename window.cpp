#include "headers/window.h"

Window::Window()
{
	Init();
	mCamera = {0,0,640,480};
	TextureLoader::Instance()->SetWindow(this);
}

Window::~Window()
{
	SDL_DestroyRenderer( mRenderer );
	SDL_DestroyWindow( mWindow );
	mWindow = NULL;
	mRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool Window::Init()
{
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		mWindow = SDL_CreateWindow( "First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN );
		if( mWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			mRenderer = SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC  );
			if( mRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( mRenderer, 0x66, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

SDL_Window* Window::GetWindow() const
{
	return mWindow;
}

SDL_Rect* Window::GetCamera()
{
	return &mCamera;
}

void Window::SetCamera(int x,int y, int w, int h)
{
	mCamera = {x,y,w,h};
}


SDL_Renderer* Window::GetRenderer() const
{
	return mRenderer;
}
