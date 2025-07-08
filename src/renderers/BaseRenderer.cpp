#include "BaseRenderer.h"
#include "../GameEngine.h"

BaseRenderer::BaseRenderer() = default;

BaseRenderer::~BaseRenderer() = default;

void BaseRenderer::init() {
    // Default implementation does nothing
}

bool BaseRenderer::render() {
    GameEngine::instance().update();

    renderCount++;
    // Return false to quit after 100 render calls
    std::cout << "Render count: " << renderCount << std::endl;
    return renderCount < MAX_RENDER_CALLS;
} 