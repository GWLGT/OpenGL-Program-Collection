#include "utils.hpp"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void FBSizeCallback(GLFWwindow* window, int width, int height);

int main(void) {
  // Some random Variable Initialization
  // You'll get the idea My Friend
  Utils::Color c;

  const int Width = 800, Height = 450;

  GLuint VBO, VAO;

  GLfloat Vertices[] = {
      -0.5f, -0.5f, 0.0f, // Bottom-Left
      0.0f,  0.5f,  0.0f, // Top-Center
      0.5f,  -0.5f, 0.0f  // Bottom-Right
  };

  const char* VertexShaderSource = R"(
    #version 330 core

    layout (location = 0) in vec3 aPos;

    void main(void) {
      gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
    } 
  )";
  const char* FragmentShaderSource = R"(
    #version 330 core

    out vec4 FragColor;

    void main(void) {
      FragColor = vec4(0.36f, 0.87f, 0.68f, 1.0f);
    }
  )";

  GLuint VertexShader, FragmentShader, ShaderProgram;

  // Check GLFW initialization Process
  if (!glfwInit()) {
    std::cout << c.Red << "ERROR: Failed to Initialize GLFW! EXITING... " << c.Orange << "CODE 2" << c.Reset << std::endl;
    return 2;
  } else {
    std::cout << c.Green << "MESSAGE: GLFW Initialized Successfully!" << c.Reset << std::endl;
  }

  /*
    Set Windoe Hints:
      - OpenGL 3.3.
      - OpenGL Core Profile.
  */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create the Window
  GLFWwindow* window = glfwCreateWindow(Width, Height, "OpenGL | Triangle", nullptr, nullptr);

  // Check the Window Creation Proccess
  if (window == nullptr) {
    std::cout << c.Red << "ERROR: Failed to Create the Window! EXITING... " << c.Orange << "CODE 2" << c.Reset << std::endl;
    return 2;
  } else {
    std::cout << c.Green << "MESSAGE: Window Created Successfully!" << c.Reset << std::endl;
  }

  // Set the Context to the Currently Created Window
  glfwMakeContextCurrent(window);

  // Check GLAD Initialization
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << c.Red << "ERROR: Failed to Initialize GLAD! EXITING... " << c.Orange << "CODE 2" << c.Reset << std::endl;
  } else {
    std::cout << c.Green << "MESSAGE: GLAD Initialized Successfully!" << c.Reset << std::endl;
  }

  // Set the OpenGL Viewport
  glViewport(0, 0, Width, Height);

  // Set the Function to Execute when the Window get Resized
  glfwSetFramebufferSizeCallback(window, FBSizeCallback);

  // Create Vertex and Fragment Shader
  VertexShader = glCreateShader(GL_VERTEX_SHADER);
  FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  // Set its Source
  glShaderSource(VertexShader, 1, &VertexShaderSource, nullptr);
  glShaderSource(FragmentShader, 1, &FragmentShaderSource, nullptr);

  // Compile it
  glCompileShader(VertexShader);
  glCompileShader(FragmentShader);

  // Create Shader Program
  ShaderProgram = glCreateProgram();

  // Attach and Link the Shader's
  glAttachShader(ShaderProgram, VertexShader);
  glAttachShader(ShaderProgram, FragmentShader);
  glLinkProgram(ShaderProgram);

  // Delete the Compiled Shader
  glDeleteShader(VertexShader);
  glDeleteShader(FragmentShader);

  // Generate VAO and VBO
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // Bind VAO to VBO
  glBindVertexArray(VAO);
  // Bind VBO as GL_ARRAY_BUFFER
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  // Insert the Data to the VBO
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

  // Setup a way to communicate between Vertex Shader and VAO/VBO
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Unbind them (VAO/VB()) for Later Use
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // Main Loop
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.38f, 0.6f, 0.38f, 1.0f); // Set Viewport Color
    glClear(GL_COLOR_BUFFER_BIT);           // Clear the Color Buffer Before Swapping
    glUseProgram(ShaderProgram);            // Use the Shader
    glBindVertexArray(VAO);                 // Re-bind the VAO
    glDrawArrays(GL_TRIANGLES, 0, 3);       // Draw the Vertices from location 0

    glfwSwapBuffers(window); // Swap the Back Buffer to Front Buffer (Vice Versa)
    glfwPollEvents();        // Handle Event
  }

  // Freeing the Memory
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(ShaderProgram);

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}

void FBSizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height); // Re-set the OpenGL Viewport when the window is Resized
}
