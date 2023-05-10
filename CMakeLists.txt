# Minimum version
cmake_minimum_required(VERSION 3.20)

set (CMAKE_CXX_STANDARD 20)

# Project settings 
project(
    Gonflux
    VERSION 1.0
    LANGUAGES CXX 
)

# name of executable would be flux 
add_executable(flux src/main.cpp src/lexer.cpp src/ast.cpp src/file.cpp src/parser.cpp)
