#include "opengl_types.hpp"

unsigned int getSizeOfType(GLenum type){
  switch(type){
    case GL_INT:
        return sizeof(int);

    case GL_FLOAT:
        return sizeof(float);
    
    case GL_UNSIGNED_INT:
        return sizeof(unsigned int);

    case GL_SHORT:
        return sizeof(short);
  }
  return -1;
}