#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "textureLoader.h"

class TextureLoader;

class Window
{
	public:
		Window();
		~Window();
		bool Init();
		SDL_Rect* GetCamera();
		void SetCamera(int x, int y, int w, int h);
		SDL_Window* GetWindow() const;
		SDL_Renderer* GetRenderer() const;
		
	private:
		const int mHeight = 640;
		const int mWidth = 400;
		SDL_Window* mWindow = NULL; //SDL window
		SDL_Renderer* mRenderer = NULL; // Window renderer 
		SDL_Rect mCamera ;
};

#endif
