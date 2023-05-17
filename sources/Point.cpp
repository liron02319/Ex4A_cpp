#include <iostream>
#include <cmath>
#include "Point.hpp"

using namespace std;

// "outline" constructor implementation:
Point::Point(double p_x, double p_y){
    this -> x = p_x;
    this -> y = p_y;
}

double Point::getX() const{
    return this -> x;
}

double Point::getY() const{
    return this -> y;
}

double Point::distance(const Point other){ // sqrt( (x1-x2)^2 + (y1-y2)^2 )
    return (std::sqrt (std::pow( this ->x - other.getX(), 2) + std :: pow(this ->y - other.getY(),2) ) );
}

string Point::print(){
    string s = "(" + to_string(this ->x) + " , " + to_string(this ->y) + " )";
    return s;    
}

Point Point :: moveTowards(const Point origin, const Point destination, double distance){
    return Point(0,0);
}

