enable_testing()

FetchContent_Declare(googletest
                    GIT_REPOSITORY  "https://github.com/google/googletest"
                    GIT_TAG         "release-1.11.0"
)

FetchContent_MakeAvailable(googletest)

include_directories(. ../src ${googletest_INCLUDE_DIR})

add_executable(basic_tests test.cpp)
target_link_libraries(basic_tests PRIVATE ${LIBS} GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
add_test(basic_tests ${TEST_PATH}/basic_tests)
