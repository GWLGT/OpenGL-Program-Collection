#ifndef TEXTURE_CLASS
#define TEXTURE_CLASS

#include "glad/glad.h"
#include "Utils.hpp"

#include "stb_image.h"

class Texture {
  public:
    /// The ID of the Texture
    GLuint TextureID;
    /// The Variable that Holds the Image Color Data
    stbi_uc* ImageData;

    /// Constructor to Load and Create the Image
    Texture(GLenum TextureType, GLenum WrapType, GLenum FilterType, const std::string TextureImagePath);

    /// Function to Bind the Texture
    void BindTexture(GLenum TextureType);
    /// Function to Delete the Texture Data
    void DeleteTexture();
    /// Function to Delete the Texture Image
    void DeleteImage();
};

#endif
