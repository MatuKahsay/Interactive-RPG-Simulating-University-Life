#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "item.h"

TEST(ItemTests, parameterConstructorTest) {
    EXPECT_NO_THROW(Item testItem());
}

TEST(ItemTests, parameterConstructorValueTest) {
    string testName = "testName";
    string testID = "testID";
    Item testItem(testName, testID);
    EXPECT_EQ(testItem.getName(), testName);
    EXPECT_EQ(testItem.getID(), testID);
}

TEST(ItemTests, getNameTest) {
    string testName = "testName";
    string testID = "testID";
    Item testItem(testName, testID);
    EXPECT_EQ(testItem.getName(), testName);
}

TEST(ItemTests, getIDTest) {
    string testName = "testName";
    string testID = "testID";
    Item testItem(testName, testID);
    EXPECT_EQ(testItem.getID(), testID);
}

TEST(ItemTests, setNameTest) {
    string testName = "testName";
    string testID = "testID";
    string newName = "newName";
    Item testItem(testName, testID);
    testItem.setName(newName);
    EXPECT_EQ(testItem.getName(), newName);
}

TEST(ItemTests, setIDTest) {
    string testName = "testName";
    string testID = "testID";
    string newID = "newID";
    Item testItem(testName, testID);
    testItem.setID(newID);
    EXPECT_EQ(testItem.getID(), newID);
}