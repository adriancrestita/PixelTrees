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

// Method to insert pixels from a queue into the tree
void T1::insertFromQueue(Queue<RGBPixelXY>& pixelQueue)
{
    // While the queue is not empty, dequeue a pixel and insert it into the tree
    while (!pixelQueue.isEmpty())
    {
        RGBPixelXY pixel = pixelQueue.dequeue(); // Dequeue a pixel from the queue
        insert(pixel); // Call the insert method to add the pixel to the tree
    }
}

// Method to insert a pixel into the tree
void T1::insert(const RGBPixelXY& pixel)
{
    unsigned int sumRGB = pixel.getSumRGB(); // Get the sumRGB value of the pixel
    root = insertRecursive(root, sumRGB, pixel); // Call the recursive insert method
}

// Recursive method to insert a pixel into the tree
Node* T1::insertRecursive(Node* node, unsigned int sumRGB, const RGBPixelXY& pixel)
{
    // Base case: if the node is null, create a new node
    if (node == nullptr)
    {
        return new Node(sumRGB, pixel);
    }

    // If the sumRGB already exists at the current node, add the pixel to the list
    if (sumRGB == node->sumRGB)
    {
        node->pixels.append(pixel); // Add the pixel to the list of this node
    }
    // If the sumRGB is smaller, insert into the left subtree
    else if (sumRGB < node->sumRGB)
    {
        node->left = insertRecursive(node->left, sumRGB, pixel);
    }
    // If the sumRGB is larger, insert into the right subtree
    else
    {
        node->right = insertRecursive(node->right, sumRGB, pixel);
    }

    return node; // Return the node without changes
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
    return containsRecursive(root, sumRGB);
}

bool T1::containsRecursive(Node* node, unsigned int sumRGB) const
{
    if (node == nullptr) {
        cout << "No node found for sumRGB: " << sumRGB << endl; // Debugging output
        return false; // Base case: node is not found
    }

    cout << "Checking node with sumRGB: " << node->sumRGB << endl; // Debugging output

    if (sumRGB == node->sumRGB) {
        cout << "Found node with sumRGB: " << sumRGB << endl; // Debugging output
        return true; // Node found, return true immediately
    }

    // Recursively check the left or right subtree based on comparison
    if (sumRGB < node->sumRGB) {
        cout << "Going left (sumRGB: " << sumRGB << " < " << node->sumRGB << ")" << endl;
        return containsRecursive(node->left, sumRGB); // Recur on the left subtree
    }
    else {
        cout << "Going right (sumRGB: " << sumRGB << " > " << node->sumRGB << ")" << endl;
        return containsRecursive(node->right, sumRGB); // Recur on the right subtree
    }
}

// Get pixels from a node
List<RGBPixelXY> T1::getNodePixels(unsigned int sumRGB) const
{
    Node* current = root;
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



void T1::printAllSumRGB() const
{
    cout << "All sumRGB values in T1 (in-order traversal):" << endl;
    printAllSumRGBHelper(root);
}

void T1::printAllSumRGBHelper(Node* node) const
{
    if (!node) {
        return; // Base case: stop recursion for null nodes
    }

    // Traverse left subtree
    printAllSumRGBHelper(node->left);

    // Print the current node's sumRGB value
    cout << "SumRGB: " << node->sumRGB << endl;

    // Traverse right subtree
    printAllSumRGBHelper(node->right);
}

