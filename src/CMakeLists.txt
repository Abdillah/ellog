file (GLOB_RECURSE ELLOG_SOURCES ${ELLOG_SOURCE_DIR}/*.cc)
add_library (ellog STATIC ${ELLOG_SOURCES})
install (FILES Log.hh DESTINATION include)
install (TARGETS ellog ARCHIVE DESTINATION lib)
