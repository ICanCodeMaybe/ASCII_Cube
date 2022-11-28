cmake_minimum_required(VERSION 3.18.1)
project(Cube)

set(CUBE_CPP src/main.cpp src/core.cpp src/renderer.cpp src/cubeMath.cpp)
set(CUBE_INCLUDE_DIR src/)

add_executable(${PROJECT_NAME} ${CUBE_CPP})
#target_include_directories(${PROJECT_NAME} PUBLIC ${CUBE_INCLUDE_DIR})
