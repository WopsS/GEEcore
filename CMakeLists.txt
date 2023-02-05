cmake_minimum_required(VERSION 3.21)

project(
  GEEcore
  VERSION 0.1.0
  LANGUAGES CXX
)

# -----------------------------------------------------------------------------
# General configuration and variables
# -----------------------------------------------------------------------------
if(PROJECT_IS_TOP_LEVEL)
  if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
  elseif(CMAKE_CXX_STANDARD LESS 23)
    message(FATAL_ERROR "GEEcore requires C++23 or higher.")
  endif()

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

set(GEECORE_CMAKE_DIR "${PROJECT_SOURCE_DIR}/cmake")
set(GEECORE_CMAKE_TEMPLATES_DIR "${GEECORE_CMAKE_DIR}/templates")
set(GEECORE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/")

# -----------------------------------------------------------------------------
# Options
# -----------------------------------------------------------------------------
option(GEECORE_INSTALL "Generate the install target." ${PROJECT_IS_TOP_LEVEL})

if(PROJECT_IS_TOP_LEVEL)
  option(GEECORE_BUILD_TESTS "Build unit tests." ON)
  option(GEECORE_EXTRA_WARNINGS "Enable extra warnings." ON)
  option(GEECORE_TREAT_WARNINGS_AS_ERRORS "Treat compiler warnings as errors." OFF)
endif()

# -----------------------------------------------------------------------------
# Dependencies
# -----------------------------------------------------------------------------
include(cmake/ConfigureAndIncludeFmt.cmake)

if(GEECORE_BUILD_TESTS)
  include(cmake/ConfigureAndIncludeCatch2.cmake)
endif()

# -----------------------------------------------------------------------------
# Options related to compiler warnings related only to this project
# -----------------------------------------------------------------------------
if(GEECORE_EXTRA_WARNINGS)
  if(MSVC)
    add_compile_options(/W4)
  else()
    message(
      FATAL_ERROR
      "The compiler options to enable extra warnings is not known for \
      '${CMAKE_CXX_COMPILER_ID}'"
    )
  endif()
endif()

if(GEECORE_TREAT_WARNINGS_AS_ERRORS)
  if(MSVC)
    add_compile_options(/WX)
  else()
    message(
      FATAL_ERROR
      "The compiler option to treat warnings as errors is not known for \
      '${CMAKE_CXX_COMPILER_ID}'"
    )
  endif()
endif()

# -----------------------------------------------------------------------------
# Main library
# -----------------------------------------------------------------------------
add_library(GEEcore STATIC)
add_library(wopss::GEEcore ALIAS GEEcore)

set(
  GEECORE_HEADER_FILES
    include/geecore/geecore.hpp
)

set(
  GEECORE_SRC_FILES
    src/geecore.cpp
)

get_property(GEECORE_USE_FOLDERS GLOBAL PROPERTY USE_FOLDERS)
if(GEECORE_USE_FOLDERS)
  source_group(cmake REGULAR_EXPRESSION cmake_pch.*)

  source_group(
    TREE "${GEECORE_INCLUDE_DIR}/geecore"
    FILES ${GEECORE_HEADER_FILES}
  )

  source_group(
    TREE "${PROJECT_SOURCE_DIR}/src"
    FILES ${GEECORE_SRC_FILES}
  )
endif()

target_include_directories(
  GEEcore
    PUBLIC
      "$<BUILD_INTERFACE:${GEECORE_INCLUDE_DIR}>"
      "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_sources(
  GEEcore
    PRIVATE
      ${GEECORE_HEADER_FILES}
      ${GEECORE_SRC_FILES}
)

target_link_libraries(
  GEEcore
    PUBLIC
      fmt::fmt
)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
if(GEECORE_BUILD_TESTS)
  add_subdirectory(tests)
endif()

# -----------------------------------------------------------------------------
# Install
# -----------------------------------------------------------------------------
if(NOT CMAKE_SKIP_INSTALL_RULES)
  if(GEECORE_INSTALL)
    include(CMakePackageConfigHelpers)
    include(GNUInstallDirs)

    set(GEECORE_EXPORT_NAME GEEcore)
    set(GEECORE_EXPORT_TARGETS "${GEECORE_EXPORT_NAME}Targets")

    set(GEECORE_CMAKE_CONFIG_DIR "${PROJECT_BINARY_DIR}")

    set(GEECORE_CMAKE_PROJECT_CONFIG_FILE "${GEECORE_CMAKE_CONFIG_DIR}/${GEECORE_EXPORT_NAME}Config.cmake")
    set(GEECORE_CMAKE_PROJECT_CONFIG_FILE_IN "${GEECORE_CMAKE_TEMPLATES_DIR}/${GEECORE_EXPORT_NAME}Config.cmake.in")
    set(GEECORE_CMAKE_PROJECT_VERSION_FILE "${GEECORE_CMAKE_CONFIG_DIR}/${GEECORE_EXPORT_NAME}ConfigVersion.cmake")

    set(GEECORE_INSTALL_CONFIG_DIR "${CMAKE_INSTALL_DATADIR}/cmake/${GEECORE_EXPORT_NAME}")

    configure_package_config_file(
      "${GEECORE_CMAKE_PROJECT_CONFIG_FILE_IN}"
      "${GEECORE_CMAKE_PROJECT_CONFIG_FILE}"
      INSTALL_DESTINATION "${GEECORE_INSTALL_CONFIG_DIR}"
    )

    write_basic_package_version_file(
      "${GEECORE_CMAKE_PROJECT_VERSION_FILE}"
      VERSION ${PROJECT_VERSION}
      COMPATIBILITY ExactVersion
    )

    install(
      DIRECTORY "${GEECORE_INCLUDE_DIR}/"
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    )

    install(
      TARGETS GEEcore
      EXPORT ${GEECORE_EXPORT_TARGETS}
      INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
      PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
      LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    )

    install(
      FILES
        "${GEECORE_CMAKE_PROJECT_CONFIG_FILE}"
        "${GEECORE_CMAKE_PROJECT_VERSION_FILE}"
      DESTINATION "${GEECORE_INSTALL_CONFIG_DIR}"
    )

    install(
      EXPORT ${GEECORE_EXPORT_TARGETS}
      NAMESPACE wopss::
      DESTINATION "${GEECORE_INSTALL_CONFIG_DIR}"
    )

    # -------------------------------------------------------------------------
    # pkg-config
    # -------------------------------------------------------------------------
    set(GEECORE_PKG_CONFIG_FILE "${GEECORE_CMAKE_CONFIG_DIR}/${GEECORE_EXPORT_NAME}.pc")
    set(GEECORE_PKG_CONFIG_FILE_IN "${GEECORE_CMAKE_TEMPLATES_DIR}/${GEECORE_EXPORT_NAME}.pc.in")
    set(GEECORE_INSTALL_PKG_CONFIG_DIR "${GEECORE_INSTALL_CONFIG_DIR}/pkgconfig")

    if (IS_ABSOLUTE "${CMAKE_INSTALL_INCLUDEDIR}")
        set(GEECORE_PKG_CONFIG_INCLUDE_DIR "${CMAKE_INSTALL_INCLUDEDIR}")
    else()
        set(GEECORE_PKG_CONFIG_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
    endif()

    if (IS_ABSOLUTE "${CMAKE_INSTALL_LIBDIR}")
        set(GEECORE_PKG_CONFIG_LIB_DIR "${CMAKE_INSTALL_LIBDIR}")
    else()
        set(GEECORE_PKG_CONFIG_LIB_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
    endif()

    configure_file(
      "${GEECORE_PKG_CONFIG_FILE_IN}"
      "${GEECORE_PKG_CONFIG_FILE}"
      @ONLY
    )

    install(
      FILES "${GEECORE_PKG_CONFIG_FILE}"
      DESTINATION "${GEECORE_INSTALL_PKG_CONFIG_DIR}"
    )
  endif()
endif()
