#
# siddiqsoft RunOnEnd
# https://github.com/siddiqsoft/RunOnEnd
#

cmake_minimum_required(VERSION 3.21)

project(RunOnEnd
		VERSION         $ENV{GV}
        LANGUAGES       CXX
		DESCRIPTION     "Header only library for run on end of scope"
		HOMEPAGE_URL    "https://github.com/siddiqsoft/RunOnEnd")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)


##
## MAIN_PROJECT CHECK
## determine if nlohmann_json is built as a subproject (using add_subdirectory) or if it is the main project
##
set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

option(RunOnEnd_BuildTests          "Build the unit tests when BUILD_TESTING is enabled." ${MAIN_PROJECT})
option(RunOnEnd_Install             "Install CMake targets during install step." ${MAIN_PROJECT})

include(ExternalProject)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

message(STATUS "${PROJECT_NAME} - add library v`$ENV{GV}`..`${CMAKE_CURRENT_SOURCE_DIR}`")
add_library( ${PROJECT_NAME} INTERFACE )

target_sources( ${PROJECT_NAME}
				PRIVATE "tests/test.cpp"
				PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/siddiqsoft/RunOnEnd.hpp")

target_include_directories( ${PROJECT_NAME} INTERFACE include/)

##
## TESTS
## create and configure the unit test target
##
if (RunOnEnd_BuildTests)
    message(STATUS "${PROJECT_NAME} - run tests..")
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
