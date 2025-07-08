#pragma once

#include <iostream>

class BaseRenderer {
private:
    int renderCount = 0;
    static const int MAX_RENDER_CALLS = 100;

public:
    BaseRenderer();
    virtual ~BaseRenderer();

    // Virtual methods that can be overridden by derived classes
    virtual void init();
    virtual bool render();
}; 