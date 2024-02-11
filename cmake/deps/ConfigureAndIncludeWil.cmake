option(WIL_BUILD_PACKAGING "" OFF)
option(WIL_BUILD_TESTS "" OFF)

if(GEECORE_INSTALL)
  add_subdirectory(deps/wil)
else()
  # Exclude this library from "install" since it doesn't have an INSTALL flag.
  add_subdirectory(deps/wil EXCLUDE_FROM_ALL)
endif()

mark_as_advanced(
  FAST_BUILD
  WIL_BUILD_PACKAGING
  WIL_BUILD_TESTS
)
