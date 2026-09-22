cmake_minimum_required(VERSION 4.3)

project(
    ghactiontests
    VERSION 0.0.1
    LANGUAGES CXX
)

add_executable(ghactiontests src/main.cpp)
target_compile_features(ghactiontests PRIVATE cxx_std_26)