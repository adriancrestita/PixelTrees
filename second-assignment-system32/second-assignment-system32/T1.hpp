#ifndef T1_HPP
#define T1_HPP

#include "RGBPixelXY.hpp"
#include "Queue.hpp"
#include "List.hpp" 

using namespace std;

// T1 Class: Represents a binary search tree for organizing pixels based on sumRGB
class T1
{
private:
    // Structure to define each node of the tree
    struct Node
    {
        unsigned int sumRGB;       // Key for the node: sum of RGB values
        List<RGBPixelXY> pixels;   // Custom List ADT to store pixels with the same sumRGB
        unsigned int originFile;   // Identifier for the file source of the pixels
        Node* left;                // Pointer to the left child
        Node* right;               // Pointer to the right child

        // Constructor to initialize the node
        Node(unsigned int key, RGBPixelXY pixel, unsigned int file)
            : sumRGB(key), originFile(file), left(nullptr), right(nullptr)
        {
            pixels.append(pixel); // Add the first pixel to the list
        }
    };

    Node* root; // Root node of the tree

    // Helper method to insert a pixel into the tree
    void insert(Node*& node, RGBPixelXY pixel, unsigned int file);

    // Helper method to clear all nodes in the tree
    void clear(Node* node);

    // Helper method to calculate the depth of the tree
    unsigned int calculateDepth(Node* node);

    // Helper method to find the maximum number of elements in a node
    unsigned int calculateMaxNodeElements(Node* node);

public:
    T1();  // Constructor
    ~T1(); // Destructor

    // Method to insert pixels from a queue into the tree
    void insertFromQueue(Queue& pixelQueue, unsigned int file);

    // Method to get the depth of the tree
    unsigned int getTreeDepth();

    // Method to get the maximum number of elements in a node
    unsigned int getMaxNodeElements();
	
	// Check if a node with the given sumRGB exists
	bool contains(unsigned int sumRGB) const; 
	
	// Add a pixel to an existing node
	void addToExistingNode(unsigned int sumRGB, const RGBPixelXY& pixel, unsigned int file); 
	
	unsigned int getNodeOriginFile(unsigned int sumRGB) const;

};

#endif
