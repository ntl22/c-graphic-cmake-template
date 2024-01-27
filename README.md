# Template for using freeglut

To use this repo, use CMake 3.11+

Step 1: Init a project

```{bash}
cmake -G <Generators> -S . -B build
```

Step 2: Run the `cg_cmake_template` file in the build folder.

> [!NOTE]
> This branch is tested on MinGW64 with GL installed. Please write an issue for other platforms

In line 10 of `CMakeLists.txt`:

```
set(CPM_SOURCE_CACHE ${CMAKE_SOURCE_DIR}/cache/CPM)
```

`CPM_SOURCE_CACHE` can be overwritten as you like, or can be hidden for the default path (in `build` folder).

**References**
- https://github.com/cpm-cmake/CPM.cmake
