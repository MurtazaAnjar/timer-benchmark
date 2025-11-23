#ifndef HELLO_WORLD_TIMER_H
#define HELLO_WORLD_TIMER_H
#include <chrono>


class Timer {
    private:
        std::chrono::time_point<std::chrono::system_clock> start_time;
        std::chrono::time_point<std::chrono::system_clock> stop_time;
        bool running;
        Timer(int presetSecs);//private constructor for preset timer objects

    public:
        Timer();
        void start();
        void stop();
        int elapsed() const;
        Timer add(const Timer& other) const;
        Timer subtract(const Timer& other) const;
        void pretty_print() const;
};


#endif //HELLO_WORLD_TIMER_H