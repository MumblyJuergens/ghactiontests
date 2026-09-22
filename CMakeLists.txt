cmake_minimum_required(VERSION 4.3)

project(
    ghactiontests
    VERSION 0.0.1
    LANGUAGES CXX
)

add_library(ghactiontests SHARED)
target_sources(ghactiontests
    PRIVATE
        src/main.cpp
)
target_compile_features(ghactiontests PRIVATE cxx_std_26)
if (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_link_libraries(ghactiontests PUBLIC stdc++exp) # std:: print, println, ...
endif()
