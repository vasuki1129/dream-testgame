#include <dream.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[]) {

    DreamInitFunc([]()
        {
           DreamAddGameObject(new GameObject())
               ->AddComponent(new SpriteRenderComponent("test.png",glm::vec2(128,128)))
               ->AddComponent(new ConstantTravelComponent(glm::vec2(1.0f,1.0f),10.0f));
        }
    );

    DreamMainLoopFunc([](float delta)
        {

        }
    );

    DreamStart();

    return 0;
}
