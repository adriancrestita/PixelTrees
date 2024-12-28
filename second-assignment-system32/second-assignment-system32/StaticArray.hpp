#ifndef STATICARRAY_HPP
#define STATICARRAY_HPP

#include "RGBPixelXY.hpp"
#include <stdexcept>

// Static array ADT for managing RGBPixelXY elements
class StaticArray
{
private:
    RGBPixelXY* data; // Pointer to the array
    size_t capacity;  // Maximum capacity based on image size
    size_t size;      // Current number of elements

public:
    // Constructor with configurable capacity
    StaticArray(size_t maxCapacity);

    // Destructor
    ~StaticArray();

    // Add a new element to the array
    void add(const RGBPixelXY& pixel);

    // Access an element by index
    RGBPixelXY& operator[](size_t index);

    // Get the size of the array
    size_t getSize() const;

    // Sort the array using QuickSort
    void quickSort(int low, int high);

private:
    // Partition method for QuickSort
    int partition(int low, int high);

    // Swap two elements in the array (manual implementation)
    void swap(int i, int j);
};

#endif // STATICARRAY_HPP
