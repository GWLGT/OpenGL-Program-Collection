#include "TextureClass.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(GLenum TextureType, GLenum WrapType, GLenum FilterType, const std::string TextureImagePath) {
  int ImageWidth, ImageHeight, ImageColorChannel;

  // Convert the Texture Image Path to C-String
  const char* ImagePath = TextureImagePath.c_str();

  // Generate and Bind the Texture
  glGenTextures(1, &TextureID);
  glBindTexture(TextureType, TextureID);

  // Set the Texture Parameter
  glTexParameteri(TextureType, GL_TEXTURE_WRAP_S, WrapType);
  glTexParameteri(TextureType, GL_TEXTURE_WRAP_T, WrapType);
  glTexParameteri(TextureType, GL_TEXTURE_MIN_FILTER, FilterType);
  glTexParameteri(TextureType, GL_TEXTURE_MAG_FILTER, FilterType);

  // Load the Image
  ImageData = stbi_load(ImagePath, &ImageWidth, &ImageHeight, &ImageColorChannel, 0);

  if (ImageData) {
    /* clang-format off */
    //Set the Texture Data
    glTexImage2D(TextureType,
                 0,
                 ImageColorChannel == 4 ? GL_RGBA : GL_RGB,
                 ImageWidth,
                 ImageHeight,
                 0,
                 ImageColorChannel == 4 ? GL_RGBA : GL_RGB,
                 GL_UNSIGNED_BYTE, ImageData);
    /* clang-format off */
    //Generate MipMap for the Current Texture
    glGenerateMipmap(TextureType);
  } else {
    Utils::PrintLog(MESSAGE_ERROR, "Failed to Read the Texture Image File!");
    throw std::runtime_error("Texture Image Reading Proccess Gone Wrong!\nMake sure to Run the Program from the Project Root Directory");
  }
}

void Texture::BindTexture(GLenum TextureType) {
  //Bind the Texture
  glBindTexture(TextureType, TextureID);
}

void Texture::DeleteTexture() {
  //Delete the Texture Data
  glDeleteTextures(1, &TextureID);
}

void Texture::DeleteImage() {
  //Delete the Texture Image
  stbi_image_free(ImageData);
}
