#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <vector>
#include "Scene.h"
#include "Player.h"

using namespace std;
using namespace scene;
using namespace player;

class GameLogic  {
    private:
        vector<Scene*> sceneList;
        Player Protagonist;
    public:
        GameLogic();
        GameLogic(vector<Scene*> newList, Player newPlayer);
        ~GameLogic();
        void addScene(Scene* newScene);
        void removeScene(int);
        void playScenes();
        void initialize();
        void clearScenes();
        Scene* getScene(int);
};

#endif