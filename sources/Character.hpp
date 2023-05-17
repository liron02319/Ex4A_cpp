#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"
using namespace std;
namespace ariel{};



class Character{

    private:

        string name;
        Point location;
        int alivePoints;

        

    public:

        //Constructors
        Character(string name, Point location, int alivePoints);
        Character(string name, Point location);

        bool isAlive(); //check if character alive(if to charachter have more them 0 Alive Points)
        
        double distance(Character& other); //Gets a pointer to another character and returns the distance between the characters

        void hit(int damagePoints); //Subtracts the amount hit points from the character.

        // get functions
        string getName() ; // get the name of the Character
        Point getLocation() ; //get the location of the Character
        int getAlivePoints() const; // get the life Points of the Character

        //set functions
        void setLocation(Point &otherLocation);
        void setAlivePoints(int addOrLessPoints);


        /*
        Prints the name of the character, the number of its hit points, and the location(position) of the point where the character is.
        If the character dies the number of hit points will not be printed, and the character's name will appear in parentheses - ( ). 
        Before the name will appear a letter indicating the type of character: N for ninja and C for morning.
        */
        string print(); 


     
        


};


#endif