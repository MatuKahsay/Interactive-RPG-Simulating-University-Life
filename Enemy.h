#ifndef ENEMY_H
#define ENEMY_H
#include "stats.h"
#include "item.h"
// #include "Player.h"

#include <iostream>


class Enemy{

    private:
        int enemyID; 
        int health;
        Stats enemyStats; 

    public: 
        Enemy(const Stats& stat, int ID); 
        void equipItem(Item& item);
        void unequipItem(Item& item);
        void attack();
        Stats& getStats();  
        void printStats();
        // void battle(Player& player, Enemy& enemy);

};






#endif 