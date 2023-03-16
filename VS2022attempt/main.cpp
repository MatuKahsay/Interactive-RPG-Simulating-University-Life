// VS2022attempt.cpp : Defines the entry point for the application.
//
#include <vector>
#include <string>
#include "scene.h"
#include "display.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
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
	// scene testing
	vector<string> testButtons{ "one", "two", "three" };
	scene* currScene = nullptr;
	scene* scene1 = new scene("test", testButtons, "C: / Users / Alex / Desktop / Alex / School / CS100 / Average life of a UCR student / VS2022attempt - Copy / VS2022attempt / images / IMG_6807.jpg", "hard", "t1", "t2", "t3");
	vector<string> introButtons{ "Play", "Quit" };
	scene* intro = new scene("intro", introButtons, "C:/Users/Alex/Desktop/Alex/School/CS100/Average life of a UCR student/VS2022attempt - Copy/VS2022attempt/images/UCR_Logo.jpg", "easy", "t1", "t2", "t3");
	currScene = intro;
	string currPicture = "NULL";
	GLuint my_image_texture = 0;
	int my_image_width = 0;
	int my_image_height = 0;
	//
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		myimgui.Update(my_image_texture, my_image_width, my_image_height, currScene, currPicture);
		myimgui.Render();
		glfwSwapBuffers(window);
	}
	myimgui.Shutdown();
	return 0;
}
