#include "Card.h"
#include "../../GameEngine.h"

Card::Card(Entity* entity) : Object(entity) {}

Card::~Card() {}

void Card::init()
{
    const auto& texture = GameEngine::instance().getAssets().getTexturePtr("c00100001");
    
    // Debug texture info
    std::cout << "Card init - Texture: " << (texture ? "valid" : "null") << std::endl;
    if (texture) {
        std::cout << "  Texture dimensions: " << texture->width << "x" << texture->height << std::endl;
    }
    
    float sprite_width = texture->width;
	float sprite_height = texture->height;
	float width = 256; 
	float height = 256;
    _entity->add<CSprite>(texture, Rectangle{0, 0, sprite_width, sprite_height}, width, height, WHITE);
}