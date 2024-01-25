cmake_minimum_required(VERSION 3.11)
project(01_hello_window)

include(FetchContent)

FetchContent_Declare(
    freeglut
    GIT_REPOSITORY https://github.com/freeglut/freeglut
    GIT_TAG e3aa3d74f3c6a93b26fd66f81152d9c55506a6c6
)

FetchContent_GetProperties(freeglut)

if(NOT freeglut_POPULATED)
    FetchContent_Populate(freeglut)
    
    set(FREEGLUT_BUILD_DEMOS OFF)
    set(FREEGLUT_REPLACE_GLUT ON)    
    set(FREEGLUT_BUILD_SHARED_LIBS ON)
    set(FREEGLUT_BUILD_STATIC_LIBS OFF)

    add_subdirectory(${freeglut_SOURCE_DIR} ${freeglut_BINARY_DIR})
endif()

include_directories(${freeglut_SOURCE_DIR}/include)

add_executable(01_hello_window
    src/callback.cpp
    src/main.cpp
)

target_link_libraries(01_hello_window freeglut)

if(WIN32)
    target_link_libraries(01_hello_window opengl32)
    
    # Copy freeglut.dll to the executable directory
    add_custom_command(TARGET 01_hello_window POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:freeglut>
            $<TARGET_FILE_DIR:01_hello_window>
    )
else()
    target_link_libraries(01_hello_window GL)

    # Copy libglut.so to the executable directory
    add_custom_command(TARGET 01_hello_window POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:freeglut>
            $<TARGET_FILE_DIR:01_hello_window>
    )
endif()
