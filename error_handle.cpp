#include "error_handle.hpp"

void GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line){
    if(GLenum error = glGetError()){
        std::cout << "[OpenGl error]: " << error << "  function: " << function << "  file: " << file << "  line: " << line << std::endl;
        return false;
    }
    return true;
} 