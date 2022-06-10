# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\minesweeperqt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\minesweeperqt_autogen.dir\\ParseCache.txt"
  "minesweeperqt_autogen"
  )
endif()
