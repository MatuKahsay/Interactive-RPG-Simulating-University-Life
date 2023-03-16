#pragma once

#include <string>
#include <vector>

using namespace std;

class scene {
private:
	int sceneID;
public:
	string sceneType;
	vector<string> sceneButtons;
	string picture;
	string difficulty;
	string text1;
	string text2;
	string text3;
	scene(string type,vector<string> but, string pic, string dif,
		string t1, string t2, string t3);
	void deleteScene();
};