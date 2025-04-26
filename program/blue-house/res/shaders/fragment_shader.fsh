#version 330 core

out vec4 Color;
uniform float Blue;

void main(void) {
  Color = vec4(0.0f, 0.0f, Blue, 1.0f);
}
