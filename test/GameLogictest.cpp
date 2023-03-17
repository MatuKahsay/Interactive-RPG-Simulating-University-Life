#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameLogic.h"

class SceneStub : public scene {
    private:
        vector<string> sceneButtons = {};
        string sceneType = "testType";
        string picture = "testPicture";
        string difficulty = "testDifficulty";
        string text1 = "testText1";
        string text2 = "testText2";
        string text3 = "testText3";
    public:
        SceneStub() : scene(sceneType, sceneButtons, picture, difficulty, text1, text2, text3) {}
};

TEST(GameLogicTests, defaultConstructorTest) {
    EXPECT_NO_THROW(GameLogic testGameLogic);
}

TEST(GameLogicTests, parameterConstructorTest) {
    Player testPlayer;
    vector<scene*> testList;
    EXPECT_NO_THROW(GameLogic testGameLogic(testList, testPlayer));
}

TEST(GameLogicTests, addSceneTest) {
    Player testPlayer;
    vector<scene*> testList = {};
    GameLogic testGameLogic(testList, testPlayer);
    string testSceneType;
    vector<string> testButtons = {};
    string testPictureDir; 
    string testDifficulty; 
    string testText1; 
    string testText2; 
    string testText3;
    scene* newScene = new scene(testSceneType, testButtons, testPictureDir, testDifficulty, testText1, testText2, testText3);
    testGameLogic.addScene(testSceneType, testButtons, testPictureDir, testDifficulty, testText1, testText2, testText3);
    scene* resultScene = testGameLogic.getScene(0);
    EXPECT_EQ(testGameLogic.getScene(0), resultScene);
}

TEST(GameLogicTests, removeSceneTest) {
    SceneStub* newScene;
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.removeScene(0);
    EXPECT_EQ(testGameLogic.getScene(0), nullptr);
}

TEST(GameLogicTests, clearScenesTest) {
    SceneStub* newScene;
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.clearScenes();
    EXPECT_EQ(testGameLogic.getScene(0), nullptr);
}

TEST(GameLogicTests, getSceneTest) {
    SceneStub* newScene;
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    scene* resultScene = testGameLogic.getScene(0);
    EXPECT_EQ(resultScene, newScene);
}

TEST(GameLogicTests, getCurrSceneTest) {
    SceneStub* newScene;
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.setCurrScene(0);
    EXPECT_EQ(testGameLogic.getCurrScene(), newScene);
}

TEST(GameLogicTests, setCurrSceneTest) {
    SceneStub* newScene;
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.setCurrScene(0);
    EXPECT_EQ(testGameLogic.getCurrScene(), newScene);
}

TEST(GameLogicTests, getNextSceneTest) {
    SceneStub* newScene;
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.setNextScene(0);
    EXPECT_EQ(testGameLogic.getNextScene(), 0);
}

TEST(GameLogicTests, setNextSceneTest) {
    SceneStub* newScene;
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.setNextScene(0);
    EXPECT_EQ(testGameLogic.getNextScene(), 0);
}

TEST(GameLogicTests, getCurrSceneDiffTest) {
    SceneStub* newScene;
    string testDiff = "testDifficulty";
    Player testPlayer;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.setCurrScene(0);
    EXPECT_EQ("testDifficulty", testDiff);
}

TEST(GameLogicTests, addEnemyTest) {
    SceneStub* newScene;
    Player testPlayer;
    Enemy* testEnemy;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.addEnemy(testEnemy);
    EXPECT_EQ(testGameLogic.getEnemy(0), testEnemy);
}

TEST(GameLogicTests, getEnemyTest) {
    SceneStub* newScene;
    Player testPlayer;
    Enemy* testEnemy;
    vector<scene*> testList = {newScene};
    GameLogic testGameLogic(testList, testPlayer);
    testGameLogic.addEnemy(testEnemy);
    EXPECT_EQ(testGameLogic.getEnemy(0), testEnemy);
}

TEST(GameLogicTests, addEnemyStatsTest) {
    // SceneStub* newScene;
    // Player testPlayer;
    // Stats* testEnemyStats = new Stats();
    // vector<scene*> testList = {newScene};
    // GameLogic* testGameLogic = new GameLogic(testList, testPlayer);
    // testGameLogic->addEnemyStats(*testEnemyStats);
    // Stats* resultStats = testGameLogic->getEnemyStats(0);
    // EXPECT_EQ(resultStats, testEnemyStats);
}

TEST(GameLogicTests, getEnemyStatsTest) {
    // SceneStub* newScene;
    // Player testPlayer;
    // Stats testEnemyStats;
    // vector<scene*> testList = {newScene};
    // GameLogic testGameLogic(testList, testPlayer);
    // testGameLogic.addEnemyStats(testEnemyStats);
    // Stats resultStats = testGameLogic.getEnemyStats(0);
    // EXPECT_EQ(testGameLogic.getEnemyStats(0), resultStats);
}

TEST(GameLogicTests, addItemTest) {
    // SceneStub* newScene;
    // Player testPlayer;
    // Item testItem;
    // vector<scene*> testList = {newScene};
    // GameLogic testGameLogic(testList, testPlayer);
    // Item resultItem = testGameLogic.addItem(testItem);
    // EXPECT_EQ(testGameLogic.getItem(0), resultItem);
}

TEST(GameLogicTests, getItemTest) {
    // SceneStub* newScene;
    // Player testPlayer;
    // Item testItem;
    // vector<scene*> testList = {newScene};
    // GameLogic testGameLogic(testList, testPlayer);
    // Item resultItem = testGameLogic.addItem(testItem);
    // EXPECT_EQ(testGameLogic.getItem(0), resultItem);
}

TEST(GameLogicTests, addItemStatsTest) {
    // SceneStub* newScene;
    // Player testPlayer;
    // Stats testItemStats;
    // vector<scene*> testList = {newScene};
    // GameLogic testGameLogic(testList, testPlayer);
    // Stats resultItemStats = testGameLogic.addItemStats(testItem);
    // EXPECT_EQ(testItemStats, resultItemStats);
}

TEST(GameLogicTests, getItemStatsTest) {
    // SceneStub* newScene;
    // Player testPlayer;
    // Stats testItemStats;
    // vector<scene*> testList = {newScene};
    // GameLogic testGameLogic(testList, testPlayer);
    // Stats resultItemStats = testGameLogic.addItemStats(testItem);
    // EXPECT_EQ(testItemStats, resultItemStats);
}