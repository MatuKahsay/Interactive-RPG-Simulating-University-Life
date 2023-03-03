#include "stats.h"


Stats::Stats(int hp, int str, int iq, int chr, int stm){
    health = hp;
    strength = str;
    intelligence = iq;
    charisma = chr;
    stamina = stm;

}

int Stats::getStrength(){
    return strength;
}

int Stats::getHealth(){
    return health;
}