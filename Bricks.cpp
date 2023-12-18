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
	strength = 1;
}

void normalBrick::collisionAction()
{
	//TODO: Add collision action logic
	strength--;
	config.Score++;

	if (strength == 0) {
		//delete bricks
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
	strength = 3;
}

void hardBrick::collisionAction()
{
	//TODO: Add collision action logic
	auto brickball = isColliding(pGame->getball(), this);
	if (brickball.collision) {
		strength--;
		config.Score++;
	}
	if (strength == 0) {
		pGame->getGrid()->deleteBrick(brickball.collisionPoint);
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
}

void Rock::collisionAction()
{
	
	auto BallBrickCollide = isColliding(pGame->getball(), this);
	if (BallBrickCollide.collision) {
		// Handle paddle-ball collision
		Yinc = std::abs(Yinc);
		float brickCenterX = (uprLft.x + config.brickWidth) / 2.0f;
		float offset = (uprLft.x - brickCenterX) / (config.brickWidth / 2.0f);


		const float maxBounceAngle = 45.0f;  // Maximum bounce angle in degrees
		float bounceAngle = maxBounceAngle * offset;

		// Rotate the ball's direction by the calculated bounce angle
		float angle = std::atan2(Yinc, Xinc);
		angle = angle + bounceAngle * (3.1415926535 / 180.0f);
		float speed = std::hypot(Xinc, Yinc);
		Xinc = speed * std::cos(angle);
		Yinc = speed * std::sin(angle);
		point ballupr;
		ballupr.x = pGame->getball()->getBoundingBox().upperLeft.x;
		ballupr.y = pGame->getball()->getBoundingBox().upperLeft.y;
		ballupr.x += Xinc;
		ballupr.y += Yinc;
		pGame->getball()->setpoint(ballupr);
	}
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
