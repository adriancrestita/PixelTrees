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
void T1::insert(Node*& node, RGBPixelXY& pixel, unsigned int file)
{
    pixel.setOriginFile(file); // Establece el archivo de origen

    if (node == nullptr) // Si el nodo es nulo, crea un nuevo nodo
    {
        node = new Node(pixel.getSumRGB(), pixel);
        cout << "Inserted new node with sumRGB: " << pixel.getSumRGB() << endl;
        return;
    }

    // Verifica la dirección de la inserción
    if (pixel.getSumRGB() < node->sumRGB)
    {
        // Navega al subárbol izquierdo
        if (node->left == nullptr) {
            node->left = new Node(pixel.getSumRGB(), pixel);
            cout << "Inserted new node on the left with sumRGB: " << pixel.getSumRGB() << endl;
        } else {
            insert(node->left, pixel, file);
        }
    }
    else if (pixel.getSumRGB() > node->sumRGB)
    {
        // Navega al subárbol derecho
        if (node->right == nullptr) {
            node->right = new Node(pixel.getSumRGB(), pixel);
            cout << "Inserted new node on the right with sumRGB: " << pixel.getSumRGB() << endl;
        } else {
            insert(node->right, pixel, file);
        }
    }
    else
    {
        // Si el nodo ya existe, maneja la inserción basada en el archivo
        if (file == 1)
        {
            node->pixels.append(pixel); // Agrega siempre para la imagen 1
            cout << "Appended pixel to existing node with sumRGB: " << node->sumRGB << endl;
        }
        else if (file == 2)
        {
            // Agrega solo si ya existe un píxel igual para la imagen 2
            bool exists = false;
            auto current = node->pixels.getHead();
            while (current)
            {
                const auto& existingPixel = current->data;
                if (existingPixel.getX() == pixel.getX() &&
                    existingPixel.getY() == pixel.getY() &&
                    existingPixel.getR() == pixel.getR() &&
                    existingPixel.getG() == pixel.getG() &&
                    existingPixel.getB() == pixel.getB())
                {
                    exists = true;
                    break;
                }
                current = current->next;
            }

            if (exists)
            {
                node->pixels.append(pixel);
                cout << "Appended pixel to existing node with matching pixel and sumRGB: " << node->sumRGB << endl;
            }
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
        cout << "Checking node with sumRGB: " << current->sumRGB << endl; // Debug
        if (sumRGB == current->sumRGB)
        {
            cout << "Found node with sumRGB: " << sumRGB << endl; // Debug
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
    cout << "No node found for sumRGB: " << sumRGB << endl; // Debug
    return false; // Node not found, return false
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