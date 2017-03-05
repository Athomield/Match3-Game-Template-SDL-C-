#ifndef LABEL_H
#define	LABEL_H

#include "sprite.h"

class Label : public Sprite
{
public:
	Label(std::string _text);

	void SetText(std::string _text);
	std::string GetText();
private:
	std::string mText;
	int mSize;
	TTF_Font* mFont;
	SDL_Color mColor;

private:
	bool SetLabelTexture();
};

#endif