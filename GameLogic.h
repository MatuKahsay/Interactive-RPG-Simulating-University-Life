#pragma once
#include <vector>
#include "scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Inventory.h"

using namespace std;

class GameLogic  {
    private:
        vector<scene*> sceneList;
        Player Protagonist;
        scene* currScene;
        int nextScene;
        vector<Enemy*> enemyList;
        vector<Stats*> enemyStats;
        vector<Stats*> itemStats;
        Inventory playerInventory = Inventory(20, 0);
    public:
        GameLogic();
        GameLogic(vector<scene*> newList, Player newPlayer);
        ~GameLogic();
        void addScene(string sceneType, vector<string> Buttons, string pictureDir, string difficulty, string text1, string text2, string text3);
        void removeScene(int);
        void initialize();
        void clearScenes();
        scene* getScene(int);
        scene* getCurrScene();
        void setCurrScene(int tarScene);
        int getNextScene();
        void setNextScene(int tarScene);
        string getCurrSceneDiff();
        void addEnemy(Enemy* enemy);
        Enemy* getEnemy(int tarEnemy);
        void addEnemyStats(Stats enemyStats);
        Stats getEnemyStats(int tarStats);
        void addItem(Item tarItem);
        Item getItem(int tarItem);
        void addItemStats(Stats* itemStats);
        Stats getItemStats(int tarStats);
};
