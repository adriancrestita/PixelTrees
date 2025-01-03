#ifndef T2_HPP
#define T2_HPP

#include "RGBPixelXY.hpp"
#include "Queue.hpp"
#include "List.hpp"

// Node structure for binary balanced tree
struct BalancedNode
{
    unsigned int sumRGB;         // Sum of RGB values
    List<RGBPixelXY> pixels;     // List of pixels with the same sumRGB
    BalancedNode* left;          // Pointer to the left subtree
    BalancedNode* right;         // Pointer to the right subtree
	int height;     // Height of the node (used for balancing)

    // Constructor for the node
    BalancedNode(unsigned int sum, const RGBPixelXY& pixel)
        : sumRGB(sum), left(nullptr), right(nullptr), height(1) 
	{
        pixels.append(pixel); // Add the first pixel to the list
    }
};

class T2
{
private:
    BalancedNode* root; // Root node of the tree
	unsigned int maxDepth; // Maximum depth of the tree
    unsigned int maxElements; // Maximum number of elements in a node

	// Recursive insertion function
    void insertHelper(BalancedNode*& node, const RGBPixelXY& pixel, int file); 
	
	// Get the height of the node
    int getHeight(BalancedNode* node); 
	
	// Get the balance factor of the node
    int getBalance(BalancedNode* node); 
	
	// Right rotation
    BalancedNode* rotateRight(BalancedNode* y); 
	
	// Left rotation
    BalancedNode* rotateLeft(BalancedNode* x);  
	
	// Balance the node
    BalancedNode* balance(BalancedNode*& node); 
	
	// Recursive function to print the tree in order
    void printInOrder(BalancedNode* node) const; 
	
	// Recursive function to clear the tree memory
    void clear(BalancedNode* node);
	
	// Recursive function to calculate the size of the tree
    unsigned int sizeHelper(BalancedNode* node) const; 
	
	// Recursive function to calculate the tree depth
    unsigned int calculateDepth(BalancedNode* node) const; 
	
	// Recursive function to calculate the node with the maximum number of elements
    void calculateMaxElements(BalancedNode* node); 
	
	// Function to collect values with and without nodes
    void collectValues(BalancedNode* node, bool valuesWithNode[], bool valuesWithoutNode[]) const; 

public:
    // Constructor to initialize an empty tree
    T2();

    // Destructor to clear the tree
    ~T2();

	// Inserts a pixel into the tree with file information
    void insert(const RGBPixelXY& pixel, int file); 
	
	// Prints the tree in order
    void print() const; 
	
	// Returns the number of nodes in the tree
    unsigned int size() const; 
	
	// Calculates statistical data of the tree
    void calculateStatistics(); 
	
	// Prints the list of values with and without nodes
    void printValueLists() const; 
	
	void insertFromQueue(queue<RGBPixelXY>& pixelQueue, int file) {

};

#endif
