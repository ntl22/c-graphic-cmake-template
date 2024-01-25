# Template for using freeglut

To use this repo, use CMake 3.11+

Step 1: Init a project

```{bash}
cmake -G <Generators> -S . -B build
```
`Generators` can be:
- mingw: MinGW Makefiles
- MSVC: NMake Makefiles, or Visual Studio generator
- Cross-platform: Ninja (please install it first)

Step 2: Check the .vscode folder

Check the following lines:

```{json}
"includePath": [
    "${workspaceFolder}/**",
    "${workspaceFolder}/build/_deps/freeglut-src"
],
```

The 3rd line is the path foe freeglut used for VSCode Intellisence.

The path can be differ between operating systems.

Step 3: Build the project

```
# In the build folder
cmake --build .
```

After that, the project with the name `01_hello_window` will appear.

> [!NOTE]
> This project is only tested on Windows but some code for MacOS/Linux is added. If you find a bug in the build process, please issue the problem in the repo.
