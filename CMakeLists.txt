cmake_minimum_required(VERSION 3.12)

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
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.[hc]pp)
add_library(katas ${SOURCE_FILES})
target_compile_features(katas PRIVATE cxx_std_20)
if(MSVC)
  target_compile_options(katas PRIVATE /W4 /WX)
else()
  target_compile_options(katas PRIVATE -Wall -Wextra -Wpedantic)
endif()

## Tests
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS tests/*.[hc]pp)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain katas)
target_compile_features(tests PRIVATE cxx_std_20)

include(CTest)
include(Catch)
catch_discover_tests(tests)