add_library(siddiqsoft INTERFACE)
target_include_directories(siddiqsoft INTERFACE "src/")

#target_sources(runonendlib INTERFACE src/RunOnEnd.hpp)
#include(GNUInstallDirs)
#target_include_directories(runonendlib INTERFACE "src")

#if(MSVC)
#  add_custom_target(runonendlib.headers SOURCES src/RunOnEnd.hpp)
#endif()

#target_include_directories(runonendlib INTERFACE "${PROJECT_SOURCE_DIR}/runonendlib")
#install(DIRECTORY "src/"
#		DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/siddiqsoft"
#		FILES_MATCHING PATTERN "*.hpp"
#)
