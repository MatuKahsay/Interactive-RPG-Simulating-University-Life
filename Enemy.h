
#ifndef ENEMY_H
#define ENEMY_H
#include "Stats.h"
#include "Combat.h"


class Enemy : public Combat {

    private:
    int difficulty;

    public:
        Enemy()
        int getDiff();
        void setDiff(int enemyDiff);
        void setStats(Stats &enemyStats);
        void showStats(Stats &enemyStats);
        virtual void attack(Stats &playerStats, Stats &enemyStats);


};
#endif

#pragma once
#include "Stats.h"
#include <string>

using namespace std;

class Enemy {

private:
    string difficulty;

public:
    Enemy();
    string getDiff();
    void setDiff(string difficulty);
    void setStats(Stats& enemyStats, string difficulty);
    void showStats(Stats& enemyStats);
    void attack(Stats& playerStats, Stats& enemyStats);

};

