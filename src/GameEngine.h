#pragma once

#include <map>

// #include "Assets.h"
// #include "scenes/Scenes.h"
// #include "Physics.h"
// #include "GameState.h"

#include "renderers/BaseRenderer.h"
#include "renderers/RaylibRenderer.h"

// using SceneMap = std::map<SceneType, Scene*>;

class GameEngine {
private:
    GameEngine();

    BaseRenderer* _renderer;
    
    // SceneMap         _scenes;
    // SceneType        _current_scene;
    // Assets           _assets;
    // GameState        _game_state;

    // bool             _should_quit = false;
public:
    static GameEngine& instance() {
        static GameEngine instance;
        return instance;
    }
    ~GameEngine();

    void init(int rendererChoice = 1);
    void run();
    // void inputs();
    // void restart();

    // Scene& getCurrentScene() { return *_scenes.at(_current_scene); }
    // Assets& getAssets() { return _assets; }
    
    // template<typename T> 
    // void changeScene(const SceneType& sceneType) {
    //     _scenes[sceneType] = new T(*this);
    //     _current_scene = sceneType;
    //     _scenes[sceneType]->init();
    // }

    // void quit() { _should_quit = true; }
    // bool shouldQuit() const { return _should_quit; }

    // GameState& getGameState() { return _game_state; }
};