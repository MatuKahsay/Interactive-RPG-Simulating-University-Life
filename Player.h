#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "Character.h"

using namespace std;

class Player: public Character{

    protected:
    string major;
    int health;
    int strength;
    int intelligence;
    int stamina;
    int charisma;

    public:
    Player(int health,  int strength, int intelligence, int stamina, int charisma, string major);
    string getMajor();
    void setMajor(string major);
    void setStats();

    


};
#endif