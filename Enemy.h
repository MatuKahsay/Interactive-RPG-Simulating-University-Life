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


};
#endif