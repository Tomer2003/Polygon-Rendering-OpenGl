cmake_minimum_required(VERSION 3.0.0)
project(tester VERSION 0.1.0)

include(CTest)
enable_testing()



add_subdirectory(
    Resources/GLEW/build/cmake
)

add_subdirectory(
    Resources/GLFW   
)

add_executable(tester main.cpp files_io.cpp vertexAttribute.cpp VertexBuffer.cpp VertexArray.cpp opengl_types.cpp shader.cpp error_handle.cpp IndexBuffer.cpp)
target_link_libraries(tester opengl32 glfw glew_s)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
