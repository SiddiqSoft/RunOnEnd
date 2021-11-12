cmake_minimum_required(VERSION 3.21)
include(FindGit)
include(ExternalProject)
include(FetchContent)
find_package(Git REQUIRED)

project(basic_tests CXX)

# Set the flag for MSVC to static link to MSVCRT
set_property(TARGET ${PROJEC_NAME} PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  
message(STATUS "${PROJECT_NAME} - Started")

enable_testing()
set(CMAKE_CXX_STANDARD 20)
if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.12.25835)
    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
endif()

set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "")

message(STATUS "${PROJECT_NAME} - About to get googletest..")
FetchContent_Declare(googletest
                    GIT_REPOSITORY  "https://github.com/google/googletest"
                    GIT_TAG         "release-1.11.0"
                    GIT_SHALLOW     TRUE
                    GIT_PROGRESS    TRUE)

message(STATUS "${PROJECT_NAME} - Download googletest..")
FetchContent_MakeAvailable(googletest)

message(STATUS "${PROJECT_NAME} - Completed googletest..")
message(STATUS "${PROJECT_NAME} - googletest source_dir: ${googletest_SOURCE_DIR}")
message(STATUS "${PROJECT_NAME} - googletest binary_dir: ${googletest_BINARY_DIR}")
message(STATUS "${PROJECT_NAME} - googletest populated: ${googletest_POPULATED}")

add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
add_test(${PROJECT_NAME} tests COMMAND test)
