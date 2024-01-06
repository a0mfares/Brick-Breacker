#pragma once
#include "drawable.h"
#include "Paddle.h"
class collectable :
    public drawable
{
public:
    struct RectC {
        point upperLeft, lowerRight;
    };
    collectable(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual RectC getBoundingBox() const = 0;
    virtual void collected() = 0;
    virtual bool isCollected(const collectable* obj1, const Paddle* obj2)const;
    virtual void move();
};


