# create an example application
ADD_EXECUTABLE(sequence_viewer_test sequence_viewer_test.cpp)
# link necessary libraries
TARGET_LINK_LIBRARIES(sequence_viewer_test sequence_viewer)
