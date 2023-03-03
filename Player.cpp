#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    health = 100;
    strength = 0;
    intelligence = 0;
    stamina = 0;
    charisma = 0;

}

void Player::setMajor(string mjr) {
    this->major = mjr;
}

string Player::getMajor() {
    return major;
}

void Player::setStats() {

    Player player;

    if(player.getMajor() == "Engineering") {
        
        player.intelligence = 50;
        player.strength = 40;
        player.stamina = 30;
        player.charisma = 20;
    }

    else if(player.getMajor() == "Business") {
        
        player.intelligence = 30;
        player.strength = 40;
        player.stamina = 20;
        player.charisma = 50;
    }

    else if(player.getMajor() == "Health") {
        
        player.intelligence = 40;
        player.strength = 50;
        player.stamina = 30;
        player.charisma = 20;
    }

    else if(player.getMajor() == "Humanities") {
        
        player.intelligence = 20;
        player.strength = 30;
        player.stamina = 50;
        player.charisma = 40;
    }

}

void Player::setHealth(int hp) {
    this->health = hp;
}

int Player::getHealth() {
    return health;
}

int Player::getStrength() {
    return strength;
}

void Player::setStrenght(int str) {
    this->strength = str;
}
 void Player::setIntelligence(int iq) {
    this->intelligence = iq;
}
int Player::getIntelligence() {
    return intelligence;
}

void Player::setStamina(int stm) {
    this->stamina = stm;
}

int Player::getStamina() {
    return stamina;
}

void Player::setCharisma(int chr) {
    this->charisma = chr;
}
int Player::getCharisma() {
    return charisma;
}



void Player::attack() {



}