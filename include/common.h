#pragma once

#include <sycl/sycl.hpp>

#include <array>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

#define THERMAL_CAMERA_FRAME_PROCESS_SERIAL 0
#define THERMAL_CAMERA_FRAME_PROCESS_ACPP   1
#define THERMAL_CAMERA_FRAME_PROCESS_SYRTOS 2

#ifndef NUM_RUNS
#define NUM_RUNS 5
#endif

#if THERMAL_CAMERA_FRAME_PROCESS_VARIANT == THERMAL_CAMERA_FRAME_PROCESS_SYRTOS
namespace syrtos::sycl {
#endif
using std::sqrt;

template<size_t Dimensions>
id<Dimensions> operator+(const id<Dimensions>& a,const id<Dimensions>& b)
{
    std::array<size_t,Dimensions> result;
    for(size_t i=0;i<Dimensions;i++) result[i]=a[i]+b[i];
    return id<Dimensions>(result);
}
#if THERMAL_CAMERA_FRAME_PROCESS_VARIANT == THERMAL_CAMERA_FRAME_PROCESS_SYRTOS
}
#endif

struct VerificationSetting {};

class BenchmarkQueue
{
public:
    template<typename F>
    sycl::event submit(F&& f)
    {
        return queue().submit(std::forward<F>(f));
    }

private:
    static sycl::queue& queue()
    {
        #if THERMAL_CAMERA_FRAME_PROCESS_VARIANT == THERMAL_CAMERA_FRAME_PROCESS_ACPP
        static sycl::queue instance;
        return instance;
        #else
        using namespace syrtos::sycl;
        #ifdef SCHED_TYPE_EDF
            static sycl::queue queue{queue_properties<queue_mode::DEADLINE>{}};
        #else
            static sycl::queue queue{queue_properties<queue_mode::PRIORITY>{}};
        #endif
        return queue;
        #endif
    }
};

struct BenchmarkArgs
{
    size_t problem_size;
    BenchmarkQueue device_queue;
};

template<typename T, size_t Dimensions>
class BenchmarkHostAccessor
{
public:
    explicit BenchmarkHostAccessor(T *data) : data(data) {}

    T& operator[](size_t index) const { return data[index]; }
    T *get_pointer() const { return data; }

private:
    T *data;
};

template<typename T, size_t Dimensions=1>
class PrefetchedBuffer
{
public:
    void initialize(BenchmarkQueue&, T *data, sycl::range<Dimensions> range)
    {
        this->data=data;
        this->range=std::make_unique<sycl::range<Dimensions>>(range);
        buffer=std::make_unique<sycl::buffer<T,Dimensions>>(data,range);
    }

    template<sycl::access::mode Mode>
    auto get_access(sycl::handler& handler)
    {
        return sycl::accessor<T,Dimensions,Mode>(*buffer,handler);
    }

    auto get_host_access() { return BenchmarkHostAccessor<T,Dimensions>(data); }
    const sycl::range<Dimensions>& get_range() const { return *range; }
    void reset() { buffer.reset(); }

private:
    T *data=nullptr;
    std::unique_ptr<sycl::range<Dimensions>> range;
    std::unique_ptr<sycl::buffer<T,Dimensions>> buffer;
};

class BenchmarkApp
{
public:
    BenchmarkApp(int argc, char **argv)
    {
        for(int i=1;i<argc;i++)
            if(std::strncmp(argv[i],"--size=",7)==0)
                args.problem_size=std::strtoul(argv[i]+7,nullptr,10);
    }

    template<typename Benchmark>
    void run()
    {
        for(size_t run=0;run<NUM_RUNS;run++)
        {
            Benchmark benchmark(args);
            benchmark.setup();
            std::vector<sycl::event> events;
            const auto before=std::chrono::steady_clock::now();
            benchmark.run(events);
            for(auto& event: events) event.wait();
            const auto after=std::chrono::steady_clock::now();
            const auto us=std::chrono::duration_cast<std::chrono::microseconds>(after-before).count();
            std::printf("[syclbench] run=%u time=%lld.%03lld ms\n",
                        static_cast<unsigned>(run+1),us/1000,us%1000);
        }
    }

private:
    BenchmarkArgs args{};
};
