#ifndef ENEMY_H
#define ENEMY_H
#include "stats.h"

class Enemy{

    private:
        int enemyID; 
        int health;
        Stats enemyStats; 

    public: 
        Enemy(const Stats& stat, int ID); 
        void attack();
        int getStrength(const Stats& stats);
        int getHealth(const Stats& stats);
        const Stats& getStats() const;  

};






#endif 