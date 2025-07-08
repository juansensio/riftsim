#pragma once

#include "Scene.h"
#include "objects/Objects.h"

class SceneDecks : public Scene
{
	Card 	_card;
public:
	SceneDecks(GameEngine& game_engine);
	~SceneDecks();

	void init() override;
	void update() override;
	void render() override;
	// void doAction(const Action& action) override;
};