include_directories(
    .
)

set(runonend_SRCS
    RunOnEnd.hpp
)

INSTALL(FILES
        RunOnEnd.hpp
        DESTINATION ${INCLUDE_INSTALL_DIR}/siddiqsoft
)

