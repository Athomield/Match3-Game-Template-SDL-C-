#include "headers/sprite.h"

Sprite::Sprite(std::string path)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = mY = 0;
	mXScaleFactor = mYScaleFactor = 1;
}

Sprite::Sprite(std::string path,int x, int y)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = x;
	mY = y;
	mXScaleFactor = mYScaleFactor = 1;
	transformRect = {(int)mX, (int)mY, mWidth, mHeight};
}

Sprite::Sprite(std::string path,int x, int y, float scale)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = x;
	mY = y;
	mXScaleFactor = mYScaleFactor = scale;
	transformRect = {(int)mX,(int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
}

Sprite::Sprite(std::string path,int x, int y, float xScale, float yScale)
{
	mTexture = TextureLoader::Instance()->LoadTexture(path);
	SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
	mX = x;
	mY = y;
	mXScaleFactor = xScale;
	mYScaleFactor = yScale;
	transformRect = {(int)mX, (int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
}

SDL_Rect* Sprite::GetTransformRect()
{
	transformRect = {(int)mX, (int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
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
	transformRect = {(int)mX, (int)mY, (int)(mWidth * mXScaleFactor), (int)(mHeight * mYScaleFactor)};
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
