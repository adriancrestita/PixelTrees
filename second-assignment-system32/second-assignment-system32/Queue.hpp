#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "RGBPixelXY.hpp"

class Queue {
private:
    struct Node {
        RGBPixelXY data;
        Node* next;
        Node(const RGBPixelXY& data) : data(data), next(nullptr) {}
    };

    Node* frontNode; // Pointer to the front of the queue
    Node* rearNode;  // Pointer to the rear of the queue

public:
    Queue();               // Constructor to initialize an empty queue
    ~Queue();              // Destructor to free memory
    void enqueue(const RGBPixelXY& value); // Method to add an element to the end of the queue
    void dequeue();        // Method to remove an element from the front of the queue
    RGBPixelXY peek() const;  // Method to return the front element without removing it
    bool isEmpty() const;  // Method to check if the queue is empty
    Queue copy() const;    // Method to create a copy of the queue
};

#endif // QUEUE_HPP
