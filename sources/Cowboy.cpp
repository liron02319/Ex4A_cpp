#include <iostream>
#include "Cowboy.hpp"

Cowboy :: Cowboy(string name, Point location) : Character(name, location){
    this ->bulletsInPistol=6;
}

void Cowboy :: shoot(Character* enemy){
    if (enemy->getAlivePoints() > 0){
        enemy->setAlivePoints(-10);
        bulletsInPistol=bulletsInPistol-1;
    }
}

bool Cowboy :: hasboolets(){
    if (bulletsInPistol > 0){
        return true;
    }

    return false;
}

void Cowboy :: reload()
{
    this -> bulletsInPistol = bulletsInPistol + 6;
} 