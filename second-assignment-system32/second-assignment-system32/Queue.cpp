#include "Queue.hpp"

// Constructor initializes the queue as empty
Queue::Queue() : frontNode(nullptr), rearNode(nullptr) {}

// Destructor clears all nodes from the queue to free memory
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(const RGBPixelXY& value) {
    Node* newNode = new Node(value);
    if (rearNode) {
        rearNode->next = newNode;
    } else {
        frontNode = newNode;
    }
    rearNode = newNode;
}

void Queue::dequeue() {
    if (frontNode) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) {
            rearNode = nullptr;
        }
        delete temp;
    }
}

RGBPixelXY Queue::peek() const {
    if (frontNode) {
        return frontNode->data;
    }
    throw std::runtime_error("Queue is empty");
}

bool Queue::isEmpty() const {
    return frontNode == nullptr;
}

// Copy method to create a duplicate of the queue
Queue Queue::copy() const {
    Queue newQueue; // Create an empty queue to hold the copy
    Node* current = frontNode; // Start from the front of the original queue

    while (current) {
        newQueue.enqueue(current->data); // Enqueue each element into the new queue
        current = current->next; // Move to the next node in the original queue
    }

    return newQueue; // Return the new queue as a copy
}
