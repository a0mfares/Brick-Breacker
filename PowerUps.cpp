#include "PowerUps.h"

PowerUps::PowerUps(point r_uprleft, int r_width, int r_height, game* r_pGame) : collectable(r_uprleft, r_width, r_height, r_pGame)

{
}

FireBall::FireBall(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerUps(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerUps\\FireBall.jpg";
}

void FireBall:: collisionAction() 
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		auto wind = pGame->getWind();
		auto ball = pGame->getball();
		ball->deleteball();
		config.fired = true;
		ball->draw();
	}
}

FireBall::Rect FireBall::getBoundingBox() const
{
	Rect boundingBox;
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

void WindGlide::collisionAction()
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		config.speedUp = true;
	}

}
WindGlide::Rect WindGlide::getBoundingBox() const
{
	Rect boundingBox;
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

void WidePaddle::collisionAction()
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		config.widen = true;
	}
}

WidePaddle::Rect WidePaddle::getBoundingBox() const
{
	Rect boundingBox;
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

void Magnet::collisionAction()
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		auto ball = pGame->getball();
		ball->deleteball();
		ball->setxyinczero();
		ball->draw();
	}
}

Magnet::Rect Magnet::getBoundingBox() const
{
	Rect boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}

MultipleBalls::MultipleBalls(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerUps(r_uprleft, r_width, r_height, r_pGame)
{
}

void MultipleBalls::collisionAction()
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		auto ball = pGame->getball();
		ball->draw();
		point BallUpperleft;
		BallUpperleft.x = config.windWidth / 2 - 50;
		BallUpperleft.y = config.paddleAreaHeight - config.BallRad;
		ball->setpoint(BallUpperleft);
		ball->draw();
		BallUpperleft.x = config.windWidth / 2 + 50;
		BallUpperleft.y = config.paddleAreaHeight - config.BallRad;
		ball->setpoint(BallUpperleft);
		ball->draw();
	}
}

MultipleBalls::Rect MultipleBalls::getBoundingBox() const
{
	Rect boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}
