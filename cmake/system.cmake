
#
# OS specific stuff -- feel free to move to other cmake/ files if something
# fits better.
#

# Linux
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  # timing library
  set(SPLATT_LIBS ${SPLATT_LIBS} rt)
endif()

# OSX
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  # Get homebrew's path prefix
  execute_process(
    COMMAND brew --prefix
    RESULT_VARIABLE brew_result
    OUTPUT_VARIABLE brew_prefix
  )

  # Add homebrew's include and lib directories to access argp
  if("${brew_result}" STREQUAL "0")
    string(STRIP ${brew_prefix} brew_prefix)
    include_directories(${brew_prefix}/include/)
    link_directories(${brew_prefix}/lib/)
    set(SPLATT_LIBS ${SPLATT_LIBS} argp)
  else()

    # Warn if homebrew isn't installed
    message(WARNING "`brew --prefix` failed with ${brew_result}.")
    message(WARNING "`homebrew` is not required, but argp.h and libargp must be found in include and lib paths.")
  endif()
endif()

