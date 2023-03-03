#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(int health, int strength, int intelligence, int stamina, int charisma, string major) {
    this->health = health;
    this->strength = strength;
    this->intelligence = intelligence;
    this->stamina = stamina;
    this->charisma = charisma;
    this->major = major;

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