#ifndef SORTPIXELQUEUE_HPP
#define SORTPIXELQUEUE_HPP

#include "Queue.hpp"  // Include Queue header

class sortPixelQueue {
public:
    // Constructor
    sortPixelQueue();

    // Destructor
    ~sortPixelQueue();

    // Function to sort the queue of pixels
    void quickSortQueue(Queue& pixelQueue);

private:
    // Recursive quicksort function for sorting the queue
    void quickSort(Queue& queue, int low, int high);

    // Function to partition the queue around the pivot element
    int partition(Queue& queue, int low, int high);

    // Function to swap two nodes in the queue by their indices
    void swapNodes(Queue& queue, int index1, int index2);
};

#endif // SORTPIXELQUEUE_HPP
