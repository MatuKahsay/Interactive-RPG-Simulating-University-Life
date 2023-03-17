#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Player.h"
#include "Action.h"
#include "Stats.h"
#include "Enemy.h"
#include "Item.h"
#include <vector>
#include <string>
using ::testing::InSequence;

class MockStats : public Stats {
    public:
        MockStats() {
            this->setHealth(100);
            this->setStrength(50);
            this->setIntelligence(50);
            this->setStamina(50);   
            this->setCharisma(50);
        }
};



/* Test for action class*/

TEST(ActionTests, Action1){
    Action action1;
    MockStats playerStats1;
    int stats = playerStats1.getIntelligence();
    action1.studyAtLibrary(playerStats1);
    int newStats = playerStats1.getIntelligence();
    EXPECT_EQ(newStats, stats + 10);

}

TEST(ActionTests, Action2){
    Action action1;
    MockStats playerStats1;
    int stats = playerStats1.getStrength();
    action1.workoutAtSRC(playerStats1);
    int newStats = playerStats1.getStrength();
    EXPECT_EQ(newStats, stats + 10);

}

TEST(ActionTests, Action3){
    Action action1;
    MockStats playerStats1;
    int stats = playerStats1.getCharisma();
    action1.goToParty(playerStats1);
    int newStats = playerStats1.getCharisma();
    EXPECT_EQ(newStats, stats + 10);

}

TEST(ActionTests, Action4){
    Action action1;
    MockStats playerStats1;
    int stats = playerStats1.getStamina();
    action1.eatAtGlassgow(playerStats1);
    int newStats = playerStats1.getStamina();
    EXPECT_GT(newStats, stats);

}

/*Test for enemy class*/

TEST(EnemyTests, Enemy1){
    Enemy enemy1("hard");
    MockStats enemyStats1;
    enemy1.setStats(enemyStats1, "hard");
    EXPECT_EQ(enemyStats1.getStrength(), 60);

}

TEST(EnemyTests, Enemy2){
    Enemy enemy2("hard");
    MockStats enemyStats2;
    MockStats playerStats1;
    playerStats1.setHealth(100);
    enemyStats2.setHealth(100);
    playerStats1.setStrength(30);
    enemyStats2.setStrength(20);
    enemy2.attack(playerStats1, enemyStats2);
    EXPECT_FALSE(enemyStats2.getHealth() < 100);

}

TEST(EnemyTests, Enemy3){
    Enemy enemy3("hard");
    MockStats enemyStats3;
    MockStats playerStats2;
    enemy3.showStats(enemyStats3);
    EXPECT_EQ(enemyStats3.getStrength(), 50);

}

TEST(EnemyTests, Enemy4){
    Enemy enemy4("medium");
    MockStats enemyStats4;
    enemy4.showStats(enemyStats4);
    EXPECT_EQ(enemyStats4.getStrength(), 50);

}

TEST(EnemyTests, Enemy5){
    Enemy enemy5("easy");
    MockStats enemyStats5;
    enemy5.showStats(enemyStats5);
    EXPECT_EQ(enemyStats5.getStrength(), 50);

}

TEST(EnemyTests, Enemy6){
    Enemy enemy6("hard");
    MockStats enemyStats6;
    enemy6.setDiff("medium");
    EXPECT_EQ(enemyStats6.getStrength(), 50);

}


/* Player Tests*/

TEST(PlayerTests, Player1){
    Player p1;
    MockStats pStats;
    EXPECT_NO_THROW(p1.showStats(pStats));

}

TEST(PlayerTests, Player2){
    Enemy testEnemy("hard");
    MockStats testEnemyStats;
    MockStats pStats2;
    pStats2.setHealth(100);
    testEnemyStats.setHealth(100);
    pStats2.setStrength(30);
    testEnemyStats.setStrength(20);
    testEnemy.attack(pStats2, testEnemyStats);
    EXPECT_TRUE(pStats2.getHealth() < 100);

}

TEST(PlayerTests, Player3){
    Enemy testEnemy2("hard");
    MockStats testEnemyStats2;
    MockStats pStats3;
    pStats3.setHealth(100);
    testEnemyStats2.setHealth(100);
    pStats3.setStrength(30);
    testEnemyStats2.setStrength(20);
    testEnemy2.attack(pStats3, testEnemyStats2);
    EXPECT_TRUE(pStats3.getHealth() < 100);
    EXPECT_EQ(testEnemyStats2.getStrength(), 20);

}

TEST(PlayerTests, Player4){
    Player p4;
    MockStats pStats3;
    MockStats itemStats1;
    itemStats1.setStrength(20);
    Item itemPencil("Pencil", "weapon", itemStats1);
    p4.equipItem(itemStats1, itemPencil);
    EXPECT_EQ(itemStats1.getStrength(), 40);

}

TEST(PlayerTests, Player5){
    Player p4;
    MockStats pStats3;
    MockStats itemStats1;
    itemStats1.setStrength(20);
    Item itemPencil("Pencil", "weapon", itemStats1);
    p4.unequipItem(itemStats1, itemPencil);
    EXPECT_EQ(pStats3.getStrength(), 50);

}





