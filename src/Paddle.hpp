#pragma once

#include <glm/glm.hpp>

class Paddle {
    Paddle(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
    void update(float deltaTime);
    void draw();
private:
    int topLeftX;
    int topLeftY;
    int bottomRightX;
    int bottomRightY;
    glm::vec3 velocity;
};



