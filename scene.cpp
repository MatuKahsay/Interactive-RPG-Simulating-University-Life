#include "scene.h"
#include "scene.h"



scene::scene(string type, vector<string> but, string pic, string dif, string t1, string t2, string t3)
{
	sceneType = type;
	for (int i = 0; i < but.size(); ++i) {
		sceneButtons.push_back(but.at(i));
	}
	picture = pic;
	difficulty = dif;
	text1 = t1;
	text2 = t2;
	text3 = t3;
}

void scene::deleteScene()
{
}
