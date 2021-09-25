//
// (C) 2021, E. Wes Bethel
// likwid_marker: simple example showing how to use the 
//  	LIKWID_MARKER API
// usage:
// 	likwid_marker  [sizeOfArray]
//

#include <iostream>
#include <likwid.h>
#include <likwid-marker.h>
#include <vector>
#include <algorithm>
#include <random>

int
main (int ac, char *av[])
{
    static char markerName[]="MyMarker";

    LIKWID_MARKER_INIT;

    LIKWID_MARKER_REGISTER(markerName);

    // set up to do some work: fill a vector with random numbers
    int N = 20;
    if (ac > 1)
        N = std::atoi(av[1]);
    std::cout << " Doing a problem of size N=" << N << std::endl;

    std::vector<int> v(N);

#if 0 // lame random number generator using srand() and rand()
    std::srand(42);
    std::generate(v.begin(), v.end(), std::rand);
#endif

#if 1 // better random number generate using c++11 random
    std::random_device rd;
    //std::default_random_engine eng(rd());
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(0, N-1);

    for (int i=0;i<N;i++)
        v[i] = distr(eng);

#endif

    if (N <= 20)
    {
        for (int i=0;i<N;i++)
            std::cout<<v[i]<<std::endl;
    }
    
    LIKWID_MARKER_START(markerName);

    // the work here is to call the sort function
    sort(v.begin(), v.end());

    LIKWID_MARKER_STOP(markerName);

    if (N <= 20)
    {
        for (int i=0;i<N;i++)
            std::cout<<v[i]<<std::endl;
    }
    
    LIKWID_MARKER_CLOSE;

    return 1;
}

