#include "GameEngine.h"

GameEngine::GameEngine() {
    _renderer = nullptr; // Will be initialized in init()
}

GameEngine::~GameEngine() {
	// for (auto& scene : _scenes) {
	// 	delete scene.second;
	// }
    delete _renderer;
}

void GameEngine::init(int rendererChoice) {
    // Delete existing renderer if any
    if (_renderer) {
        delete _renderer;
    }
    
    // Create the appropriate renderer based on choice
    switch (rendererChoice) {
        case 0:
            _renderer = new BaseRenderer(); // No renderer (does nothing)
            break;
        case 1:
            _renderer = new RaylibRenderer(); // Raylib renderer
            break;
        default:
            _renderer = new BaseRenderer(); // Default to no renderer
            break;
    }
    
    _renderer->init();

    changeScene<SceneMenu>(SceneType::MENU);
}

void GameEngine::run() {
	while (true) {
		bool should_continue = _renderer->render();   
		if (!should_continue || _should_quit) {
			break;
		}
	}             
}

void GameEngine::update(const float& elapsed) {
    getCurrentScene().update();
}   

// void GameEngine::inputs() {
// 	for (auto& [key, action]: getCurrentScene().getActionMap())
// 	{
// 		if (IsMouseButtonPressed(key) || IsMouseButtonReleased(key)) {
// 			ActionType type = IsMouseButtonPressed(key) ? ActionType::START : ActionType::END;
// 			Action action(getCurrentScene().getActionMap().at(key), type);
// 			getCurrentScene().doAction(action);
// 		} else if (IsKeyPressed(key) || IsKeyReleased(key)) {
// 			ActionType type = IsKeyPressed(key) ? ActionType::START : ActionType::END;
// 			Action action(getCurrentScene().getActionMap().at(key), type);
// 			getCurrentScene().doAction(action);
// 		}
// 	}
// }

// void GameEngine::restart() {
// 	_game_state = GameState();
// }