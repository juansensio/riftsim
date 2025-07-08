#pragma once

#include "Scene.h"

class SceneMenu : public Scene
{
public:
	SceneMenu(GameEngine& game_engine);
	~SceneMenu();

	void init() override;
	void update() override;
	void render() override;
	// void doAction(const Action& action) override;
};