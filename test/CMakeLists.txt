option (ELLOG_BUILD_TESTS "Determines whether to build tests." ON)
if (ELLOG_BUILD_TESTS)
    enable_testing()

    add_library (Catch INTERFACE)
    find_path (libcatch_DIR catch.hpp)
    target_include_directories (Catch INTERFACE ${libcatch_DIR})

    add_library (Ellog INTERFACE)
    target_include_directories (Ellog INTERFACE ${ELLOG_SOURCE_DIR})

    FILE(GLOB_RECURSE ELLOG_SOURCES ${ELLOG_SOURCE_DIR}/*.cc)
    set (ELLOG_TEST_SOURCES
        ${ELLOG_TEST_DIR}/test-stdout.cc
        ${ELLOG_SOURCES}
    )

    add_executable (ellogtest ${ELLOG_TEST_SOURCES})
    target_link_libraries (ellogtest Catch)
    target_link_libraries (ellogtest Ellog)
    add_test (NAME EllogTest COMMAND ellogtest)
endif()
