cmake_minimum_required(VERSION 3.25)

project(fast_advent)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_RELEASE "-O3")
add_subdirectory(lib)
add_subdirectory(challenges)
