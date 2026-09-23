cmake_minimum_required(VERSION 4.3)

project(
    ghactiontests
    VERSION 0.0.1
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CPM)
include(helpers)

CPMAddPackage("gh:godotengine/godot-cpp#4.5")

list(APPEND CMAKE_MODULE_PATH "${godot-cpp_SOURCE_DIR}/cmake")
include(emsdkHack)
include(GodotCPPModule)

# Create the gen directory at configure time so IDEs can see generated headers immediately after generate_bindings
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/godot-cpp/gen/include")
set(GODOT_PROJECT_DIR "gdapp/addons/ghactiontests")


get_target_property(GODOTCPP_SUFFIX godot::cpp GODOTCPP_SUFFIX)
get_target_property(GODOTCPP_PLATFORM godot::cpp GODOTCPP_PLATFORM)

add_library(ghactiontests SHARED)
target_sources(ghactiontests
    PRIVATE
        src/cxx26test.cpp
        src/register_types.hpp
        src/register_types.cpp
        src/TestableThingy.hpp
)
target_compile_features(ghactiontests PRIVATE cxx_std_26)
target_link_libraries(ghactiontests PRIVATE godot::cpp)
if (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_link_libraries(ghactiontests PUBLIC stdc++exp) # std:: print, println, ...
endif()

set_target_properties(ghactiontests
    PROPERTIES
    # The generator expression here prevents msvc from adding a Debug or Release subdir.
    RUNTIME_OUTPUT_DIRECTORY "$<1:${PROJECT_SOURCE_DIR}/bin/${GODOTCPP_PLATFORM}>"

    PREFIX ""
    OUTPUT_NAME "ghactiontests${GODOTCPP_SUFFIX}"
)

set(GODOT_PROJECT_BINARY_DIR "${PROJECT_SOURCE_DIR}/${GODOT_PROJECT_DIR}/bin/${GODOTCPP_PLATFORM}")

add_custom_command(TARGET ghactiontests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:ghactiontests>" "${GODOT_PROJECT_BINARY_DIR}/$<TARGET_FILE_NAME:ghactiontests>"
)