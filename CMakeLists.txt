cmake_minimum_required(VERSION 3.10)

project(katas-cpp
        VERSION 0.0.0
        LANGUAGES CXX)

# Test Dependencies
Include(FetchContent)

# Catch2
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

# Targets

## Program
add_library(katas src/main.cpp)
target_compile_features(katas PRIVATE cxx_std_20)

## Tests
add_executable(tests tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_compile_features(tests PRIVATE cxx_std_20)

include(CTest)
include(Catch)
catch_discover_tests(tests)