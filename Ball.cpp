#include "Ball.h"
#include "game.h"
#include "gameConfig.h"
#include "CMUgraphicsLib\auxil.h"
#include <iostream>
using namespace std;


Ball::Ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :collidable(r_uprleft, r_width, r_height, r_pGame)
{
	
}

void Ball::collisionAction()
{
	auto PadleBallCollide = isColliding(this,pGame->getpadle());
	if (PadleBallCollide.collision == true) {
        this->moveball();

	}

}

void Ball::moveball()
{
    pGame->getWind()->SetBuffering(true);
    pGame->getWind()->FlushKeyQueue();   
    // Check for paddle-ball collision
    this->checkforboundies(pGame->getpadle());
    this->reflectball();
   
    // Draw the game elements
    this->drawgameelements();
    // Update ball position
    this->updatepos();
    //draw ball
    this->draw();
       
}

Ball::Rect Ball::getBoundingBox() const
{
    Rect boundingBox;
    boundingBox.upperLeft.x = uprLft.x - BallRad;
    boundingBox.upperLeft.y = uprLft.y - BallRad;
    boundingBox.lowerRight.x = uprLft.x + BallRad;
    boundingBox.lowerRight.y = uprLft.y + BallRad;
    return boundingBox;
}

void Ball::setpoint(point r)
{
    uprLft = r;
}

void Ball::deleteball()
{
   
    pGame->getWind()->SetPen(LAVENDER, 1);
    pGame->getWind()->SetBrush(LAVENDER);
    pGame->getWind()->DrawCircle(uprLft.x, uprLft.y, width, FILLED);
}

void Ball::resetxyinc()
{
    float deflectionAngle = std::rand() % 46; // Random angle between 0 and 45 degrees
    Xinc = BallRad * 3 * std::sin(deflectionAngle * (3.1415926535 / 180.0f));
    Yinc = BallRad * 3 * std::cos(deflectionAngle * (3.1415926535 / 180.0f));

}

void Ball::setxyinczero()
{
    Xinc = 0;
    Yinc = 0;

}

void Ball::reflectball()
{
  
    bool isvertical = true;

    // Check for paddle-ball collision
    auto PadleBallCollide = isColliding(this, pGame->getpadle());

    

    // Check for paddle collision
    if (PadleBallCollide.collision) {


        // Adjust the ball's position to prevent it from sticking to the boundary
        uprLft.y = (uprLft.y < config.toolBarHeight + BallRad) ? config.toolBarHeight + BallRad : PadleBallCollide.collisionPoint.y - (BallRad + 1);

        // Handle paddle-ball collision
        Yinc = -std::abs(Yinc);
        float paddleCenterX = (pGame->getpadle()->getBoundingBox().upperLeft.x + pGame->getpadle()->getBoundingBox().lowerRight.x) / 2.0f;
        float offset = (uprLft.x - paddleCenterX) / (config.padlewidth / 2.0f);

        // Check if the collision point is within the center half area of the paddle
        bool isInCenterHalf = ((PadleBallCollide.collisionPoint.x <= paddleCenterX && PadleBallCollide.collisionPoint.x > pGame->getpadle()->getBoundingBox().upperLeft.x + (config.padlewidth / 3)))
            || (PadleBallCollide.collisionPoint.x >= paddleCenterX && PadleBallCollide.collisionPoint.x < pGame->getpadle()->getBoundingBox().upperLeft.x + ((2 * config.padlewidth) / 3));

        if (isInCenterHalf) {
            // Reflect the ball vertically
            Yinc = -std::abs(Yinc);
            Xinc = 0;
        }
        else {
            // Calculate the bounce angle based on the position of the ball relative to the paddle's center
            const float maxBounceAngle = 45.0f;  // Maximum bounce angle in degrees
            float bounceAngle = maxBounceAngle * offset;

            // Rotate the ball's direction by the calculated bounce angle
            float angle = atan2(Yinc, Xinc);
            angle = angle + bounceAngle * (3.1415926535 / 180.0f);
            float speed = max(hypot(Yinc, Xinc),20);
            Xinc = speed * cos(angle);
            Yinc = speed * sin(angle);

        }
    }
}

void Ball::reflectball(collidable* o)
{
    
    
    Yinc = -Yinc;
   
    // Determine if the collision is on the left or right side
    bool collideLeft = uprLft.x <  o->getBoundingBox().upperLeft.x&& uprLft.x + BallRad >  o->getBoundingBox().upperLeft.x;
    bool collideRight = uprLft.x > o->getBoundingBox().lowerRight.x && uprLft.x - BallRad < o->getBoundingBox().lowerRight.x;

    // Adjust the position and reflect horizontally if collision is on the left or right side
    if (collideLeft) {
        uprLft.x = o->getBoundingBox().upperLeft.x - BallRad; // Adjust position to the left edge of the object
        Xinc = -std::abs(Xinc); // Reflect to the left
    }
    else if (collideRight) {
        uprLft.x = o->getBoundingBox().lowerRight.x + BallRad; // Adjust position to the right edge of the object
        Xinc = std::abs(Xinc); // Reflect to the right
    }
    this->updatepos();
}

void Ball::checkforboundies(collidable* o)
{
    auto ObjectBallCollide = isColliding(this, o);
    // Check for vertical boundary collision

    if (uprLft.y - BallRad <= config.toolBarHeight || ObjectBallCollide.collision) {

        // Invert the vertical direction
        Yinc = -Yinc;
    }


    // Check for horizontal boundary collision
    if (uprLft.x - BallRad <= 0 || uprLft.x + BallRad >= config.windWidth - 10) {
        // Invert the horizontal direction
        Xinc = -Xinc;
    }
}

void Ball::updatepos()
{
    uprLft.x += Xinc;
    uprLft.y += Yinc;
}

void Ball::drawgameelements()
{
    pGame->getWind()->SetPen(LAVENDER, 1);
    pGame->getWind()->SetBrush(LAVENDER);
    pGame->getWind()->DrawRectangle(0, 0, config.windWidth, config.windHeight, FILLED);
    pGame->getGrid()->draw();
    pGame->gettoolbarr()->draw();
    pGame->getpadle()->draw();
}

void Ball::moveball1()
{
    pGame->getWind()->SetBuffering(true);
    pGame->getWind()->FlushKeyQueue();
   
    this->checkforboundies(pGame->getpadle());
    this->reflectball();
    
  
    
    this->updatepos();
    
}







void Ball::draw() const
{

	window* pWind = pGame->getWind();
    color c;
    
    if (config.fired) {
        c = RED;
    }
    else
        c = BLACK;
	pWind->SetPen(c, 1);
	pWind->SetBrush(c);
	pWind->DrawCircle(uprLft.x, uprLft.y, width,FILLED);

}


//float Ball::calculateReflectionAngle(Brick* brick) {
//    // Get the bounding box of the brick
//    Rect brickBoundingBox = brick->getBoundingBox();
//
//    // Get the current position of the ball
//    point ballPosition = this->getPosition(); // Assuming getPosition() returns the current position
//
//    // Calculate the reflection angle based on the collision side
//    if (ballPosition.y < brickBoundingBox.upperLeft.y || ballPosition.y > brickBoundingBox.lowerRight.y) {
//        // Ball hit the top or bottom of the brick
//        return M_PI - currentAngle; // Reflect vertically
//    }
//    else {
//        // Ball hit the left or right of the brick
//        return -currentAngle; // Reflect horizontally
//    }
//}



