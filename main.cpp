#include <iostream>
#include "Resources/GLEW/include/GL/glew.h"
#include "Resources/GLFW/include/GLFW/glfw3.h"
#include "api_files/polygon_api.hpp"

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

    Polygon polygon;
    polygon.bindPolygon(3, 0.7, 0.6, 0.7, 1.0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //GLCALL(glDrawArrays(GL_TRIANGLES, 0, 3));
        glDrawElements(GL_TRIANGLES, 3 * 3, GL_UNSIGNED_INT, 0);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
