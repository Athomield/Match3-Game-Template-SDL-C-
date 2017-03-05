#ifndef LANDINGMENUSCENE_H
#define LANDINGMENUSCENE_H

#include "window.h"
#include "scene.h"
#include "game_scene.h"
#include "sprite.h"
#include "block.h"
#include <vector>

class LandingMenuScene : public Scene
{
	
public:
	LandingMenuScene();
	virtual ~LandingMenuScene();
	virtual void init();
	virtual void update(double deltaTime);
	virtual void handleInput(SDL_Event e);
	virtual void render(Window* window);
	virtual void exit();
	
	virtual void goToScene(Scene*& activeScene);
private:
	void AddSprite(Sprite* sta);
	Scene* nextScene = NULL;
	
private:
	std::vector<Sprite*> sprites;
	Sprite* landingPlayButton = NULL;
};

#endif