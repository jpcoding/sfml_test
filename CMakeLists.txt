cmake_minimum_required(VERSION 3.15)

project(SFML_TESTS
    VERSION 1.0.0
    DESCRIPTION "SFML examples and tests"
    LANGUAGES CXX
)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)


find_package(SFML  COMPONENTS graphics audio REQUIRED)

add_subdirectory(tests)


