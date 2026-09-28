# Miosix SYCL Bench

PolyBench SYCL workloads adapted for Miosix.
To use miosix-sycl-bench in a miosix project, add this repository as a submodule, then include `miosix-sycl-bench.cmake`:

```cmake
include(path/to/miosix-sycl-bench/miosix-sycl-bench.cmake)
target_sources(main PRIVATE ${MIOSIX_SYCL_BENCH_SOURCES})
target_include_directories(main PRIVATE ${MIOSIX_SYCL_BENCH_INCLUDE_DIRS})
target_compile_definitions(main PRIVATE NUM_RUNS=5 HALF_SIZE)
```
