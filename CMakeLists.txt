add_library(runonendlib INTERFACE)
target_sources(runonendlib INTERFACE src/RunOnEnd.hpp)

target_include_directories(runonendlib INTERFACE "${PROJECT_SOURCE_DIR}/runonendlib")

add_library(runonendlib INTERFACE)
if(MSVC)
  add_custom_target(runonendlib.headers SOURCES RunOnEnd.hpp)
endif()

target_include_directories(runonendlib INTERFACE "${PROJECT_SOURCE_DIR}/runonendlib")
