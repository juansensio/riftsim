#pragma once

#include "Component.h"

class CLife : public Component
{
public:
    int life;
    
    CLife() {}
    CLife(int life) : life(life) {}
}; 