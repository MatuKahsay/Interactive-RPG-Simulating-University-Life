#include "Enemy.h"

#include <iostream>
#include <random>

using namespace std;


Enemy::Enemy() {
    this->difficulty = "";
}

string Enemy::getDiff() {
    return difficulty;
}

void Enemy::setDiff(string difficulty) {
    //based upon the scence you will be able to get a the difficulty of the enemy.
    this->difficulty = difficulty;
}


void Enemy::setStats(Stats& enemyStats, string difficulty) {

    enemyStats.setHealth(100);
    this->setDiff(difficulty);

    if (this->getDiff() == "easy") {
        enemyStats.setStrength(20);
        enemyStats.setHealth(100);
    }
    else if (this->getDiff() == "") {
        enemyStats.setStrength(30);
        enemyStats.setHealth(100);

    }
    else if (this->getDiff() == "medium") {
        enemyStats.setStrength(40);
        enemyStats.setHealth(100);

    }
    else if (this->getDiff() == "") {
        enemyStats.setStrength(50);

    }
    else if (this->getDiff() == "hard") {
        enemyStats.setStrength(60);
        enemyStats.setHealth(100);

    }
}

void Enemy::showStats(Stats& enemyStats) {

    cout << "These are the current stats of the enemy" << endl;
    cout << "Health: " << enemyStats.getHealth() << endl;
    cout << "Strength: " << enemyStats.getStrength() << endl;

}

void Enemy::attack(Stats& playerStats, Stats& enemyStats) {
    int baseAttack = 7, hitAmount = 0, playerHealth = 0, prob = 0;

    if (enemyStats.getStrength() < 20) {
        random_device rd;

        uniform_int_distribution<int> dist(1, 3);

        prob = dist(rd);

        if ((prob == 3) && (enemyStats.getStrength() == 0)) {
            int hitAmount = prob * playerStats.getStrength();

            cout << "The enemy hit a critical, but their strength is zero. " << endl;

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }
        else if ((prob == 5) && (enemyStats.getStrength() > 0)) {
            int hitAmount = prob * baseAttack;

            cout << "The enemy got a critical, they did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }
        else {

            int hitAmount = prob * baseAttack;

            cout << "The enemy did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }
    }
    else if ((enemyStats.getStrength() >= 20) && (enemyStats.getStrength() <= 29)) {

        random_device rd;

        uniform_int_distribution<int> dist(1, 5);

        prob = dist(rd);

        if ((prob == 5)) {
            int hitAmount = prob * baseAttack;

            cout << "The enemy got a critical, they did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }

        else {

            int hitAmount = prob * baseAttack;

            cout << "The enemy did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }

    }

    else if ((enemyStats.getStrength() >= 30) && (enemyStats.getStrength() <= 39)) {

        random_device rd;

        uniform_int_distribution<int> dist(1, 6);

        prob = dist(rd);

        if ((prob == 5) || (prob == 6)) {
            int hitAmount = prob * baseAttack;

            cout << "The enemy got a critical, they did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }

        else {

            int hitAmount = prob * baseAttack;

            cout << "The enemy did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }
    }
    else if ((enemyStats.getStrength() >= 40) && (enemyStats.getStrength() <= 49)) {

        random_device rd;

        uniform_int_distribution<int> dist(1, 7);

        prob = dist(rd);

        if ((prob == 5) || (prob == 6) || (prob == 7)) {
            int hitAmount = prob * baseAttack;

            cout << "The enemy got a critical, they did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }

        else {

            int hitAmount = prob * baseAttack;

            cout << "The enemy did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }
    }

    else if ((enemyStats.getStrength() >= 50) && (enemyStats.getStrength() <= 100)) {

        random_device rd;

        uniform_int_distribution<int> dist(1, 8);

        prob = dist(rd);

        if ((prob == 5) || (prob == 6) || (prob == 7) || (prob == 8)) {
            int hitAmount = prob * baseAttack;

            cout << "The enemy got a critical, they did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }

        else {

            int hitAmount = prob * baseAttack;

            cout << "The enemy did " << hitAmount << " damage. ";

            playerHealth = playerStats.getHealth() - hitAmount;

            playerStats.setHealth(playerHealth);
        }
    }

}