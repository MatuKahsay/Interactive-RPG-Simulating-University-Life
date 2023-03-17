#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Stats.h"
#include "Item.h"



using namespace std;

class Player {

    private:
    string major;
    public:
    Player();
    string getMajor();
    void setMajor(string major);
    void setStats(Stats &playerStats);
    void showStats(Stats &playerStats);
    void attack(Stats &playerStats, Stats &enemyStats);
    void equipItem(Stats &playerStats, Item& item);
    void unequipItem(Stats &playerStats, Item& item);
};
#endif