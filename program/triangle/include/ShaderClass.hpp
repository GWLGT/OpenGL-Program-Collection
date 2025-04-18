#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP

#include "glad/glad.h"
#include "Utils.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Shader {
  /// Function to Read File
  std::string ReadFile(const std::string FilePath);

  class Shader {
    public:
      /// The ID of the Shader Program
      GLuint ShaderID;

      /// Constructor to Compile and Link the Shader
      Shader(const std::string VertexFile, const std::string FragmentFile);

      /// Function to Use/Activate the Shader Program
      void UseShader();
      /// Function to Delete the Shader Program
      void DeleteShader();
  };
} // namespace Shader

#endif
