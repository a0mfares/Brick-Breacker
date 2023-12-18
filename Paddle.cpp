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

void Paddle::padlemove()
{
    char cKeyData;
    keytype  kType2;
    kType2 = pGame->getWind()->GetKeyPress(cKeyData);
    pGame->getWind()->SetPen(LAVENDER, 1);
    pGame->getWind()->SetBrush(LAVENDER);

    if (kType2 == ARROW) {
        switch (cKeyData) {
        case 4:
            // Move paddle left
            if (uprLft.x > 10) {
                uprLft.x -= 40;
                pGame->getWind()->DrawRectangle(0, config.remainingHeight, config.windWidth, config.paddleAreaHeight, FILLED);
                
            }
            break;

        case 6:
            // Move paddle right
            if (uprLft.x < config.windWidth - 200) {
                uprLft.x += 40;
                pGame->getWind()->DrawRectangle(0, config.remainingHeight, config.windWidth, config.paddleAreaHeight, FILLED);
                
            }
            break;
        }

        // Draw the updated paddle
        this->draw();


    }

    // Update the screen buffer
    pGame->getWind()->UpdateBuffer();
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

