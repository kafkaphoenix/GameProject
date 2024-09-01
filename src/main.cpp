#include <gameengine/engine.h>
#include <glm/glm.hpp>
#include <gameengine/utils.h>
#include <iostream>

int main() {
    engine::Engine engine;
    engine.start();
    std::cout << "After engine started I can do other things, like using third party libraries exposed by the engine" << std::endl;
    glm::vec3 v(1.0f, 0.0f, 0.0f);
    std::cout << "Using glm: " << v.x << " " << v.y << " " << v.z << std::endl;
    APP_ASSERT(1 != 1, "Trying macro");
    return 0;
}
