# locate the necessary dependencies
# add the necessary include directories
find_package(PCL 1.3 REQUIRED)

INCLUDE_DIRECTORIES(${PCL_INCLUDE_DIRS} 
                    /usr/local/include 
                    ../include
                    .
                   )

# driver source files
SET(sources pcl_sequence_viewer.cpp)

# application header files
SET(headers pcl_sequence_viewer.h)

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# create the shared library
ADD_LIBRARY(sequence_viewer SHARED ${sources})

# link necessary libraries
target_link_libraries(sequence_viewer 
                         ${PCL_LIBRARIES}
                     )

INSTALL(TARGETS sequence_viewer
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
INSTALL(FILES ../include/${headers} DESTINATION include/TGdrivers)
INSTALL(FILES ../Findsequence_viewer.cmake DESTINATION ${CMAKE_ROOT}/Modules/)

ADD_SUBDIRECTORY(examples)
