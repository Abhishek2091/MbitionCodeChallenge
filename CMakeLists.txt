cmake_minimum_required(VERSION 3.22.2)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_COMPILER "C:/Program Files/CodeBlocks/MinGW/bin/gcc")
#set(CMAKE_CXX_COMPILER "C:/Program Files/CodeBlocks/MinGW/bin/g++")

project ("IntentRecognizer")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(IntentRecognizer ${SOURCES})