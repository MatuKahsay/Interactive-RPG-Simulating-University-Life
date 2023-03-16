#include "stats.h"


Stats::Stats(int hp, int str, int iq, int chr, int stm){
    health = hp;
    strength = str;
    intelligence = iq;
    charisma = chr;
    stamina = stm;

}
void Stats::setStrength(int newStr){
    strength = newStr;
}

int Stats::getStrength(){
    return strength;
}

int Stats::getHealth(){
    return health;
}

void Stats::setHealth(int newHp){
    health = newHp;
}

int Stats::getIntelligence(){
    return intelligence;
}

void Stats::setIntelligence(int newIq){
    intelligence = newIq;
}

int Stats::getCharisma(){
    return charisma;

}

void Stats::setCharisma(int newChr){
    charisma = newChr;
}


int Stats::getStamina(){
    return stamina;

}

void Stats::setStamina(int newStm){
    stamina = newStm;
}
