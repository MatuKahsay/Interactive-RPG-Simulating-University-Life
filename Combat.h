#ifndef COMBAT_HPP
#define COMBAT_HPP
#include "Player.h"
#include "Enemy.h"
#include "Stats.h"
#include <iostream>


class Combat {

    public:




    void Fight(Player &player1, Stats &playerStats,Enemy &enemy1, Stats &enemyStats);
    bool Run(Stats &playerStats);
    bool Talk(Stats &playerStats);
    bool Examine(Stats &playerStats);

};
#endif