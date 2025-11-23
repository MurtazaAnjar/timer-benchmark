#include "timer.h"
#include <iostream>

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

Timer::Timer(int presetSecs) {
    running = false;
    start_time = std::chrono::system_clock::now();
    stop_time = start_time + std::chrono::seconds(presetSecs);
}

Timer Timer::add(const Timer& other) const {
    int total = this->elapsed() + other.elapsed();
    if (total < 0)
        total = 0;  // checks for neg time, 0 if neg found
    return Timer(total);
}

Timer Timer::subtract(const Timer& other) const {
    int diff = this->elapsed() - other.elapsed();
    if (diff < 0)
        diff = 0;  // no negative time
    return Timer(diff);
}

void Timer::pretty_print() const {
    int total = elapsed();

    if (total == 0) {
        std::cout << "No time has passed." << std::endl;
        return;
    }

    int hours = total / 3600;
    int minutes = (total % 3600) / 60;
    int seconds = total % 60;

    //output
    if (hours > 0) {
        std::cout << hours << " hour";
        if (hours > 1)
            std::cout << "s";
        if (minutes > 0 || seconds > 0)
            std::cout << ", ";
    }

    if (minutes > 0) {
        std::cout << minutes << " minute";
        if (minutes > 1)
            std::cout << "s";
        if (seconds > 0)
            std::cout << " and ";
    }

    if (seconds > 0) {
        std::cout << seconds << " second";
        if (seconds > 1)
            std::cout << "s";
    }

    std::cout << " have passed." << std::endl;
}