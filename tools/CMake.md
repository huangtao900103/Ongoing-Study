1. cmake -G "Visual Studio 10 2010" ..

2. E:\vcpkg>vcpkg.exe integrate install
    >Applied user-wide integration for this vcpkg root.
    >
    >All MSBuild C++ projects can now #include any installed libraries.
    >Linking will be handled automatically.
    >Installing new libraries will make them instantly available.
    >
    >CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=e:/vcpkg/scripts/buildsystems/vcpkg.cmake"

3. Specify toolchain file

    - [CMake: specifying build toolchain](https://stackoverflow.com/questions/5098360/cmake-specifying-build-toolchain)
    - [CMAKE_TOOLCHAIN_FILE only recognized on command line](https://github.com/queezythegreat/arduino-cmake/issues/38)
    - [cmake : Set environment variables from a script](https://stackoverflow.com/questions/21047399/cmake-set-environment-variables-from-a-script)
    - [Cross Compiling](https://gitlab.kitware.com/cmake/community/wikis/doc/cmake/CrossCompiling)
