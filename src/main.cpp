#include "GameEngine.h"
#include <iostream>

int main(int argc, char* argv[]) {
    int rendererChoice = 1; // Default to raylib renderer
    
    if (argc > 1) {
        rendererChoice = std::atoi(argv[1]);
    }
    
    if (rendererChoice != 0 && rendererChoice != 1) {
        std::cout << "Usage: " << argv[0] << " [renderer_choice]" << std::endl;
        std::cout << "  renderer_choice: 0 for no renderer, 1 for raylib renderer" << std::endl;
        return 1;
    }
    
    GameEngine::instance().init(rendererChoice);
    GameEngine::instance().run();
    return 0;
}