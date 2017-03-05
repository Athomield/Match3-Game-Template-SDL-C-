#ifndef SCENE_H
#define SCENE_H

#include "window.h"

class Scene //these are game states aka room/scene
{
public:
	virtual ~Scene() {};
	virtual void init() = 0;
	virtual void update(double deltaTime) = 0;
	virtual void handleInput(SDL_Event e) = 0;
	virtual void render(Window* window) = 0;
	virtual void exit() = 0;
	
	virtual void goToScene(Scene*& activeScene) = 0;
};

#endif

