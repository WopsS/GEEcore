add_executable(Tests)

set(
  GEECORE_TESTS_HEADER_FILES
    mocks/MockMsgBoxDriver.hpp
)

set(
  GEECORE_TESTS_SRC_FILES
    Exception.cpp
    exceptions/Win32Exception.cpp

    SpecialMemberFunctions.cpp

    detail/BaseMsgBox.cpp
    detail/BasicMsgBoxExceptionless.cpp
)

source_group(
  TREE "${CMAKE_CURRENT_SOURCE_DIR}"
  FILES ${GEECORE_TESTS_HEADER_FILES}
)

source_group(
  TREE "${CMAKE_CURRENT_SOURCE_DIR}"
  FILES ${GEECORE_TESTS_SRC_FILES}
)

target_include_directories(
  Tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(
  Tests
    PRIVATE
      ${GEECORE_TESTS_HEADER_FILES}
      ${GEECORE_TESTS_SRC_FILES}
)

target_link_libraries(
  Tests
    PRIVATE
      GEEcore
      Catch2::Catch2WithMain
      trompeloeil::trompeloeil
)
