#include <iostream>
#include "Resources/GLEW/include/GL/glew.h"
#include "Resources/GLFW/include/GLFW/glfw3.h"
#include "files_io.hpp"
#include "VertexAttribute.hpp"
#include "VertexArray.hpp"
#include "shader.hpp"

int main(void)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    if(glewInit() != GLEW_OK){
        std::cout << "error glew does not initated!" << std::endl;
        exit(1);
    }

    float buffer[] = {
        0.0f, 0.5f,
        -0.5f, 0.0f, 
        0.5f, 0.0f,
    };

    VertexAttribute vertexAttrib;
    vertexAttrib.addLayout<float>(2, false);

    VertexArray vertexArray;
    vertexArray.addBufferAndAttribute(buffer, sizeof(float) * 6, vertexAttrib);
    vertexArray.bind();

    Shader shader("Resources/shaders/vertex.shader", "Resources/shaders/fragment.shader");
    shader.bind();
    shader.setUniform4f("colors", 0.4f, 0.2f, 0.7f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
