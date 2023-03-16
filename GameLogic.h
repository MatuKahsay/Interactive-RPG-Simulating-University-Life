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
<<<<<<< HEAD
        int nextScene;
=======
>>>>>>> ff579e204c9827229f73e99663775518550bd4d5
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
<<<<<<< HEAD
        int getNextScene();
        void setNextScene(int tarScene);
=======
>>>>>>> ff579e204c9827229f73e99663775518550bd4d5
};

#endif