#include "ShaderClass.hpp"

std::string Shader::ReadFile(const std::string FilePath) {
  std::string Content;
  std::stringstream Buffer;

  std::ifstream File(FilePath);

  if (!File) {
    Utils::PrintLog(MESSAGE_ERROR, "Failed to Read the Vertex/Fragment Shader File!");
    throw std::runtime_error("Vertex/Fragment Shader Reading Proccess Gone Wrong!\nMake sure to Run the Program from the Project Root Directory");
  } else {
    Buffer << File.rdbuf();
    Content = Buffer.str();

    Utils::PrintLog(MESSAGE_OK, "Vertex/Fragment Shader File was Read Successfully!");
  }

  return Content;
}

Shader::Shader::Shader(const std::string VertexFile, const std::string FragmentFile) {
  int Success;
  char LogMessage[512];

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
  glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &Success);

  if (!Success) {
    glGetShaderInfoLog(VertexShader, 512, nullptr, LogMessage);

    Utils::PrintLog(MESSAGE_ERROR, "Failed to Compile the Vertex Shader!");
    throw std::runtime_error(LogMessage);
  }

  glCompileShader(FragmentShader);
  glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &Success);

  if (!Success) {
    glGetShaderInfoLog(FragmentShader, 512, nullptr, LogMessage);

    Utils::PrintLog(MESSAGE_ERROR, "Failed to Compile the Fragment Shader!");
    throw std::runtime_error(LogMessage);
  }

  // Create the Shader Program
  ShaderID = glCreateProgram();

  // Attach and Link the Shader Program
  glAttachShader(ShaderID, VertexShader);
  glAttachShader(ShaderID, FragmentShader);

  glLinkProgram(ShaderID);
  glGetProgramiv(ShaderID, GL_LINK_STATUS, &Success);

  if (!Success) {
    glGetProgramInfoLog(ShaderID, 512, nullptr, LogMessage);

    Utils::PrintLog(MESSAGE_ERROR, "Failed to Link the Shaders!");
    throw std::runtime_error(LogMessage);
  }

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

GLint Shader::Shader::GetUniform(const std::string UniformNameSTR, GLuint ShaderID) {
  const char* UniformName = UniformNameSTR.c_str();
  GLint UniformID = glGetUniformLocation(ShaderID, UniformName);

  if (UniformID == -1) {
    Utils::PrintLog(MESSAGE_ERROR, "Failed to Retrieve the Uniform Location!");
    throw std::runtime_error("Uniform ID of \"" + UniformNameSTR + "\" cannot be Retrieved, Make sure it's Exist in the Vertex Shader!");
  } else {
    Utils::PrintLog(MESSAGE_OK, "Uniform ID Retrieved Successfully as \"" + UniformNameSTR + "\"!");
  }

  return UniformID;
}
