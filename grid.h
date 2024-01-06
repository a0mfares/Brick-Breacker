#pragma once

#include "drawable.h"
#include "Bricks.h"
#include "collectable.h"


class game;

class grid:public drawable
{
	
	brick*** brickMatrix;		//2D array of brick pointers

	int rows, cols;
	int random = rand() % 4;
	collectable** colected;
	
	
public:
	point index;
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	int addBrick(BrickType brkType, point clickedPoint);
	void deleteBrick(point clicked);
	brick*** getbrickmatrix();
	point collisionAction();
	void deleteBrickOncollison(point index);
	collectable** getcollected();
	

};

