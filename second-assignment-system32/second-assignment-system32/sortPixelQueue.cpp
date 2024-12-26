#include "sortPixelQueue.hpp"

// Constructor
sortPixelQueue::sortPixelQueue() {}

// Destructor
sortPixelQueue::~sortPixelQueue() {}

// Function to sort the queue of pixels
void sortPixelQueue::quickSortQueue(Queue& pixelQueue) {
    int size = pixelQueue.getQueueSize();
    if (size > 1) {
        quickSort(pixelQueue, 0, size - 1); // Call quickSort on the full queue
    }
}

// Recursive quicksort partition function
void sortPixelQueue::quickSort(Queue& queue, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(queue, low, high);  // Get the pivot index
        quickSort(queue, low, pivotIndex - 1);  // Recursively sort the left part
        quickSort(queue, pivotIndex + 1, high);  // Recursively sort the right part
    }
}

// Function to partition the queue around the pivot element
int sortPixelQueue::partition(Queue& queue, int low, int high) {
    RGBPixelXY pivot;
    Queue copyQueue = queue.copy();  // Make a copy of the queue

    // Traverse to the 'high' index in the copyQueue
    for (int i = 0; i < high; ++i) {
        copyQueue.dequeue();  // Skip to the 'high' index
    }
    pivot = copyQueue.peek();  // Take the pivot from the 'high' index

    int i = low - 1;
    int count = 0;
    Node* current = queue.frontNode;  // Start from the front of the queue

    // Iterate over the queue and swap elements based on their sumRGB
    while (current) {
        if (count >= low && count < high) {
            if (current->data.getSumRGB() < pivot.getSumRGB()) {
                i++;
                swapNodes(queue, i, count);  // Swap the nodes in the queue
            }
        }
        current = current->next;
        count++;
    }

    swapNodes(queue, i + 1, high);  // Move the pivot to the correct position
    return i + 1;  // Return the pivot index
}

// Function to swap two nodes in the queue by their indices
void sortPixelQueue::swapNodes(Queue& queue, int index1, int index2) {
    if (index1 == index2) return;

    Node* node1 = nullptr;
    Node* node2 = nullptr;
    Node* current = queue.frontNode;
    int count = 0;

    // Find both nodes
    while (current) {
        if (count == index1) {
            node1 = current;
        }
        if (count == index2) {
            node2 = current;
        }
        current = current->next;
        count++;
    }

    if (node1 && node2) {
        // Swap the data between the nodes
        RGBPixelXY temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
}
