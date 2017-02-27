cmake_minimum_required(VERSION 3.4.1)

file(GLOB study_srcs "src/main/cpp/runoob/study/*.cpp" "src/main/cpp/runoob/study/*.c")
file(GLOB test_srcs "src/main/cpp/runoob/test/*.cpp" "src/main/cpp/runoob/test/*.c")
file(GLOB point_srcs "src/main/cpp/runoob/point/*.cpp" "src/main/cpp/runoob/point/*.c")
file(GLOB enter_file "src/main/cpp/*.cpp")
file(GLOB _20140807 "src/main/cpp/02CPP/_20140807/*.cpp" "src/main/cpp/02CPP/_20140807/*.cpp")

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             ${study_srcs}
             ${test_srcs}
             ${point_srcs}
             ${_20140807})

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
