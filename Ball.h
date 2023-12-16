#pragma once
#include "drawable.h"
#include "collidable.h"
class Ball : public  collidable
{
	int BallRad = 10;
	
	
public:
	
	Ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void moveball();
	
	void  draw() const;
	struct factor;
	//factor checkcollison(Paddle* , Ball* ball);
	//void ballmotion();

};

