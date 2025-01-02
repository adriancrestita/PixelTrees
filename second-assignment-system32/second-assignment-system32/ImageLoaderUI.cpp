#include "ImageLoaderUI.hpp"

using namespace std;

// Constructor - Initializes the user interface
ImageLoaderUI::ImageLoaderUI()
{
}

// Main method to execute the user interface
void ImageLoaderUI::run()
{
    string imageFile1, imageFile2;
    
    // Request first image file name
    cout << "Enter the name of the first BMP image file (including extension):\n ";
    cin >> imageFile1;
    
    // Start timer for calculate processing time
    Timer timer;
    
    // Start global timer
    Timer globalTimer;

    // Validate and load the first image
    TinyImageJM image1(imageFile1);
    if (!loadImage(imageFile1, image1))
    {
        cerr << "Error: Unable to load the first image." << endl;
        return; // Stop execution if the first image cannot be loaded
    }

    // Load pixels from the first image into the queue
	loadPixelsToQueue(image1, queue1);	
    if(!queue1.isEmpty())
    {
        cout << "First image loaded into the queue successfully." << endl;    
    }
    
	// Insert pixels from image1 to t1 tree and to t2 tree
	processImageWithTree(image1, queue1, 1);
    
    // Stop timer and print dedicated time
    timer.endTimer();
    timer.calculateDuration();
    cout << "*******************************************" << endl;
    cout << "Image 1 procesing time:" << endl;
    timer.printTime();
    cout << "*******************************************" << endl;
	
	
    // Request second image file name
    Timer inputTimer;
    cout << "Enter the name of the second BMP image file (including extension):\n ";
    cin >> imageFile2;
    inputTimer.endTimer();
    inputTimer.calculateDuration();
    
    // Restart the timer for the second image
    timer.resetTimer();
    
    // Validate and load the second image
    TinyImageJM image2(imageFile2);
    if (!loadImage(imageFile2, image2))
    {
        cerr << "Error: Unable to load the second image." << endl;
        return; // Stop execution if the second image cannot be loaded
    }

    // Load pixels from the second image into the queue
    loadPixelsToQueue(image2, queue2);
    if(!queue2.isEmpty())
    {
        cout << "Second image loaded into the queue successfully." << endl;    
    }
    
    // Stop timer and print dedicated time
    timer.endTimer();
    timer.calculateDuration();
    cout << "*******************************************" << endl;
    cout << "Image 2 procesing time:" << endl;
    timer.printTime();
    cout << "*******************************************" << endl;
	
    // Reset timer
    timer.resetTimer();
    
	// Add pixels from the second image to T1 and T2
    processImage2Addition(queue2);
    
    // Stop timer and print dedicated time
    timer.endTimer();
    timer.calculateDuration();
    cout << "*******************************************" << endl;
    cout << "Time take to merge both images: " << endl;
    timer.printTime();
    
    // Reset timer
    timer.resetTimer();
    
    // Print the lists of node presence for T1 and its running time
    printNodePresenceListsForT1();
    timer.endTimer();
    timer.calculateDuration();
    cout << "*******************************************" << endl;
    cout << "Time taken to analyze sumRGB in T1:" << endl;
    timer.printTime();
    cout << "*******************************************" << endl;
    
	// Generate output images
    
    
    cout << "Creating image 2..." << endl;
    ImageSaver::saveImage2(image2, tree1, imageFile2);
    
    cout << "Creating image 3..." << endl;
    ImageSaver::saveImage3(image2, tree2, imageFile2);
    
    cout << "Creating image 1..." << endl;
    ImageSaver::saveImage1(image1, tree1, imageFile1);
	
    // Stop global timer and print dedicated time
    globalTimer.endTimer();
    globalTimer.calculateDuration();
    cout << "-------------------------------------------" << endl;
    cout << "Global time taken:" << endl;
    globalTimer.subtractTime(inputTimer);
    globalTimer.printTime();
    cout << "-------------------------------------------" << endl;
}

// Method to validate and load an image
bool ImageLoaderUI::loadImage(const string& imageName, TinyImageJM& image)
{
    // Attempt to load the image
    if (!image.loadImageFromDisk())
    {
        cerr << "Error: Failed to load the file: " << imageName << endl;
        return false;
    }

    return true; // Image loaded successfully
}

// Method to load pixels from an image into a queue
void ImageLoaderUI::loadPixelsToQueue(TinyImageJM& image, Queue& queue)
{
    // Create an instance of PixelQueue to manage pixel extraction
    PixelQueue pixelQueueManager;

    // Load the pixels from the image into PixelQueue's internal queue
    pixelQueueManager.loadPixelsIntoQueue(image);

    // Transfer pixels from PixelQueue's internal queue to the provided queue
    while (!pixelQueueManager.getPixelQueue().isEmpty())
    {
        // Add the pixel to the target queue
        queue.enqueue(pixelQueueManager.getPixelQueue().peek());
        // Remove the processed pixel from PixelQueue
        pixelQueueManager.getPixelQueue().dequeue();
    }

    // Notify the user that the pixels were successfully loaded into the queue
    cout << "Image pixels loaded into the queue successfully." << endl;
}

void ImageLoaderUI::processImageWithTree(const TinyImageJM& image, Queue& queue, unsigned int fileID)
{
	tree1.insertFromQueue(queue, fileID);         

    cout << "Tree T1 created successfully with pixels from the image." << endl;

    // Calculate statistics for T1
    unsigned int treeDepth = tree1.getTreeDepth();
    unsigned int maxNodeElements = tree1.getMaxNodeElements();
    cout << "*******************************************" << endl;
    cout << "Statistics for Tree T1:" << endl;
    cout << "Maximum Depth: " << treeDepth << endl;
    cout << "Node with Maximum Elements: " << maxNodeElements << endl;
	
	// Insert pixels into T2
    tree2.insertFromQueue(queue, fileID);
    cout << "Tree T2 created successfully with pixels from the image." << endl;

    // Calculate statistics for T2
    unsigned int t2Depth = tree2.getTreeDepth();
    unsigned int t2MaxNodeElements = tree2.getMaxNodeElements();
    cout << "*******************************************" << endl;
    cout << "Statistics for Tree T2:" << endl;
    cout << "Maximum Depth: " << t2Depth << endl;
    cout << "Node with Maximum Elements: " << t2MaxNodeElements << endl;
}

void ImageLoaderUI::processImage2Addition(Queue& pixelQueue)
{
    Queue tempQueue = pixelQueue.copy();
    unsigned int fileID = 2;

    while (!tempQueue.isEmpty())
    {
        RGBPixelXY pixel = tempQueue.peek();
        if (tree1.contains(pixel.getSumRGB()))
        {
            tree1.addToExistingNode(pixel.getSumRGB(), pixel, fileID);
        }
        if (tree2.contains(pixel.getSumRGB()))
        {
            tree2.addToExistingNode(pixel.getSumRGB(), pixel, fileID);
        }
        tempQueue.dequeue();
    }

    cout << "Image 2 processed and added to T1 and T2." << endl;
    
    // Calculate statistics for T1
    unsigned int treeDepth = tree1.getTreeDepth();
    unsigned int maxNodeElements = tree1.getMaxNodeElements();
    cout << "*******************************************" << endl;
    cout << "Statistics for Tree T1:" << endl;
    cout << "Maximum Depth: " << treeDepth << endl;
    cout << "Node with Maximum Elements: " << maxNodeElements << endl;
    
    // Calculate statistics for T2
    unsigned int t2Depth = tree2.getTreeDepth();
    unsigned int t2MaxNodeElements = tree2.getMaxNodeElements();
    cout << "*******************************************" << endl;
    cout << "Statistics for Tree T2:" << endl;
    cout << "Maximum Depth: " << t2Depth << endl;
    cout << "Node with Maximum Elements: " << t2MaxNodeElements << endl;
}

void ImageLoaderUI::printNodePresenceListsForT1()
{
    List<unsigned int> valuesWithNode;      // List of values with nodes
    List<unsigned int> valuesWithoutNode;  // List of values without nodes

    // Traverse the range from 0 to 765
    for (unsigned int i = 0; i <= 765; ++i)
    {
        if (tree1.contains(i)) // Check if the value exists in T1
        {
            valuesWithNode.append(i); // Add to the list of values with nodes
        }
        else
        {
            valuesWithoutNode.append(i); // Add to the list of values without nodes
        }
    }

    // Print the list of values with nodes
    cout << "*******************************************" << endl;
    cout << "Values with Nodes in T1:" << endl;
    valuesWithNode.print();

    // Print the list of values without nodes
    cout << "*******************************************" << endl;
    cout << "Values without Nodes in T1:" << endl;
    valuesWithoutNode.print();
}

// C:\Users\adria\Desktop\logo.bmp