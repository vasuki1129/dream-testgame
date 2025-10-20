#include <dream.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class ShipComponent : public Component
{
private:
    glm::vec2 velocity;
};

int main(int argc, char *argv[]) {

    DreamInitFunc([]()
        {
           DreamAddGameObject(new GameObject())
               ->AddComponent(new SpriteRenderComponent("test.png",glm::vec2(128,128)))
               ->AddComponent(new PhysicsMomentumComponent())
               ->AddComponent(new InputBindComponent(GLFW_KEY_S,[](float delta, Component* c){
                   c->gameobject->GetComponent<PhysicsMomentumComponent>()->ApplyForce(glm::vec2(1.0f,1.0f), delta);
               }));
        }
    );

    DreamMainLoopFunc([](float delta)
        {

        }
    );

    DreamStart();

    return 0;
}
