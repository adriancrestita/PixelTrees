#include "PixelVector.hpp"
#include <stdexcept>
#include <utility> // For std::swap

using namespace std;

// Constructor initializes an empty vector
PixelVector::PixelVector() : data(nullptr), capacity(0), size(0) 
{
}

// Destructor releases dynamic memory
PixelVector::~PixelVector()
{
    delete[] data;
}

// Resize the vector to accommodate more elements
void PixelVector::resize()
{
    size_t newCapacity;
    if (capacity == 0)
    {
        newCapacity = 1;
    }
    else
    {
        newCapacity = capacity * 2;
    }
    RGBPixelXY* newData = new RGBPixelXY[newCapacity];

    // Copy existing data to new array
    for (size_t i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Add a new pixel to the vector
void PixelVector::pushBack(const RGBPixelXY& pixel)
{
    if (size == capacity)
    {
        resize();
    }
    data[size++] = pixel;
}

// Access an element by index
RGBPixelXY& PixelVector::operator[](size_t index)
{
    if (index >= size)
    {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

// Get the number of elements in the vector
size_t PixelVector::getSize() const
{
    return size;
}

// Partition helper for QuickSort
int PixelVector::partition(int low, int high)
{
    RGBPixelXY pivot = data[high]; // Use the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (data[j].getSumRGB() <= pivot.getSumRGB())
        {
            i++;
            swap(data[i], data[j]); // Use std::swap
        }
    }
    swap(data[i + 1], data[high]); // Use std::swap
    return i + 1;
}

// QuickSort implementation
void PixelVector::quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);

        // Recursively sort the partitions
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// Bubble Sort implementation
void PixelVector::bubbleSort()
{
    for (size_t i = 0; i < size - 1; i++)
    {
        // Last i elements are already sorted
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (data[j].getSumRGB() > data[j + 1].getSumRGB())
            {
                // Swap adjacent elements if they are in the wrong order
                swap(data[j], data[j + 1]);
            }
        }
    }
}
