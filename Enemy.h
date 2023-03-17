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