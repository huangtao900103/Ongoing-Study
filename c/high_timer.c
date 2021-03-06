#include "high_timer.h"

#if defined(_WIN32)

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

void high_timer_start(high_timer_t *timer)
{
    LARGE_INTEGER start;

    assert(timer != NULL);

    if (QueryPerformanceCounter(&start))
    {
        timer->start_time = start.QuadPart;
        timer->started = true;
    }
    else
    {
        timer->start_time = 0;
        timer->started = false;
    }
}


int64_t high_timer_ellapsed_ms(high_timer_t *timer)
{
    LARGE_INTEGER stop;
    LARGE_INTEGER frequency;

    assert(timer != NULL);
    assert(timer->started);

    if (timer->started)
    {
        if (QueryPerformanceCounter(&stop) && QueryPerformanceFrequency(&frequency))
            return (int64_t)((stop.QuadPart - timer->start_time) * 1000.0L / frequency.QuadPart);
        else
            return 0;
    }
    else
    {
        return 0;
    }
}


#elif defined(__linux__)


void high_timer_start(high_timer_t *timer)
{
    assert(timer != NULL);

    gettimeofday(&timer->start_time, NULL);
    timer->started = true;
}

int64_t high_timer_ellapsed_ms(high_timer_t *timer)
{
    struct timeval stop;

    assert(timer != NULL);
    assert(timer->started);

    if (timer->started)
    {
        gettimeofday(&stop, NULL);
        return (int64_t)((stop.tv_sec - timer->start_time.tv_sec) * 1000.0
            + (stop.tv_usec - timer->start_time.tv_usec) / 1000.0);
    }
    else
    {
        return 0;
    }
}

#else

#error high_timer: Unsupported platform!

#endif


// References:
// https://github.com/mloskot/spatial_index_benchmark/blob/master/high_resolution_timer.hpp
// https://github.com/miloyip/nativejson-benchmark/blob/master/src/timer.h
// https://stackoverflow.com/questions/21557816/whats-the-c-suffix-for-long-double-literals
