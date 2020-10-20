#include <iostream>
#include "Resources/GLEW/include/GL/glew.h"
#include "Resources/GLFW/include/GLFW/glfw3.h"
#include "files_io.hpp"
#include "VertexAttribute.hpp"
#include "VertexArray.hpp"
#include "shader.hpp"
#include "error_handle.hpp"
#include "IndexBuffer.hpp"
#include "polygon_api.hpp"

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

  /* float buffer[] = {
		-0.5, -0.5, 
		-0.5, 0.5, 
		0.5, -0.5, 
        0.5, 0.5
	};

    unsigned int indexBufferData[] ={
        0, 1, 2,
        1, 2, 3
    };

    VertexBuffer vertexBuffer(buffer, sizeof(float) * 2 * 4);

    VertexAttribute vertexAttrib;
    vertexAttrib.addLayout<float>(2);

    VertexArray vertexArray;
    vertexArray.addBufferAndAttribute(vertexBuffer, vertexAttrib);
    vertexArray.bind();

    Shader shader("../../Resources/shaders/vertex.shader", "../../Resources/shaders/fragment.shader");
    shader.bind();
    shader.setUniform4f("colors", 0.4f, 0.2f, 0.7f, 1.0f);

    IndexBuffer indexBuffer(indexBufferData, 2 * 3 * sizeof(unsigned int));
    indexBuffer.bind();*/

    Polygon polygon;
    polygon.definePolygon(100, 0.7, 0.6, 0.7, 1.0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //GLCALL(glDrawArrays(GL_TRIANGLES, 0, 3));
        glDrawElements(GL_TRIANGLES, 3 * 100, GL_UNSIGNED_INT, 0);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
