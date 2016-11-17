#ifndef SPRITE_H
#define SPRITE_H

#include "window.h"

class Sprite
{
	public:
		Sprite(std::string path);
		Sprite(std::string path,int x, int y);
		Sprite(std::string path,int x, int y, float scale);
		Sprite(std::string path,int x, int y, float xScale, float yScale);

		virtual ~Sprite();
		SDL_Texture* GetTexture();
		void SetTexture(std::string path);
		void SetPos(int x, int y);
		SDL_Rect* GetTransformRect();
		void HandleEvents(SDL_Event e);
		virtual void Update(double deltaTime);
	protected:
		SDL_Texture* mTexture;
		float mX,mY;
		int mWidth, mHeight;
		float mXScaleFactor, mYScaleFactor;
		SDL_Rect transformRect;
};

#endif
