#ifndef APP_CLASS_HPP
#define APP_CLASS_HPP

#include "Utils.hpp"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

class App {
  public:
    /// Constructor to Intitialize GLFW and GLAD, and Create the Windoe
    App(int Width, int Height, const char* Title);

    /// Function (Getter) to get the Window ID
    GLFWwindow* GetWindow();
    /// Function to Destroy the Window and Terminate GLFW
    void DeleteApp();
    /// Functiin to Set Window Resizing Callback
    static void FramebufferSizeCallback(GLFWwindow* Window, int Width, int Height);

  private:
    GLFWwindow* Window;
};

#endif
