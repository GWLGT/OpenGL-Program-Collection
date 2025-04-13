#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

#include "utils.hpp"

extern GLFWwindow* window;

void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

bool RenderWindow(int width, int height, const char* title);
