#include <iostream>
#include "Team.hpp"

Team :: Team(Character* leader) : leader(*leader){
}


//~Team(); /free constructor memory
    
void Team :: add(Character* newPlayer){
    this ->numberOfPlayers += 1;
}

void  Team :: attack(Team* other){
    other ->players.clear();
    other ->numberOfPlayers = 0;
}

int Team :: stillAlive(){
    return this ->numberOfPlayers;
}

void Team :: print(){
    cout << " printing " << endl;
}