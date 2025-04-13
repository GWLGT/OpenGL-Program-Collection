#include "opengl_renderer.hpp"

bool OpenGLRenderer(int width, int height) {
  bool ReturnValue;

  // Check GLAD Initialization
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    ReturnValue = false;
  } else {
    ReturnValue = true;

    // Set OpenGL Rendering Viewport to the same size as the Window
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
  }

  return ReturnValue;
}

void MainLoop() {
  // Main Loop
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f); // Set the Viewport Color
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the Color Buffer for Next Draw

    glfwSwapBuffers(window); // Swap the Window Buffers for Next Draw
    glfwPollEvents();
  }
}
