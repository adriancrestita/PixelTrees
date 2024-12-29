#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>

using namespace std;

class Timer 
{
private:
    // Start time
    chrono::time_point<chrono::high_resolution_clock> start; 
    
    // End time
    chrono::time_point<chrono::high_resolution_clock> end; 

    // Duration of the timer
    chrono::duration<double> duration;                       

public:
    
    // Constructor: initializes the start time
    Timer();                           
    
    // Destructor
    ~Timer();                          
    
    // Marks the end time
    void endTimer();                   
    
    // Calculates the time duration
    void calculateDuration();          
    
    // Prints the elapsed time
    void printTime();

    // Resets the timer to start again
    void resetTimer();                 
};

#endif
