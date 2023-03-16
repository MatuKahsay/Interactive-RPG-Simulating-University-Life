#include "display.h"
#include <iostream>

display::display()
{
}

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Simple helper function to load an image into a OpenGL texture with common settings
bool display::LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
	// Load from file
	int image_width = 0;
	int image_height = 0;
	unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
	if (image_data == NULL)
		return false;

	// Create a OpenGL texture identifier
	GLuint image_texture;
	glGenTextures(1, &image_texture);
	glBindTexture(GL_TEXTURE_2D, image_texture);

	// Setup filtering parameters for display
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

	// Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
	stbi_image_free(image_data);

	*out_texture = image_texture;
	*out_width = 1280;
	*out_height = 720;

	return true;
}

void display::LoadImage(GLuint& my_image_texture, int& my_image_width, int& my_image_height, scene*& currScene, string& currPicture, GameLogic* game)
{
	glEnable(GL_TEXTURE_2D);
	my_image_width = 0;
	my_image_height = 0;
	my_image_texture = 0;
	const char* cPicture = currScene->picture.c_str();
	bool ret = LoadTextureFromFile(cPicture, &my_image_texture, &my_image_width, &my_image_height);
	cout << my_image_texture << endl;
	my_image_width = 1280;
	my_image_height = 720;
	glDisable(GL_TEXTURE_2D);
	IM_ASSERT(ret);
	currPicture = currScene->picture;
}

void display::Init(GLFWwindow* window, const char* glsl_version) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();
}

void display::NewFrame() {
	//feed inputs to dear imgui, start new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void display::UpdateTest(GLuint my_image_texture, int my_image_width, int my_image_height)
{
	ImGui::Button("AAAAAAAAA");
	ImGui::Text("pointer = %p", my_image_texture);
	ImGui::Text("size = %d x %d", my_image_width, my_image_height);
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
}

void display::UpdateIntro(GLuint my_image_texture, int my_image_width, int my_image_height, scene* &currScene, GameLogic* game)
{
	ImGui::Text("pointer = %p", my_image_texture);
	ImGui::Text("size = %d x %d", my_image_width, my_image_height);
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	ImGui::Text(currScene->text1.c_str());
	string Button1 = currScene->sceneButtons.at(0);
	const char* cButton1 = Button1.c_str();
	string Button2 = currScene->sceneButtons.at(1);
	const char* cButton2 = Button2.c_str();
	if (ImGui::Button(cButton1)) {
		game->setCurrScene(2);
	}
	if (ImGui::Button(cButton2)) {
		Shutdown();
	}
}

void display::UpdateSelectMajor(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player* &player)
{
	displayText("Please select your major by clicking one of the blue buttons below: ");
	if (ImGui::Button("Engineering")) {
		player->setMajor("Engineering");
		player->setStats(player);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 50 \n Strength: 40 \n Stamina: 30 \n Charisma: 20");
	if (ImGui::Button("Business")) {
		player->setMajor("Business");
		player->setStats(player);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 30 \n Strength: 40 \n Stamina: 20 \n Charisma: 50");
	if (ImGui::Button("Health")) {
		player->setMajor("Health");
		player->setStats(player);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 40 \n Strength: 50 \n Stamina: 30 \n Charisma: 20");
	if (ImGui::Button("Humanities")) {
		player->setMajor("Humanities");
		player->setStats(player);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 20 \n Strength: 30 \n Stamina: 50 \n Charisma: 40");
	ImGui::Text("*stats of majors having any resemblance to real life stereotypes is entirely coincidental and should be disregarded*");
}

void display::UpdateCheckStats(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player)
{
	displayText("Your current stats are:");
	displayText("Major: ");
	ImGui::SameLine();
	string tMajor = player->getMajor();
	const char* cMajor = tMajor.c_str();
	displayText(cMajor);

	displayText("Health: ");
	ImGui::SameLine();
	string tHealth = to_string(player->getHealth());
	displayText(tHealth);

	displayText("Intelligence: ");
	ImGui::SameLine();
	string tIntelligence = to_string(player->getIntelligence());
	displayText(tIntelligence);

	displayText("Strength: ");
	ImGui::SameLine();
	string tStrength = to_string(player->getStrength());
	displayText(tStrength);

	displayText("Stamina: ");
	ImGui::SameLine();
	string tStamina = to_string(player->getStamina());
	displayText(tStamina);

	displayText("Charisma: ");
	ImGui::SameLine();
	string tCharisma = to_string(player->getCharisma());
	displayText(tCharisma);

	ImGui::Button("Continue");
}

void display::displayText(string text)
{
	const char* cText = text.c_str();
	ImGui::Text(cText);
}

void display::Update(GLuint &my_image_texture, int &my_image_width, int &my_image_height, scene* &currScene, string &currPicture, GameLogic* game, Player* &player)	{
	//render your GUI
	this->NewFrame();
	ImGui::Begin("Average Life of a UCR student");
	if (currScene->sceneType == "intro") {																//intro
		if (currPicture != currScene->picture) {
			LoadImage( my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
		}
		UpdateIntro(my_image_texture, my_image_width, my_image_height, currScene, game);
	}

	if (currScene->sceneType == "test") {																//test
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
		}
		UpdateTest(my_image_texture, my_image_width, my_image_height);
	}

	if (currScene->sceneType == "majorSelect") {														//majorSelect
		UpdateSelectMajor(my_image_texture, my_image_width, my_image_height, currScene, game, player);
	}

	if (currScene->sceneType == "checkStats") {														//majorSelect
		UpdateCheckStats(my_image_texture, my_image_width, my_image_height, currScene, game, player);
	}
	ImGui::End();
}

void display::Render()	{
	//Render dear imgui into screen
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void display::Shutdown() {
	//Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
