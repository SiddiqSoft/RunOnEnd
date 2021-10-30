#
# siddiqsoft RunOnEnd
# https://github.com/siddiqsoft/RunOnEnd
#

cmake_minimum_required(VERSION 3.10...3.21)
project("RunOnEnd"	VERSION         1.2.1
                    LANGUAGES       CXX
					DESCRIPTION     "Header only library for run on end of scope"
					HOMEPAGE_URL    "https://github.com/siddiqsoft/RunOnEnd")

include(GNUInstallDirs)

message(STATUS "${PROJECT_NAME} - add library..")
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

IF(BUILD_TESTING)
    message(STATUS "${PROJECT_NAME} - Testing enabled")
	enable_testing()
ENDIF(BUILD_TESTING)

message(STATUS "${PROJECT_NAME} - About to include src..")
add_subdirectory(src)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})


include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME})

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME})

IF(BUILD_TESTING)
    message(STATUS "${PROJECT_NAME} - Add the tests subdirectory.")
	add_subdirectory(tests)
ENDIF(BUILD_TESTING)

# Reference
# https://dominikberner.ch/cmake-interface-lib/
message(STATUS "${PROJECT_NAME} - Finish ${PROJECT_NAME} main file..")