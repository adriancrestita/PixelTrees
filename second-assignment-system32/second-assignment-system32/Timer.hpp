#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>

using namespace std;

class Timer {
private:
    chrono::time_point<chrono::high_resolution_clock> start; // Start time
    chrono::time_point<chrono::high_resolution_clock> end;   // End time
    chrono::duration<double> duration;                       // Duration of the timer

public:
    Timer();                           // Constructor: initializes the start time
    ~Timer();                          // Destructor
    void endTimer();                   // Marks the end time
    void calculateDuration();          // Calculates the time duration
    void printTime();                  // Prints the elapsed time
    void resetTimer();                 // Resets the timer to start again
};

#endif
