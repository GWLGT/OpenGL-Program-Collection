cmake_minimum_required(VERSION 3.31.6)
project(OpenGL_Window VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDDARD 17)
set(CMAKE_CXX_STANDDARD_REQUIRED True)

include_directories(include/)

add_executable(main
  src/glad.c
  src/window.cpp
  src/opengl_renderer.cpp
  src/main.cpp
)

target_link_libraries(main
  GL
  glfw
)
