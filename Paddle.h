#pragma once
#include "collidable.h"

class Paddle :public collidable
{
	int movementSpeed = 15;
	game* Game;
	
public:
	Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	point getpoint()const;
	void setpoint(point p);
	Rect getBoundingBox() const override;
	
	

};


