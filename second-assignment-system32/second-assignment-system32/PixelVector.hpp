#ifndef PIXELVECTOR_HPP
#define PIXELVECTOR_HPP

#include "RGBPixelXY.hpp"
#include <stdexcept>

class PixelVector
{
private:
    RGBPixelXY* data; // Pointer to dynamic array
    size_t capacity;  // Current allocated capacity
    size_t size;      // Current number of elements

    // Resize the vector when capacity is exceeded
    void resize();

public:
    // Constructor
    PixelVector();

    // Destructor
    ~PixelVector();

    // Add a new pixel to the vector
    void pushBack(const RGBPixelXY& pixel);

    // Access an element by index
    RGBPixelXY& operator[](size_t index);

    // Get the number of elements
    size_t getSize() const;

    // Sort the vector using QuickSort
    void quickSort(int low, int high);

    // Partition helper for QuickSort
    int partition(int low, int high);
    
    void bubbleSort();
};

#endif // PIXELVECTOR_HPP
