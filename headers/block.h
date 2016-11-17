#ifndef BLOCK_H
#define BLOCK_H

#include "sprite.h"
#include <time.h> 
#include <math.h>
#include <stdlib.h>

class Block : public Sprite
{
	public:
		enum Type {Apple,Banana,Orange,Grape};
		
	private:
		Type mType;
		int desiredXPos, desiredYPos;
		float mDropVelocity;
		bool mIsMoving;
		
		bool isTiltRight, isTiltLeft, isTiltUp, isTiltDown;
		
		Uint32 animationTimer;
	public:
		Block(int x, int y, float scale);
		void SetDesiredPos(int x, int y);

		virtual void Update(double deltaTime);
		bool IsMoving();
		int GetDesiredYPos();
		int GetDesiredXPos();
		int GetXPos();
		int GetYPos();
		int GetYCoord();
		int GetXCoord();
		void TiltRight(double deltaTime);
		void StartTiltRight();
		~Block();
		Type GetType();
	
};

#endif
