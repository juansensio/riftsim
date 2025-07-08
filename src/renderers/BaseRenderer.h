#pragma once

class BaseRenderer {
public:
    BaseRenderer() = default;
    virtual ~BaseRenderer() = default;

    // Virtual methods that can be overridden by derived classes
    virtual void init() {
        // Default implementation does nothing
    }
    
    virtual void run() {
        // Default implementation does nothing
    }
}; 