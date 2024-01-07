#include "collectable.h"
#include "game.h"

collectable::collectable(point r_uprleft, int r_width, int r_height, game* r_pGame) : collidable(r_uprleft, r_width, r_height, r_pGame)
{

}


void collectable::move()
{
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    uprLft.y++;
    this->draw();
}

void collectable::draw()
{
    window* pWind = pGame->getWind();
    color c;

    if (config.collecteditems == 0)  c = RED;
    else if (config.collecteditems == 1) c = VIOLET;
    else if (config.collecteditems == 2) c = BLUE;
    else if (config.collecteditems == 3) c = GREEN;
    else if (config.collecteditems == 4) c = VIOLETRED;
    else if (config.collecteditems == 5) c = YELLOW;
    else if (config.collecteditems == 6) c = BROWN;
    else if (config.collecteditems == 7) c = GOLD;


   
    pWind->SetPen(c, 1);
    pWind->SetBrush(c);
    pWind->DrawCircle(uprLft.x, uprLft.y, width, FILLED);
}

void collectable::setpoint(point p)
{
    uprLft = p;
}
