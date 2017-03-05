#include "headers/sprite.h"

Sprite::Sprite(int x, int y)
{
	//mTexture = TextureLoader::Instance()->LoadTexture(path);
	//SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = x;
	mY = y;
	mXScaleFactor = mYScaleFactor = 1;
	transformRect = {(int)mX, (int)mY, mWidth, mHeight};
	mZIndex = Index_Background;
	mXOffset = mYOffset = 0;
}


Sprite::Sprite(std::string path)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = mY = 0;
	mXScaleFactor = mYScaleFactor = 1;
	mXOffset = mYOffset = 0;
	mZIndex = Index_Background;
}

Sprite::Sprite(std::string path,int x, int y)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = x;
	mY = y;
	mXScaleFactor = mYScaleFactor = 1;
	transformRect = {(int)mX, (int)mY, mWidth, mHeight};
	mXOffset = mYOffset = 0;
	mZIndex = Index_Background;
}

Sprite::Sprite(std::string path,int x, int y, float scale)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = x;
	mY = y;
	mXOffset = mYOffset = 0;
	mXScaleFactor = mYScaleFactor = scale;
	transformRect = {(int)mX,(int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
	mZIndex = Index_Background;
}

Sprite::Sprite(std::string path,int x, int y, float xScale, float yScale)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = x;
	mY = y;
	mXOffset = mYOffset = 0;
	mXScaleFactor = xScale;
	mYScaleFactor = yScale;
	transformRect = {(int)mX, (int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
	mZIndex = Index_Background;
}

SDL_Rect* Sprite::GetTransformRect()
{
	transformRect = {(int)mX + mXOffset, (int)mY + mYOffset, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
	return &transformRect;
}

void Sprite::SetTexture(std::string path)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	transformRect = {(int)mX, (int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
}

void Sprite::SetPos(int x, int y)
{
	mX = x;
	mY = y;
	//transformRect = {(int)mX, (int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
}

void Sprite::SetOffset(int _x, int _y)
{
	mXOffset = _x;
	mYOffset = _y;
	//transformRect = {(int)mX + mXOffset, (int)mY + mYOffset, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
}

int Sprite::GetZIndex()
{
	return mZIndex;
}

void Sprite::SetZIndex(int _newZIndex)
{
	mZIndex = _newZIndex;
}

void Sprite::HandleEvents(SDL_Event e)
{

}

void Sprite::Update(double deltaTime)
{
	
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
}

SDL_Texture* Sprite::GetTexture()
{
	return mTexture;
}
