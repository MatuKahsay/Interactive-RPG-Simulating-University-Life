#ifndef GAMELOGIC_CPP
#define GAMELOGIC_CPP

#include <vector>
#include "GameLogic.h"
#include "Scene.h"
#include "Player.h"

GameLogic::GameLogic() {}

GameLogic::GameLogic(vector<Scene*> newList, Player newPlayer) {
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

void GameLogic::addScene(Scene* newScene) {
    this->sceneList.push_back(newScene);
}

void GameLogic::removeScene(int index) {
    this->sceneList.at(index)->deleteScene(); // Scene takes care of deallocation
    this->sceneList.at(index) = 0;
    // delete?
    // remove not just pointer but its pointee
}

void GameLogic::playScenes() {
    for (int i = 0; i < this->sceneList.size(); i++) {
        this->sceneList.at(i)->startScene();
    }
}

void GameLogic::initialize() {
    Scene* startScreen_p = new Scene(/*Start Menu Parameters*/);

    this->sceneList.at(0) = startScreen_p;
    this->sceneList.at(0)->startScene();
}

void GameLogic::clearScenes() {
    for (int i = 0; i < this->sceneList.size(); i++) {
        this->removeScene(i);
    }
}

Scene* GameLogic::getScene(int index) {
    return this->sceneList.at(index);
}

#endif