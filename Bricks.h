#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"

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
public:
	Rock(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	Rect getBoundingBox() const;
};


