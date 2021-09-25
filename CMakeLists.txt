project ( likwid_marker LANGUAGES CXX )

cmake_minimum_required( VERSION 3.0 )

find_package ( LIKWID REQUIRED )

# use cmake --log-level=debug to see DEBUG messages
if ( LIKWID_FOUND )
   message ( STATUS "Likwid: found")
else()
   message( STATUS  "Likwid: NOT found")
endif()


include_directories(${LIKWID_INCLUDES})

add_executable (likwid_marker likwid_marker.cpp)

add_executable (likwid_marker_omp likwid_marker_omp.cpp)
target_compile_options (likwid_marker_omp PRIVATE -fopenmp)
target_link_options (likwid_marker_omp PRIVATE -fopenmp)
if ( LIKWID_FOUND )
   target_include_directories(likwid_marker_omp PRIVATE ${LIKWID_INCLUDE_DIR})
   target_compile_definitions(likwid_marker_omp PRIVATE -DLIKWID_PERFMON)
   target_link_libraries(likwid_marker_omp PRIVATE ${LIKWID_LIBRARIES})
endif()

target_link_libraries( likwid_marker ${LIKWID_LIBRARIES} )

set (CMAKE_CXX_FLAGS "-DLIKWID_PERFMON")

