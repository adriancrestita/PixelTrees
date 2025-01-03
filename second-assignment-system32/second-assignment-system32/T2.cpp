#include "T2.hpp"

// Constructor: Initializes the tree as empty
T2::T2() : root(nullptr) {}

// Destructor: Clears all nodes in the tree
T2::~T2()
{
    clear(root);
}

// Inserts a pixel into the balanced tree with file information
void T2::insert(const RGBPixelXY& pixel, int file) {
    unsigned int sum = pixel.getSumRGB(); // Get the sumRGB value of the pixel
    insertHelper(root, pixel, file); // Call the recursive function to insert the pixel
}

// Recursive function to insert a pixel into the tree
void T2::insertHelper(BalancedNode*& node, const RGBPixelXY& pixel, int file) {
    if (node == nullptr) {
        // If the node does not exist, create a new node with the pixel
        node = new BalancedNode(pixel.getSumRGB(), pixel);
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

    node = balance(node); // Balance the tree after insertion
}

// Get the height of a node
int T2::getHeight(BalancedNode* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Get the balance factor of a node
int T2::getBalance(BalancedNode* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right rotation to balance the tree
BalancedNode* T2::rotateRight(BalancedNode* y) {
    BalancedNode* x = y->left;
    BalancedNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// Left rotation to balance the tree
BalancedNode* T2::rotateLeft(BalancedNode* x) {
    BalancedNode* y = x->right;
    BalancedNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

// Balance the tree at the given node
BalancedNode* T2::balance(BalancedNode*& node) {
    int balanceFactor = getBalance(node);

    // Left heavy subtree
    if (balanceFactor > 1) {
        if (getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left); // Left-Right case
        }
        node = rotateRight(node); // Left-Left case
    }

    // Right heavy subtree
    else if (balanceFactor < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rotateRight(node->right); // Right-Left case
        }
        node = rotateLeft(node); // Right-Right case
    }

    return node; // Return the balanced node
}

// Prints the tree in order
void T2::print() const {
    printInOrder(root);
    cout << endl;
}

// Recursive function to print the tree in order
void T2::printInOrder(BalancedNode* node) const {
    if (node) {
        printInOrder(node->left); // Print the left subtree
        node->pixels.print();     // Print the pixels in the node
        printInOrder(node->right); // Print the right subtree
    }
}

// Returns the number of nodes in the tree
unsigned int T2::size() const {
    return sizeHelper(root);
}

// Recursive function to calculate the size of the tree
unsigned int T2::sizeHelper(BalancedNode* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + sizeHelper(node->left) + sizeHelper(node->right); // Count the nodes in the left and right subtrees
}

// Recursive function to clear the memory of the tree
void T2::clear(BalancedNode* node) {
    if (node) {
        clear(node->left);  // Clear the left subtree
        clear(node->right); // Clear the right subtree
        delete node;        // Delete the current node
    }
}

// Calculates the maximum depth of the tree
unsigned int T2::calculateDepth(BalancedNode* node) const {
    if (node == nullptr) {
        return 0;
    }
    unsigned int leftDepth = calculateDepth(node->left); // Calculate the depth of the left subtree
    unsigned int rightDepth = calculateDepth(node->right); // Calculate the depth of the right subtree
    return 1 + max(leftDepth, rightDepth); // Return the maximum depth between the left and right subtrees
}

// Calculates the node with the maximum number of elements (pixels)
void T2::calculateMaxElements(BalancedNode* node) {
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
void T2::calculateStatistics() {
    maxDepth = calculateDepth(root); // Calculate the maximum depth of the tree
    calculateMaxElements(root); // Calculate the node with the maximum number of elements

    cout << "Maximum depth: " << maxDepth << endl;
    cout << "Maximum number of elements in a node: " << maxElements << endl;
}

// Recursively collects values with and without nodes in the tree
void T2::collectValues(BalancedNode* node, bool valuesWithNode[], bool valuesWithoutNode[]) const {
    if (node) {
        valuesWithNode[node->sumRGB] = true; // Mark the value as present in the tree
        collectValues(node->left, valuesWithNode, valuesWithoutNode); // Recursively check the left subtree
        collectValues(node->right, valuesWithNode, valuesWithoutNode); // Recursively check the right subtree
    }
}

// Prints the lists of values with and without nodes in the tree
void T2::printValueLists() const {
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
void T2::insertFromQueue(queue<RGBPixelXY>& pixelQueue, int file) {
    while (!pixelQueue.empty()) {
        RGBPixelXY pixel = pixelQueue.front();
        pixelQueue.pop();
        
        // Insert the pixel into the tree with the file number
        insert(pixel, file);
    }
}