cmake_minimum_required(VERSION 3.31.6)
project(OpenGL_Triangle VERSION 2.2.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_compile_options(-Wall -Wextra)
add_link_options(-s)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

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
  OpenGL::GL
  glfw
)
