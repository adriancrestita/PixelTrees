#include "T2.hpp"

// Constructor: Initializes the tree as empty
T2::T2() : root(nullptr) {}

// Destructor: Clears all nodes in the tree
T2::~T2()
{
    clear(root);
}

// Helper to recursively clear all nodes
void T2::clear(BalancedNode* node)
{
    if (node)
    {
        clear(node->left);  // Clear left subtree
        clear(node->right); // Clear right subtree
        delete node;        // Delete current node
    }
}

// Helper to insert a pixel into the tree
BalancedNode* T2::insert(BalancedNode* node, RGBPixelXY pixel, unsigned int file)
{
    if (!node)
    {
        // Create a new node if none exists
        return new BalancedNode(pixel.getSumRGB(), pixel, file);
    }

    if (pixel.getSumRGB() < node->sumRGB)
    {
        // Insert into the left subtree if sumRGB is smaller
        node->left = insert(node->left, pixel, file);
    }
    else if (pixel.getSumRGB() > node->sumRGB)
    {
        // Insert into the right subtree if sumRGB is greater
        node->right = insert(node->right, pixel, file);
    }
    else
    {
        // Add the pixel to the list if a node with the same sumRGB exists
        node->pixels.append(pixel);
        if (node->originFile != file)
        {
            node->originFile = 2; // Mark as mixed origin
        }
    }

    // Balance the tree after insertion
    return balanceTree(node);
}

// Insert a pixel into the tree (public method)
void T2::insert(RGBPixelXY pixel, unsigned int file)
{
    root = insert(root, pixel, file);
}

// Helper to balance the tree
BalancedNode* T2::balanceTree(BalancedNode* node)
{
    int balanceFactor = getBalanceFactor(node);

    // Left-heavy case
    if (balanceFactor > 1)
    {
        // Left-right case
        if (getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node); // Perform right rotation
    }
    // Right-heavy case
    if (balanceFactor < -1)
    {
        // Right-left case
        if (getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node); // Perform left rotation
    }

    return node; // No balancing needed
}

// Helper to calculate the height of the tree
int T2::getHeight(BalancedNode* node)
{
    if (!node)
    {
        return 0; // Base case: height of an empty node is 0
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Helper to calculate the balance factor
int T2::getBalanceFactor(BalancedNode* node)
{
    if (!node)
    {
        return 0; // Balance factor of an empty node is 0
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
        return 0; // Base case: an empty node has depth 0
    }

    unsigned int leftDepth = calculateDepth(node->left);  // Depth of the left subtree
    unsigned int rightDepth = calculateDepth(node->right); // Depth of the right subtree

    return 1 + std::max(leftDepth, rightDepth); // Return the larger depth
}

// Get the depth of the tree
unsigned int T2::getTreeDepth()
{
    return calculateDepth(root);
}

// Helper to calculate the maximum number of elements in a node
unsigned int T2::calculateMaxNodeElements(BalancedNode* node)
{
    if (!node)
    {
        return 0; // Base case: an empty node has no elements
    }

    // Maximum number of elements in the left and right subtrees
    unsigned int leftMax = calculateMaxNodeElements(node->left);
    unsigned int rightMax = calculateMaxNodeElements(node->right);

    // Number of elements in the current node
    unsigned int currentSize = node->pixels.getSize();

    // Find the maximum of the three values
    if (currentSize >= leftMax && currentSize >= rightMax)
    {
        return currentSize;
    }
    else if (leftMax >= currentSize && leftMax >= rightMax)
    {
        return leftMax;
    }
    else
    {
        return rightMax;
    }
}

// Get the maximum number of elements in any node
unsigned int T2::getMaxNodeElements()
{
    return calculateMaxNodeElements(root);
}

// Check if a node with the given sumRGB exists
bool T2::contains(unsigned int sumRGB) const
{
    BalancedNode* current = root;

    while (current)
    {
        if (sumRGB == current->sumRGB)
        {
            return true; // Found the node
        }
        else if (sumRGB < current->sumRGB)
        {
            current = current->left; // Traverse left
        }
        else
        {
            current = current->right; // Traverse right
        }
    }

    return false; // Node not found
}

// Add a pixel to an existing node with the given sumRGB
void T2::addToExistingNode(unsigned int sumRGB, const RGBPixelXY& pixel, unsigned int file)
{
    BalancedNode* current = root;

    while (current)
    {
        if (sumRGB == current->sumRGB)
        {
            // Add the pixel to the node's list
            current->pixels.append(pixel);

            // Update originFile if necessary
            if (current->originFile != file)
            {
                current->originFile = 2; // Mark as mixed origin
            }
            return;
        }
        else if (sumRGB < current->sumRGB)
        {
            current = current->left; // Traverse left
        }
        else
        {
            current = current->right; // Traverse right
        }
    }
}

// Insert all pixels from a queue into the tree
void T2::insertFromQueue(Queue& pixelQueue, unsigned int file)
{
    Queue tempQueue = pixelQueue.copy(); // Copy the queue

    while (!tempQueue.isEmpty())
    {
        RGBPixelXY pixel = tempQueue.peek(); // Get the front pixel
        insert(pixel, file);                 // Insert into the tree
        tempQueue.dequeue();                 // Remove the pixel from the queue
    }
}

unsigned int T2::getNodeOriginFile(unsigned int sumRGB)
{
    BalancedNode* current = root;
    while (current)
    {
        if (sumRGB < current->sumRGB)
        {
            current = current->left;
        }
        else if (sumRGB > current->sumRGB)
        {
            current = current->right;
        }
        else
        {
            return current->originFile;
        }
    }
    return 0; // Not found
}

// Get pixels from a node
List<RGBPixelXY> T2::getNodePixels(unsigned int sumRGB) const
{
    BalancedNode* current = root;
    while (current)
    {
        if (sumRGB == current->sumRGB)
        {
            return current->pixels;
        }
        current = (sumRGB < current->sumRGB) ? current->left : current->right;
    }
    return List<RGBPixelXY>(); // Return empty list if not found
}