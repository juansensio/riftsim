#pragma once

#include "Scene.h"

class SceneDecks : public Scene
{
public:
	SceneDecks(GameEngine& game_engine);
	~SceneDecks();

	void init() override;
	void update() override;
	void render() override;
	// void doAction(const Action& action) override;
};