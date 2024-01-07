#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "grid.h"
#include "Paddle.h"
#include "Ball.h"







//Main class that coordinates the game operation
class game
{
	

	/// Add more members if needed


	
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	Paddle* padlespot;
	Ball* ballspot;
	Ball* b1;
	Ball* b2;
	Ball* b3;

	//collectable** colected;
	


	bool isplay =false;
	bool isExit = false;
	bool ispause = false;
	bool gameover = false;
	int COUNT = 0;
	
	
	

public:
	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	MODE gameMode;
	game();
	~game();


	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user
	keytype Getkeypressed(char& ckeytype) const;


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go() ;
	void move();

	window* getWind() const;		//returns a pointer to the graphics window



	grid* getGrid() const;
	Paddle* getpadle() const;
	Ball* getball() const;
	toolbar* gettoolbarr() const;
	MODE getMode() const;
	void setmode(MODE m);
	void setplay(bool p);
	void setexit(bool e);
	void setpause(bool p);
	void setgameover(bool g);
	void updatelive();
	void updateTime(double i , double j);
	void statusbardraw();
	/*collectable** getcollectable() const;*/
	void collectedtimer();
	void timer(bool &x);
	Ball* getball1() const;
	Ball* getball2() const;
	Ball* getball3() const;



};

