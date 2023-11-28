#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "scene.h"
#include "GameLogic.h"
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"
#include "glad/glad.h"

class display {
public:
	display();
	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	void LoadImage(GLuint& my_image_texture, int& my_image_width, int& my_image_height, scene*& currScene, string& currPicture, GameLogic* game);
	void Init(GLFWwindow* window, const char* glsl_version);
	void Render();
	void Shutdown();
	void NewFrame();
	void Update(GLuint &in_my_image_texture, int &my_image_width, int &my_image_height, scene* &currScene, string &currPicture, GameLogic* game, Player* &player, Stats &playerStats);
	void UpdateTest(GLuint my_image_texture, int my_image_width, int my_image_height);
	void UpdateIntro(GLuint my_image_texture, int my_image_width, int my_image_height, scene* &currScene, GameLogic* game);
	void UpdateSelectMajor(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player* &player, Stats &playerStats);
	void UpdateCheckStats(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats);
	void displayText(string text);
	void UpdateTravel(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats);
	void UpdateHub(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats);
	void UpdateSRC(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats);
	void UpdateParty(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats);
	void UpdateLibrary(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats);
	void UpdateGlasgow(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats);
	void UpdateWhere(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats);
	void UpdatePhysics(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats);
	void UpdatePhysicsFight(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats, Enemy* &enemyWallet, Stats &walletStats);
	void UpdatePhysicsItem(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats);
	void UpdatePhysicsRun(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats, Enemy* &enemyWallet, Stats& walletStats);
	


};