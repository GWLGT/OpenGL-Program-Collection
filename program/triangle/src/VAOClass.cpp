#include "BuffersClass.hpp"

Buffers::VAO::VAO() {
  // Generate the ID for the VAO
  glGenVertexArrays(1, &VAOID);
}

void Buffers::VAO::LinkVBO(VBO VBO, GLuint Layout) {
  // Bind the VBO
  VBO.BindVBO();

  // Set a Way to Communicate Between Vertex Shader and the VBO
  glVertexAttribPointer(Layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  // Enable The Vertex Attribute
  glEnableVertexAttribArray(0);

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
