#include "SceneDecks.h"
#include "../GameEngine.h"

SceneDecks::SceneDecks(GameEngine& game_engine)
	: Scene(game_engine) {}

SceneDecks::~SceneDecks() {}

void SceneDecks::init()
{
}

void SceneDecks::update()
{
}

void SceneDecks::render()
{
	// Calculate centered group box position and size
	const int boxWidth = 200;
	const int boxHeight = 200;
	const int screenWidth = GetScreenWidth();
	const int screenHeight = GetScreenHeight();
	Rectangle bounds = {
		(float)(screenWidth - boxWidth)/2,
		(float)(screenHeight - boxHeight)/2,
		(float)boxWidth,
		(float)boxHeight
	};

	// Draw title "RIFTSIM"
	GuiSetStyle(DEFAULT, TEXT_SIZE, 40);  // Temporarily increase text size for title
	const char* title = "RIFTSIM";
	int titleWidth = MeasureText(title, 40);
	GuiLabel(Rectangle{bounds.x + (bounds.width - titleWidth)/2, bounds.y - 60, (float)titleWidth, 40}, title);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);  // Reset text size to default for buttons

	// Calculate button dimensions
	const int buttonWidth = 120;
	const int buttonHeight = 40;
	const int buttonSpacing = 10;
	float buttonX = bounds.x + (bounds.width - buttonWidth)/2;
	float buttonY = bounds.y + 40; // Leave space after group box title

	// Draw buttons centered in the group box
	if (GuiButton(Rectangle{buttonX, buttonY, buttonWidth, buttonHeight}, "MENU")) {
		_game_engine.changeScene<SceneMenu>(SceneType::MENU);
	}
	
	if (GuiButton(Rectangle{buttonX, buttonY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight}, "PLAY")) {
		_game_engine.changeScene<ScenePlay>(SceneType::PLAY);
	}
}

// void SceneMenu::doAction(const Action& action)
// {
// }