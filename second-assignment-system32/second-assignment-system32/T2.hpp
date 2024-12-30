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
    unsigned int originFile;     // File identifier (1 for image 1, 2 for image 2, 0 for mixed origin)
    BalancedNode* left;          // Pointer to the left subtree
    BalancedNode* right;         // Pointer to the right subtree

    // Constructor for initializing a node
    BalancedNode(unsigned int sum, const RGBPixelXY& pixel, unsigned int file)
        : sumRGB(sum), originFile(file), left(nullptr), right(nullptr)
    {
        pixels.append(pixel);
    }
};

class T2
{
private:
    BalancedNode* root; // Root node of the tree

    // Recursively clears all nodes in the tree
    void clear(BalancedNode* node);

    // Helper to insert a pixel into the tree
    BalancedNode* insert(BalancedNode* node, RGBPixelXY pixel, unsigned int file);

    // Balances the tree after an insertion
    BalancedNode* balanceTree(BalancedNode* node);

    // Returns the height of a subtree
    int getHeight(BalancedNode* node);

    // Calculates the balance factor of a node
    int getBalanceFactor(BalancedNode* node);

    // Performs a left rotation on a subtree
    BalancedNode* rotateLeft(BalancedNode* node);

    // Performs a right rotation on a subtree
    BalancedNode* rotateRight(BalancedNode* node);

    // Recursively calculates the depth of the tree
    unsigned int calculateDepth(BalancedNode* node);

    // Recursively calculates the maximum number of elements in any node
    unsigned int calculateMaxNodeElements(BalancedNode* node);
    
public:
    // Constructor to initialize an empty tree
    T2();

    // Destructor to clear the tree
    ~T2();

    // Inserts a pixel into the tree
    void insert(RGBPixelXY pixel, unsigned int file);

    // Returns the depth of the tree
    unsigned int getTreeDepth();

    // Returns the maximum number of elements in any node
    unsigned int getMaxNodeElements();

    // Checks if a node with the given sumRGB exists in the tree
    bool contains(unsigned int sumRGB);

    // Adds a pixel to an existing node with a matching sumRGB
    void addToExistingNode(unsigned int sumRGB, const RGBPixelXY& pixel, unsigned int file);
	
	// Insert all pixels from a queue into the tree
	void insertFromQueue(Queue& pixelQueue, unsigned int file); 
};

#endif
