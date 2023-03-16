#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Player.h"
#include "Scene.h"
#include "GameLogic.h"
#include <vector>
using namespace player;
using namespace scene;
using ::testing::InSequence;

class PlayerStub : public Player {
    public:
        
};

class SceneStub : public Scene {
    public:
        void startScene() {
            cout << "Dummy Start" << endl;
        }
};

class MockScene : public Scene
{
    public:
        MOCK_METHOD(void, startScene, (), (override));
};

TEST(GameLogicTests, ConstructorTest) {
    vector<Scene*> testVector;
    PlayerStub testPlayer;
    EXPECT_NO_THROW(GameLogic testGameLogic(testVector, testPlayer));
}

TEST(GameLogicTests, GetSceneTest) {
    vector<Scene*> testVector;
    PlayerStub testPlayer;
    GameLogic testGameLogic(testVector, testPlayer);
    EXPECT_EQ(testGameLogic.getScene(0), 0);
}

TEST(GameLogicTests, AddSceneTest) {
    vector<Scene*> testVector;
    PlayerStub testPlayer;
    SceneStub testScene;
    SceneStub* testScene_p = &testScene;
    GameLogic testGameLogic(testVector, testPlayer);
    testGameLogic.addScene(testScene_p);
    EXPECT_EQ(testGameLogic.getScene(0)->getSceneId(), testScene.getSceneId());
}

TEST(GameLogicTests, RemoveSceneTest) {
    vector<Scene*> testVector;
    PlayerStub testPlayer;
    SceneStub testScene;
    SceneStub* testScene_p = &testScene;
    GameLogic testGameLogic(testVector, testPlayer);
    testGameLogic.addScene(testScene_p);
    testGameLogic.removeScene(0);
    EXPECT_EQ(testGameLogic.getScene(0), 0);
}

TEST(GameLogicTests, ClearScenesTest) {
    vector<Scene*> testVector;
    PlayerStub testPlayer;
    SceneStub testScene1;
    SceneStub testScene2;
    SceneStub* testScene_p1 = &testScene1;
    SceneStub* testScene_p2 = &testScene2;
    GameLogic testGameLogic(testVector, testPlayer);
    testGameLogic.addScene(testScene_p1);
    testGameLogic.addScene(testScene_p2);
    testGameLogic.clearScenes();
    EXPECT_EQ(testGameLogic.getScene(0), 0);
}

TEST(GameLogicTests, InitalizeTest) {
    vector<Scene*> testVector;
    PlayerStub testPlayer;
    Scene* startSceneTest_p = new Scene(/*Start Menu Parameters*/);
    GameLogic testGameLogic(testVector, testPlayer);
    testGameLogic.initialize();
    EXPECT_EQ(testGameLogic.getScene(0)->getSceneId(), startSceneTest_p->getSceneId());
}

TEST(GameLogicTests, playScenesTest) {
    MockScene startScene;
    vector<Scene*> testVector;
    PlayerStub testPlayer;
    GameLogic testGameLogic(testVector, testPlayer);
    {
        InSequence sequence;
        EXPECT_CALL(startScene, startScene());
    }
    testGameLogic.playScenes();
}