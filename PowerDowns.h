#pragma once
#include "collectable.h"
enum PowerDownTyp {
    REVERSE,
    QUICKSAND,
    SHRINK,
};
class PowerDowns :
    public collectable
{
public:
    PowerDowns(point r_uprleft, int r_width, int r_height, game* r_pGame);
};


class ReverseDirection : public PowerDowns {
public:
    ReverseDirection(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collisionAction();
    Rect getBoundingBox() const;
};

class QuickSand : public PowerDowns {
public:
    QuickSand(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collisionAction();
    Rect getBoundingBox() const override;
};

class ShrinkPaddle : public PowerDowns {
public:
    ShrinkPaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collisionAction();
    Rect getBoundingBox() const override;
};
