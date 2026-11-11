#pragma once

#ifdef SYCLBENCH_CORE_PINNING
const unsigned char syclBenchCoreMask=SYCLBENCH_CORE_PINNING;
#else
const unsigned char syclBenchCoreMask=0b11;
#endif

void runSyclBench();
