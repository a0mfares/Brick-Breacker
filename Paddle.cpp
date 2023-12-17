#include "Paddle.h"
#include "game.h"
#include "gameConfig.h"



Paddle::Paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :collidable(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\Paddle\\Paddle.jpg";
}

void Paddle::collisionAction()
{
	
}



point Paddle::getpoint() const
{
	return uprLft;
}

void Paddle::setpoint(point p)
{
	uprLft = p;
}

Paddle::Rect Paddle::getBoundingBox() const
{
    Rect boundingBox;
    // Adjust the bounding box based on the paddle's dimensions
    boundingBox.upperLeft.x = uprLft.x;
    boundingBox.upperLeft.y = uprLft.y;
    boundingBox.lowerRight.x = uprLft.x + config.padlewidth;
    boundingBox.lowerRight.y = uprLft.y + config.padleheight;
    return boundingBox;
}

