#ifndef LIST_CPP
#define LIST_CPP

#include "List.hpp"

// Constructor: initializes an empty list
template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

// Destructor: clears the list to free memory
template <typename T>
List<T>::~List()
{
    clear();
}

// Adds an element to the end of the list
template <typename T>
void List<T>::append(const T& value)
{
    Node* newNode = new Node(value); // Create a new node
    if (!head) // If the list is empty
    {
        head = tail = newNode; // Set both head and tail to the new node
    }
    else
    {
        tail->next = newNode; // Link the new node to the end of the list
        tail = newNode;       // Update the tail pointer
    }
    ++size; // Increment the size of the list
}

// Removes the first occurrence of a value in the list
template <typename T>
bool List<T>::remove(const T& value)
{
    Node* current = head; // Start from the head
    Node* previous = nullptr;

    while (current) // Traverse the list
    {
        if (current->data == value) // If the value is found
        {
            if (current == head) // If it's the first node
            {
                head = current->next; // Update head pointer
            }
            else
            {
                previous->next = current->next; // Link the previous node to the next node
            }

            if (current == tail) // If it's the last node
            {
                tail = previous; // Update tail pointer
            }

            delete current; // Free the memory
            --size;         // Decrease the size
            return true;    // Indicate success
        }

        previous = current;
        current = current->next;
    }

    return false; // Value not found
}

// Finds if a value exists in the list
template <typename T>
bool List<T>::find(const T& value) const
{
    Node* current = head; // Start from the head

    while (current) // Traverse the list
    {
        if (current->data == value) // If the value is found
        {
            return true;
        }
        current = current->next; // Move to the next node
    }

    return false; // Value not found
}

// Clears all elements in the list
template <typename T>
void List<T>::clear()
{
    Node* current = head;

    while (current) // Traverse the list
    {
        Node* temp = current;
        current = current->next; // Move to the next node
        delete temp;             // Free the memory of the current node
    }

    head = tail = nullptr; // Reset head and tail pointers
    size = 0;              // Reset size
}

// Returns the number of elements in the list
template <typename T>
unsigned int List<T>::getSize() const
{
    return size;
}

// Prints all elements in the list
template <typename T>
void List<T>::print() const
{
    Node* current = head;

    while (current) // Traverse the list
    {
        std::cout << current->data << " "; // Print the data
        current = current->next;          // Move to the next node
    }

    std::cout << std::endl;
}

// Inserts an element at position N in the list
template <typename T>
bool List<T>::insertAtPosition(unsigned int position, const T& value)
{
    // Check if the position is valid (0 <= position <= size)
    if (position > size)
    {
        return false; // Invalid position
    }

    Node* newNode = new Node(value); // Create a new node

    // Special case: insert at the beginning (position 0)
    if (position == 0)
    {
        newNode->next = head; // Link the new node to the current head
        head = newNode;       // Update the head to the new node
        if (!tail)            // If the list was empty, set tail to the new node as well
        {
            tail = newNode;
        }
    }
    // Special case: insert at the end (position == size)
    else if (position == size)
    {
        tail->next = newNode; // Link the new node to the end of the list
        tail = newNode;       // Update the tail pointer
    }
    else
    {
        Node* current = head; // Start from the head
        // Traverse to the node just before the insertion point
        for (unsigned int i = 0; i < position - 1; ++i)
        {
            current = current->next;
        }

        // Insert the new node after the current node
        newNode->next = current->next;
        current->next = newNode;
    }

    ++size; // Increment the size of the list
    return true; // Successful insertion
}
// Returns the first element of the list
template <typename T>
typename List<T>::Node* List<T>::getHead() {
    return head; // Returns the first node
}

// Returns the element in N position
template <typename T>
typename List<T>::Node* List<T>::getNodeAt(unsigned int position) {
    if (position >= size) return nullptr; // If position is out of range
    Node* current = head;
    for (unsigned int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current;
}



#endif
