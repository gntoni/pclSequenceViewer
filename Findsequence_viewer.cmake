#edit the following line to add the librarie's header files
FIND_PATH(sequence_viewer_INCLUDE_DIR sequence_viewer.h /usr/include/iridrivers /usr/local/include/iridrivers)

FIND_LIBRARY(sequence_viewer_LIBRARY
    NAMES sequence_viewer
    PATHS /usr/lib /usr/local/lib /usr/local/lib/iridrivers) 

IF (sequence_viewer_INCLUDE_DIR AND sequence_viewer_LIBRARY)
   SET(sequence_viewer_FOUND TRUE)
ENDIF (sequence_viewer_INCLUDE_DIR AND sequence_viewer_LIBRARY)

IF (sequence_viewer_FOUND)
   IF (NOT sequence_viewer_FIND_QUIETLY)
      MESSAGE(STATUS "Found sequence_viewer: ${sequence_viewer_LIBRARY}")
   ENDIF (NOT sequence_viewer_FIND_QUIETLY)
ELSE (sequence_viewer_FOUND)
   IF (sequence_viewer_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find sequence_viewer")
   ENDIF (sequence_viewer_FIND_REQUIRED)
ENDIF (sequence_viewer_FOUND)
