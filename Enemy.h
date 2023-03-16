#ifndef ENEMY_H
#define ENEMY_H
#include "Stats.h"


class Enemy {

    private:
    int difficulty;

    public:
        Enemy();
        int getDiff();
        void setDiff(int enemyDiff);
        void setStats(Stats &enemyStats);
        void showStats(Stats &enemyStats);
        void attack(Stats &playerStats, Stats &enemyStats);

    public: 
        Enemy(const Stats& stat, int ID); 
        void attack();
        int getStrength(Stats& stats);
        int getHealth(Stats& stats);
        const Stats& getStats() const;  

};
#endif