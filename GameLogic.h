#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <vector>
#include "scene.h"
#include "Player.h"

using namespace std;

class GameLogic  {
    private:
        vector<scene*> sceneList;
        Player Protagonist;
        scene* currScene;
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
};

#endif