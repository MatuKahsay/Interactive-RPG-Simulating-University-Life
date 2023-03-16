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
    Player();
    Player(int health,  int strength, int intelligence, int stamina, int charisma, string major);
    string getMajor();
    void setMajor(string major);
    void setStats(Player* &player);
    int getHealth();
    int getStrength();
    int getIntelligence();
    int getStamina();
    int getCharisma();
};
#endif