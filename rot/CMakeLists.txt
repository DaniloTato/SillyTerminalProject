cmake_minimum_required(VERSION 3.20)

project(ROT LANGUAGES CXX)

add_library(ROT STATIC
    src/ASCIITexture.cpp
    src/Color.cpp
    src/TerminalWindow.cpp
    src/Text.cpp
)

target_include_directories(ROT
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(ROT PUBLIC cxx_std_20)

target_compile_options(ROT PRIVATE
    -Wall
    -Wextra
)