#include "T2.hpp"

// Constructor: Initializes the tree as empty
T2::T2() : root(nullptr) {}

// Destructor: Clears all nodes from the tree
T2::~T2()
{
    clear(root);
}

// Helper to clear all nodes
void T2::clear(BalancedNode* node)
{
    if (node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Clears the entire tree
void T2::clearTree()
{
    clear(root);
    root = nullptr;
}

// Helper to insert a pixel into the tree
BalancedNode* T2::insert(BalancedNode* node, RGBPixelXY pixel, unsigned int file)
{
    if (!node)
    {
        return new BalancedNode(pixel.getSumRGB(), pixel, file);
    }

    if (pixel.getSumRGB() < node->sumRGB)
    {
        node->left = insert(node->left, pixel, file);
    }
    else if (pixel.getSumRGB() > node->sumRGB)
    {
        node->right = insert(node->right, pixel, file);
    }
    else
    {
        node->pixels.append(pixel); // Add the pixel to the list in the node
    }

    return balanceTree(node);
}

// Public method to insert a pixel
void T2::insert(RGBPixelXY pixel, unsigned int file)
{
    root = insert(root, pixel, file);
}

// Helper to balance the tree
BalancedNode* T2::balanceTree(BalancedNode* node)
{
    int balanceFactor = getBalanceFactor(node);

    // Left-heavy
    if (balanceFactor > 1)
    {
        if (getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    // Right-heavy
    if (balanceFactor < -1)
    {
        if (getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

// Helper to get the height of the tree
int T2::getHeight(BalancedNode* node)
{
    if (!node)
    {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Helper to calculate balance factor
int T2::getBalanceFactor(BalancedNode* node)
{
    if (!node)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Perform left rotation
BalancedNode* T2::rotateLeft(BalancedNode* node)
{
    BalancedNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

// Perform right rotation
BalancedNode* T2::rotateRight(BalancedNode* node)
{
    BalancedNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

// Helper to calculate the depth of the tree
unsigned int T2::calculateDepth(BalancedNode* node)
{
    if (!node)
    {
        return 0;
    }
    unsigned int leftDepth = calculateDepth(node->left);
    unsigned int rightDepth = calculateDepth(node->right);
    return 1 + std::max(leftDepth, rightDepth);
}

// Method to get the depth of the tree
unsigned int T2::getTreeDepth()
{
    return calculateDepth(root);
}

// Helper to calculate the maximum number of elements in any node
unsigned int T2::calculateMaxNodeElements(BalancedNode* node)
{
    if (!node)
    {
        return 0;
    }
    unsigned int leftMax = calculateMaxNodeElements(node->left);
    unsigned int rightMax = calculateMaxNodeElements(node->right);
    unsigned int currentSize = node->pixels.getSize();
    return std::max({leftMax, rightMax, currentSize});
}

// Method to get the maximum number of elements in any node
unsigned int T2::getMaxNodeElements()
{
    return calculateMaxNodeElements(root);
}
