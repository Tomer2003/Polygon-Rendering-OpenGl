cmake_minimum_required(VERSION 3.0.0)
project(tester VERSION 0.1.0)

include(CTest)
enable_testing()

set(_GLFW_WIN32 ON)



add_subdirectory(
    Resources/GLFW   
)

add_executable(tester main.cpp)
target_link_libraries(tester opengl32 glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
