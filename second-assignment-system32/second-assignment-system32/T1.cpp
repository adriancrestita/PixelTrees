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

// Method to insert pixels from a queue into the tree, especificando fileID
void T1::insertFromQueue(Queue& pixelQueue, int fileID)
{
    // Mientras la cola no esté vacía
    while (!pixelQueue.isEmpty())
    {
        // Tomamos el pixel de la cola
        RGBPixelXY pixel = pixelQueue.peek();  
        pixelQueue.dequeue();

        // Asignamos el originFile al pixel antes de insertarlo
        pixel.setOriginFile(fileID);

        // Si fileID == 1, insertamos todos
        if (fileID == 1)
        {
            insert(pixel);
        }
        // Si fileID == 2, solo insertamos si su sumRGB ya existe
        else if (fileID == 2)
        {
            // contains() verifica si el sumRGB ya está en el árbol
            if (contains(pixel.getSumRGB()))
            {
                insert(pixel);
            }
            // Si no existe, no hacemos nada
        }
        else
        {
            // Manejo de caso: fileID desconocido
            cerr << "[insertFromQueue] fileID no esperado: " << fileID << endl;
        }
    }
}

// Resto de métodos T1, sin cambios

void T1::insert(const RGBPixelXY& pixel)
{
    const unsigned int sumRGB = pixel.getSumRGB();
    root = insertRecursive(root, sumRGB, pixel);
}

T1::Node* T1::insertRecursive(Node* node, unsigned int sumRGB, const RGBPixelXY& pixel)
{
    if (node == nullptr)
    {
        return new Node(sumRGB, pixel);  
    }

    if (sumRGB == node->sumRGB)
    {
        // Agregamos el pixel a la lista del nodo
        node->pixels.append(pixel);
    }
    else if (sumRGB < node->sumRGB)
    {
        node->left = insertRecursive(node->left, sumRGB, pixel);
    }
    else // sumRGB > node->sumRGB
    {
        node->right = insertRecursive(node->right, sumRGB, pixel);
    }
    return node;
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
        return false; // Base case: node is not found
    }


    if (sumRGB == node->sumRGB) {
        return true; // Node found, return true immediately
    }

    // Recursively check the left or right subtree based on comparison
    if (sumRGB < node->sumRGB) {
        return containsRecursive(node->left, sumRGB); // Recur on the left subtree
    }
    else {
        return containsRecursive(node->right, sumRGB); // Recur on the right subtree
    }
}

// In-order traversal to enqueue all pixels
void T1::exportAllPixelsHelper(Node* node, Queue& outQueue) const
{
    if (!node) return;
    exportAllPixelsHelper(node->left, outQueue);

    // Enqueue each pixel from this node
    auto cur = node->pixels.getHead();
    while (cur)
    {
        outQueue.enqueue(cur->data);
        cur = cur->next;
    }

    exportAllPixelsHelper(node->right, outQueue);
}

Queue T1::exportAllPixels() const
{
    Queue result;
    exportAllPixelsHelper(root, result);
    return result;
}

// Count originFile=1 vs. originFile=2 in each node
void T1::exportPixelsMajorityFile1Helper(Node* node, Queue& outQueue) const
{
    if (!node) return;

    // in-order traversal
    exportPixelsMajorityFile1Helper(node->left, outQueue);

    // 1) count how many have file=1 and file=2
    unsigned int count1 = 0;
    unsigned int count2 = 0;

    auto curCount = node->pixels.getHead();
    while (curCount)
    {
        int f = curCount->data.getOriginFile();
        if (f == 1) count1++;
        if (f == 2) count2++;
        curCount = curCount->next;
    }

    // 2) if #file1 > #file2, enqueue all file=1 pixels from this node
    if (count1 > count2)
    {
        auto curEnq = node->pixels.getHead();
        while (curEnq)
        {
            if (curEnq->data.getOriginFile() == 1)
            {
                outQueue.enqueue(curEnq->data);
            }
            curEnq = curEnq->next;
        }
    }

    exportPixelsMajorityFile1Helper(node->right, outQueue);
}

Queue T1::exportPixelsMajorityFile1() const
{
    Queue result;
    exportPixelsMajorityFile1Helper(root, result);
    return result;
}

