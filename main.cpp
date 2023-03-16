
// VS2022attempt.cpp : Defines the entry point for the application.
//
#include <vector>
#include <string>
#include "scene.h"
#include "display.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "inventory.h"
#include "Character.h"
#include "Enemy.h"
#include "GameLogic.h"
#include "item.h"
#include "Player.h"
#include "stats.h"
#include <iostream>


using namespace std;


int main()
{
	// Setup window
	if (!glfwInit())
		return 1;

	// Decide GL+GLSL versions
#if __APPLE__
	// GL 3.2 + GLSL 150
	const char* glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // Required on Mac
#else
	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1920, 1080, "Dear ImGui - Example", NULL, NULL);
	if (window == NULL)
		return 1;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw("unable to context to OpenGL");

	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);
	display myimgui;
	myimgui.Init(window, glsl_version);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}
//-------------------------------------------------------------------------------------------------------------------------------------- stuff we need to care about is below
	  Inventory inventory1(10); 
   //inventory1.displayInventory();
   Item item("Sword", "weapon",Stats(10, 0, 0,0,0));
   inventory1.addItem(Item("Sword", "weapon",Stats(10, 0, 0,0,0)));
  // inventory1.addItem(Item("Bow", "weapon"));
  // inventory1.addItem(Item("Shield", "weapon"));
   inventory1.displayInventory();

   Enemy enemy1(Stats(5, 5, 5, 5, 5), 30);
   enemy1.getStats().setCharisma(10);
   enemy1.printStats();
   cout << "Testing add item " << endl;
   enemy1.equipItem(item); 
   enemy1.printStats();
   cout << "Testing removing item " << endl;
   enemy1.unequipItem(item);
   enemy1.printStats();
   item.getStats().setHealth(15);
   enemy1.equipItem(item);
   cout << "Testing updated item" << endl;
   enemy1.printStats();
  
  GameLogic* game = new GameLogic;
	game->initialize();
	game->setCurrScene(0);
	string currPicture = "NULL";
	GLuint my_image_texture = 0;
	int my_image_width = 0;
	int my_image_height = 0;
	Player* player = new Player;
	//
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		scene* currScene = game->getCurrScene();
		cout << currScene->sceneType << endl;
		myimgui.Update(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game, player);
		myimgui.Render();
		glfwSwapBuffers(window);
	}
	myimgui.Shutdown();
	return 0;
}
