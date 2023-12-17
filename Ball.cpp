#include "Ball.h"
#include "game.h"
#include "gameConfig.h"
#include "CMUgraphicsLib\auxil.h"


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

    int Xinc = BallRad * 3, Yinc = BallRad * 3;



    char cKeyData;
    keytype kType, kType2;
    int BallCenterX = config.windWidth / 2;
    int BallCenterY = config.paddleAreaHeight - config.BallRad;
    bool isvertical;
    auto wind = pGame->getWind();
    auto paddle = pGame->getpadle();
    point p = paddle->getpoint();

    isvertical = true;


    do
    {
        //Redraw the background every iteration 
        

        wind->FlushKeyQueue();
        kType = wind->GetKeyPress(cKeyData);
        
        if (isvertical) { 
            Xinc = 0;
            
        
        }
        else Xinc = BallRad * 3;

        //If the ball hits the screen boundaries, negate the increment value.
        if ((uprLft.x <= BallRad) || (uprLft.x >= pGame->getWind()->GetWidth() - BallRad-10) && !isvertical )
            Xinc = -Xinc;
        if ((uprLft.y <= config.toolBarHeight +BallRad+10) || (uprLft.y >= config.paddleAreaHeight - BallRad-10))
            Yinc = -Yinc;
 
        //Shift the ball center in both X and Y directions
       
        uprLft.x += Xinc / 2;
        uprLft.y += Yinc / 2;

        
        //draw lines showing the grid
        wind->SetPen(LAVENDER, 1);
        wind->SetBrush(LAVENDER);
        wind->DrawRectangle(0, 0, config.windWidth, config.windHeight, FILLED);
        pGame->getGrid()->draw();
        pGame->gettoolbarr()->draw();
        pGame->getpadle()->draw();
        this->draw();

        kType2 = wind->GetKeyPress(cKeyData);
        wind->SetPen(LAVENDER, 1);
        wind->SetBrush(LAVENDER);
        if (kType2 == ARROW) {
            switch (cKeyData)
            {
            case 4:
                if (p.x > 10) {
                    p.x -= 20;
                    wind->DrawRectangle(0, config.remainingHeight, config.windWidth, config.paddleAreaHeight, FILLED);
                    paddle->setpoint(p);
                }


                break;
            case 6:

                if (p.x < config.windWidth - 200) {
                    p.x += 20;
                    wind->DrawRectangle(0, config.remainingHeight, config.windWidth, config.paddleAreaHeight, FILLED);
                    paddle->setpoint(p);
                }

                wind->UpdateBuffer();
                break;
            }
            paddle->draw();
        }
        



        // Update the screen buffer
        wind->UpdateBuffer();
    
       
        
    } while (true);
    

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

