#include "GameLogic.h""
#ifndef GAMELOGIC_CPP
#define GAMELOGIC_CPP

#include <vector>
#include "GameLogic.h"

GameLogic::GameLogic() {}

GameLogic::GameLogic(vector<scene*> newList, Player newPlayer) {
    this->sceneList = newList;
    this->Protagonist = newPlayer;
}

GameLogic::~GameLogic() {
    for (int i = 0; i < this->sceneList.size(); i++) {
        this->sceneList.at(i) = 0;
        this->removeScene(i);
    }
    // delete this->sceneList;
    // delete this->Protagonist;
}

void GameLogic::addScene(string sceneType, vector<string> Buttons, string pictureDir, string difficulty, string text1, string text2, string text3) {
    scene* newScene = new scene(sceneType, Buttons, pictureDir, difficulty, text1, text2, text3);
    sceneList.push_back(newScene);
}

void GameLogic::removeScene(int index) {
    this->sceneList.at(index)->deleteScene(); // Scene takes care of deallocation
    this->sceneList.at(index) = 0;
    // delete?
    // remove not just pointer but its pointee
}

void GameLogic::initialize() {
    Stats cheggStats;
    cheggStats.setIntelligence(10);
    Item cheggSubscription = Item("Chegg Subscription", "0", cheggStats);
    addItem(cheggSubscription);
    addItemStats(&cheggStats);

    Stats walletStats;
    Enemy* wallet = new Enemy();
    wallet->setStats(walletStats, "easy");
    addEnemy(wallet);
    addEnemyStats(walletStats);


    vector<string> introButtons{ "Play", "Quit" };
    addScene("intro", introButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/UCR_Logo.jpg", "easy", "Welcome to The Average Life of a UCR student.  Press Play to continue or Quit to quit.", "t2", "t3");

    vector<string> testButtons{ "hi" };
    addScene("test", testButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/IMG_6807.jpg", "hard", "t1", "t2", "t3");

    vector<string> majorButtons{ "Engineering", "Business", "Health", "Humanities" };
    addScene("majorSelect", majorButtons, "NULL", "easy", "", "", "");

    vector<string> statButtons{ "Continue" };
    addScene("checkStats", statButtons, "NULL", "easy", "", "", "");

    vector<string> travelButtons;
    addScene("Traveling", travelButtons, "NULL", "easy", "", "", "");

    vector<string> hubButtons{ "Go to the SRC (gym)", "Go to a party", "Study at the Library", "Eat at Glasgow", "Go to the hospital" };
    addScene("Hub", hubButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/UCR_Hub.jpg", "easy", "", "", "");

    vector<string> srcButtons{ "Continue" };
    addScene("SRC", srcButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/UCR_SRC.jpg", "easy", "", "", "");

    vector<string> partyButtons{ "Continue" };
    addScene("Party", partyButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/UCR_Party.jpg", "easy", "", "", "");

    vector<string> libraryButtons{ "Continue" };
    addScene("Library", libraryButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/UCR_Library.jpg", "easy", "", "", "");

    vector<string> glasgowButtons{ "Continue" };
    addScene("Glasgow", glasgowButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/UCR_Glasgow.jpg", "easy", "", "", "");

    vector<string> whereButtons{ "Student Success Center", "Physics Building", "Winston Chung Hall"};
    addScene("Where", whereButtons, "NULL", "easy", "", "", "");

    vector<string> physicsButtons{ "Fight", "Run", "Talk", "Examine", "Check Your Stats"};
    addScene("Physics", physicsButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/IMG_6807.jpg", "easy", "", "", "");

    vector<string> physicsFightButtons{ "" };
    addScene("PhysicsFight", physicsFightButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/IMG_6807.jpg", "easy", "", "", "");

    vector<string> physicsItemButtons{ "" };
    addScene("PhysicsItem", physicsItemButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/Chegg-Logo.png", "easy", "", "", "");

    vector<string> physicsRunButtons{ "" };
    addScene("PhysicsRun", physicsRunButtons, "C:/Users/zan/Desktop/School/CS100/final-project-f1-d1-rank1-team/images/Chegg-Logo.png", "easy", "", "", "");

    cout << "vecSize " << sceneList.size() << endl;

}

void GameLogic::clearScenes() {
    for (int i = 0; i < this->sceneList.size(); i++) {
        this->removeScene(i);
    }
}

scene* GameLogic::getScene(int index) {
    return this->sceneList.at(index);
}

scene* GameLogic::getCurrScene()
{
    return this->currScene;
}

void GameLogic::setCurrScene(int tarScene)
{
    this->currScene = sceneList.at(tarScene);
}

int GameLogic::getNextScene()
{
    return nextScene;
}

void GameLogic::setNextScene(int tarScene)
{
    this->nextScene = tarScene;
}

string GameLogic::getCurrSceneDiff()
{
    return currScene->difficulty;
}

void GameLogic::addEnemy(Enemy* enemy)
{
    enemyList.push_back(enemy);
}

Enemy* GameLogic::getEnemy(int tarEnemy)
{
    return enemyList.at(tarEnemy);
}

void GameLogic::addEnemyStats(Stats enemyStat)
{
    this->enemyStats.push_back(&enemyStat);
}

Stats GameLogic::getEnemyStats(int tarStats)
{
    return *enemyStats.at(tarStats);
}

void GameLogic::addItem(Item tarItem)
{
    playerInventory.addItem(tarItem);
}

Item GameLogic::getItem(int tarItem)
{
    return playerInventory.items.at(tarItem);
}

void GameLogic::addItemStats(Stats* itemStat)
{
    itemStats.push_back(itemStat);
}

Stats GameLogic::getItemStats(int tarStats)
{
    return *itemStats.at(tarStats);
}

#endif