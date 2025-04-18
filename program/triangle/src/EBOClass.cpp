#include "BuffersClass.hpp"

Buffers::EBO::EBO(GLuint* Indices, GLsizeiptr Size) {
  // Generate the ID for the EBO
  glGenBuffers(1, &EBOID);
  // Bind the EBO as GL_ELEMENT_ARRAY_BUFFER
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOID);

  // Send Indices Data to the EBO
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, Size, Indices, GL_STATIC_DRAW);
}

void Buffers::EBO::BindEBO() {
  // Bind the EBO as GL_ELEMENT_ARRAY_BUFFER
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOID);
}

void Buffers::EBO::UnbindEBO() {
  // Unbind the EBO
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Buffers::EBO::DeleteEBO() {
  // Delete the EBO
  glDeleteBuffers(1, &EBOID);
}
