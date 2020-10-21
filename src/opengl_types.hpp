#pragma once
#include "../Resources/GLEW/include/GL/glew.h"
#include <string>

/**
 * @brief The function return size of openGL type
 * 
 * @param type - openGL type
 * @return unsigned int - size of openGL type
 */
unsigned int getSizeOfType(GLenum type);