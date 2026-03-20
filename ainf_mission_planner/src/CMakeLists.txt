# Sources set
LIST(APPEND SOURCES
  ../src/specificworker.cpp
)

# Headers set
LIST(APPEND HEADERS
  ../src/specificworker.h
  ../src/ollama.hpp
)

INCLUDE($ENV{ROBOCOMP}/cmake/modules/opencv4.cmake)
LIST(APPEND LIBS ${LIBS})
# no-char8_t to avoid a problem with ICE Connection lib.
add_definitions(-g -fmax-errors=1 -fno-char8_t)

