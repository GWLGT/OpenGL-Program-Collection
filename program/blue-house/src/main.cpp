#include "AppClass.hpp"
#include "ShaderClass.hpp"
#include "BuffersClass.hpp"
#include "Utils.hpp"

int main(void) {
  // Some random Variable Initialization
  // You'll get the idea My Friend

  const int Width = 800, Height = 450;
  const char* Title = "OpenGL | Blue House Thing";

  GLfloat Vertices[] = {
      // Vertices //
      -0.5f, -0.5f, 0.0f, // Bottom-Left | Index 0
      0.5f,  -0.5f, 0.0f, // Bottom-Right | Index 1
      0.5f,  0.5f,  0.0f, // Top-Right | Index 2
      -0.5f, 0.5f,  0.0f, // Top-Left | Index 3
      0.0f,  0.8f,  0.0f  // Top-Center | Index 4
  };

  GLuint Indices[] = {
      // Rectangle //
      0, 2, 1, // First-Half Triangle
      0, 3, 2, // Second-Half Triangle

      // Triangle //
      3, 4, 2 // Top Triangle
  };

  const std::string VertexShaderPath = "res/shaders/vertex_shader.vsh", FragmentShaderPath = "res/shaders/fragment_shader.fsh";

  try {
    // Initialize GLFW and GLAD, and Create the Window
    App GLFWApp(Width, Height, Title);
    // Get the ID of the Window for Later Use
    GLFWwindow* Window = GLFWApp.GetWindow();

    // Read, Compile and Link the Shader
    Shader::Shader MainShader(VertexShaderPath, FragmentShaderPath);

    // Create the VAO
    Buffers::VAO MainVAO;
    // Bind the VAO to the VBO
    MainVAO.BindVAO();

    // Set the VBO and EBO Data
    Buffers::VBO MainVBO(Vertices, sizeof(Vertices));
    Buffers::EBO MainEBO(Indices, sizeof(Indices));

    // Link the VAO to the VBO
    MainVAO.LinkAttribute(MainVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

    // Unbind every Buffers
    MainVAO.UnbindVAO();
    MainVBO.UnbindVBO();
    MainEBO.UnbindEBO();

    // Retrieve the Specified Uniform for Later Use
    GLint ColorUniform = Shader::Shader::GetUniform("Blue", MainShader.ShaderID);

    // Main Loop
    while (!glfwWindowShouldClose(Window)) {
      glClearColor(0.38f, 0.6f, 0.38f, 1.0f); // Set Viewport Color
      glClear(GL_COLOR_BUFFER_BIT);           // Clear the Color Buffer Before Swapping
      MainShader.UseShader();                 // Use the Shader

      float Time = glfwGetTime(); // Get the current time (in Second)

      // Calculate the final Value
      float Value = sin(Time) / 2.0f + 0.5f;

      // Set the Blue value to the value of "Value" variable
      glUniform1f(ColorUniform, Value);

      MainVAO.BindVAO();                                   // Re-bind the VA0
      glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0); // Draw the Vertices from location 0

      glfwSwapBuffers(Window); // Swap the Back Buffer to Front Buffer (Vice Versa)
      glfwPollEvents();        // Handle Event
    }

    // Free up the Memory
    MainVAO.DeleteVAO();
    MainVBO.DeleteVBO();
    MainEBO.DeleteEBO();
    MainShader.DeleteShader();
    GLFWApp.DeleteApp();
  } catch (const std::exception& err) {
    Utils::PrintLog(MESSAGE_WARNING, "Exception Caught\n");
    std::cerr << Utils::Color::Red << err.what() << Utils::Color::Reset << std::endl;

    return 2;
  }

  return 0;
}
