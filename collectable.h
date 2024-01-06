#pragma once
#include "collidable.h"
#include "Paddle.h"
class collectable :
    public collidable
{
public:
   
    collectable(point r_uprleft, int r_width, int r_height, game* r_pGame);
   
   
    virtual void move();
};


