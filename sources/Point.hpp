#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;
namespace ariel{};

class Point{

    private:

        double x;
        double y;

    public:
        Point(double p_x, double p_y); //constructor to get Cordinates

        //get function
        double getX() const;  
        double getY() const;

        //The function receives a point and calculates the distance between the two points
        double distance( Point other);

        //Prints the two coordinates in ( , )
        string print();

        //The function returns the closest point to the destination point (at the given distance from the source point)
        Point moveTowards( Point source,  Point destination, double distance);

        

        
};


#endif