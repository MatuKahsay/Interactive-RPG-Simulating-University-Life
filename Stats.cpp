#include "Stats.h"
#include <iostream>

using namespace std;


Stats::Stats() {
     health = 100;
     strength = 0;
     intelligence = 0;
     charisma = 0;
     stamina = 0;
}

void Stats::setHealth(int hp) {

    if(hp > 100) {
        this->health = 100;
    }

    else if(hp < 0) {
        this ->health = 0;
    }

    else {
        this->health = hp;
    }
}

int Stats::getHealth() {
    return health;
}

int Stats::getStrength() {
    return strength;
}

void Stats::setStrength(int str) {

    if(str > 100) {

        strength = 100;
    }

    else if (str < 0) {

        strength = 0;
    }

    else {
        strength = str;
    }

}
 void Stats::setIntelligence(int iq) {

    if(iq >100) {
        this->intelligence = 100;
    }

    else if(iq < 0) {
        this->intelligence = 0;
    }

    else {
        this->intelligence = iq;
    }
}
int Stats::getIntelligence() {
    return intelligence;
}

void Stats::setStamina(int stm) {

    if(stm > 100) {
        this->stamina = 100;
    }
    else if(stm < 0) {
        this->stamina = 0;
    }
    else {
        this->stamina = stm;
    }
}

int Stats::getStamina() {
    return stamina;
}

void Stats::setCharisma(int chr) {
    if(chr > 100) {
        this->charisma = 100;
    }

    else if(chr < 0) {
        this->charisma = 0;
    }

    else {
        this->charisma = chr;
    }
}

int Stats::getCharisma() {
    return charisma;
}