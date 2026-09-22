cmake_minimum_required(VERSION 4.3)

set(GHAT_FINAL_OUTPUT "test.so" CACHE STRING "The output file named correctly")

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

add_custom_command(TARGET ghactiontests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:ghactiontests>" "${GHAT_FINAL_OUTPUT}"
)