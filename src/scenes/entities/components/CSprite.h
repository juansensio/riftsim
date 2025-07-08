
#pragma once

#include "Component.h"

class CSprite : public Component
{
public:
    const Texture2D*    texture; // no puede ser referencia porque el memory pool necesita constructor por defecto y ahí no tengo textura aún en memoria
    Rectangle           source_rect;
    float               width;
    float               height;
    Color               color;

    CSprite() : texture(nullptr), source_rect({0, 0, 0, 0}), width(0), height(0), color(WHITE) {}
    CSprite(const Texture2D* texture, const Rectangle& source_rect, const float& width, const float& height, const Color& color) : texture(texture), source_rect(source_rect), width(width), height(height), color(color) {}
}; 