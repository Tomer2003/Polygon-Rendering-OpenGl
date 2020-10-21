cmake_minimum_required(VERSION 3.0.0)
project(tester VERSION 0.1.0)

include(CTest)
enable_testing()



add_subdirectory(
    Resources/GLEW/build/cmake
)

add_library(tester src/files_io.cpp src/vertexAttribute.cpp src/VertexBuffer.cpp src/VertexArray.cpp src/opengl_types.cpp src/shader.cpp src/IndexBuffer.cpp api_files/polygon_api.cpp)
target_link_libraries(tester opengl32 glfw glew_s)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
