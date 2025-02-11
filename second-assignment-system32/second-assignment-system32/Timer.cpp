#include "Timer.hpp"

using namespace std;

// Constructor: initializes the start time
Timer::Timer() 
{
    start = chrono::high_resolution_clock::now();
}

// Destructor: no specific cleanup needed
Timer::~Timer() 
{
}

// Marks the end time
void Timer::endTimer() 
{
    end = chrono::high_resolution_clock::now();
}

// Calculates the time duration between start and end
void Timer::calculateDuration() 
{
    duration = end - start;
}

// Prints the elapsed time in seconds
void Timer::printTime() 
{
    cout << "Dedicated time operation: " << duration.count() << " seconds." << endl;
}

// Resets the timer by setting a new start time
void Timer::resetTimer() 
{
    start = chrono::high_resolution_clock::now();
    duration = chrono::duration<double>::zero(); // Reset the duration to zero
}

// Subtracts the duration of another timer
void Timer::subtractTime(const Timer& other) 
{
    duration -= other.duration; // Subtract the duration of the other timer
    if (duration.count() < 0) {
        duration = chrono::duration<double>::zero(); // Ensure no negative durations
    }
}

// Method to get the duration in seconds
double Timer::getDuration() const
{
    return duration.count(); // Return the duration in seconds as a double
}
