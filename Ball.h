#pragma once
#include "drawable.h"
#include "collidable.h"
#include "gameConfig.h"

#include <iostream>
using namespace std;
class Ball : public  collidable
{
	int BallRad = 10;
	// Bounce back with a deflection angle between 0 and 45 degrees
	float deflectionAngle = std::rand() % 46; // Random angle between 0 and 45 degrees
	int Xinc = BallRad * 3 * std::sin(deflectionAngle * (3.1415926535 / 180.0f));
	int Yinc = BallRad * 3 * std::cos(deflectionAngle * (3.1415926535 / 180.0f));
	
	
	

	
	
	
public:
	
	Ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void moveball();
	Rect getBoundingBox() const override;
	void setpoint(point r);
	void deleteball();
	void resetxyinc();
	void setxyinczero();
	void reflectball();
	void reflectball(collidable* o);
	void checkforboundies(collidable* o);
	void updatepos();
	void drawgameelements();
	void moveball1();

	
	
	
	
	void  draw() const;
	struct factor;
	//factor checkcollison(Paddle* , Ball* ball);
	//void ballmotion();

};

