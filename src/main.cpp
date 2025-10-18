#include <iostream>
#include <dream.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
class TestObject : public GameObject
{
    float posX = 0.0f;
    float posY = 0.0f;
public:
    void tick(float delta) override;
    void render() override;

};


void TestObject::tick(float delta) {

  if (DreamKeyDown(GLFW_KEY_W)) {
      posY -= delta * 1.0f;
  }
  if (DreamKeyDown(GLFW_KEY_S)) {
      posY += delta * 1.0f;
  }

  if (DreamKeyDown(GLFW_KEY_A)) {
      posX -= delta * 1.0f;
  }
  if (DreamKeyDown(GLFW_KEY_D)) {
      posX += delta * 1.0f;
  }
}

void TestObject::render()
{
    DreamDrawQuadTexture(posX,posY,128,128,glm::vec4(1.0f,0.0f,0.0f,1.0f),"test.png");
}

int main(int argc, char *argv[]) {

    DreamInitFunc([]()
        {
            DreamAddGameObject(new TestObject());
        }
    );

    DreamMainLoopFunc([](float delta)
        {

        }
    );

    DreamStart();

    return 0;
}
