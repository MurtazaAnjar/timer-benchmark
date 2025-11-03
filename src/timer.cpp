#include "timer.h"

Timer::Timer() {
    running = false;
    start_time = stop_time = std::chrono::system_clock::now();
}

void Timer::start() {
    start_time = std::chrono::system_clock::now();
    running = true;
}

void Timer::stop() {
    if (running) {
        stop_time = std::chrono::system_clock::now();
        running = false;
    }
}

int Timer::elapsed() const {
    std::chrono::duration<double> elapsed_time;
    if (running) {
        elapsed_time = std::chrono::system_clock::now() - start_time;
    } else {
        elapsed_time = stop_time - start_time;
    }
    return static_cast<int>(elapsed_time.count());
}