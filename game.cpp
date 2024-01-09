#include "game.h"
#include <iostream>
using namespace std;
#include "gameConfig.h"
#include "CMUgraphicsLib\auxil.h"
#include <sstream>
#include "PowerUps.h"
#include "PowerDowns.h"



game::game()
{
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;


	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	////2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft, 0, config.toolBarHeight, this);
	gameToolbar->draw();

	

	//3 - create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();


	//4- Create the ball
	point BallUpperleft;
	BallUpperleft.x = config.windWidth / 2;
	BallUpperleft.y = config.paddleAreaHeight - config.BallRad;
	ballspot = new Ball(BallUpperleft, config.BallRad, config.BallRad, this);
	ballspot->draw();


	point bb1;
	bb1.x = config.windWidth / 2;
	bb1.y = config.paddleAreaHeight - config.BallRad;
	point bb2;
	bb2.x = (config.windWidth / 2) + 20;
	bb2.y = config.paddleAreaHeight - config.BallRad;
	point bb3;
	bb3.x = (config.windWidth / 2) - 20;
	bb3.y = config.paddleAreaHeight - config.BallRad;
	b1 = new Ball(bb1, config.BallRad, config.BallRad, this);
	b2 = new Ball(bb2, config.BallRad, config.BallRad, this);
	b3 = new Ball(bb3, config.BallRad, config.BallRad, this);

	




	////5- Create lower Toolbar

	//5- Create lower Toolbar
	

	//5- Create the Paddle
	point PadleUpperleft;
	PadleUpperleft.x = (config.windWidth / 2) - (config.padlewidth / 2);
	PadleUpperleft.y = config.paddleAreaHeight;
	padlespot = new Paddle(PadleUpperleft, config.padlewidth, config.padleheight, this);
	padlespot->draw();
	/*point Ballleft;
	Ballleft.x = 60;
	Ballleft.y = 60;

	colected = new collectable * [8];
	colected[0] = new FireBall(Ballleft, config.BallRad, config.BallRad, this);
	colected[1] = new WindGlide(Ballleft, config.BallRad, config.BallRad, this);
	colected[2] = new WidePaddle(Ballleft, config.BallRad, config.BallRad, this);
	colected[3] = new Magnet(Ballleft, config.BallRad, config.BallRad, this);
	colected[4] = new MultipleBalls(Ballleft, config.BallRad, config.BallRad, this);
	colected[5] = new ReverseDirection(Ballleft, config.BallRad, config.BallRad, this);
	colected[6] = new QuickSand(Ballleft, config.BallRad, config.BallRad, this);
	colected[7] = new ShrinkPaddle(Ballleft, config.BallRad, config.BallRad, this);*/



	/*if (gameMode == MODE_PLAY)*
	/*ballspot->collisionAction();*/
	/*char cKeyData;
	keytype kType;

	kType = pWind->GetKeyPress(cKeyData);
	if (kType == ESCAPE) gameMode = MODE_PLAY;*/
	//while (gameMode==MODE_PLAY)
	//{
	//	padlespot->onPress(*pWind, padlespot);
	//	ballspot->moveball();
	//}
	

	

	/*padlespot->onPress(*pWind, padlespot);
	ballspot->moveball();*/

	/*if (gameMode = MODE_PLAY) {
		ballspot->draw();
		
	}*/


	


	

	//6- Create and clear the status bar
	clearStatusBar();
	
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
	delete padlespot;
	delete ballspot;
	delete b1;
	delete b2;
	delete b3;

	
	
}



clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}



//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

keytype game::Getkeypressed(char& ckeytype) const
{
	return  pWind->WaitKeyPress(ckeytype);
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}

Paddle* game::getpadle() const
{
	return padlespot;
}

Ball* game::getball() const
{
	return ballspot;
}

toolbar* game::gettoolbarr() const
{
	return gameToolbar;
}

game::MODE game::getMode() const
{
	return gameMode;
}

void game::setmode(MODE m)
{
	gameMode = m;
}




void game::setplay(bool p)
{
	isplay =p;
}

void game::setexit(bool e)
{
	isExit = e;
}

void game::setpause(bool p)
{
	ispause = p;
}

void game::setgameover(bool g)
{
	gameover = g;
}

void game::updatelive()
{
	point BallUpperleft;
	BallUpperleft.x = config.windWidth / 2;
	BallUpperleft.y = config.paddleAreaHeight - config.BallRad;
	point PadleUpperleft;
	PadleUpperleft.x = (config.windWidth / 2) - (config.padlewidth / 2);
	PadleUpperleft.y = config.paddleAreaHeight;

	if (ballspot->getBoundingBox().lowerRight.y > config.windHeight && config.Lives>0) {
		--config.Lives;
		ballspot->setpoint(BallUpperleft);
		padlespot->setpoint(PadleUpperleft);
		ballspot->resetxyinc();
		pWind->FlushKeyQueue();



	}
	if (config.Lives == 0) {
		setgameover(true);
		
	}
}

void game::updateTime(double i , double j)
{
	//minutes duration(10);
	//auto endTime = steady_clock::now() + duration;
	//
	//
	///*while(std::chrono::steady_clock::now() < endTime){*/
	//
	//	auto remainingTime = duration_cast<seconds>(endTime - steady_clock::now());
	//	auto Minutes = duration_cast<minutes>(remainingTime);
	//	auto Seconds = remainingTime % minutes(1);
	//	string m = to_string(Minutes.count());
	//	string s = to_string(Seconds.count());

	//	pWind->SetPen(BLACK, 1);
	//	pWind->SetBrush(BLACK);
	//	pWind->DrawString(10, config.windHeight - config.statusBarHeight, m + ":" + s);
	
	string minutes[11] = { "10","09","08","07","06","05","04","03","02","01","00" };
	string seconds[60] = { "59","58","57","56","55","54","53","52","51","50",
						  "49","48","47","46","45","44","43","42","41","40",
						  "39","38","37","36","35","34","33","32","31","30",
						  "29","28","27","26","25","24","23","22","21","20",
						  "19","18","17","16","15","14","13","12","11","10",
						  "09","08","07","06","05","04","03","02","01","00",
	};
	if (seconds[int(j)] == "00") {
		config.i++;
		config.j = 0;
	}
	else {
		config.i = config.i;
	}
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(BLACK);
	pWind->DrawString(10, config.windHeight - config.statusBarHeight, minutes[int(i)] + ":" + seconds[int(j)]);

	
	/*}*/
	




}

void game::statusbardraw()
{
	
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(BLACK);
	//pGame->getWind()->DrawString(10, config.windHeight - config.statusBarHeight, pGame->updateTIme());
	pWind->DrawString(config.windWidth / 2, config.windHeight - config.statusBarHeight, "Score : " + to_string(config.Score));
	pWind->DrawString(config.windWidth / 2 + 500, config.windHeight - config.statusBarHeight, "Lives : " + to_string(config.Lives));
	updateTime(config.i,config.j);

}

void game::collectedtimer(bool &x)
{
	if (config.j <= 29) {
		config.getcollectedtimer = true;
	}
	else {
		x = false;
	}
}

void game::timer(bool &x)
{
	if(x == true){
		config.timer += 0.1;
		if (config.timer >= 30) {
			x = false;
			config.timer = 0;
		}
	}
	
}

Ball* game::getball1() const
{
	return b1;
}

Ball* game::getball2() const
{
	return b2;
}

Ball* game::getball3() const
{
	return b3;
}




//collectable** game::getcollectable() const
//{
//	return colected;
//}






////////////////////////////////////////////////////////////////////////
void game::go()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;

	char c;



	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	printMessage("Ready...");

	do
	{


		/*pWind->FlushKeyQueue();*/
		pWind->GetMouseClick(x, y);	//Get the coordinates of the user click

		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{

				gameToolbar->handleClick(x, y);
			}

			if (gameover == true) {
				pWind->SetPen(BLACK, 1);
				pWind->SetBrush(BLACK);
				pWind->DrawRectangle(0, 0, config.windWidth, config.windHeight, FILLED);
				pWind->SetPen(DARKRED, 1);
				pWind->SetBrush(DARKRED);
				pWind->SetFont(50,1,ROMAN,"Times New Roman");
				pWind->DrawString(config.windWidth / 2 - 100, config.windHeight / 2 - 100, "GAME OVER");
				pWind->SetPen(WHITE, 1);
				pWind->SetBrush(WHITE);
				pWind->DrawString(config.windWidth / 2 + 100, config.windHeight / 2 + 100, "Score : "+config.Score);
				pWind->UpdateBuffer();

			}

		}

		if (gameMode == MODE_PLAY)		//Game is in the play mode
		{

			char cKeyData;
			keytype kType;
			kType = pWind->GetKeyPress(cKeyData);
			COUNT = 0;
			if (kType == ASCII && cKeyData == ' ') {
				do
				{


					config.j += 0.1;
					pWind->GetMouseClick(x, y);
					kType = pWind->GetKeyPress(cKeyData);


					//[1] If user clicks on the Toolbar
					if ((y >= 0 && y < config.toolBarHeight) && x > 330)
					{

						gameToolbar->handleClick(x, y);

					}

					


					ballspot->moveball();
					this->updatelive();
					this->statusbardraw();
					this->collectedtimer(config.getcollectedtimer);
					this->timer(config.widen);
					this->timer(config.shrink);
					this->timer(config.speedUp);
					this->timer(config.speedDown);
					this->timer(config.reversed);
					this->timer(config.fired);
					this->timer(config.magnet);
					this->timer(config.multibleballs);
					padlespot->setWidth();

					padlespot->padlemove();
					if (config.getcollected) {
						bricksGrid->getcollected()[config.collecteditems]->move();
						bricksGrid->getcollected()[config.collecteditems]->collisionAction();

						/*bricksGrid->getcollected()[0]->draw();*/
						pWind->UpdateBuffer();
					}
					
					bricksGrid->collisionAction();











				} while (isplay && !gameover && !ispause && config.i < 10 && config.j < 60);




				gameMode = MODE_DSIGN;


			}




		}


	} while (!isExit );
	
}
void game::move()
{


	do
	{
		ballspot->moveball();
		
	} while (isplay);

	isplay = false;

}

