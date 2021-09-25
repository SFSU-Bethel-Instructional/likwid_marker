# likwid_marker

This repository contains two codes that demonstrate use of LIKWID's Marker API.

More information: 
* LIKWID : https://github.com/RRZE-HPC/likwid/wiki
* LIKWID's Marker API: https://github.com/RRZE-HPC/likwid/wiki/LikwidAPI-and-MarkerAPI
* Examples showing C++ usage of LIKWID's Marker API, including from OpenMP: https://github.com/RRZE-HPC/likwid/wiki/TutorialMarkerC


## likwid_marker

This serial code uses the LIKWID Marker API to surround a block of code that does a sorting operation.

Command line usage: likwid_marker  [sizeOfArray]

## likwid_marker_omp

This OpenMP code uses the LIKWID Marker API to surround a code block that executes a sleep(2) call.

Command line usage: likwid_marker_omp

## Use with likwid-perfctr

For the serial code:  
   likwid-perfctr -g FLOPS_DP -C N:0 ./likwid_marker 100000

For the omp code:  
   likwid-perfctr -g FLOPS_DP -C N:0-3 ./likwid_marker_omp


## building the code

CMAKE_PREFIX_PATH needs to point to the directory where LIKWID is installed, under which 
there is a [.../]likwid-config.cmake file

From the main likwid_marker directory:
* mkdir build
* cd build
* cmake ../
* make

Then run the codes as indicated above.

# eof

