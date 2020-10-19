#pragma once
#include "Resources/GLEW/include/GL/glew.h"
#include <iostream>

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

#define GLCALL(x) GLClearError();\
    x;\
    GLLogCall(#x, __FILE__, __LINE__);