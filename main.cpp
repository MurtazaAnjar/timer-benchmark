#include <iostream>
#include <chrono>
#include "src/timer.h"


int main() {
    Timer timer;

    auto system_start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(system_start);
    std::cout << "System time at start: " << std::ctime(&start_time);


    timer.start();


    auto work_start = std::chrono::system_clock::now();
    while (true) {
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = now - work_start;
        if (elapsed.count() >= 3.0)
            break;  // busy-wait ~3 seconds
    }


    timer.stop();


    auto system_end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(system_end);
    std::cout << "System time at end: " << std::ctime(&end_time);

    timer.pretty_print();

    int timer_elapsed = timer.elapsed();
    std::cout << "Timer measured: " << timer_elapsed << " seconds" << std::endl;

    std::chrono::duration<double> actual_elapsed = system_end - system_start;
    std::cout << "Actual system elapsed time: "<< static_cast<int>(actual_elapsed.count()) << " seconds" << std::endl;

    Timer t2;
    t2.start();
    auto work_startT2 = std::chrono::system_clock::now();
    while (true) {
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = now - work_startT2;
        if (elapsed.count() >= 5.0)
            break;  // busy-wait ~5 seconds
    }
    t2.stop();
    std::cout<<"timer2: ";
    t2.pretty_print();

    Timer t3 = timer.add(t2);
    std::cout<<"add timer and timer 2: ";
    t3.pretty_print();
    Timer t4 = t2.subtract(timer);
    std::cout<<"subtract timer 2 and timer: ";
    t4.pretty_print();


    return 0;
}