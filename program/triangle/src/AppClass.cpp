#include "AppClass.hpp"

GLFWwindow* App::GetWindow() {
  // Return the Window ID
  return Window;
}

void App::DeleteApp() {
  // Destroy the Windoe and Terminate GLFW
  glfwDestroyWindow(Window);
  glfwTerminate();
}

void App::FramebufferSizeCallback(GLFWwindow* Window, int Width, int Height) {
  // Reset the Viewport when Resized
  glViewport(0, 0, Width, Height);
}

App::App(int Width, int Height, const char* Title) {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cout << Utils::Color::Red << "ERROR: Failed to Initialize GLFW! EXITING... " << Utils::Color::Orange << "CODE 2" << Utils::Color::Reset << std::endl;
    throw std::runtime_error("GLFW Initialization Gone Wrong!\nMake sure to Run the Program while on Graphical Server (e.g X11/Wayland)");
  } else {
    std::clog << Utils::Color::Green << "MESSAGE: GLFW Initialized Successfully!" << Utils::Color::Reset << std::endl;
  }

  // Set the Window Hints
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create the Window
  Window = glfwCreateWindow(Width, Height, Title, nullptr, nullptr);

  // Check Window Initialization
  if (Window == nullptr) {
    std::cout << Utils::Color::Red << "ERROR: Failed to Create the Window! EXITING... " << Utils::Color::Orange << "CODE 2" << Utils::Color::Reset << std::endl;
    throw std::runtime_error("Window Creation Gone Wrong!");
  } else {
    std::clog << Utils::Color::Green << "MESSAGE: Window Created Successfully!" << Utils::Color::Reset << std::endl;
  }
  glfwMakeContextCurrent(Window);

  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << Utils::Color::Red << "ERROR: Failed to Initialize GLAD! EXITING... " << Utils::Color::Orange << "CODE 2" << Utils::Color::Reset << std::endl;
    throw std::runtime_error("GLAD Initialization Gone Wrong!");
  } else {
    std::clog << Utils::Color::Green << "MESSAGE: GLAD Initialized Successfully!" << Utils::Color::Reset << std::endl;
  }

  // Set the OpenGL Viewport and the Framebuffer Callback
  glViewport(0, 0, Width, Height);
  glfwSetFramebufferSizeCallback(Window, App::FramebufferSizeCallback);
}
