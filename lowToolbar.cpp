#include "lowToolbar.h"
#include "drawable.h"
#include "gameConfig.h"
lowerToolbaricon::lowerToolbaricon(point r_lwrleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_lwrleft, r_width, r_height, r_pGame)
{}

////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////

iconSave::iconSave(point r_lwrleft, int r_width, int r_height, game* r_pGame) :
	lowerToolbaricon(r_lwrleft, r_width, r_height, r_pGame)
{}

void iconSave::onClick()
{
	//TO DO: add code for cleanup and game exit here
}
iconLoad::iconLoad(point r_lwrleft, int r_width, int r_height, game* r_pGame) : 
	lowerToolbaricon(r_lwrleft, r_width, r_height, r_pGame)
{}

void iconLoad::onClick() {

}


iconPause::iconPause(point r_lwrleft, int r_width, int r_height, game* r_pGame) :
	lowerToolbaricon(r_lwrleft, r_width, r_height, r_pGame)
{}

void iconPause::onClick() {
	config.isPlaying = false;
}

////////////////////////////////////////////////////  class lowertoolbar   //////////////////////////////////////////////
LowertoolBar::LowertoolBar(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{

	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	

	
	iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\Save-icon.jpg";
	iconsImages[ICON_LOAD] = "images\\ToolbarIcons\\Upload.jpg";
	iconsImages[ICON_PAUSE] = "images\\ToolbarIcons\\Pause.jpg";
	

	point p;
	p.x = config.lowertoolbarPositionY + 100;
	p.y = config.remainingHeight ;

	iconsList = new lowerToolbaricon * [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height

	
	iconsList[ICON_PAUSE] = new iconPause(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth + 6;
	iconsList[ICON_LOAD] = new iconLoad(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth + 6;
	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	
	
	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]);

	}
}



void LowertoolBar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	
	
}

//handles clicks on toolbar icons, returns true if exit is clicked
bool LowertoolBar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon



	


}
LowertoolBar::~LowertoolBar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}


