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
	protected:
		static TextureLoader* _instance;
		Window* mWindow;
};

#endif
