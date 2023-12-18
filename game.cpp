#include "game.h"
#include <iostream>
using namespace std;
#include "gameConfig.h"
#include "CMUgraphicsLib\auxil.h"


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
	




	////5- Create lower Toolbar

	//5- Create lower Toolbar
	

	//5- Create the Paddle
	point PadleUpperleft;
	PadleUpperleft.x = (config.windWidth / 2) - (config.padlewidth / 2);
	PadleUpperleft.y = config.paddleAreaHeight;
	padlespot = new Paddle(PadleUpperleft, config.padlewidth, config.padleheight, this);
	
	padlespot->draw();


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






////////////////////////////////////////////////////////////////////////
void game::go() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x,y;
	
	char c;
	
	

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");
	
	do
	{
		printMessage("Ready...");
		pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		
		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{
			
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				
				gameToolbar->handleClick(x, y);
			}
		}
		if (gameMode == MODE_PLAY)		//Game is in the play mode
		{
			
			do
			{
				
				pWind->GetMouseClick(x, y);

				
			//[1] If user clicks on the Toolbar
				if ((y >= 0 && y < config.toolBarHeight)&& x>330)
				{

					gameToolbar->handleClick(x, y);
					
				}
				ballspot->moveball();
				/*bricksGrid->collisonaction();*/

				
				
			} while (isplay && !ispause);
			gameMode = MODE_DSIGN;
			
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

