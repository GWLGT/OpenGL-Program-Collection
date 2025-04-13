#include "opengl_renderer.hpp"

const int WIDTH = 800, HEIGHT = 450;
GLFWwindow* window = nullptr;

int main(void) {
  Color color;

  // Check GLFW initialization Process
  if (!glfwInit()) {
    std::cout << color.Red << "ERROR: Failed to Initialize GLFW! EXITING... " << color.Orange << "CODE 2" << color.Reset << std::endl;
    return 2;
  } else {
    std::cout << color.Green << "MESSAGE: GLFW Initialized Successfully!" << color.Reset << std::endl;
  }

  // Check Window creation Process
  if (!RenderWindow(WIDTH, HEIGHT, "OpenGL | Window")) {
    std::cout << color.Red << "ERROR: Failed to Create the Window! EXITING... " << color.Orange << "CODE 2" << color.Reset << std::endl;
    glfwTerminate();
    return 2;
  } else {
    std::cout << color.Green << "MESSAGE: Window Created Successfully!" << color.Reset << std::endl;
  }

  // Check GLAD initialization Process
  if (!OpenGLRenderer(WIDTH, HEIGHT)) {
    std::cout << color.Red << "ERROR: Failed to Initialize GLAD! EXITING... " << color.Orange << "CODE 2" << color.Reset << std::endl;
    return 2;
  } else {
    std::cout << color.Green << "MESSAGE: GLAD Initialized Successfully!" << color.Reset << std::endl;
  }

  MainLoop();

  // Clean everything Created
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
};
