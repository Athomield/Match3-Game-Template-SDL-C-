#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "window.h"

class Window;

class TextureLoader
{
	public:
		TextureLoader();
		~TextureLoader();
		static TextureLoader* Instance();
		SDL_Texture* LoadTexture(std::string path);
		void SetWindow(Window* window);
		Window* GetWindow();
	protected:
		static TextureLoader* _instance;
		TTF_Font* mFont;
		Window* mWindow;
};

#endif
