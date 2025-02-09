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
    pixel.setOriginFile(file); // Always set the origin file

    // If the node is null (subtree is empty)
    if (!node)
    {
        // For file=1, create a new node (since we want to insert everything)
        if (file == 1)
        {
            return new BalancedNode(pixel.getSumRGB(), pixel);
        }
        // For file=2, do NOT create a new node
        // (meaning we don't insert it if sumRGB is not found)
        return nullptr;
    }

    // Compare sumRGB to decide BST placement
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
        // sumRGB == node->sumRGB
        // For both file=1 and file=2, if the node already exists, we append the pixel
        //  (since it's the same sumRGB)
        node->pixels.append(pixel);
    }

    // Balance the tree (if you're using AVL)
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

void T2::exportAllPixelsHelper(BalancedNode* node, Queue& outQueue) const
{
    if (!node) return;

    exportAllPixelsHelper(node->left, outQueue);

    // Enqueue each pixel in this node
    auto cur = node->pixels.getHead();
    while (cur)
    {
        outQueue.enqueue(cur->data);
        cur = cur->next;
    }

    exportAllPixelsHelper(node->right, outQueue);
}

Queue T2::exportAllPixels() const
{
    Queue result;
    exportAllPixelsHelper(root, result);
    return result;
}