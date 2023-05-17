#include <stdexcept>

#include "doctest.h"
#include "sources/Team.hpp"


using namespace std;
using namespace ariel;



TEST_CASE("Check Point Constructor And Functions"){
    Point point1 (1,1);
    Point point2 (4,5);
    Point point3 (0,0);
    Point point4 (0,9);

    CHECK_EQ(point1.getX(),1);
    CHECK_EQ(point1.getY(),1);
    CHECK(point2.getX() == 4);
    CHECK(point2.getY() == 5);
    CHECK(point1.distance(point2) == 5);
    CHECK(point2.distance(Point(0,5)) == 4);

    CHECK_EQ(point3.getX(),0);
    CHECK_EQ(point3.getY(),0);
    CHECK(point4.getX() == 0);
    CHECK(point4.getY() == 9);
    CHECK(point3.distance(point4) == 9);


    
}


TEST_CASE("Check The Constructors Of Characters"){
    Point cowboyLocation(45,60);
    Cowboy cow_boy("kobi", cowboyLocation);
    Point oldNinjaLocation(0,0);
    YoungNinja young_ninja("saray" , Point(29,28));
    TrainedNinja trained_ninja("liraz", Point(58,87));
    OldNinja old_ninja("liron", oldNinjaLocation);

    CHECK(cow_boy.getName() == "kobi");
    CHECK(young_ninja.getName() == "saray");
    CHECK(trained_ninja.getName() == "liraz");
    CHECK(old_ninja.getName() == "liron");
    CHECK(old_ninja.getAlivePoints() == 150);
    CHECK(young_ninja.getAlivePoints() == 100);
    CHECK(trained_ninja.getAlivePoints() == 120);
    CHECK(old_ninja.getSpeed() == 8);
    CHECK(young_ninja.getSpeed() == 14);
    CHECK(trained_ninja.getSpeed() == 12);

    CHECK(old_ninja.isAlive() == true);
    CHECK(trained_ninja.isAlive() == true);
    CHECK(young_ninja.isAlive() == true);

    
}


TEST_CASE("Check distance Between Character"){
    Point cowboyLocation(45,60);
    Cowboy cow_boy("kobi", cowboyLocation);
    Point oldNinjaLocation(0,0);
    YoungNinja young_ninja("saray" , Point(28,29));
    TrainedNinja trained_ninja("liraz", Point(58,87));
    OldNinja old_ninja("liron", oldNinjaLocation);


    CHECK(cow_boy.distance(young_ninja) == 35.35533905932738);
    CHECK(trained_ninja.distance(cow_boy) ==  29.966648127543394);
    CHECK(old_ninja.distance(young_ninja) == 40.311288741492746);

    
}

TEST_CASE("Checking the move function")
{

    Point location_old(0,0);

    OldNinja *old_ninja = new OldNinja("liron", location_old);
    TrainedNinja *trained_ninja = new TrainedNinja("liraz", Point(50,50));

    CHECK( (old_ninja->getLocation().distance(trained_ninja->getLocation()) )== 70.7107);
    CHECK(old_ninja->getSpeed() == 8);

    old_ninja->move(trained_ninja);

    cout<< "OldNinja was at Point " << location_old.print() << " and get Moved ,now He at position " << old_ninja->getLocation().print() << endl;

    CHECK_NOTHROW(old_ninja->getLocation().print());

}
    

TEST_CASE("Check slash and shoot function before and after "){

    Point p1(1,5);
    Cowboy *cow_boy = new Cowboy("kobi", p1);
    Point location_old(200,300);
    YoungNinja *young_Ninja = new YoungNinja("saray" , Point(0,5));
    TrainedNinja *trained_Ninja = new TrainedNinja("liraz", Point(0,4));
    OldNinja *old_Ninja = new OldNinja("liron", location_old);


    CHECK(young_Ninja->getAlivePoints() == 100);
    trained_Ninja->slash(young_Ninja);
    CHECK(young_Ninja->getAlivePoints() == 60);

    CHECK(old_Ninja->getAlivePoints() == 150);
    CHECK(location_old.distance(Point(0,4)) > 100);
    trained_Ninja->slash(old_Ninja);
    CHECK(old_Ninja->getAlivePoints() == 150);

    cow_boy->shoot(young_Ninja);
    CHECK(young_Ninja->getAlivePoints() == 50);
    CHECK(cow_boy->hasboolets()==true);
    cow_boy->shoot(young_Ninja);
    cow_boy->shoot(young_Ninja);
    cow_boy->shoot(young_Ninja);
    cow_boy->shoot(young_Ninja);
    cow_boy->shoot(young_Ninja);
    CHECK(cow_boy->hasboolets()==false);
    CHECK(young_Ninja->getAlivePoints() == 0);
    CHECK(young_Ninja->isAlive() == false);


    
}



