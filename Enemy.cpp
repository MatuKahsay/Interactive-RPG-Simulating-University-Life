#include "Enemy.h"


Enemy::Enemy(const Stats& stat, int ID){
    enemyID = ID;
    enemyStats = stat; 

}

void Enemy::attack(){
    enemyStats.getStrength();

}

int Enemy::getStrength(Stats& enemyStat){
    return enemyStat.getStrength();
}

int Enemy::getHealth(Stats& enemyStat){
    return enemyStat.getHealth();
}


const Stats& Enemy::getStats() const {
    return enemyStats;
}

