cmake_minimum_required(VERSION 2.8)
project(ImacGL)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#find_package(SDL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
#find_package(EIGEN3 REQUIRED)


if(APPLE)
	include_directories(usr/local/include)
endif(APPLE)

include_directories(${SDL2_INCLUDE_DIRS})

#include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} #${GLEW_INCLUDE_DIR} glimac/include third-party/include third-party/include/imgui)

include_directories(
	${SDL2_INCLUDE_DIRS} 
	${OPENGL_INCLUDE_DIR} 
	${GLEW_INCLUDE_DIR}
	${EIGEN3_INCLUDE_DIR} 
	glimac/include 
	third-party/include 
	third-party/include/imgui
)

file(GLOB_RECURSE IMGUI_SOURCES third-party/include/imgui/*)
add_library(IMGUI STATIC ${IMGUI_SOURCES})

#set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} #${GLEW_LIBRARY} IMGUI)

set(ALL_LIBRARIES glimac ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} IMGUI)


add_subdirectory(glimac)

file(GLOB TP_DIRECTORIES "TP*")

foreach(TP ${TP_DIRECTORIES})
    add_subdirectory(${TP})
endforeach()