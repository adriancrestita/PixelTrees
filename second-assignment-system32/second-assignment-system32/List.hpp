#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

// Template class for a linked list
template <typename T>
class List
{
private:
    // Node structure
    struct Node
    {
        T data;       // Data stored in the node
        Node* next;   // Pointer to the next node

        // Constructor to initialize a node
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node
    unsigned int size; // Number of elements in the list

public:
    // Constructor
    List();

    // Destructor
    ~List();

    // Adds an element to the end of the list
    void append(const T& value);

    // Removes the first occurrence of a value in the list
    bool remove(const T& value);

    // Finds if a value exists in the list
    bool find(const T& value) const;

    // Clears all elements in the list
    void clear();

    // Returns the number of elements in the list
    unsigned int getSize() const;

    // Prints all elements in the list
    void print() const;
    
    // Inserts an element at position N in the list
    bool insertAtPosition(unsigned int position, const T& value);
};

#include "List.cpp" // Include implementation for templates
#endif
