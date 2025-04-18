#include "ShaderClass.hpp"

std::string Shader::ReadFile(const std::string FilePath) {
  std::string Content;
  std::stringstream Buffer;

  std::ifstream File(FilePath);

  if (!File) {
    std::cout << Utils::Color::Red << "ERROR: Failed to Read the Shader File! EXITING... " << Utils::Color::Orange << "CODE 2" << Utils::Color::Reset << std::endl;
    throw std::runtime_error("Vertex/Fragment Shader Reading Proccess Gone Wrong!\nMake sure to Run the Program from the Project Root Directory");
  } else {
    Buffer << File.rdbuf();
    Content = Buffer.str();

    std::clog << Utils::Color::Green << "MESSAGE: Vertex/Fragment Shader was Read Successfully!" << Utils::Color::Reset << std::endl;
  }

  return Content;
}

Shader::Shader::Shader(const std::string VertexFile, const std::string FragmentFile) {
  // Read the Shader File
  std::string VertexShaderFileCPP = ReadFile(VertexFile);
  std::string FragmentShaderFileCPP = ReadFile(FragmentFile);

  // Convert it to C String Array
  const char* VertexShaderFile = VertexShaderFileCPP.c_str();
  const char* FragmentShaderFile = FragmentShaderFileCPP.c_str();

  // Create the Shader
  GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  // Set the Shader Source
  glShaderSource(VertexShader, 1, &VertexShaderFile, nullptr);
  glShaderSource(FragmentShader, 1, &FragmentShaderFile, nullptr);

  // Compile the Shader
  glCompileShader(VertexShader);
  glCompileShader(FragmentShader);

  // Create the Shader Program
  ShaderID = glCreateProgram();

  // Attach and Link the Shader Program
  glAttachShader(ShaderID, VertexShader);
  glAttachShader(ShaderID, FragmentShader);
  glLinkProgram(ShaderID);

  // Delete the Compiled Shader
  glDeleteShader(VertexShader);
  glDeleteShader(FragmentShader);
}

void Shader::Shader::UseShader() {
  glUseProgram(ShaderID); // Use the Shader Program
}

void Shader::Shader::DeleteShader() {
  glDeleteProgram(ShaderID); // Delete the Shader Program
}
