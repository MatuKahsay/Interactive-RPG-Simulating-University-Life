#ifndef PLAYER_H
#define PLAYER_H
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
    string getMajor();
    void setMajor(string major);
    void setStats();
    void attack();
    void setHealth(int hp);
    int getHealth();
    int getStrength();
    void setStrenght(int str);
    void setIntelligence(int iq);
    int getIntelligence();
    void setStamina(int stm);
    int getStamina();
    void setCharisma(int chr);
    int getCharisma();

    void attack();


    
};
#endif