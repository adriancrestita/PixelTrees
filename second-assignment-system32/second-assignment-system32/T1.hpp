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
		: sumRGB(key), left(nullptr), right(nullptr)
	{
		pixels.append(pixel); // Add the first pixel to the list
	}
};

private:
	Node* root; // Root node of the tree
	unsigned int maxDepth; // Maximum depth of the tree
	unsigned int maxElements; // Maximum number of elements in a node

	// Recursive insertion function
    void insertHelper(Node*& node, const RGBPixelXY& pixel, int file); 
	
	// Recursive function to print the tree in order
    void printInOrder(Node* node) const; 
	
	// Recursive function to clear the tree memory
    void clear(Node* node); 
	
	// Recursive function to calculate the size of the tree
    unsigned int sizeHelper(Node* node) const; 
	
	// Recursive function to calculate the tree depth
    unsigned int calculateDepth(Node* node) const; 
	
	// Recursive function to calculate the node with the maximum number of elements
    void calculateMaxElements(Node* node); 
	
	// Function to collect values with and without nodes
    void collectValues(Node* node, bool valuesWithNode[], bool valuesWithoutNode[]) const; 

public:
    T1();  // Constructor
    ~T1(); // Destructor

	// Inserts a pixel into the tree with file information
    void insert(const RGBPixelXY& pixel, int file); 
	
	// Finds a node by its sumRGB value
    bool find(unsigned int sumRGB) const; 
	
	// Prints the tree in order
    void print() const; 
	
	// Returns the number of nodes in the tree
    unsigned int size() const; 
	
	// Calculates statistical data of the tree
    void calculateStatistics(); 
	
	// Prints the list of values with and without nodes
    void printValueLists() const; 
	
	// Insert pixels from a queue
	void insertFromQueue(queue<RGBPixelXY>& pixelQueue, int file) {

};

#endif
