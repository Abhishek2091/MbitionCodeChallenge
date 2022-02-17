cmake_minimum_required(VERSION 3.22.2)

set(CMAKE_CXX_STANDARD 17)

project ("IntentRecognizer")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

include_directories(src/include)

add_subdirectory(src)

add_subdirectory(tst)

add_subdirectory(lib/googletest)