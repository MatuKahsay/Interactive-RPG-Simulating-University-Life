#ifndef ENEMY_H
#define ENEMY_H
#include "Stats.h"
#include <string>

using namespace std;

class Enemy {

private:
    string difficulty;

public:
    Enemy(string difficulty);
    string getDiff();
    void setDiff(string difficulty);
    void setStats(Stats& enemyStats, string difficulty);
    void showStats(Stats& enemyStats);
    void attack(Stats& playerStats, Stats& enemyStats);

};
#endif