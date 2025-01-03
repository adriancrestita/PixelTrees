#include "T1.hpp"

// Constructor: Initializes the tree as empty
T1::T1() : root(nullptr), maxDepth(0), maxElements(0) {}

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

// Inserts a pixel into the tree with file information
void T1::insert(const RGBPixelXY& pixel, int file) {
    unsigned int sum = pixel.getSumRGB(); // Get the sumRGB value of the pixel
    insertHelper(root, pixel, file); // Call the recursive function to insert the pixel
}

// Recursive function to insert a pixel into the tree
void T1::insertHelper(Node*& node, const RGBPixelXY& pixel, int file) {
    if (node == nullptr) {
        // If the node does not exist, create a new node with the pixel
        node = new Node(pixel.getSumRGB(), pixel);
    } else if (node->sumRGB == pixel.getSumRGB()) {
        // If a node with the same sumRGB value exists, add the pixel to the list
        node->pixels.append(pixel);
    } else if (node->sumRGB < pixel.getSumRGB()) {
        // If the sumRGB of the node is smaller, go to the right subtree
        insertHelper(node->right, pixel, file);
    } else {
        // If the sumRGB of the node is larger, go to the left subtree
        insertHelper(node->left, pixel, file);
    }
}

// Finds a node by its sumRGB value
bool T1::find(unsigned int sumRGB) const {
    Node* current = root;
    while (current) {
        if (current->sumRGB == sumRGB) {
            return true; // Node found
        } else if (current->sumRGB < sumRGB) {
            current = current->right; // Go to the right subtree
        } else {
            current = current->left; // Go to the left subtree
        }
    }
    return false; // Node not found
}

// Prints the tree in order
void T1::print() const {
    printInOrder(root);
    cout << endl;
}

// Recursive function to print the tree in order
void T1::printInOrder(Node* node) const {
    if (node) {
        printInOrder(node->left); // Print the left subtree
        node->pixels.print();     // Print the pixels in the node
        printInOrder(node->right); // Print the right subtree
    }
}

// Returns the number of nodes in the tree
unsigned int T1::size() const {
    return sizeHelper(root);
}

// Recursive function to calculate the size of the tree
unsigned int T1::sizeHelper(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + sizeHelper(node->left) + sizeHelper(node->right); // Count the nodes in the left and right subtrees
}

// Recursive function to clear the memory of the tree
void T1::clear(Node* node) {
    if (node) {
        clear(node->left);  // Clear the left subtree
        clear(node->right); // Clear the right subtree
        delete node;        // Delete the current node
    }
}

// Calculates the maximum depth of the tree
unsigned int T1::calculateDepth(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    unsigned int leftDepth = calculateDepth(node->left); // Calculate the depth of the left subtree
    unsigned int rightDepth = calculateDepth(node->right); // Calculate the depth of the right subtree
    return 1 + max(leftDepth, rightDepth); // Return the maximum depth between the left and right subtrees
}

// Calculates the node with the maximum number of elements (pixels)
void T1::calculateMaxElements(Node* node) {
    if (node) {
        unsigned int nodeSize = node->pixels.getSize(); // Get the number of pixels in the node
        if (nodeSize > maxElements) {
            maxElements = nodeSize; // Update the maximum number of elements if necessary
        }
        calculateMaxElements(node->left); // Recursively check the left subtree
        calculateMaxElements(node->right); // Recursively check the right subtree
    }
}

// Calculates and prints statistical data about the tree
void T1::calculateStatistics() {
    maxDepth = calculateDepth(root); // Calculate the maximum depth of the tree
    calculateMaxElements(root); // Calculate the node with the maximum number of elements

    cout << "Maximum depth: " << maxDepth << endl;
    cout << "Maximum number of elements in a node: " << maxElements << endl;
}

// Recursively collects values with and without nodes in the tree
void T1::collectValues(Node* node, bool valuesWithNode[], bool valuesWithoutNode[]) const {
    if (node) {
        valuesWithNode[node->sumRGB] = true; // Mark the value as present in the tree
        collectValues(node->left, valuesWithNode, valuesWithoutNode); // Recursively check the left subtree
        collectValues(node->right, valuesWithNode, valuesWithoutNode); // Recursively check the right subtree
    }
}

// Prints the lists of values with and without nodes in the tree
void T1::printValueLists() const {
    bool valuesWithNode[766] = {false}; // Array to track values with nodes (initialized to false)
    bool valuesWithoutNode[766] = {true}; // Array to track values without nodes (initialized to true)

    collectValues(root, valuesWithNode, valuesWithoutNode); // Collect values with and without nodes

    cout << "Values with nodes in the tree:" << endl;
    for (int i = 0; i <= 765; ++i) {
        if (valuesWithNode[i]) {
            cout << i << " "; // Print the value if it exists in the tree
        }
    }
    cout << endl;

    cout << "Values without nodes in the tree:" << endl;
    for (int i = 0; i <= 765; ++i) {
        if (valuesWithoutNode[i]) {
            cout << i << " "; // Print the value if it does not exist in the tree
        }
    }
    cout << endl;
}

// Method to insert pixels from a queue
void T1::insertFromQueue(queue<RGBPixelXY>& pixelQueue, int file) {
    while (!pixelQueue.empty()) {
        RGBPixelXY pixel = pixelQueue.front();
        pixelQueue.pop();
        
        // Insert the pixel into the tree with the file number
        insert(pixel, file);
    }
}