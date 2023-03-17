#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Player.h"
#include <string>
//using namespace player;
using namespace std;

// class PlayerStub : public Player {
//     public:
//         int getStrength() {return this->strength;}
//         int getIntelligence() {return this->intelligence;}
//         int getStamina() {return this->stamina;}
//         int getCharisma() {return this->charisma;}  
// };

class ItemStub : public Item {
    private:
        Stats testStats;
    public:
        ItemStub() : Item("testName", "testID", this->testStats) {} 
};

TEST(PlayerTests, ConstructorTest) {
    EXPECT_NO_THROW(Player testPlayer);
}

TEST(PlayerTests, getMajorTest) {
    Player testPlayer;
    EXPECT_EQ(testPlayer.getMajor(), "");
}

TEST(PlayerTests, setMajorTest) {
    Player testPlayer;
    testPlayer.setMajor("testMajor");
    EXPECT_EQ(testPlayer.getMajor(), "testMajor");
}

TEST(PlayerTests, setStatsEngineeringTest) {
    Player testPlayer;
    Stats testStats;
    testPlayer.setMajor("Engineering");
    testPlayer.setStats(testStats);
    EXPECT_EQ(testStats.getIntelligence(), 50);
    EXPECT_EQ(testStats.getStrength(), 40);   
    EXPECT_EQ(testStats.getStamina(), 30);
    EXPECT_EQ(testStats.getCharisma(), 20);
}

TEST(PlayerTests, setStatsBusinessTest) {
    Player testPlayer;
    Stats testStats;
    testPlayer.setMajor("Business");
    testPlayer.setStats(testStats);
    EXPECT_EQ(testStats.getIntelligence(), 30);
    EXPECT_EQ(testStats.getStrength(), 40);   
    EXPECT_EQ(testStats.getStamina(), 20);
    EXPECT_EQ(testStats.getCharisma(), 50);
}

TEST(PlayerTests, setStatsHealthTest) {
    Player testPlayer;
    Stats testStats;
    testPlayer.setMajor("Health");
    testPlayer.setStats(testStats);
    EXPECT_EQ(testStats.getIntelligence(), 40);
    EXPECT_EQ(testStats.getStrength(), 50);   
    EXPECT_EQ(testStats.getStamina(), 30);
    EXPECT_EQ(testStats.getCharisma(), 20);
}

TEST(PlayerTests, setStatsHumanitiesTest) {
    Player testPlayer;
    Stats testStats;
    testPlayer.setMajor("Humanities");
    testPlayer.setStats(testStats);
    EXPECT_EQ(testStats.getIntelligence(), 20);
    EXPECT_EQ(testStats.getStrength(), 30);   
    EXPECT_EQ(testStats.getStamina(), 50);
    EXPECT_EQ(testStats.getCharisma(), 40);
}

TEST(PlayerTests, attackTest) {
    Player testPlayer;
    Stats testPlayerStats;
    Stats testEnemyStats;
    testPlayer.attack(testPlayerStats, testEnemyStats);
    EXPECT_EQ(testPlayerStats.getHealth(), 100);
    EXPECT_EQ(testEnemyStats.getHealth(), 100);
}

TEST(PlayerTest, equipItemTest) {
    Player testPlayer;
    Stats testPlayerStats;
    ItemStub testItem;
    testPlayer.equipItem(testPlayerStats, testItem);
    EXPECT_EQ(testPlayerStats.getHealth(), 100);
    EXPECT_EQ(testPlayerStats.getIntelligence(), 100);
    EXPECT_EQ(testPlayerStats.getStrength(), 0);   
    EXPECT_EQ(testPlayerStats.getStamina(), 100);
    EXPECT_EQ(testPlayerStats.getCharisma(), 0);
}

TEST(PlayerTest, unequipItemTest) {
    Player testPlayer;
    Stats testPlayerStats;
    ItemStub testItem;
    testPlayer.unequipItem(testPlayerStats, testItem);
    EXPECT_EQ(testPlayerStats.getHealth(), 52);
    EXPECT_EQ(testPlayerStats.getIntelligence(), 0);
    EXPECT_EQ(testPlayerStats.getStrength(), 100);   
    EXPECT_EQ(testPlayerStats.getStamina(), 0);
    EXPECT_EQ(testPlayerStats.getCharisma(), 100);
}