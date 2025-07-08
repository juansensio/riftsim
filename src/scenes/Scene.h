#pragma once

#include <memory>
#include <vector>

#include "entities/EntityManager.h"
// #include "Actions.h"

class GameEngine;

// using ActionMap = std::map<int, ActionName>;

class Scene {
protected:
	GameEngine& 				_game_engine;
	EntityManager 				_entity_manager;
	// ActionMap					_action_map;

public:
    // Scene(GameEngine& game_engine) : _game_engine(game_engine), _entity_manager() {}
    Scene(GameEngine& game_engine) : _game_engine(game_engine) {}
    virtual ~Scene() {}

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	// virtual void doAction(const Action& action) = 0;

	// void registerAction(int key, const ActionName& name) {_action_map[key] = name;}
	// const ActionMap& getActionMap() const { return _action_map; }

	EntityManager& getEntityManager() { return _entity_manager; }
};