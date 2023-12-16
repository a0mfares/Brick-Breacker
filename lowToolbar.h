#pragma once
#include "drawable.h"
#include "game.h"

class game;

class lowerToolbaricon :public drawable
{
public:
	lowerToolbaricon(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() = 0;   //The action that should be taken when this icon is clicked
};

class iconSave :public lowerToolbaricon
{
public:
	iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
class iconLoad : public lowerToolbaricon
{
public: 
	iconLoad(point r_lwrleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
class iconPause : public lowerToolbaricon
{
public:
	iconPause(point r_lwrleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


////////////////////////////////////////////////////  class lowertoolbar   //////////////////////////////////////////////
class LowertoolBar :public drawable
{

	enum ICONS //The icons of the toolbar (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_PAUSE,
		ICON_LOAD,
		ICON_SAVE,
				//Exit icon

		ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

private:
	lowerToolbaricon** iconsList; //an array of toolbarIcon pointers
	string iconsImages[ICON_COUNT];
	game* pGame;

public:
	LowertoolBar(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~LowertoolBar();
	void draw() const;
	bool handleClick(int x, int y);	//handles clicks on toolbar icons, returns true if exit is clicked
};

