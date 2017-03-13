cmake_minimum_required (VERSION 2.8.8)
project (arduino_mock)

find_package(Threads REQUIRED)
add_subdirectory(lib/gtest)

message ("building arduino_mock")
message("Gtest include: ${GTEST_INCLUDE_DIRS}")
message("Gmock include: ${GMOCK_INCLUDE_DIRS}")
include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} include)
file(GLOB SRC
    "src/ArduinoMockAll.cc"
)

add_library(arduino_mock STATIC ${SRC})

target_include_directories(arduino_mock
    PUBLIC "include"
)

target_link_libraries(arduino_mock
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GMOCK_LIBS_DIR}/libgmock.a
    ${CMAKE_THREAD_LIBS_INIT}
)

set_target_properties( arduino_mock
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)

add_dependencies(arduino_mock gtest)

option(test "Build all tests." OFF)

if (test)
  enable_testing()
  add_subdirectory(test)
endif()
