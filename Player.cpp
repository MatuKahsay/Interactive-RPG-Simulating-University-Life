#include "Player.h"

#include <iostream>
#include <random>

using namespace std;


void Player::setMajor(string mjr) {
    this->major = mjr;
}

Player::Player()
{
    this->major = "";
}

string Player::getMajor() {
    return major;
}


void Player::setStats(Stats &playerStats) {

    playerStats.setHealth(100);

    if(this->getMajor() == "Engineering") {

        playerStats.setIntelligence(50);
        playerStats.setStrength(40);
        playerStats.setStamina(30);
        playerStats.setCharisma(20);
    }

    else if(this->getMajor() == "Business") {
        playerStats.setIntelligence(30);
        playerStats.setStrength(40);
        playerStats.setStamina(20);
        playerStats.setCharisma(50);
    }

    else if(this->getMajor() == "Health") {
        
        playerStats.setIntelligence(40);
        playerStats.setStrength(50);
        playerStats.setStamina(30);
        playerStats.setCharisma(20);

    }

    else if(this->getMajor() == "Humanities") {
        playerStats.setIntelligence(20);
        playerStats.setStrength(30);
        playerStats.setStamina(50);
        playerStats.setCharisma(40);
    }

}

void Player::showStats(Stats &playerStats) {

    cout << "These are the current stats of the player" << endl;
    cout << "Health: " << playerStats.getHealth() << endl;
    cout << "Intelligence: " << playerStats.getIntelligence() << endl;
    cout << "Strength: " << playerStats.getStrength() << endl;
    cout << "Stamina: " << playerStats.getStamina() << endl;
    cout << "Charisma: " << playerStats.getCharisma() << endl;
}

void Player::attack(Stats &playerStats, Stats &enemyStats) {
    int baseAttack = 7, hitAmount = 0, enemyHealth = 0, prob = 0;

    if(playerStats.getStrength() < 20) {
        // random_device rd;

        // uniform_int_distribution<int> dist(1,3);

        prob = 1;

        if((prob == 1) && (playerStats.getStrength() == 0)) {
            int hitAmount = prob * playerStats.getStrength();

            cout << "You hit a critical, but your strength is zero. " << endl;

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }
        else if ((prob == 1) && (playerStats.getStrength() > 0)) {
            int hitAmount = prob * baseAttack;

            cout << "You did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }
        // else {
            
        //     int hitAmount = prob * baseAttack;

        //     cout << "You did " << hitAmount << " damage. ";

        //     enemyHealth = enemyStats.getHealth() - hitAmount;

        //     enemyStats.setHealth(enemyHealth);
        // }
    }
    else if((playerStats.getStrength() >= 20) && (playerStats.getStrength() <= 29)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,5);

        prob = dist(rd);

        if ((prob == 5)) {
            int hitAmount = prob * baseAttack;

            cout << "You got a critical, you did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }

        else {
            
            int hitAmount = prob * baseAttack;

            cout << "You did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }

    }

    else if((playerStats.getStrength() >= 30) && (playerStats.getStrength() <= 39)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,6);

        prob = dist(rd);

        if ((prob == 5) || (prob == 6)) {
            int hitAmount = prob * baseAttack;

            cout << "You got a critical, you did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }

        else {
            
            int hitAmount = prob * baseAttack;

            cout << "You did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }
    }
    else if((playerStats.getStrength() >= 40) && (playerStats.getStrength() <= 49)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,7);

        prob = dist(rd);

        if ((prob == 5) || (prob == 6)|| (prob == 7)) {
            int hitAmount = prob * baseAttack;

            cout << "You got a critical, you did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }

        else {
            
            int hitAmount = prob * baseAttack;

            cout << "You did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }
    }

    else if((playerStats.getStrength() >= 50) && (playerStats.getStrength() <= 100)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,8);

        prob = dist(rd);

        if ((prob == 5) || (prob == 6)|| (prob == 7) || (prob == 8)) {
            int hitAmount = prob * baseAttack;

            cout << "You got a critical, you did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }

        else {
            
            int hitAmount = prob * baseAttack;

            cout << "You did " << hitAmount << " damage. ";

            enemyHealth = enemyStats.getHealth() - hitAmount;

            enemyStats.setHealth(enemyHealth);
        }
    }

}

void Player::equipItem(Stats &playerStats, Item& item) {
    playerStats.setHealth(playerStats.getHealth() + item.getStats().getHealth());
    playerStats.setIntelligence(playerStats.getIntelligence() + item.getStats().getIntelligence());
    playerStats.setStrength(playerStats.getStrength() + item.getStats().getStrength());
    playerStats.setStamina(playerStats.getStamina() + item.getStats().getStamina());
    playerStats.setCharisma(playerStats.getCharisma() + item.getStats().getCharisma());

    // for (int i = 0; i < itemInv.)
}

void Player::unequipItem(Stats &playerStats, Item& item){
    playerStats.setHealth(playerStats.getHealth() - item.getStats().getHealth());
    playerStats.setIntelligence(playerStats.getIntelligence() - item.getStats().getIntelligence());
    playerStats.setStrength(playerStats.getStrength() - item.getStats().getStrength());
    playerStats.setStamina(playerStats.getStamina() - item.getStats().getStamina());
    playerStats.setCharisma(playerStats.getCharisma() - item.getStats().getCharisma());
}