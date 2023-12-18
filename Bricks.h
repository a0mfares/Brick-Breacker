#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"
#include <iostream>
using namespace std;

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_HRD,	//Hard Brick
	BRK_ROCK,

	//TODO: Add more types
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	int strength;

};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	Rect getBoundingBox() const;
};

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////

class hardBrick :public brick
{
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	Rect getBoundingBox() const;
};

////////////////////////////////////////////////////  class Rock  /////////////////////////////////

class Rock :public brick
{
	float deflectionAngle = std::rand() % 46; // Random angle between 0 and 45 degrees
	int Xinc = 15 * 3 * std::cos(deflectionAngle * (3.1415926535 / 180.0f));
	int Yinc = 15 * 3 * std::cos(deflectionAngle * (3.1415926535 / 180.0f));
public:
	Rock(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	Rect getBoundingBox() const;
};


