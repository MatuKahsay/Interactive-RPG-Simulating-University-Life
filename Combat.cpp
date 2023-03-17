#include "Combat.h"
#include <iostream>
#include <random>

using namespace std;


void Combat::Fight(Player &player1, Stats &playerStats,Enemy &enemy1, Stats &enemyStats) {
     
     while((playerStats.getHealth() > 0) || (enemyStats.getHealth() > 0)) {
        player1.attack(playerStats, enemyStats);
        if(enemyStats.getHealth() <= 0) {
            break;
        }
        enemy1.attack(playerStats, enemyStats);
        if(playerStats.getHealth() <= 0) {
            break;
        }
    }

}

bool Combat::Run(Stats &playerStats) {

    if(playerStats.getStamina() < 20) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,10);

        int prob = dist(rd);

        if(prob == 10) {
             cout << "You decide to run away from the enemy and the enemy is slow to catch up, you have successfully ran away from the enemy. " << endl;
             return true;
        }

        else {
             cout << "You try to run away from the enemy, but the enemy is to fast, so they catch up to you. You must fight the enemy. " << endl;
             return false;
        }
    }

    else if((playerStats.getStamina() >= 20) && (playerStats.getStamina() <= 29)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,5);

        int prob = dist(rd);

        if(prob == 5) {
            cout << "You decide to run away from the enemy and the enemy is slow to catch up, you have successfully ran away from the enemy. " << endl;
            return true;
        }

        else {
            cout << "You try to run away from the enemy, but the enemy is to fast, so they catch up to you. You must fight the enemy. " << endl;
            return false;
        }
    }

    else if((playerStats.getStamina() >= 30) && (playerStats.getStamina() <= 39)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,6);

        int prob = dist(rd);

        if(prob == 5 || prob == 6) {
            cout << "You decide to run away from the enemy and the enemy is slow to catch up, you have successfully ran away from the enemy. " << endl;
            return true;
        }

        else {
            cout << "You try to run away from the enemy, but the enemy is to fast, so they catch up to you. You must fight the enemy. " << endl;
            return false;
        }
    }

    else if((playerStats.getStamina() >= 40) && (playerStats.getStamina() <= 49)){
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,7);

        int prob = dist(rd);

        if(prob == 5 || prob == 6 || prob == 7) {
            cout << "You decide to run away from the enemy and the enemy is slow to catch up, you have successfully ran away from the enemy. " << endl;
            return true;
        }

        else {
            cout << "You try to run away from the enemy, but the enemy is to fast, so they catch up to you. You must fight the enemy. " << endl;
            return false;
        }
    }

    else if((playerStats.getStamina() >= 50) && (playerStats.getStamina() <= 100)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,8);

        int prob = dist(rd);

        if(prob == 5 || prob == 6 || prob == 7 || prob == 8) {
            cout << "You decide to run away from the enemy and the enemy is slow to catch up, you have successfully ran away from the enemy. " << endl;
            return true;
        }

        else {
            cout << "You try to run away from the enemy, but the enemy is to fast, so they catch up to you. You must fight the enemy. " << endl;
            return false;
        }
    }
}

bool Combat::Talk(Stats &playerStats) {

    if(playerStats.getCharisma() < 20) {
        random_device rd;
        
        uniform_int_distribution<int> dist(1,10);

        int prob = dist(rd);

        if(prob == 10) {
            cout << "Successfully charmed your away out of the fight" << endl;
            return true;
        }

        else {
            cout << "Charm didn't work, you must fight" << endl;
        }
    }
    else if((playerStats.getCharisma() >= 20) && (playerStats.getCharisma() <= 29)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,5);

        int talk = dist(rd);

        if(talk == 5) {
            cout << "Successfully charmed your away out of the fight" << endl;
        }

        else {
             cout << "Charm didn't work, you must fight" << endl;
        }
    }

    else if((playerStats.getCharisma() >= 30) && (playerStats.getCharisma() <= 39)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,6);

        int talk = dist(rd);

        if(talk == 5 || talk == 6) {
            cout << "Successfully charmed your away out of the fight" << endl;
        }

        else {
            cout << "Charm didn't work, you must fight" << endl;
        }
    }

    else if((playerStats.getCharisma() >= 40) && (playerStats.getCharisma() <= 49)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,7);

        int talk = dist(rd);

        if(talk == 5 || talk == 6 || talk == 7) {
            cout << "Successfully charmed your away out of the fight" << endl;
        }

        else {
            cout << "Charm didn't work, you must fight" << endl;
        }
    }

    else if((playerStats.getCharisma() >= 50) && (playerStats.getCharisma() <= 100)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,8);

        int talk = dist(rd);

        if(talk == 5 || talk == 6 || talk == 7 || talk == 8) {
            cout << "Successfully charmed your away out of the fight" << endl;
        }

        else {
            cout << "Charm didn't work, you must fight" << endl;
        }
    }
}

bool Combat::Examine(Stats &playerStats) {
    int playerBoost = 0;

    if(playerStats.getIntelligence() < 20) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,10);

        int iq = dist(rd);

        if(iq == 10) {
            cout << "You have examined your surroundings and have discovered a weapon to use, this boosts your strength by 10. " << endl;
            playerBoost = playerStats.getStrength() + 10;
            playerStats.setStrength(playerBoost);
            return true;
        }

        else {
            cout << "You have examined your surroundings and have found nothing. " << endl;
        }
    }
    
    else if((playerStats.getIntelligence() >= 20) && (playerStats.getIntelligence() <= 29)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,5);

        int iq = dist(rd);

        if(iq == 5) {
            cout << "You have examined your surroundings and have discovered a weapon to use, this boosts your strength by 10. " << endl;
            playerBoost = playerStats.getStrength() + 10;
            playerStats.setStrength(playerBoost);
        }

        else {
            cout << "You have examined your surroundings and have found nothing. " << endl;
        }
    }

   else if((playerStats.getIntelligence() >= 30) && (playerStats.getIntelligence() <= 39)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,6);

        int iq = dist(rd);

        if(iq == 5 || iq == 6) {
            cout << "You have examined your surroundings and have discovered a weapon to use, this boosts your strength by 10. " << endl;
            playerBoost = playerStats.getStrength() + 10;
            playerStats.setStrength(playerBoost);
        }

        else {
            cout << "You have examined your surroundings and have found nothing. " << endl;
        }
    }

   else if((playerStats.getIntelligence() >= 40) && (playerStats.getIntelligence() <= 49)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,7);

        int iq = dist(rd);

        if(iq == 5 || iq == 6 || iq == 7) {
           cout << "You have examined your surroundings and have discovered a weapon to use, this boosts your strength by 10. " << endl;
            playerBoost = playerStats.getStrength() + 10;
            playerStats.setStrength(playerBoost);
        }

        else {
            cout << "You have examined your surroundings and have found nothing. " << endl;
        }
    }

   else if((playerStats.getIntelligence() >= 50) && (playerStats.getIntelligence() <= 100)) {
        
        random_device rd;
        
        uniform_int_distribution<int> dist(1,8);

        int iq = dist(rd);

        if(iq == 5 || iq == 6 || iq == 7 || iq == 8) {
            cout << "You have examined your surroundings and have discovered a weapon to use, this boosts your strength by 10. " << endl;
            playerBoost = playerStats.getStrength() + 10;
            playerStats.setStrength(playerBoost);
        }

        else {
            cout << "You have examined your surroundings and have found nothing. " << endl;
        }
    }
}