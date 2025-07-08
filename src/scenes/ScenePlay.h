#pragma once

#include "Scene.h"

class ScenePlay : public Scene
{
public:
	ScenePlay(GameEngine& game_engine);
	~ScenePlay();

	void init() override;
	void update() override;
	void render() override;
	// void doAction(const Action& action) override;
};