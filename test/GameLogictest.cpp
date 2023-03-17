#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameLogic.h"

TEST(GameLogicTests, defaultConstructorTest) {
    EXPECT_NO_THROW(GameLogic testGameLogic);
}

TEST(GameLogicTests, parameterConstructorTest) {
    Player testPlayer;
    vector<scene*> testList;
    EXPECT_NO_THROW(GameLogic testGameLogic(testList, testPlayer));
}

TEST(GameLogicTests) {

}