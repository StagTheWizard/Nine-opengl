cmake_minimum_required(VERSION 3.6)

project(Nine)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(deps/glfw)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(deps/assimp)


# -------------------------------------------------------------------------------------------------------------------- #
#
# -------------------------------------------------------------------------------------------------------------------- #
set(CMAKE_CXX_STANDARD 11)

if (NOT EXISTS ${CMAKE_SOURCE_DIR}/build/)
    execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/build/)
endif()

# -------------------------------------------------------------------------------------------------------------------- #
#
# -------------------------------------------------------------------------------------------------------------------- #
include_directories(
        include/
        deps/assimp/include/
        deps/glad/include/
        deps/glfw/include/
        deps/glm/
        deps/freetype/include
)

file(GLOB DEPS_SOURCES
        deps/glad/src/glad.c)
file(GLOB PROJECT_HEADERS
        include/Launcher.h
        include/core/Engine.h
        include/core/State.h
        include/core/IntroState.h
        include/core/Constants.h
        include/core/Camera.h
        )
file(GLOB PROJECT_SOURCES
        src/Launcher.cpp
        src/core/Engine.cpp
        src/core/IntroState.cpp
        src/core/Constants.cpp
        src/core/Camera.cpp
        )
file(GLOB PROJECT_SHADERS
        src/shaders/*.vert
        src/shaders/*.tesc
        src/shaders/*.tese
        src/shaders/*.geom
        src/shaders/*.frag)

file(GLOB PROJECT_CONFIGS
        CMakeLists.txt
        README.md
        .gitignore
        .gitmodules)

source_group("include" FILES ${PROJECT_HEADERS})
source_group("shaders" FILES ${PROJECT_SHADERS})
source_group("src" FILES ${PROJECT_SOURCES})
source_group("deps" FILES ${DEPS_SOURCES})

#add_definitions(-D GLFW_INCLUDE_NONE -D PROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_SHADERS}
        ${PROJECT_CONFIGS}
        ${DEPS_SOURCES})

#message("Locating glfw3...")
#find_package(glfw3 REQUIRED)
#include_directories(${glfw3_INCLUDE_DIRS})
#link_directories(${glfw3_LIBRARY_DIRS})
#add_definitions(${glfw3_DEFINITIONS})
#if (NOT glfw3_FOUND)
#    message(ERROR " ...glfw3 not found!")
#else(glfw3_FOUND)
#    message("...glfw3 found! @ " ${glfw3_LIBRARY_DIRS})
#endif(NOT glfw3_FOUND)


target_link_libraries(${PROJECT_NAME}
        glfw
        assimp
        freetype
        ${GLFW_LIBRARIES}
        )

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
