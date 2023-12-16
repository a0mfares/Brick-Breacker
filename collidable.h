#pragma once
#include "drawable.h"

// Base class for all collidable (objects that may collide with other objects)
class collidable : public drawable
{
    struct collisionInfo
    {
        bool collision = false;
        point collisionPoint;
    };
    // Calculate the bounding boxes of the objects
    int left = uprLft.x;
    int right = uprLft.x + width;
    int top = uprLft.y;
    int bottom = uprLft.y + height;
public:
    /*  struct collisionInfo
      {
          bool collision = false;
          point collisionPoint;
      };*/

    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);

    virtual void collisionAction() = 0;  // action that should be performed upon collision
    virtual collisionInfo isColliding(const collidable* obj1, const collidable* obj2)const;
};
