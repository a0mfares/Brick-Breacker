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
}

void collectable::draw()
{
    window* pWind = pGame->getWind();
    color c;

   
    c = RED;
    pWind->SetPen(c, 1);
    pWind->SetBrush(c);
    pWind->DrawCircle(uprLft.x, uprLft.y, width, FILLED);
}

void collectable::setpoint(point p)
{
    uprLft = p;
}
