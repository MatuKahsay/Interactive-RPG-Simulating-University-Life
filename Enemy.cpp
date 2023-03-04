#include "Enemy.h"


Enemy::Enemy(const Stats& stat, int ID){
    enemyID = ID;
    enemyStats = stat; 

}

void Enemy::attack(){
    enemyStats.getStrength();

}

int Enemy::getStrength(const Stats& enemyStat){
    enemyStat.getStrength();
}

int Enemy::getHealth(const Stats& enemyStat){
    enemyStat.getHealth();
}


const Stats& Enemy::getStats() const {
    return enemyStats;
}

