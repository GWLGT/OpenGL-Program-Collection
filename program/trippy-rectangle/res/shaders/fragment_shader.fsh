#version 330 core

uniform vec4 ColorValues;
uniform sampler2D Texture;

out vec4 Color;
in vec2 TexCoord;

void main(void) {
  Color = texture(Texture, TexCoord) + ColorValues;
}
