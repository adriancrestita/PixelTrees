#include "SortPixelQueue.hpp"

// Temporary node structure for the linked list to store the pixels
struct TempNode {
    RGBPixelXY data;  // Pixel data (RGB values)
    TempNode* next;   // Pointer to the next node in the list
    // Constructor to initialize a node with a pixel
    TempNode(const RGBPixelXY& pixel) : data(pixel), next(nullptr) {}
};

// Function to sort a queue of pixels
Queue SortPixelQueue::sortPixelQueue(const Queue& queue) {
    Queue sortedQueue; // New queue to store the sorted elements

    // Step 1: Extract elements from the original queue into a temporary linked list
    TempNode* head = nullptr;  // Head of the linked list
    Queue tempQueue = queue.copy();  // Create a copy of the original queue

    // Transfer all elements from the queue to the temporary linked list
    while (!tempQueue.isEmpty()) {
        RGBPixelXY pixel = tempQueue.peek();  // Get the front pixel
        tempQueue.dequeue();  // Remove the pixel from the queue

        // Create a new node for the pixel and insert it at the beginning of the linked list
        TempNode* newNode = new TempNode(pixel);
        newNode->next = head;
        head = newNode;
    }

    // Step 2: Sort the linked list using Bubble Sort algorithm
    if (!head || !head->next) {
        // If the list has 0 or 1 elements, it is already sorted
        TempNode* current = head;
        while (current) {
            sortedQueue.enqueue(current->data);  // Insert into the sorted queue
            TempNode* temp = current;
            current = current->next;  // Move to the next node
            delete temp;  // Delete the current node
        }
        return sortedQueue;
    }

    bool swapped;  // Flag to check if any elements were swapped
    do {
        swapped = false;  // Reset the swapped flag
        TempNode* current = head;
        TempNode* prev = nullptr;

        // Traverse the linked list and compare adjacent nodes
        while (current && current->next) {
            if (current->data.getSumRGB() < current->next->data.getSumRGB()) {
                // If the current node's sum of RGB is less than the next node's, swap them
                RGBPixelXY temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;  // Mark that a swap occurred
            }
            prev = current;  // Move the prev pointer forward
            current = current->next;  // Move the current pointer forward
        }
    } while (swapped);  // Repeat the process as long as swaps occur

    // Step 3: Insert the sorted elements back into the sorted queue
    TempNode* current = head;
    while (current) {
        sortedQueue.enqueue(current->data);  // Insert each pixel into the sorted queue
        TempNode* temp = current;
        current = current->next;  // Move to the next node
        delete temp;  // Delete the current node to free memory
    }

    return sortedQueue;  // Return the sorted queue
}

// Function to print the sum of RGB values for each pixel in the queue
void SortPixelQueue::printPixelQueue(const Queue& queue) {
    // Create a temporary queue by copying the original queue to avoid modifying it
    Queue tempQueue = queue.copy();

    // Iterate through the queue and print the sum of RGB values for each pixel
    while (!tempQueue.isEmpty()) {
        RGBPixelXY pixel = tempQueue.peek();  // Get the front pixel of the queue
        tempQueue.dequeue();  // Remove the pixel from the temporary queue

        // Print the sum of the RGB values of the pixel
        std::cout << "Sum of RGB values: " << pixel.getSumRGB() << std::endl;
    }
}

