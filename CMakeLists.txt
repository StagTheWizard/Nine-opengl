cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME Nine)
project(${PROJECT_NAME})

# -------------------------------------------------------------------------------------------------------------------- #
#
# -------------------------------------------------------------------------------------------------------------------- #
set(CMAKE_CXX_STANDARD 11)

# -------------------------------------------------------------------------------------------------------------------- #
# DEPENDENCIES
# -------------------------------------------------------------------------------------------------------------------- #
# OpenGL
#message("Locating OpenGL...")
find_package(OpenGL REQUIRED)
#include_directories(${OpenGL_INCLUDE_DIRS})
#link_directories(${OpenGL_LIBRARY_DIRS})
#add_definitions(${OpenGL_DEFINITIONS})
#if (NOT OpenGL_FOUND)
#    message(ERROR " ...OpenGL not found!")
#else(OpenGL_FOUND)
#    message("...OpenGL found!")
#endif(NOT OpenGL_FOUND)
# glad
#set(glad_INCLUDE ${PROJECT_SOURCE_DIR}/dependencies/glad/include)
#set(glad_SOURCE ${PROJECT_SOURCE_DIR}/dependencies/glad/src)
#include_directories(${glad_INCLUDE} ${glad_SOURCE})
# GLFW
message("Locating GLFW...")
find_package(glfw3 3.2 REQUIRED)
include_directories(${glfw3_INCLUDE_DIRS})
link_directories(${glfw3_LIBRARY_DIRS})
add_definitions(${glfw3_DEFINITIONS})
if (NOT glfw3_FOUND)
    message(ERROR " ...GLFW not found!")
else(glfw3_FOUND)
    message("...GLFW found!")
endif(NOT glfw3_FOUND)

include_directories(dependencies/glad)

# -------------------------------------------------------------------------------------------------------------------- #
#
# -------------------------------------------------------------------------------------------------------------------- #
set(HEADER_FILES
        include/Launcher.h
        )

set(SOURCE_FILES
        src/Launcher.cpp
        )

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})