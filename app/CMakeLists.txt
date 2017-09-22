cmake_minimum_required(VERSION 3.4.1)

add_compile_options(-std=c++11)#指定使用 c++11

file(GLOB zero "src/main/cpp/*/*.cpp" "src/main/cpp/*/*.c")
file(GLOB first "src/main/cpp/*/*/*.cpp" "src/main/cpp/*/*/*.c")
file(GLOB sencond "src/main/cpp/*/*/*/*.cpp" "src/main/cpp/*/*/*/*.c")
file(GLOB third "src/main/cpp/*/*/*/*/*.cpp" "src/main/cpp/*/*/*/*/*.c")
file(GLOB forth "src/main/cpp/*/*/*/*/*/*.cpp" "src/main/cpp/*/*/*/*/*/*.c")

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             ${zero}
             ${first}
             ${sencond}
             ${third}
             ${forth}
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
