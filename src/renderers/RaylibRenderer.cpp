#include "RaylibRenderer.h"

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
}

void RaylibRenderer::run() {
    // #ifdef _DEBUG
	// 	changeScene<ScenePlay>(SceneType::PLAY);
	// 	// changeScene<SceneLoading>(SceneType::LOADING);
	// #else
	// 	changeScene<SceneLoading>(SceneType::LOADING);
	// #endif
	int frame = 0;
	float lastTime = GetTime();
	float lag = 0.0f;
	// float SECONDS_PER_UPDATE = 1.0f / 60.0f; // fps
    while (!WindowShouldClose())   
    {
		// inputs();
		float currentTime = GetTime();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		lag += deltaTime;
		int updates = 0;
		// while (lag >= SECONDS_PER_UPDATE) {
		// 	getCurrentScene().update(SECONDS_PER_UPDATE);
		// 	lag -= SECONDS_PER_UPDATE;
		// 	updates++;
		// }
		// if (updates == 0 && lag > 0.0f) {
		// 	getCurrentScene().update(lag);
		// 	lag = 0.0f;
		// 	updates++;
		// }
		frame += 1;
		BeginDrawing();
        ClearBackground(BLACK);
		// getCurrentScene().render();
        EndDrawing();
    }
    CloseWindow();  
}