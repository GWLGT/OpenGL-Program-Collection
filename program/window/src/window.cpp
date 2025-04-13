#include "window.hpp"

void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

bool RenderWindow(int width, int height, const char* title) {
  bool ReturnValue;

  /* Set GLFW Contexts
   - OpenGL 3.3
   - OpenGL Core Profile
  */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create Window
  window = glfwCreateWindow(width, height, title, nullptr, nullptr);

  // Check Window Creation
  if (window == nullptr) {
    glfwTerminate();
    ReturnValue = false;
  } else {
    ReturnValue = true;

    glfwMakeContextCurrent(window);
  }

  return ReturnValue;
}
