#ifndef T2_HPP
#define T2_HPP

#include "RGBPixelXY.hpp"
#include "List.hpp"

// Node structure for the binary balanced tree
struct BalancedNode
{
    unsigned int sumRGB; // Sum of RGB values
    List<RGBPixelXY> pixels; // List of pixels with the same sumRGB
    unsigned int originFile; // File identifier
    BalancedNode* left;  // Pointer to the left subtree
    BalancedNode* right; // Pointer to the right subtree

    BalancedNode(unsigned int sum, const RGBPixelXY& pixel, unsigned int file)
        : sumRGB(sum), originFile(file), left(nullptr), right(nullptr)
    {
        pixels.append(pixel); // Add the pixel to the list
    }
};

class T2
{
private:
    BalancedNode* root; // Root of the balanced tree

    void clear(BalancedNode* node); // Helper to delete all nodes
    BalancedNode* insert(BalancedNode* node, RGBPixelXY pixel, unsigned int file); // Helper to insert a pixel
    BalancedNode* balanceTree(BalancedNode* node); // Helper to balance the tree
    int getHeight(BalancedNode* node); // Helper to get the height of the tree
    int getBalanceFactor(BalancedNode* node); // Helper to calculate balance factor
    BalancedNode* rotateLeft(BalancedNode* node); // Perform left rotation
    BalancedNode* rotateRight(BalancedNode* node); // Perform right rotation

    unsigned int calculateDepth(BalancedNode* node); // Helper to calculate tree depth
    unsigned int calculateMaxNodeElements(BalancedNode* node); // Helper to calculate max elements in any node

public:
    T2();  // Constructor
    ~T2(); // Destructor

    void insert(RGBPixelXY pixel, unsigned int file); // Public method to insert a pixel
    unsigned int getTreeDepth(); // Method to get the depth of the tree
    unsigned int getMaxNodeElements(); // Method to get max elements in any node
    void clearTree(); // Clears the entire tree
};

#endif
