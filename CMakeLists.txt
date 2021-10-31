#
# siddiqsoft RunOnEnd
# https://github.com/siddiqsoft/RunOnEnd
#

cmake_minimum_required(VERSION 3.20)

project(RunOnEnd
		VERSION         1.2.1
        LANGUAGES       CXX
		DESCRIPTION     "Header only library for run on end of scope"
		HOMEPAGE_URL    "https://github.com/siddiqsoft/RunOnEnd")

include(GNUInstallDirs)

message(STATUS "${PROJECT_NAME} - add library..`${CMAKE_CURRENT_SOURCE_DIR}`")
add_library( ${PROJECT_NAME} INTERFACE )

target_sources( ${PROJECT_NAME}
				PRIVATE "tests/test.cpp"
				PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/siddiqsoft/RunOnEnd.hpp")

target_include_directories( ${PROJECT_NAME} INTERFACE include/)