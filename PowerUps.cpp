#include "PowerUps.h"

PowerUps::PowerUps(point r_uprleft, int r_width, int r_height, game* r_pGame) : collectable(r_uprleft, r_width, r_height, r_pGame)

{
}

FireBall::FireBall(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerUps(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerUps\\FireBall.jpg";
}

void FireBall::collected()
{
	auto paddle = pGame->getpadle();
	bool iscollected = isCollected(this, paddle);
	if (iscollected) {
		auto wind = pGame->getWind();
		auto ball = pGame->getball();
		ball->deleteball();
		config.fired = true;
		ball->draw();
	}
}

FireBall::RectC FireBall::getBoundingBox() const
{
	RectC boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}

WindGlide::WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerUps(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerUps\\WindGlide.jpg";
}

void WindGlide::collected()
{
	auto paddle = pGame->getpadle();
	bool iscollected = isCollected(this, paddle);
	if (iscollected) {
		
	}

}
WindGlide::RectC WindGlide::getBoundingBox() const
{
	RectC boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}

WidePaddle::WidePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerUps(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerUps\\WidePaddle.jpeg";
}

void WidePaddle::collected()
{
	auto paddle = pGame->getpadle();
	bool iscollected = isCollected(this, paddle);
	if (iscollected) {

	}
}

WidePaddle::RectC WidePaddle::getBoundingBox() const
{
	RectC boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}

Magnet::Magnet(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerUps(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerUps\\Magnet.jpeg";
}

void Magnet::collected()
{
	auto paddle = pGame->getpadle();
	bool iscollected = isCollected(this, paddle);
	if (iscollected) {

	}
}

Magnet::RectC Magnet::getBoundingBox() const
{
	RectC boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}

MultipleBalls::MultipleBalls(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerUps(r_uprleft, r_width, r_height, r_pGame)
{
}

void MultipleBalls::collected()
{
	auto paddle = pGame->getpadle();
	bool iscollected = isCollected(this, paddle);
	if (iscollected) {

	}
}

MultipleBalls::RectC MultipleBalls::getBoundingBox() const
{
	RectC boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}
