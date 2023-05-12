add_executable(Tests)

set(
  GEECORE_TESTS_SRC_FILES
    Exception.cpp
    SpecialMemberFunctions.cpp
)

source_group(
  TREE "${CMAKE_CURRENT_SOURCE_DIR}"
  FILES ${GEECORE_TESTS_SRC_FILES}
)

target_sources(
  Tests
    PRIVATE
      ${GEECORE_TESTS_SRC_FILES}
)

target_link_libraries(
  Tests
    PRIVATE
      GEEcore
      Catch2::Catch2WithMain
)
