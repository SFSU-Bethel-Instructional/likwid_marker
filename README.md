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

## Run codes with likwid-perfctr to obtain h/w perf ctd data

First, [set up your environment on Perlmutter to use LIKWID.](#envSetup)

Then, [salloc a Perlmutter CPU node with performance counters enabled.](#sallocNode)


Then, run the codes:

* The serial code:
```
likwid-perfctr -g FLOPS_DP -C N:0 ./likwid_marker 100000
```

* The omp code:  
```
likwid-perfctr -g FLOPS_DP -C N:0-3 ./likwid_marker_omp
```
  
<br></br>

## <a name="envSetup"> Set up your environment on Perlmutter to use LIKWID

Run the below commands to set up your environment to use LIKWID:

```
module load cpu
export MODULEPATH=/global/cfs/cdirs/m3930/modulefiles:$MODULEPATH
module load likwid
```

Now, you should be able to use cmake/make to build codes that have a measure of LIKWID awareness in the CMakeLists.txt file (such as this repository).

<br></br>
## <a name="sallocNode">Allocating a CPU node on Perlmutter to use LIKWID to obtain h/w performance counter data

Next, when you are ready to actually run the code with LIKWID enabled to obtain hw performance counter data, use this version of the salloc command:

```
salloc --nodes 1 --qos interactive --time 00:30:00 --constraint cpu --account=m3930  --perf=generic
```

If you don't include the "--perf=generic" option, LIKWID will throw errors when you try and collect performance counter data.


<br></br>
## Building the code

The overall approach here is to use cmake, which relies on the CMAKE_PREFIX_PATH environment variable being set to point to the directory where LIKWID is installed, under which 
there is a [.../]likwid-config.cmake file

First, [set up your environment on Perlmutter to use LIKWID.](#envSetup)


Now CMAKE_PREFIX_PATH points to the correct location thanks to the "module load likwid" command, and you can build the code as follows:

From the main likwid_marker directory:
* mkdir build
* cd build
* cmake ../
* make

Then run the codes as indicated above.


## Dustbin below here

### Perlmutter environment setup circa 2024, no longer valid in 2025 and beyond

Run the below commands to load LIKWID in your environment before building and running your code.

```
module load e4s/22.05
spack env activate cuda
spack load likwid
```



# eof

