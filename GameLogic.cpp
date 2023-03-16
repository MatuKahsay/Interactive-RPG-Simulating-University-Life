#include "GameLogic.h"
#include "GameLogic.h"
#ifndef GAMELOGIC_CPP
#define GAMELOGIC_CPP

#include <vector>
#include "GameLogic.h"
#include "Scene.h"
#include "Player.h"

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
    vector<string> introButtons{ "Play", "Quit" };
    addScene("intro", introButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/final-project-f1-d1-rank-1-team/images/UCR_Logo.jpg", "easy", "Welcome to The Average Life of a UCR student.  Press Play to continue or Quit to quit.", "t2", "t3");

    vector<string> testButtons{ "hi" };
    addScene("test", testButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/final-project-f1-d1-rank-1-team/images/IMG_6807.jpg", "hard", "t1", "t2", "t3");

    vector<string> majorButtons{ "Engineering", "Business", "Health", "Humanities" };
    addScene("majorSelect", majorButtons, "NULL", "easy", "", "", "");

    vector<string> statButtons{ "Continue" };
    addScene("checkStats", statButtons, "NULL", "easy", "", "", "");

    vector<string> travelButtons;
    addScene("Traveling", travelButtons, "NULL", "easy", "", "", "");

    vector<string> hubButtons{ "Go to the SRC (gym)", "Go to a party", "Study at the Library", "Eat at Glasgow", "Go to the hospital" };
    addScene("Hub", hubButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/final-project-f1-d1-rank-1-team/images/UCR_Hub.jpg", "easy", "", "", "");

    vector<string> srcButtons{ "Continue" };
    addScene("SRC", srcButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/final-project-f1-d1-rank-1-team/images/UCR_SRC.jpg", "easy", "", "", "");

    vector<string> partyButtons{ "Continue" };
    addScene("Party", partyButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/final-project-f1-d1-rank-1-team/images/UCR_Party.jpg", "easy", "", "", "");

    vector<string> libraryButtons{ "Continue" };
    addScene("Library", libraryButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/final-project-f1-d1-rank-1-team/images/UCR_Library.jpg", "easy", "", "", "");

    vector<string> glasgowButtons{ "Continue" };
    addScene("Glasgow", glasgowButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/final-project-f1-d1-rank-1-team/images/UCR_Glasgow.jpg", "easy", "", "", "");
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

#endif