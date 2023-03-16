#ifndef COMBAT_HPP
#define COMBAT_HPP
#include "Player.h"
#include "Enemy.h"
#include "Stats.h"
#include <iostream>


class Combat {

    public:




    void Fight(Player &player1, Stats &playerStats,Enemy &enemy1, Stats &enemyStats);
    void Run(Stats &playerStats);
    void Talk(Stats &playerStats);
    void Examine(Stats &playerStats);

};
#endif