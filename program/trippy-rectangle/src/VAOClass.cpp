#include "BuffersClass.hpp"

Buffers::VAO::VAO() {
  // Generate the ID for the VAO
  glGenVertexArrays(1, &VAOID);
}

void Buffers::VAO::LinkAttribute(VBO VBO, GLuint Layout, GLuint Components, GLenum Type, GLsizeiptr Stride, void* Offset) {
  // Bind the VBO
  VBO.BindVBO();

  // Set a Way to Communicate Between Vertex Shader and the VBO
  glVertexAttribPointer(Layout, Components, Type, GL_FALSE, Stride, Offset);
  // Enable The Vertex Attribute
  glEnableVertexAttribArray(Layout);

  // Unbind the VBO
  VBO.UnbindVBO();
}

void Buffers::VAO::BindVAO() {
  // Bind the VAO
  glBindVertexArray(VAOID);
}

void Buffers::VAO::UnbindVAO() {
  // Unbind the VAO
  glBindVertexArray(0);
}

void Buffers::VAO::DeleteVAO() {
  // Delete the VAO
  glDeleteVertexArrays(1, &VAOID);
}
