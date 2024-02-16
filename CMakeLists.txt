cmake_minimum_required(VERSION 3.20)
project(Curves) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET( CMAKE_CXX_FLAGS_DEBUG  "-g")

add_executable(curv
    src/main.cpp
)
add_library(curves SHARED
    include/curve.h
    include/curves.h
    include/circle.h
    src/circle.cpp
    include/elipse.h
    src/elipse.cpp
    include/helix.h
    src/helix.cpp
)


target_include_directories(curves PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(curv PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package(OpenMP REQUIRED)
target_link_libraries(curv curves OpenMP::OpenMP_CXX)

