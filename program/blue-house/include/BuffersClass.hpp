#ifndef BUFFERS_CLASS_HPP
#define BUFFERS_CLASS_HPP

#include "glad/glad.h"

namespace Buffers {
  class VBO {
    public:
      /// The ID of the VBO
      GLuint VBOID;

      /// Constructor to Create the VBO
      VBO(GLfloat* Vertices, GLsizeiptr Size);

      /// Function to Bind the VBO
      void BindVBO();
      /// Function to Unbind thw VBO
      void UnbindVBO();
      /// Function to Delete the VBO
      void DeleteVBO();
  };

  class VAO {
    public:
      /// The ID of the VAO
      GLuint VAOID;

      /// Constructor to Create the VAO
      VAO();

      /// Function to Link the VAO to the Specified Attribute
      void LinkAttribute(VBO VBO, GLuint Layout, GLuint Components, GLenum Type, GLsizeiptr Stride, void* Offset);
      /// Function to Bind the VAO
      void BindVAO();
      /// Function to Unbind thw VAO
      void UnbindVAO();
      /// Function to Delete the VAO
      void DeleteVAO();
  };

  class EBO {
    public:
      /// The ID of the EBO
      GLuint EBOID;

      /// Constructor to Create the EBO
      EBO(GLuint* Indices, GLsizeiptr Size);

      /// Function to Bind the EBO
      void BindEBO();
      /// Function to Unbind thw EBO
      void UnbindEBO();
      /// Function to Delete the EB0
      void DeleteEBO();
  };
} // namespace Buffers

#endif
