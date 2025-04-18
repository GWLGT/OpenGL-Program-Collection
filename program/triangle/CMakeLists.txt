cmake_minimum_required(VERSION 3.31.6)
project(OpenGL_Triangle VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDDARD 17)
set(CMAKE_CXX_STANDDARD_REQUIRED True)

include_directories(include/)
add_compile_options(-Wall -Wextra)
add_link_options(-s)

add_executable(main
  src/glad.c
  src/AppClass.cpp
  src/ShaderClass.cpp
  src/VBOClass.cpp
  src/VAOClass.cpp
  src/EBOClass.cpp
  src/main.cpp
)

target_link_libraries(main
  GL
  glfw
)
