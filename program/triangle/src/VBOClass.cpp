#include "BuffersClass.hpp"

Buffers::VBO::VBO(GLfloat* Vertices, GLsizeiptr Size) {
  // Generate the ID for the VBO
  glGenBuffers(1, &VBOID);
  // Bind the VBO as GL_ARRAY_BUFFER
  glBindBuffer(GL_ARRAY_BUFFER, VBOID);

  // Send Vertices data to the VBO
  glBufferData(GL_ARRAY_BUFFER, Size, Vertices, GL_STATIC_DRAW);
}

void Buffers::VBO::BindVBO() {
  // Bind the VBO as GL_ARRAY_BUFFER
  glBindBuffer(GL_ARRAY_BUFFER, VBOID);
}

void Buffers::VBO::UnbindVBO() {
  // Unbind the VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffers::VBO::DeleteVBO() {
  // Delete the VBO
  glDeleteBuffers(1, &VBOID);
}
