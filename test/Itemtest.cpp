#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Item.h"
#include "Stats.h"

TEST(ItemTests, parameterConstructorTest) {
    string testName = "testName";
    string testID = "testID";
    Stats testStats;
    EXPECT_NO_THROW(Item testItem(testName, testID, testStats));
}

TEST(ItemTests, getNameTest) {
    string testName = "testName";
    string testID = "testID";
    Stats testStats;
    Item testItem(testName, testID, testStats);
    EXPECT_EQ(testItem.getName(), testName);
}

TEST(ItemTests, getIDTest) {
    string testName = "testName";
    string testID = "testID";
    Stats testStats;
    Item testItem(testName, testID, testStats);
    EXPECT_EQ(testItem.getID(), testID);
}

TEST(ItemTests, setNameTest) {
    string testName = "testName";
    string testID = "testID";
    string newName = "newName";
    Stats testStats;
    Item testItem(testName, testID, testStats);
    testItem.setName(newName);
    EXPECT_EQ(testItem.getName(), newName);
}

TEST(ItemTests, setIDTest) {
    string testName = "testName";
    string testID = "testID";
    string newID = "newID";
    Stats testStats;
    Item testItem(testName, testID, testStats);
    testItem.setID(newID);
    EXPECT_EQ(testItem.getID(), newID);
}

TEST(ItemTests, getStatsTest) {
    string testName = "testName";
    string testID = "testID";
    string newID = "newID";
    Stats testStats;
    Item testItem(testName, testID, testStats);
    EXPECT_EQ(testItem.getStats().getHealth(), testStats.getHealth());
}