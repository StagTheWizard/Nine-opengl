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

add_subdirectory(deps/sfml)

# -------------------------------------------------------------------------------------------------------------------- #
#
# -------------------------------------------------------------------------------------------------------------------- #
set(CMAKE_CXX_STANDARD 11)

if (NOT EXISTS ${CMAKE_SOURCE_DIR}/build/)
    execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/build/)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/)

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
        deps/sfml/include
)

file(GLOB DEPS_SOURCES
        deps/glad/src/glad.c)
file(GLOB PROJECT_HEADERS
        include/Launcher.h

        include/core/Engine.h
        include/core/EngineRenderer.h

        include/core/TextRenderModule.h

        include/core/structs/FontData.h
        include/core/structs/FontChar.h
        include/core/structs/FontTextureAtlas.h

        include/core/State.h
        include/core/IntroState.h
        include/core/Constants.h
        include/core/Camera.h

        include/core/shaders/ShaderProgram.h
        include/core/shaders/TextShaderProgram.h

        include/core/libs/textlib.h
        include/core/libs/filelib.h
        )
file(GLOB PROJECT_SOURCES
        src/Launcher.cpp

        src/core/Engine.cpp
        src/core/EngineRenderer.cpp

        src/core/TextRenderModule.cpp

        src/core/structs/FontTextureAtlas.cpp

        src/core/IntroState.cpp
        src/core/Constants.cpp
        src/core/Camera.cpp

        src/core/shaders/ShaderProgram.cpp
        src/core/shaders/TextShaderProgram.cpp

        src/core/libs/textlib.cpp
        src/core/libs/filelib.cpp
        )
set(PROJECT_SHADERS
        ../../CLionProjects/Reclaimer/shaders/Text.vert
        ../../CLionProjects/Reclaimer/shaders/Text.frag
#        shaders/*.vert
#        shaders/*.tesc
#        shaders/*.tese
#        shaders/*.geom
#        shaders/*.frag
        )
set(PROJECT_ASSETS
        ../../CLionProjects/Reclaimer/assets/fonts/Menlo-Regular.ttf)

file(GLOB PROJECT_CONFIGS
        CMakeLists.txt
        README.md
        .gitignore
        .gitmodules)

source_group("include" FILES ${PROJECT_HEADERS})
source_group("shaders" FILES ${PROJECT_SHADERS})
source_group("src" FILES ${PROJECT_SOURCES})
source_group("deps" FILES ${DEPS_SOURCES})
source_group("assets" FILES ${PROJECT_ASSETS})

# Copy all the resources into the bin
set(PROJECT_RESOURCES ${PROJECT_SHADERS} ${PROJECT_ASSETS})
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
    foreach(item IN LISTS PROJECT_RESOURCES)
        add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
        )
        message(STATUS "COPYING " ${item})
        message(STATUS "from " "${CMAKE_CURRENT_SOURCE_DIR}/${item}" " to " "${CMAKE_CURRENT_BINARY_DIR}/${item}")
    endforeach()
endif()

add_custom_target(data-target ALL DEPENDS ${PROJECT_RESOURCES})

add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_SHADERS}
        ${PROJECT_ASSETS}
        ${PROJECT_CONFIGS}
        ${DEPS_SOURCES})

target_link_libraries(${PROJECT_NAME}
        glfw
        assimp
        freetype
        ${GLFW_LIBRARIES}
        )

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
