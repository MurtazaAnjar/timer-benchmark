#ifndef HELLO_WORLD_TIMER_H
#define HELLO_WORLD_TIMER_H
#include <chrono>


class Timer {
    private:
    std::chrono::time_point<std::chrono::system_clock> start_time;
    std::chrono::time_point<std::chrono::system_clock> stop_time;
    bool running;

public:
    Timer();
    void start();
    void stop();
    int elapsed() const;
};


#endif //HELLO_WORLD_TIMER_H