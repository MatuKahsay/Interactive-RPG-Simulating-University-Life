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

void display::UpdateSelectMajor(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player* &player, Stats &playerStats)
{
	displayText("Please select your major by clicking one of the blue buttons below: ");
	if (ImGui::Button("Engineering")) {
		player->setMajor("Engineering");
		player->setStats(playerStats);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 50 \n Strength: 40 \n Stamina: 30 \n Charisma: 20");
	if (ImGui::Button("Business")) {
		player->setMajor("Business");
		player->setStats(playerStats);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 30 \n Strength: 40 \n Stamina: 20 \n Charisma: 50");
	if (ImGui::Button("Health")) {
		player->setMajor("Health");
		player->setStats(playerStats);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 40 \n Strength: 50 \n Stamina: 30 \n Charisma: 20");
	if (ImGui::Button("Humanities")) {
		player->setMajor("Humanities");
		player->setStats(playerStats);
		game->setCurrScene(3);
	}
	displayText("Intelligence: 20 \n Strength: 30 \n Stamina: 50 \n Charisma: 40");
	ImGui::Text("*stats of majors having any resemblance to real life stereotypes is entirely coincidental and should be disregarded*");
	game->setNextScene(5);
}

void display::UpdateCheckStats(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats)
{
	displayText("Your current stats are:");
	displayText("Major: ");
	ImGui::SameLine();
	string tMajor = player->getMajor();
	const char* cMajor = tMajor.c_str();
	displayText(cMajor);

	displayText("Health: ");
	ImGui::SameLine();
	string tHealth = to_string(playerStats.getHealth());
	displayText(tHealth);

	displayText("Intelligence: ");
	ImGui::SameLine();
	string tIntelligence = to_string(playerStats.getIntelligence());
	displayText(tIntelligence);

	displayText("Strength: ");
	ImGui::SameLine();
	string tStrength = to_string(playerStats.getStrength());
	displayText(tStrength);

	displayText("Stamina: ");
	ImGui::SameLine();
	string tStamina = to_string(playerStats.getStamina());
	displayText(tStamina);

	displayText("Charisma: ");
	ImGui::SameLine();
	string tCharisma = to_string(playerStats.getCharisma());
	displayText(tCharisma);
	if (ImGui::Button("Continue")) {
		game->setCurrScene(game->getNextScene());
	}

}

void display::displayText(string text)
{
	const char* cText = text.c_str();
	ImGui::Text(cText);
}

void display::UpdateTravel(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats)
{
	displayText("Travelling to next destination...");
	cout << game->getNextScene();
	if (ImGui::Button("Continue")) {
		game->setCurrScene(game->getNextScene());
	}
}

void display::UpdateHub(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	displayText("Welcome to the HUB (Highlander Union Building).  Here you can choose how to spend your free time which will change your stats.");

	string tButton = currScene->sceneButtons.at(0);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(6);
	}
	tButton = currScene->sceneButtons.at(1);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(7);
	}
	tButton = currScene->sceneButtons.at(2);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(8);
	}
	tButton = currScene->sceneButtons.at(3);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(9);
	}
	if (ImGui::Button("Check Stats")) {
		game->setNextScene(5);
		game->setCurrScene(3);
	}
}

void display::UpdateSRC(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	displayText("After hitting the gym you have gained 10 Strength but lost 5 intellegence, stamina, and charisma");

	if (ImGui::Button("Continue")) {
		game->setCurrScene(10);
	}
}

void display::UpdateParty(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	displayText("After going to a party, you have gained 10 Charisma but lost 5 intelligence, strength, and stamina");
	if (ImGui::Button("Continue")) {
		game->setCurrScene(10);
	}
}

void display::UpdateLibrary(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	displayText("After studying at the library with some Lofi 24 hour chill beats to study to (not sponsored), you have gained 10 Intelligence but lost 5 charisma, strength, and stamina");
	if (ImGui::Button("Continue")) {
		game->setCurrScene(10);
	}
}

void display::UpdateGlasgow(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats &playerStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	displayText("After grabbing a bite to eat, you have gained 10 Stamina but lost 5 charisma, strength, and intelligence");
	if (ImGui::Button("Continue")) {
		game->setCurrScene(10);
	}
}

void display::UpdateWhere(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats)
{
	displayText("Where would you like to explore next?");
	string tButton = currScene->sceneButtons.at(0);
	if (ImGui::Button(tButton.c_str())) {
		game->setNextScene(10);
		game->setCurrScene(4);
	}
	tButton = currScene->sceneButtons.at(1);
	if (ImGui::Button(tButton.c_str())) {
		game->setNextScene(11);
		game->setCurrScene(4);
	}
	tButton = currScene->sceneButtons.at(2);
	if (ImGui::Button(tButton.c_str())) {
		game->setNextScene(10);
		game->setCurrScene(4);
	}

}

void display::UpdatePhysics(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats)
{
	displayText("difficulty: easy");
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	displayText("You've encountered your poor financial skills!  What would you like to do?");
	string tButton = currScene->sceneButtons.at(0);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(12);
	}
	tButton = currScene->sceneButtons.at(1);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(14);
	}
	tButton = currScene->sceneButtons.at(2);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(11);
	}
	tButton = currScene->sceneButtons.at(3);
	if (ImGui::Button(tButton.c_str())) {
		game->setCurrScene(11);
	}
	tButton = currScene->sceneButtons.at(4);
	if (ImGui::Button(tButton.c_str())) {
		game->setNextScene(11);
		game->setCurrScene(3);
	}
}

void display::UpdatePhysicsFight(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats, Enemy* &enemyWallet, Stats& walletStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	Combat walletFight;
	if (playerStats.getHealth() > 0 && walletStats.getHealth() > 0) {
		walletFight.Fight(*player, playerStats, *enemyWallet, walletStats);
	}
	else if (playerStats.getHealth() <= 0) {
		displayText("You've lost the fight! Your health is 0 and your poor financial decision's health is ");
		ImGui::SameLine();
		displayText(to_string(walletStats.getHealth()));
		ImGui::Button("Continue");
	}
	else if (walletStats.getHealth() <= 0) {
		displayText("You've won the fight!  Your health is ");
		ImGui::SameLine();
		displayText(to_string(playerStats.getHealth()));
		ImGui::SameLine();
		displayText(" and your poor financial decision's health is 0");
		if (ImGui::Button("Continue")) {
			game->setCurrScene(13);
		}
	}
}

void display::UpdatePhysicsItem(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	displayText("You've found a Chegg Subscription!  Equip it to boost your intelligence by 10 points!");
	if (ImGui::Button("Equip!")) {
		Item eItem = game->getItem(0);
		Stats eItemStats = game->getItemStats(0);
		player->equipItem(playerStats, eItem);
		game->setNextScene(5);
		game->setCurrScene(4);
	}
}

void display::UpdatePhysicsRun(GLuint my_image_texture, int my_image_width, int my_image_height, scene*& currScene, GameLogic* game, Player*& player, Stats& playerStats, Enemy* &enemyWallet, Stats &walletStats)
{
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	Combat walletRun;
	if (walletRun.Run(playerStats)) {
		displayText("You try and run away...Luckily, you are too fast and get away!");
		if (ImGui::Button("Continue")) {
			game->setNextScene(5);
			game->setCurrScene(4);
		}
	}
	else {
		displayText("You try and run away...You are not fast enough and get caught.  You still have to face your poor financial decisions");
		if (ImGui::Button("Continue")) {
			game->setCurrScene(11);
		}
	}
}


//Update function finds which scene we are trying to display and calls the appropriate UpdateXXX function


void display::Update(GLuint &my_image_texture, int &my_image_width, int &my_image_height, scene* &currScene, string &currPicture, GameLogic* game, Player* &player, Stats &playerStats)	{
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
		UpdateSelectMajor(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "checkStats") {															//majorSelect
		UpdateCheckStats(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "Traveling") {															//Traveling
		UpdateTravel(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "Hub") {																//Hub
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
		}
		UpdateHub(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "SRC") {																//SRC
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
			playerStats.setStrength(playerStats.getStrength() + 10);
			playerStats.setIntelligence(playerStats.getIntelligence() - 5);
			playerStats.setStamina(playerStats.getStamina() - 5);
			playerStats.setCharisma(playerStats.getCharisma() - 5);
		}
		UpdateSRC(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "Party") {																//Party
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
			playerStats.setCharisma(playerStats.getCharisma() + 10);
			playerStats.setIntelligence(playerStats.getIntelligence() - 5);
			playerStats.setStamina(playerStats.getStamina() - 5);
			playerStats.setStrength(playerStats.getStrength() - 5);
		}
		UpdateParty(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "Library") {															//Library
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
			playerStats.setIntelligence(playerStats.getIntelligence() + 10);
			playerStats.setStrength(playerStats.getStrength() - 5);
			playerStats.setStamina(playerStats.getStamina() - 5);
			playerStats.setCharisma(playerStats.getCharisma() - 5);
		}
		UpdateLibrary(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "Glasgow") {															//Glasgow
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
			playerStats.setStamina(playerStats.getStamina() + 10);
			playerStats.setIntelligence(playerStats.getIntelligence() - 5);
			playerStats.setStrength(playerStats.getStrength() - 5);
			playerStats.setCharisma(playerStats.getCharisma() - 5);
		}
		UpdateGlasgow(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "Where") {																//Where
		UpdateWhere(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "Physics") {
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
		}
		UpdatePhysics(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "PhysicsFight") {
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
		}
		Enemy* wallet = game->getEnemy(0);
		Stats walletStats = game->getEnemyStats(0);
		UpdatePhysicsFight(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats, wallet, walletStats);
	}

	if (currScene->sceneType == "PhysicsItem") {
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
		}
		UpdatePhysicsItem(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats);
	}

	if (currScene->sceneType == "PhysicsRun") {
		if (currPicture != currScene->picture) {
			LoadImage(my_image_texture, my_image_width, my_image_height, currScene, currPicture, game);
		}
		Enemy* wallet = game->getEnemy(0);
		Stats walletStats = game->getEnemyStats(0);
		UpdatePhysicsRun(my_image_texture, my_image_width, my_image_height, currScene, game, player, playerStats, wallet, walletStats);
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
