cmake_minimum_required(VERSION 3.11)
project(MyProject)

set(FREEGLUT_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(FREEGLUT_REPLACE_GLUT ON CACHE BOOL "" FORCE)
set(FREEGLUT_BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(FREEGLUT_BUILD_STATIC_LIBS OFF CACHE BOOL "" FORCE)
set(FREEGLUT_DIR ${CMAKE_CURRENT_LIST_DIR}/extern/freeglut)

add_subdirectory(${FREEGLUT_DIR})

include_directories(${FREEGLUT_DIR}/include)
add_executable(MyProject
    src/callback.cpp
    src/main.cpp
)
target_link_libraries(MyProject PRIVATE freeglut)

# -----------------------------------------------
# Shipping the binary
# -----------------------------------------------
set(DIST_DIR ${CMAKE_BINARY_DIR}/dist)
add_custom_target(package ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DIST_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MyProject> ${DIST_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:freeglut> ${DIST_DIR}
    COMMENT "Creating runnable dist folder"
)
