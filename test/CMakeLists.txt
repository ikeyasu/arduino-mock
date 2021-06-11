message ("building tests for Arduino Mock")
# include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB SRCS *.cc)

add_executable(test_all test_all.cc)

target_link_libraries(test_all
    arduino_mock
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    ${GMOCK_LIBS_DIR}/libgmock.a
    ${GMOCK_LIBS_DIR}/libgmock_main.a
    ${CMAKE_THREAD_LIBS_INIT}
)

add_dependencies(test_all gtest)
add_test(arduino_mock_test test_all)
