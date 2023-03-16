#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "scene.h"
#include "GameLogic.h"
#include "Player.h"

class display {
public:
	display();
	bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	void LoadImage(GLuint& my_image_texture, int& my_image_width, int& my_image_height, scene*& currScene, string& currPicture, GameLogic* game);
	void Init(GLFWwindow* window, const char* glsl_version);
	void Render();
	void Shutdown();
	void NewFrame();
	void Update(GLuint &in_my_image_texture, int &my_image_width, int &my_image_height, scene* &currScene, string &currPicture, GameLogic* game, Player* &player);
	void UpdateTest(GLuint my_image_texture, int my_image_width, int my_image_height);
	void UpdateIntro(GLuint my_image_texture, int my_image_width, int my_image_height, scene* &currScene, GameLogic* game);
	void UpdateSelectMajor(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player* &player);
	void UpdateCheckStats(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player);
	void displayText(string text);
	void UpdateTravel(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player);
	void UpdateHub(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player);
	void UpdateSRC(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player);
	void UpdateParty(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player);
	void UpdateLibrary(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player);
	void UpdateGlasgow(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player);
};