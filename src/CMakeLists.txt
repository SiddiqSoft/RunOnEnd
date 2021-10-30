include_directories(
    .
)

set(runonend_SRCS
    RunOnEnd.hpp
)

message(STATUS "About to install files to destination..")
INSTALL(FILES
        RunOnEnd.hpp
        DESTINATION ${INCLUDE_INSTALL_DIR}/siddiqsoft
)

message(STATUS "Finished src..")