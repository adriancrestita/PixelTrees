#include "T1.hpp"

// Constructor: Initializes the tree as empty
T1::T1() : root(nullptr) {}

// Destructor: Clears all nodes from the tree
T1::~T1()
{
    clear(root);
}

// Helper method to clear all nodes in the tree
void T1::clear(Node* node)
{
    if (node)
    {
        clear(node->left);  // Recursively clear the left subtree
        clear(node->right); // Recursively clear the right subtree
        delete node;        // Free memory for the current node
    }
}

// Helper method to insert a pixel into the tree
void T1::insert(Node*& node, RGBPixelXY pixel, unsigned int file)
{
    if (!node)
    {
        // Create a new node if none exists
        node = new Node(pixel.getSumRGB(), pixel, file);
    }
    else if (pixel.getSumRGB() < node->sumRGB)
    {
        // Insert into the left subtree if sumRGB is smaller
        insert(node->left, pixel, file);
    }
    else if (pixel.getSumRGB() > node->sumRGB)
    {
        // Insert into the right subtree if sumRGB is greater
        insert(node->right, pixel, file);
    }
    else
    {
        // Add the pixel to the list if the node already exists
        node->pixels.append(pixel);

        // Update the originFile if pixels from a different file are added
        if (node->originFile != file)
        {
            node->originFile = 0; // 0 indicates pixels from multiple files
        }
    }
}

// Method to insert pixels from a queue into the tree
void T1::insertFromQueue(Queue& pixelQueue, unsigned int file)
{
    Queue tempQueue = pixelQueue.copy(); // Create a copy of the queue

    // Process each pixel in the queue
    while (!tempQueue.isEmpty())
    {
        RGBPixelXY pixel = tempQueue.peek(); // Get the front pixel
        insert(root, pixel, file);           // Insert the pixel into the tree
        tempQueue.dequeue();                 // Remove the pixel from the queue
    }
}

// Add a pixel to an existing node with the given sumRGB
void T1::addToExistingNode(unsigned int sumRGB, const RGBPixelXY& pixel, unsigned int file)
{
    Node* current = root;

    while (current)
    {
        if (sumRGB == current->sumRGB)
        {
            // Add the pixel to the node's list
            current->pixels.append(pixel);

            // Update originFile if necessary
            if (current->originFile != file)
            {
                current->originFile = 0; // Mark as mixed origin
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

// Helper method to calculate the depth of the tree
unsigned int T1::calculateDepth(Node* node)
{
    if (!node)
    {
        return 0; // An empty node has depth 0
    }

    unsigned int leftDepth = calculateDepth(node->left);  // Depth of the left subtree
    unsigned int rightDepth = calculateDepth(node->right); // Depth of the right subtree

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth); // Return the larger depth
}

// Method to get the depth of the tree
unsigned int T1::getTreeDepth()
{
    return calculateDepth(root); // Start calculating from the root
}

// Helper method to calculate the maximum number of elements in any node
unsigned int T1::calculateMaxNodeElements(Node* node)
{
    if (!node)
    {
        return 0; // An empty node has no elements
    }

    unsigned int leftMax = calculateMaxNodeElements(node->left);  // Max elements in the left subtree
    unsigned int rightMax = calculateMaxNodeElements(node->right); // Max elements in the right subtree
    unsigned int currentSize = node->pixels.getSize(); // Number of pixels in the current node

    return (currentSize > leftMax && currentSize > rightMax) ? currentSize : (leftMax > rightMax ? leftMax : rightMax);
}

// Method to get the maximum number of elements in any node
unsigned int T1::getMaxNodeElements()
{
    return calculateMaxNodeElements(root); // Start calculating from the root
}

// Check if a node with the given sumRGB exists
bool T1::contains(unsigned int sumRGB) const
{
    Node* current = root; // Start at the root of the tree

    while (current) // Traverse the tree until a leaf is reached
    {
        if (sumRGB == current->sumRGB)
        {
            return true; // Node found, return true immediately
        }
        else if (sumRGB < current->sumRGB)
        {
            current = current->left; // Move to the left subtree
        }
        else
        {
            current = current->right; // Move to the right subtree
        }
    }

    return false; // Node not found, return false
}

unsigned int T1::getNodeOriginFile(unsigned int sumRGB) const
{
    Node* current = root;
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

