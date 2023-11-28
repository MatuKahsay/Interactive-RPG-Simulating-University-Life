#ifndef ACTION_HPP
#define ACTION_HPP
#include "Player.h"
#include "Enemy.h"
#include "Stats.h"
#include <iostream>

class Action {

    public:
    
    void studyAtLibrary(Stats &playerStats);
    void goToParty(Stats &playerStats);
    void eatAtGlassgow(Stats & playerStats);
    void workoutAtSRC(Stats & playerStats);
};

