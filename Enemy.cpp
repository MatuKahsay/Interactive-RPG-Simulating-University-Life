#include "Enemy.h"


Enemy::Enemy(const Stats& stat, int ID){
    enemyID = ID;
    enemyStats = stat; 

}


void Enemy::attack(){
    enemyStats.getStrength();
    


}


const Stats& Enemy::getStats() const {
    return enemyStats;
}