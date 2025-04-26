#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 ITexCoord;

out vec2 TexCoord;

void main(void) {
  gl_Position = vec4(Position.x, Position.y, Position.z, 1.0f);

  TexCoord = ITexCoord;
}
