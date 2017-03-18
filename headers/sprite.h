#ifndef SPRITE_H
#define SPRITE_H

#include "window.h"

class Sprite
{
public:
		Sprite(int x, int y);
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
		void SetZIndex(int _newZIndex);
		int GetZIndex();
		void SetOffset(int _x, int _y);
		enum LayerDepthIndex {Index_Background = 0,Index_ForeBackground = 10,Index_Normal = 20,Index_GUI = 30};
protected:
		int mZIndex;
		SDL_Texture* mTexture;
		float mX,mY;
		int mXOffset, mYOffset;
		int mWidth, mHeight;
		float mXScaleFactor, mYScaleFactor;
		SDL_Rect transformRect;
};

#endif
