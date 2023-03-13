#include "Enemy.h"
//#include "Player.h"
#include "item.h"
#include <iostream>



Enemy::Enemy(const Stats& stat, int ID){
    enemyID = ID;
    enemyStats = stat; 

}

void Enemy::equipItem(Item& item) {
    enemyStats.setHealth(enemyStats.getHealth() + item.getStats().getHealth());
    enemyStats.setIntelligence(enemyStats.getIntelligence() + item.getStats().getIntelligence());
    enemyStats.setStrength(enemyStats.getStrength() + item.getStats().getStrength());
    enemyStats.setStamina(enemyStats.getStamina() + item.getStats().getStamina());
    enemyStats.setCharisma(enemyStats.getCharisma() + item.getStats().getCharisma());

}

void Enemy::unequipItem(Item& item){
    enemyStats.setHealth(enemyStats.getHealth() - item.getStats().getHealth());
    enemyStats.setIntelligence(enemyStats.getIntelligence() - item.getStats().getIntelligence());
    enemyStats.setStrength(enemyStats.getStrength() - item.getStats().getStrength());
    enemyStats.setStamina(enemyStats.getStamina() - item.getStats().getStamina());
    enemyStats.setCharisma(enemyStats.getCharisma() - item.getStats().getCharisma());
}



void Enemy::attack(){
    std::cout << "Attack Start: \n";
    // enemyStats.getStrength();
    
}

/*void Enemy::battle(Player& player, Enemy& enemy){
    int baseAttack = 0;
    while(enemy.getStats().getHealth() > 0){
        std:: cout << "Testing";
    }
}*/


Stats& Enemy::getStats() {
    return enemyStats;
}

void Enemy::printStats(){
    std::cout << "Enemy Health: " << enemyStats.getHealth() << "\n";
    std::cout << "Enemy Strength: " << enemyStats.getStrength()<< "\n";
    std::cout << "Enemy Intelligence: " << enemyStats.getIntelligence()<< "\n";
    std::cout << "Enemy Charisma: " << enemyStats.getCharisma()<< "\n";
    std::cout << "Enemy Stamina: " << enemyStats.getStamina()<< "\n";
    

}