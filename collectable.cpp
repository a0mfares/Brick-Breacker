#include "collectable.h"

collectable::collectable(point r_uprleft, int r_width, int r_height, game* r_pGame) : drawable(r_uprleft, r_width, r_height, r_pGame)
{

}

bool collectable::isCollected(const collectable* obj1, const Paddle* obj2) const
{
    if (obj1->getBoundingBox().lowerRight.x < obj2->getBoundingBox().upperLeft.x ||
        obj1->getBoundingBox().upperLeft.x > obj2->getBoundingBox().lowerRight.x ||
        obj1->getBoundingBox().lowerRight.y < obj2->getBoundingBox().upperLeft.y ||
        obj1->getBoundingBox().upperLeft.y > obj2->getBoundingBox().lowerRight.y) {
        return false;
    }

    return true;
}

void collectable::move()
{

}
