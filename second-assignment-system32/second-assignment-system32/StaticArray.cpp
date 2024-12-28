#include "StaticArray.hpp"

using namespace std;


// Constructor initializes the array with a fixed capacity
StaticArray::StaticArray(size_t maxCapacity) : capacity(maxCapacity), size(0)
{
    if (capacity == 0)
    {
        throw invalid_argument("Capacity must be greater than 0");
    }
    data = new RGBPixelXY[capacity]; // Allocate memory for the array
}

// Destructor releases memory
StaticArray::~StaticArray()
{
    delete[] data;
}

// Add a new element to the array
void StaticArray::add(const RGBPixelXY& pixel)
{
    if (size >= capacity)
    {
        throw overflow_error("StaticArray is full");
    }
    data[size++] = pixel; // Add the pixel and increment size
}

// Access an element by index
RGBPixelXY& StaticArray::operator[](size_t index)
{
    if (index >= size)
    {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

// Get the size of the array
size_t StaticArray::getSize() const
{
    return size;
}

// Swap two elements in the array manually
void StaticArray::swap(int i, int j)
{
    RGBPixelXY temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

// Partition method for QuickSort
int StaticArray::partition(int low, int high)
{
    RGBPixelXY pivot = data[high]; // Use the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (data[j].getSumRGB() <= pivot.getSumRGB())
        {
            i++;
            swap(i, j); // Swap elements manually
        }
    }
    swap(i + 1, high); // Place the pivot in the correct position
    return i + 1;
}

// QuickSort implementation
void StaticArray::quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high); // Partition the array

        // Recursively sort the two halves
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
