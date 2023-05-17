#include <iostream>
#include "Ninja.hpp"


Ninja :: Ninja (string name, Point location, int alivePoints, int speed): Character(name, location, alivePoints){
    this ->speed  = speed;
}

int Ninja :: getSpeed()const{
    return this ->speed;
}

/*
C_x = A_x + (n * (B_x - A_x)) / ||AB||
C_y = A_y + (n * (B_y - A_y)) / ||AB||

*/
void Ninja :: move(Character* enemy){

    double distance = this->getLocation().distance(enemy->getLocation());

    double distanceX = double(  ( (enemy->getLocation().getX() - this->getLocation().getX()) * (this->speed) )) /distance;
    double distanceY = double(  ( (enemy->getLocation().getY() - this->getLocation().getY()) * (this->speed) )) /distance;

    double newX = this->getLocation().getX() + distanceX;
    double newY = this->getLocation().getY() + distanceY;

    Point newLocation(newX, newY);
    this ->setLocation(newLocation);

}

void Ninja :: slash(Character* enemy)
{
    if ( this->getLocation().distance(enemy->getLocation()) < 100){
        enemy->setAlivePoints(-40);
    }
}

