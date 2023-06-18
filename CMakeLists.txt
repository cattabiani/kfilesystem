cmake_minimum_required(VERSION 3.22.1)
project(kfilesystem)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC
     "src/*.hpp"
     "src/*.cpp"
)



add_executable(kfilesystem  main.cpp ${SRC})
