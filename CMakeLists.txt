# Minimum version
cmake_minimum_required(VERSION 3.25)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set (CMAKE_CXX_STANDARD 20)
endif()

# Project settings 
project(
    Gonflux
    VERSION 0.1.0
    DESCRIPTION ""
    LANGUAGES CXX 
)

# Using g++ for now
set (CMAKE_CXX_COMPILER /usr/bin/g++)

# look at testing 
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

#set (CMAKE_CXX_FLAGS "-o2")

# target_compile_options(./build/flux PRIVATE -o3)

# name of executable would be flux 
add_executable(flux src/main.cpp src/lexer.cpp src/ast.cpp src/file.cpp src/parser.cpp)
