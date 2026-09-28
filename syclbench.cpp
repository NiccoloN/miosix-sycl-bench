#include "bench-sizes.h"
#include "syclbench.h"
#include "polybench/common/benchmarks.hpp"

#include <cstdio>
#include <iostream>

namespace {

using BenchFunction=int (*)(int,char **);

struct Benchmark
{
    const char *name;
    BenchFunction function;
    int size;
};

constexpr Benchmark benchmarks[]={
    {"2mm",_2mm,SIZE_2MM},
    {"3mm",_3mm,SIZE_3MM},
    {"atax",atax,SIZE_ATA},
    {"bicg",bicg,SIZE_BIC},
    {"convolution-2d",convolution_2d,SIZE_CONVOLUTION_2},
    {"convolution-3d",convolution_3d,SIZE_CONVOLUTION_3},
    {"correlation",correlation,SIZE_COR},
    {"covariance",covariance,SIZE_COV},
    {"gemm",gemm,SIZE_GEMM},
    {"gesummv",gesummv,SIZE_GES},
    {"gramschmidt",gramschmidt,SIZE_GRA},
    {"mvt",mvt,SIZE_MVT},
    {"syr2k",syr2k,SIZE_SYR2},
    {"syrk",syrk,SIZE_SYRK},
};

} // namespace

void runSyclBench()
{
    unsigned i=0;
    while (true) {
        for(;i<std::size(benchmarks);i++) {
            const auto& benchmark=benchmarks[i];
            char sizeArgument[24];
            std::snprintf(sizeArgument,sizeof(sizeArgument),"--size=%d",benchmark.size);
            char program[]="syclbench";
            char *argv[]={program,sizeArgument,nullptr};
            std::printf("[syclbench] benchmark=%s size=%d\n",benchmark.name,benchmark.size);
            benchmark.function(2,argv);
            std::puts("[syclbench] complete");
        }
        i = 0;
    }
}
