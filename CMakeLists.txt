cmake_minimum_required (VERSION 3.3)

project (Ellog)

set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} /usr/include")

set (CMAKE_CXX_COMPILER "clang++")

set (CXXFLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -g -Wall")
set (CMAKE_CXX_FLAGS ${CXXFLAGS})
set (CMAKE_CXX_FLAGS_DEBUG ${CXXFLAGS})
set (CMAKE_CXX_FLAGS_RELEASE ${CXXFLAGS})

set (ELLOG_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set (ELLOG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (ELLOG_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

add_subdirectory (src)
add_subdirectory (test)
