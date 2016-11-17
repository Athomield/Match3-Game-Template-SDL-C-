#include "headers/textureLoader.h"

TextureLoader* TextureLoader::_instance = NULL;

SDL_Texture* TextureLoader::LoadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(mWindow->GetRenderer(), loadedSurface);
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

TextureLoader* TextureLoader::Instance()
{
	if(_instance == NULL)
	{
		_instance = new TextureLoader();
	}
	return _instance;
}

void TextureLoader::SetWindow(Window* window)
{
	mWindow = window;
}

TextureLoader::TextureLoader()
{
	
}

TextureLoader::~TextureLoader()
{
	delete _instance;
	delete mWindow;
	_instance = NULL;
	mWindow = NULL;
}
