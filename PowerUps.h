#pragma once
#include "collectable.h"
#include "game.h"
enum PowerUpTyp {
    FIRE,
    WIND,
    WIDE,
    MGNT,
    MBALL,
};
class PowerUps :
    public collectable
{
public:
    PowerUps(point r_uprleft, int r_width, int r_height, game* r_pGame);
};

class FireBall : public PowerUps {
public:
    FireBall(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collected();
    RectC getBoundingBox() const;
};

class WindGlide : public PowerUps {
public:
    WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collected();
    RectC getBoundingBox() const;
};

class WidePaddle : public PowerUps {
public:
    WidePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collected();
    RectC getBoundingBox() const;
};
class Magnet : public PowerUps {
public:
    Magnet(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collected();
    RectC getBoundingBox() const;
};

class MultipleBalls : public PowerUps {
public:
    MultipleBalls(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void collected();
    RectC getBoundingBox() const;
};