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

    
    // Bounce back with a deflection angle between 0 and 45 degrees
    float deflectionAngle = std::rand() % 90; // Random angle between 0 and 45 degrees
    int Xinc = BallRad * 3 * std::cos(deflectionAngle * (3.1415926535 / 180.0f));
    int Yinc = BallRad * 3 * std::cos(deflectionAngle * (3.1415926535 / 180.0f));




    char cKeyData;
    keytype kType, kType2;
    int BallCenterX = config.windWidth / 2;
    int BallCenterY = config.paddleAreaHeight - config.BallRad;
    bool isvertical;
    auto wind = pGame->getWind();
    auto paddle = pGame->getpadle();
    point p = paddle->getpoint();

    isvertical = true;


    // Assuming the Ball and Paddle classes have appropriate methods and attributes.

    do {
        wind->FlushKeyQueue();
        kType = wind->GetKeyPress(cKeyData);

        // Check for paddle-ball collision
        auto PadleBallCollide = isColliding(this, pGame->getpadle());

        // Update ball position
        uprLft.x += Xinc;
        uprLft.y += Yinc;

        // Check for vertical boundary collision
        if (uprLft.y - BallRad <= config.toolBarHeight || PadleBallCollide.collision) {
            // Adjust the ball's position to prevent it from sticking to the boundary
            uprLft.y = (uprLft.y < config.toolBarHeight + BallRad) ? config.toolBarHeight + BallRad : PadleBallCollide.collisionPoint.y - (BallRad + 1);

            // Invert the vertical direction
            Yinc = -Yinc;
        }

        
        //draw lines showing the grid
        wind->SetPen(LAVENDER, 1);
        wind->SetBrush(LAVENDER);
        wind->DrawRectangle(0, 0, config.windWidth, config.windHeight, FILLED);

        // Check for horizontal boundary collision
        if (uprLft.x - BallRad <= 0 || uprLft.x + BallRad >= config.windWidth - 10) {
            // Invert the horizontal direction
            Xinc = -Xinc;
        }

        // Check for paddle collision
        if (PadleBallCollide.collision) {
            // Handle paddle-ball collision
            Yinc = -std::abs(Yinc);
            float paddleCenterX = (pGame->getpadle()->getBoundingBox().upperLeft.x + pGame->getpadle()->getBoundingBox().lowerRight.x) / 2.0f;
            float offset = (uprLft.x - paddleCenterX) / (config.padlewidth / 2.0f);

            // Check if the collision point is within the center half area of the paddle
            //bool isInCenterHalf = ((PadleBallCollide.collisionPoint.x <= paddleCenterX && PadleBallCollide.collisionPoint.x > pGame->getpadle()->getBoundingBox().upperLeft.x + (config.padlewidth / 3)))
            //    || (PadleBallCollide.collisionPoint.x >= paddleCenterX && PadleBallCollide.collisionPoint.x < pGame->getpadle()->getBoundingBox().upperLeft.x + ((2*config.padlewidth) / 3));

            //if (isInCenterHalf) {
            //    // Reflect the ball vertically
            //    Yinc = -std::abs(Yinc);
            //    Xinc = 0;
            //}
            //else {
                // Calculate the bounce angle based on the position of the ball relative to the paddle's center
                const float maxBounceAngle = 45.0f;  // Maximum bounce angle in degrees
                float bounceAngle = maxBounceAngle * offset;

                // Rotate the ball's direction by the calculated bounce angle
                float angle = std::atan2(Yinc, Xinc);
                angle = angle + bounceAngle * (3.1415926535 / 180.0f);
                float speed = std::hypot(Xinc, Yinc);
                Xinc = speed * std::cos(angle);
                Yinc = speed * std::sin(angle);

        }

        // Draw the game elements
        wind->SetPen(LAVENDER, 1);
        pGame->getWind()->SetBrush(LAVENDER);
        pGame->getWind()->DrawRectangle(0, 0, config.windWidth, config.windHeight, FILLED);
        pGame->getGrid()->draw();
        pGame->gettoolbarr()->draw();
        pGame->getpadle()->draw();
        this->draw();

        // Check for arrow key input
        kType2 = wind->GetKeyPress(cKeyData);
        wind->SetPen(LAVENDER, 1);
        wind->SetBrush(LAVENDER);

        if (kType2 == ARROW) {
            switch (cKeyData) {
            case 4:
                // Move paddle left
                if (p.x > 10) {
                    p.x -= 40;
                    wind->DrawRectangle(0, config.remainingHeight, config.windWidth, config.paddleAreaHeight, FILLED);
                    pGame->getpadle()->setpoint(p);
                }
                break;

            case 6:
                // Move paddle right
                if (p.x < config.windWidth - 200) {
                    p.x += 40;
                    wind->DrawRectangle(0, config.remainingHeight, config.windWidth, config.paddleAreaHeight, FILLED);
                    pGame->getpadle()->setpoint(p);
                }
                break;
            }

            // Draw the updated paddle
            pGame->getpadle()->draw();
        }

        // Update the screen buffer
        wind->UpdateBuffer();

    } while (true);






    

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

void Ball::draw() const
{
	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(BLACK);
	pWind->DrawCircle(uprLft.x, uprLft.y, width,FILLED);

}


//01069141516



//void Ball::ballmotion()
//{
//	int Xinc = BallRad, Yinc = BallRad;
//	//If the ball hits the screen boundaries, negate the increment value.
//	if ((uprLft.x <= BallRad) || (uprLft.x >= config.windWidth - BallRad))
//		Xinc = -Xinc;
//	if ((uprLft.y <= BallRad) || (uprLft.y >= config.windHeight - BallRad))
//		Yinc = -Yinc;
//
//	//Shift the ball center in both X and Y directions
//	uprLft.x += Xinc / 2;
//	uprLft.y += Yinc / 2;
//}

