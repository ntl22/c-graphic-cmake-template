cmake_minimum_required(VERSION 3.14)
project(cg_cmake_template)

add_executable(cg_cmake_template src/main.cpp)

include(cmake/CPM.cmake)

# You can set other folders to cache
# or comment this line to use default CPM cache folder
set(CPM_SOURCE_CACHE ${CMAKE_SOURCE_DIR}/cache/CPM)

CPMAddPackage(
  NAME glut
  GITHUB_REPOSITORY freeglut/freeglut
  GIT_TAG v3.4.0
  OPTIONS
    "FREEGLUT_BUILD_SHARED_LIBS OFF"
    "FREEGLUT_BUILD_STATIC_LIBS ON"
    "FREEGLUT_REPLACE_GLUT ON"
)

if(glut_ADDED)
    find_package(OpenGL REQUIRED)

    target_include_directories(cg_cmake_template PRIVATE ${glut_SOURCE_DIR}/include)
    target_include_directories(cg_cmake_template SYSTEM PRIVATE ${glut_SOURCE_DIR}/src)

    target_link_libraries(cg_cmake_template freeglut_static OpenGL::GL OpenGL::GLU)

    # Add flag on windows to hide console window
    if(WIN32)
        if(MINGW)
            target_link_options(cg_cmake_template PRIVATE -mwindows)
        elseif(MSVC)
            target_link_options(cg_cmake_template PRIVATE /SUBSYSTEM:WINDOWS)
        endif()
    endif()
endif()
