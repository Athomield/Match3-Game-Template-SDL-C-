#include "headers/label.h"

Label::Label(std::string _text) : Sprite(0,0)
{
	mTexture = NULL;
	mText = _text;
	mColor = {255,255,255};
	mSize = 28;

	mFont = TTF_OpenFont("../resources/KOMIKAB.ttf",mSize);
	
	if( mFont == NULL ) 
	{ 
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() ); 
	}
	
	SetLabelTexture();
	
	mZIndex = Index_GUI;
}

void Label::SetText(std::string _text)
{
	mText = _text;
	SetLabelTexture();
}

std::string Label::GetText()
{
	return mText;
}

bool Label::SetLabelTexture()
{
	SDL_DestroyTexture(mTexture);
	
	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, mText.c_str(), mColor);
	
	if(textSurface == NULL) 
	{ 
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() ); 
	}
	else
	{
		mTexture = SDL_CreateTextureFromSurface(TextureLoader::Instance()->GetWindow()->GetRenderer(), textSurface);
		
		if( mTexture == NULL )
		{ 
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() ); 
		}
		else
		{
			mWidth = textSurface->w; mHeight = textSurface->h;
			transformRect = {(int)mX, (int)mY, mWidth, mHeight};SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
		}
		
		 SDL_FreeSurface( textSurface );
	}

	
	return mTexture != NULL;	
}

