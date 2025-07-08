#include "RaylibRenderer.h"
#include "../GameEngine.h"

RaylibRenderer::RaylibRenderer() {
    // Constructor implementation
}

RaylibRenderer::~RaylibRenderer() {
    // Destructor implementation
}

void RaylibRenderer::init() {
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(1270, 720, "RIFTSIM");
    // InitAudioDevice();
    SetTargetFPS(60); 
    _frame = 0;
    _lastTime = GetTime();
    _lag = 0.0f;
}

bool RaylibRenderer::render() {
    const float SECONDS_PER_UPDATE = 1.0f / 60.0f; // 60 FPS target
    
    if (WindowShouldClose()) {
        CloseWindow();
        return false;
    }   
    
    // Handle input (uncomment when ready)
    // inputs();
    
    // Calculate delta time
    float currentTime = GetTime();
    float deltaTime = currentTime - _lastTime;
    _lastTime = currentTime;
    
    // Accumulate lag for fixed timestep updates
    _lag += deltaTime;
    
    // Run fixed timestep updates
    int updates = 0;
    while (_lag >= SECONDS_PER_UPDATE) {
        GameEngine::instance().update(SECONDS_PER_UPDATE);
        _lag -= SECONDS_PER_UPDATE;
        updates++;
    }
    
    // Handle remaining lag (spiral of death prevention)
    if (updates == 0 && _lag > 0.0f) {
        GameEngine::instance().update(_lag);
        _lag = 0.0f;
        updates++;
    }
    
    // Increment frame counter
    _frame++;
    
    // Render frame
    BeginDrawing();
    ClearBackground(BLACK);
    GameEngine::instance().getCurrentScene().render();
    EndDrawing();

    return true;
}