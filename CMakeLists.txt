cmake_minimum_required(VERSION 3.17)
project(Pong)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE GLVND)

add_executable(Pong src/main.cpp src/Paddle.cpp src/Paddle.hpp src/Ball.cpp src/Ball.hpp src/Game.cpp src/Game.hpp)

target_compile_options(Pong PRIVATE -Wall)

# glad
include_directories(lib/glad/include)

# glfw
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(Pong PRIVATE glfw)

# glew
add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
target_link_libraries(Pong PRIVATE libglew_static)

# glm
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
target_link_libraries(Pong PRIVATE glm)
