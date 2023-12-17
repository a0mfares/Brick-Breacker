#include "collidable.h"

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    drawable(r_uprleft, r_width, r_height, r_pGame)
{
}

//collidable::collisionInfo collidable::isColliding(const collidable* obj1, const collidable* obj2) const
//{
//    // Create a structure to store collision information
//    collidable::collisionInfo info;
//
//    // Calculate the center coordinates of the first object
//    float centerx1 = obj1->uprLft.x + (obj1->width / 2);
//    float centery1 = obj1->uprLft.y + (obj1->height / 2);
//
//    // Calculate the center coordinates of the second object
//    float centerx2 = obj2->uprLft.x + (obj2->width / 2);
//    float centery2 = obj2->uprLft.y + (obj2->height / 2);
//
//    // Calculate the differences in x and y coordinates between the centers of the two objects
//    float diffOfX = abs(centerx1 - centerx2);
//    float diffOfY = abs(centery1 - centery2);
//
//    // Calculate the overlap in the x and y directions
//    float overlaponx = (obj1->width) + (obj2->width) - diffOfX;
//    float overlapony = (obj1->height) + (obj2->height) - diffOfY;
//
//    // Check if there is an overlap in both x and y directions
//    if (overlaponx > 0 && overlapony > 0)
//    {
//        // Indicate a collision has occurred
//        info.collision = true;
//
//        // Determine the direction of the collision
//        if (overlaponx > overlapony)
//        {
//            // Set the collision point in the x direction
//            info.collisionPoint.x = (diffOfX > 0) ? obj1->uprLft.x + obj1->width : obj1->uprLft.x;
//            info.collisionPoint.y = centery1;
//        }
//        else
//        {
//            // Set the collision point in the y direction
//            info.collisionPoint.y = (diffOfY > 0) ? obj1->uprLft.y + obj1->height : obj1->uprLft.y;
//            info.collisionPoint.x = centerx1;
//        }
//    }
//
//    // Return the collision information
//    return info;
//}
collidable::collisionInfo collidable::isColliding(const collidable* obj1, const collidable* obj2) const
{
    collisionInfo collisionInfo;
    collisionInfo.collision = false;

    // Check for non-collision cases first
    if (obj1->getBoundingBox().lowerRight.x < obj2->getBoundingBox().upperLeft.x ||
        obj1->getBoundingBox().upperLeft.x > obj2->getBoundingBox().lowerRight.x ||
        obj1->getBoundingBox().lowerRight.y < obj2->getBoundingBox().upperLeft.y ||
        obj1->getBoundingBox().upperLeft.y > obj2->getBoundingBox().lowerRight.y) {
        return collisionInfo;
    }

    // Bounding boxes overlap, handle collision cases

    // Calculate the collision point based on the centers of the two objects
    collisionInfo.collisionPoint.x = (obj1->getBoundingBox().upperLeft.x + obj1->getBoundingBox().lowerRight.x) / 2;
    collisionInfo.collisionPoint.y = (obj1->getBoundingBox().upperLeft.y + obj1->getBoundingBox().lowerRight.y) / 2;

    collisionInfo.collision = true;
    return collisionInfo;
}


