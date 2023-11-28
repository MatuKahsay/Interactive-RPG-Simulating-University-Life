#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Combat.h"
using ::testing::InSequence;

class PlayerStub : public Player {
    public:
        // void attack(Stats& playerStats, Stats& enemyStats) {
        //     enemyStats.setHealth(90);
        // }
};

class EnemyStub : public Enemy {
    public:
        // void attack(Stats& playerStats, Stats& enemyStats) {
        //     playerStats.setHealth(90);
        // }
};

class StatsStub : public Stats {
    public:
        StatsStub() {
            this->setHealth(100);
            this->setStrength(50);
            this->setIntelligence(50);
            this->setStamina(50);   
            this->setCharisma(50);
        }
};

class MockStats : public Stats {
    public:
        MOCK_METHOD(void, getStamina, ()); 
        MOCK_METHOD(void, getCharisma, ()); 
        MOCK_METHOD(void, setIntelligence, ());
};

// All of these tests fail due to Liskov Subsitution principle
TEST(CombatTest, fightTest) {
    Combat testCombat;
    PlayerStub testPlayer;
    EnemyStub testEnemy;
    StatsStub testPlayerStats;
    StatsStub testEnemyStats;
    testCombat.Fight(testPlayer, testPlayerStats, testEnemy, testEnemyStats);
    EXPECT_EQ(testPlayerStats.getHealth(), 2);
    EXPECT_EQ(testEnemyStats.getHealth(), 0);
}

TEST(CombatTest, runTest) {
    Combat testCombat;
    MockStats testStats;
    {
        InSequence sequence;
        EXPECT_CALL(testStats, getStamina());
        EXPECT_CALL(testStats, getStamina());
    }
    testCombat.Run(testStats);
}

TEST(CombatTest, talkTest) {
    Combat testCombat;
    MockStats testStats;
    {
        InSequence sequence;
        EXPECT_CALL(testStats, getCharisma());
        EXPECT_CALL(testStats, getCharisma());
    }
    testCombat.Run(testStats);
}

TEST(CombatTest, examineTest) {
    Combat testCombat;
    MockStats testStats;
    {
        InSequence sequence;
        EXPECT_CALL(testStats, setIntelligence());
        EXPECT_CALL(testStats, setIntelligence());
    }
    testCombat.Run(testStats);
}

