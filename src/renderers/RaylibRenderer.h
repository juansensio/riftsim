#pragma once

#include "raylib.h"
#include "raygui.h"

#include "BaseRenderer.h"

class RaylibRenderer : public BaseRenderer {
private:
    int _frame;
    float _lastTime;
    float _lag;
    
public:
    RaylibRenderer();
    ~RaylibRenderer();

    void init();
    bool render();
};