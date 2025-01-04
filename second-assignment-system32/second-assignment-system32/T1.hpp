#ifndef T1_HPP
#define T1_HPP

#include "RGBPixelXY.hpp"
#include "Queue.hpp"
#include "List.hpp" 

using namespace std;

// T1 Class: Represents a binary search tree for organizing pixels based on sumRGB
class T1
{
// Structure to define each node of the tree
struct Node
{
    unsigned int sumRGB;       // Key for the node: sum of RGB values
    List<RGBPixelXY> pixels;   // Custom List ADT to store pixels with the same sumRGB
    Node* left;                // Pointer to the left child
    Node* right;               // Pointer to the right child

    // Constructor to initialize the node
    Node(unsigned int key, const RGBPixelXY& pixel)
        : sumRGB(key), pixels(), left(nullptr), right(nullptr)
    {
        pixels.append(pixel); // Add the first pixel to the list
    }
};

private:
    
    Node* root; // Root node of the tree


    // Helper method to clear all nodes in the tree
    void clear(Node* node);

    // Helper method to calculate the depth of the tree
    unsigned int calculateDepth(Node* node);

    // Helper method to find the maximum number of elements in a node
    unsigned int calculateMaxNodeElements(Node* node);
    
    void exportAllPixelsHelper(Node* node, Queue& outQueue) const;
    
    void exportPixelsMajorityFile1Helper(Node* node, Queue& outQueue) const;

public:
    T1();  // Constructor
    ~T1(); // Destructor

    void insertFromQueue(Queue& pixelQueue, int fileID);
   
    void insert(const RGBPixelXY& pixel);
    
    Node* insertRecursive(Node* node, unsigned int sumRGB, const RGBPixelXY& pixel);

    // Method to get the depth of the tree
    unsigned int getTreeDepth();

    // Method to get the maximum number of elements in a node
    unsigned int getMaxNodeElements();
	
	// Check if a node with the given sumRGB exists
	bool contains(unsigned int sumRGB) const; 
    
    bool containsRecursive(Node* node, unsigned int sumRGB) const;
		        
    Queue exportAllPixels() const;

    Queue exportPixelsMajorityFile1() const;

};

#endif
