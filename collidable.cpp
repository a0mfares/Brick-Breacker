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
    // Check if the bounding boxes overlap for left or right sides
    // calculating the collision point(x,y) 

    if (obj1->right == obj2->left)
        if (obj1->top <= obj2->top && obj1->top >= obj2->bottom)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->right;
            collisionInfo.collisionPoint.y = obj1->top + (obj1->top + obj2->bottom) / 2;
        }
        else if (obj1->bottom >= obj2->top && obj1->bottom <= obj2->bottom)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->right;
            collisionInfo.collisionPoint.y = obj2->top + (obj2->top + obj1->bottom) / 2;
        }
        else if (obj2->top <= obj1->top && obj2->bottom >= obj1->bottom)

        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->right;
            collisionInfo.collisionPoint.y = obj2->top + (obj2->bottom - obj2->top) / 2;
        }
    if (obj1->left == obj2->right)
        if (obj1->top <= obj2->top && obj1->top >= obj2->bottom)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->left;
            collisionInfo.collisionPoint.y = obj1->top + (obj1->top + obj2->bottom) / 2;
        }
        else if (obj1->bottom >= obj2->top && obj1->bottom <= obj2->bottom)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->left;
            collisionInfo.collisionPoint.y = obj2->top + (obj2->top + obj1->bottom) / 2;
        }
        else if (obj2->top <= obj1->top && obj2->bottom >= obj1->bottom)

        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->left;
            collisionInfo.collisionPoint.y = obj2->top + (obj2->bottom - obj2->top) / 2;
        }

    //check heck if the bounding boxes overlap for top or bottom sides
    //calculating the collision point(x, y)
    if (obj1->top == obj2->bottom)
        if (obj1->left <= obj2->left && obj1->left >= obj2->right)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->left + (obj2->right - obj1->left) / 2;
            collisionInfo.collisionPoint.y = obj1->top;
        }
        else  if (obj2->left <= obj1->left && obj2->left >= obj1->right)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj2->left + (obj1->right - obj2->left) / 2;
            collisionInfo.collisionPoint.y = obj1->top;
        }
        else if (obj2->left >= obj1->left && obj2->right <= obj1->right)

        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj2->left + (obj2->right - obj2->left) / 2;
            collisionInfo.collisionPoint.y = obj1->top;
        }
    if (obj1->bottom == obj2->top)
        if (obj1->left <= obj2->left && obj1->left >= obj2->right)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj1->left + (obj2->right - obj1->left) / 2;
            collisionInfo.collisionPoint.y = obj1->bottom;
        }
        else  if (obj2->left <= obj1->left && obj2->left >= obj1->right)
        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj2->left + (obj1->right - obj2->left) / 2;
            collisionInfo.collisionPoint.y = obj1->bottom;
        }
        else if (obj2->left >= obj1->left && obj2->right <= obj1->right)

        {
            collisionInfo.collision = true;
            collisionInfo.collisionPoint.x = obj2->left + (obj2->right - obj2->left) / 2;
            collisionInfo.collisionPoint.y = obj1->bottom;

            return collisionInfo;
        }
}

