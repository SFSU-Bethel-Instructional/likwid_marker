//
// (C) 2021, E. Wes Bethel
// likwid_marker_omp: simple example showing how to use the 
//  	LIKWID_MARKER API
// usage:
// 	likwid_marker_omp
//

#include <iostream>
#include <likwid.h>
#include <vector>
#include <algorithm>
#include <random>
#include <omp.h>
#include <unistd.h>

#define MY_MARKER_REGION_NAME "Rip_van_Winkle_Region"

int
main (int ac, char *av[])
{
    static char markerName[]="MyMarker";

    int sleep_duration_sec = 2;

    LIKWID_MARKER_INIT;


#pragma omp parallel
    {
       // ID of the thread in the current team
      int thread_id = omp_get_thread_num();
      // Number of threads in the current team
      int nthreads = omp_get_num_threads();

#pragma omp critical
      {
         std::cout << "Hello world, I'm thread " << thread_id << " out of " << nthreads << " total threads. " << std::endl;
      }

       // Each thread must add itself to the Marker API, therefore must be
       // in parallel region
       LIKWID_MARKER_THREADINIT;
       // Register region name
       LIKWID_MARKER_REGISTER(MY_MARKER_REGION_NAME);
    }

    // with LIKWID's marker api and parallel code, it is permissible to
    // register the marker in a section of parallel code, then start/stop
    // the marker region in a later section of parallel code

    std::cout << "Hello from a serial code section in main() " << std::endl; 

#pragma omp parallel
    {
      LIKWID_MARKER_START(MY_MARKER_REGION_NAME);

      sleep(sleep_duration_sec);   

      LIKWID_MARKER_STOP(MY_MARKER_REGION_NAME);
    }

    LIKWID_MARKER_CLOSE;

    return 0;
}

