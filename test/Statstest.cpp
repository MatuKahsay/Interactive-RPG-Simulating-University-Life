#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Stats.h"

TEST(StatsTest, constructorTest) {
    EXPECT_NO_THROW(Stats testStats);
}

TEST(StatsTest, setHealthTest) {
    Stats testStats;
    testStats.setHealth(100);
    EXPECT_EQ(testStats.getHealth(), 100);
}

TEST(StatsTest, getHealthTest) {
    Stats testStats;
    testStats.setHealth(100);
    EXPECT_EQ(testStats.getHealth(), 100);
}

TEST(StatsTest, setStrengthTest) {
    Stats testStats;
    testStats.setStrength(100);
    EXPECT_EQ(testStats.getStrength(), 100);
}

TEST(StatsTest, getStrengthTest) {
    Stats testStats;
    testStats.setStrength(100);
    EXPECT_EQ(testStats.getStrength(), 100);
}

TEST(StatsTest, setIntelligenceTest) {
    Stats testStats;
    testStats.setIntelligence(100);
    EXPECT_EQ(testStats.getIntelligence(), 100);
}

TEST(StatsTest, getIntelligenceTest) {
    Stats testStats;
    testStats.setIntelligence(100);
    EXPECT_EQ(testStats.getIntelligence(), 100);
}

TEST(StatsTest, setStaminaTest) {
    Stats testStats;
    testStats.setStamina(100);
    EXPECT_EQ(testStats.getStamina(), 100);
}

TEST(StatsTest, getStaminaTest) {
    Stats testStats;
    testStats.setStamina(100);
    EXPECT_EQ(testStats.getStamina(), 100);
}


TEST(StatsTest, setCharismaTest) {
    Stats testStats;
    testStats.setCharisma(100);
    EXPECT_EQ(testStats.getCharisma(), 100);
}

TEST(StatsTest, getCharismaTest) {
    Stats testStats;
    testStats.setCharisma(100);
    EXPECT_EQ(testStats.getCharisma(), 100);
}