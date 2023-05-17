#include <iostream>
#include <cmath>
#include "Character.hpp"

using namespace std;


Character :: Character(string name, Point location, int alivePoints): location(location){
    this -> name = name;
    this ->alivePoints = alivePoints;
}

Character :: Character(string name, Point location): location(location){
    this -> name = name;
}

bool Character :: isAlive(){
    if (this ->alivePoints > 0){
        return true;
    }
    return false;
}

double Character :: distance(Character& other){
    return this->location.distance(other.getLocation());
}

void Character :: hit(int damagePoints){
    cout << "hit  " << endl;
}

string Character::getName(){
    return this ->name;
}

Point Character :: getLocation(){
    return this ->location;
}


int Character :: getAlivePoints() const {
    return this ->alivePoints;
}
void Character :: setLocation(Point &otherLocation){
    this ->location = otherLocation;
}

void Character :: setAlivePoints(int addOrLessPoints){
    this ->alivePoints = alivePoints+addOrLessPoints;
    cout << this->alivePoints << endl;
}

string Character :: print()
{
    string alive_Points =  to_string(this -> alivePoints);
    string detailsCharacter = this -> name +  " is standing at " + (this ->location.print()) + " and have " + alive_Points + " Alives Points.";
    return detailsCharacter;

}


