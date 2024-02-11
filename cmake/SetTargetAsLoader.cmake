# geecore_set_target_as_loader(TARGET)
#
# Configures a given target to act as a loader by generating a .def file from a
# template and adding it to the target's sources.
# The .def file contains the exports that the loader should provide.
#
# Parameters:
#   TARGET - The target for which to set as loader.
#
# Usage:
#   geecore_set_target_as_loader(MyTarget)
function(geecore_set_target_as_loader TARGET)
  set(FILE_NAME "GEEcore.def")
  set(TEMPLATES_DIR "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/templates")
  set(OUTPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}")

  configure_file(
    "${TEMPLATES_DIR}/${FILE_NAME}.in"
    "${OUTPUT_FILE}"
    @ONLY
  )

  target_sources(
    ${TARGET}
      PRIVATE
        "${OUTPUT_FILE}"
  )
endfunction()
