#include "PowerDowns.h"
#include "gameConfig.h"
#include "game.h"
PowerDowns::PowerDowns(point r_uprleft, int r_width, int r_height, game* r_pGame) : collectable(r_uprleft, r_width, r_height, r_pGame)

{
}

ReverseDirection::ReverseDirection(point r_uprleft, int r_width, int r_height, game* r_pGame): PowerDowns(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerDowns\\Reverse.jpg";
}

void ReverseDirection::collisionAction()
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		config.reversed = true;
	}
}

ReverseDirection::Rect ReverseDirection::getBoundingBox() const
{
	Rect boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}

QuickSand::QuickSand(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerDowns(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerDowns\\QuickSand.jpg";
}

void QuickSand::collisionAction()
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		config.speedDown = true;
	}
}

QuickSand::Rect QuickSand::getBoundingBox() const
{
	Rect boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}

ShrinkPaddle::ShrinkPaddle(point r_uprleft, int r_width, int r_height, game* r_pGame) : PowerDowns(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\PowerDowns\\Shrink.jpg";
}

void ShrinkPaddle::collisionAction()
{
	auto paddle = pGame->getpadle();
	auto iscollected = isColliding(this, paddle);
	if (iscollected.collision) {
		config.shrink = true;
	}
}

ShrinkPaddle::Rect ShrinkPaddle::getBoundingBox() const
{
	Rect boundingBox;
	boundingBox.upperLeft.x = uprLft.x;
	boundingBox.upperLeft.y = uprLft.y;
	boundingBox.lowerRight.x = uprLft.x;
	boundingBox.lowerRight.y = uprLft.y;
	return boundingBox;
}
