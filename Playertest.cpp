#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Player.h"
#include <string>
using namespace player;
using namespace std;

class PlayerStub : public Player {
    public:
        int getStrength() {return this->strength;}
        int getIntelligence() {return this->intelligence;}
        int getStamina() {return this->stamina;}
        int getCharisma() {return this->charisma;}  
};

TEST(PlayerTests, defaultConstructorTest) {
    EXPECT_NO_THROW(Player *testPlayer = new Player());
}

TEST(PlayerTests, parameterConstructorTest) {
    EXPECT_NO_THROW(Player *testPlayer = new Player(1, 2, 3, 4, 5, "testMajor"));
}

TEST(PlayerTests, getMajorBusinessTest) {
    Player testPlayer(0, 0, 0, 0, 0, "Business");
    EXPECT_EQ(testPlayer.getMajor(), "Business");
}

TEST(PlayerTests, getMajorEngineeringTest) {
    Player testPlayer(0, 0, 0, 0, 0, "Engineering");
    EXPECT_EQ(testPlayer.getMajor(), "Engineering");
}

TEST(PlayerTests, getMajorHealthTest) {
    Player testPlayer(0, 0, 0, 0, 0, "Health");
    EXPECT_EQ(testPlayer.getMajor(), "Health");
}

TEST(PlayerTests, getMajorHumanitiesTest) {
    Player testPlayer(0, 0, 0, 0, 0, "Humanities");
    EXPECT_EQ(testPlayer.getMajor(), "Humanities");
}

TEST(PlayerTests, setMajorTest) {
    Player testPlayer;
    testPlayer.setMajor("testMajor");
    EXPECT_EQ(testPlayer.getMajor(), "testMajor");
}

TEST(PlayerTests, setStatsBusinessTest) {
    PlayerStub testPlayer;
    testPlayer.setMajor("Business");
    testPlayer.setStats();
    EXPECT_EQ(testPlayer.getIntelligence(), 30);
    EXPECT_EQ(testPlayer.getStrength(), 40);   
    EXPECT_EQ(testPlayer.getStamina(), 20);
    EXPECT_EQ(testPlayer.getCharisma(), 50);
}

TEST(PlayerTests, setStatsEngineeringTest) {
    PlayerStub testPlayer;
    testPlayer.setMajor("Engineering");
    testPlayer.setStats();
    EXPECT_EQ(testPlayer.getIntelligence(), 50);
    EXPECT_EQ(testPlayer.getStrength(), 40);
    EXPECT_EQ(testPlayer.getStamina(), 30);
    EXPECT_EQ(testPlayer.getCharisma(), 20);
}

TEST(PlayerTests, setStatsHealthTest) {
    PlayerStub testPlayer;
    testPlayer.setMajor("Health");
    testPlayer.setStats();
    EXPECT_EQ(testPlayer.getIntelligence(), 40);
    EXPECT_EQ(testPlayer.getStrength(), 50);
    EXPECT_EQ(testPlayer.getStamina(), 30);
    EXPECT_EQ(testPlayer.getCharisma(), 20);
}

TEST(PlayerTests, setStatsHumanitiesTest) {
    PlayerStub testPlayer;
    testPlayer.setMajor("Humanities");
    testPlayer.setStats();
    EXPECT_EQ(testPlayer.getIntelligence(), 20);
    EXPECT_EQ(testPlayer.getStrength(), 30);
    EXPECT_EQ(testPlayer.getStamina(), 50);
    EXPECT_EQ(testPlayer.getCharisma(), 40);
}