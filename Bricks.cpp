#include "Bricks.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
	stren = 1;
	
}

void normalBrick::collisionAction()
{
	//TODO: Add collision action logic
	auto brickball = isColliding(pGame->getball(),this);
	if (brickball.collision) {
		stren--;
		config.Score++;
	}
	
}

normalBrick::Rect normalBrick::getBoundingBox() const
{
	Rect boundingBox;
	// Adjust the bounding box based on the paddle's dimensions
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x + config.brickWidth;
	boundingBox.lowerRight.y = uprLft.y + config.brickHeight;
	return boundingBox;
}

////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\HardBrick.jpg";
	stren = 3;
	
}

void hardBrick::collisionAction()
{
	//TODO: Add collision action logic
	auto brickball = isColliding(pGame->getball(), this);
	if (brickball.collision) {
		stren--;
		config.Score++;
	}
	
}

hardBrick::Rect hardBrick::getBoundingBox() const
{
	Rect boundingBox;
	// Adjust the bounding box based on the paddle's dimensions
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x + config.brickWidth;
	boundingBox.lowerRight.y = uprLft.y + config.brickHeight;
	return boundingBox;
}


////////////////////////////////////////////////////  class Rock  /////////////////////////////////
Rock::Rock(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\RockIcon.jpg";
	stren = 1;
}

void Rock::collisionAction()
{
	
	
}

Rock::Rect Rock::getBoundingBox() const
{
	Rect boundingBox;
	// Adjust the bounding box based on the paddle's dimensions
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x + config.brickWidth;
	boundingBox.lowerRight.y = uprLft.y + config.brickHeight;
	return boundingBox;
}
