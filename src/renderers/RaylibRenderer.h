#pragma once

#include "raylib.h"
#include "raygui.h"

#include "BaseRenderer.h"

class RaylibRenderer : public BaseRenderer {
public:
    RaylibRenderer();
    ~RaylibRenderer();

    void init();
    void run();
};