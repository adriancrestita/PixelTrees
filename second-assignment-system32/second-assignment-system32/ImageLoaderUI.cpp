#include "ImageLoaderUI.hpp"
#include "Timer.hpp"

using namespace std;

// Constructor - Initializes the user interface
ImageLoaderUI::ImageLoaderUI()
{
}

// Main method to execute the user interface
void ImageLoaderUI::run()
{
    string imageFile1, imageFile2;
    T1 tree1;
    T2 tree2;
    
    // Request first image file name
    cout << "Enter the name of the first BMP image file (including extension):\n ";
    cin >> imageFile1;
    
    // Start a global timer and Timer for operations
    Timer globalTimer;
    Timer operationTimer;
    
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
    
    // Print Time dedicated to load image and reset timer
    operationTimer.endTimer();
    operationTimer.calculateDuration();
    cout << "*******************************************" << endl;
    cout << "Time dedicated to load image 1" << endl;
    operationTimer.printTime();
    cout << "*******************************************" << endl;
    operationTimer.resetTimer();
    
	// Insert pixels from image1 to t1 tree and to t2 tree
    processImageWithTree(tree1, tree2, image1, queue1, 1);
    operationTimer.endTimer();
    operationTimer.calculateDuration();
    printNodePresenceListsForT1(tree1);
    cout << "*******************************************" << endl;
    cout << "Time dedicated to insert image 1 in T1 and T2" << endl;
    operationTimer.printTime();
    cout << "*******************************************" << endl;
    
    
    // Timer to calculate precise global time
    Timer inputTimer;
    
    // Request second image file name
    cout << "Enter the name of the second BMP image file (including extension):\n ";
    cin >> imageFile2;
    
    // Stop inputTimer and restart operation timer
    inputTimer.endTimer();
    inputTimer.calculateTimer();
    operationTimer.resetTimer();
    
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
    
    // Print Time dedicated to load image and reset timer
    operationTimer.endTimer();
    operationTimer.calculateDuration();
    cout << "*******************************************" << endl;
    cout << "Time dedicated to load image 2" << endl;
    operationTimer.printTime();
    cout << "*******************************************" << endl;
    operationTimer.resetTimer();
    
	// Add pixels from the second image to T1 and T2
    processImageWithTree(tree1, tree2, image2, queue2, 2);
    operationTimer.endTimer();
    operationTimer.calculateDuration();
    printNodePresenceListsForT1(tree1);
    cout << "*******************************************" << endl;
    cout << "Time dedicated to insert image 2 in T1 and T2" << endl;
    operationTimer.printTime();
    cout << "*******************************************" << endl;
    

    cout << "*******************************************" << endl;
	// Generate output images
    cout << "Creating image 1..." << endl;
    //ImageSaver::saveImage1(image1, tree1, imageFile1);
    cout << "[DEBUG] Finished saving image1" << endl;

    cout << "Creating image 2..." << endl;
    ImageSaver::saveImage2(image2, tree1, imageFile2);
    cout << "[DEBUG] Finished saving image2" << endl;
    
    cout << "Creating image 3..." << endl;
    ImageSaver::saveImage3(image2, tree2, imageFile2);
    cout << "[DEBUG] Finished saving image3" << endl;
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

void ImageLoaderUI::processImageWithTree(T1& tree1, T2& tree2, const TinyImageJM& image, Queue& queue, unsigned int fileID)
{ 
    Queue tempQueue1 = queue.copy();
    Queue tempQueue2 = queue.copy();
    
    // Timer
    Timer insertTimer;
    
    // Insert the image pixels into T1 and T2
    tree1.insertFromQueue(tempQueue1, fileID);
    insertTimer.endTimer();
    insertTimer.calculateDuration();
    double T1time = insertTimer.getDuration();
    insertTime.resetTimer();
    tree2.insertFromQueue(tempQueue2, fileID);
    insertTimer.endTimer();
    insertTimer.calculateDuration();
    double T2time = insertTimer.getDuration();
    insertTimer.resetTimer();

    // Print success message depending on fileID
    if (fileID == 1) {
        cout << "Image 1 processed and added to T1 and T2." << endl;
    } else if (fileID == 2) {
        cout << "Image 2 processed and added to T1 and T2." << endl;
    } else {
        cout << "Unknown file ID. Image processed and added to T1 and T2." << endl;
    }

    // Calculate statistics for T1
    unsigned int treeDepth = tree1.getTreeDepth();
    unsigned int maxNodeElements = tree1.getMaxNodeElements();
    cout << "\n\n*******************************************" << endl;
    cout << "Statistics for Tree T1:" << endl;
    cout << "Maximum Depth: " << treeDepth << endl;
    cout << "Node with Maximum Elements: " << maxNodeElements << endl;
    cout << "Time dedicated to insert all pixels: " << T1time << endl;

    // Calculate statistics for T2
    unsigned int t2Depth = tree2.getTreeDepth();
    unsigned int t2MaxNodeElements = tree2.getMaxNodeElements();
    cout << "\n\n*******************************************" << endl;
    cout << "Statistics for Tree T2:" << endl;
    cout << "Maximum Depth: " << t2Depth << endl;
    cout << "Node with Maximum Elements: " << t2MaxNodeElements << endl;
    cout << "Time dedicated to insert all pixels: " << T2time << endl;
}

void ImageLoaderUI::printNodePresenceListsForT1(T1& tree1)
{
    List<unsigned int> valuesWithNode;      // List of sumRGB values with nodes
    List<unsigned int> valuesWithoutNode;  // List of sumRGB values without nodes

    // Traverse all possible sumRGB values (0 to 765)
    for (unsigned int sumRGB = 0; sumRGB <= 765; ++sumRGB)
    {
        if (tree1.contains(sumRGB)) // Check if the node exists in T1
        {
            valuesWithNode.append(sumRGB);
        }
        else
        {
            valuesWithoutNode.append(sumRGB);
        }
    }

    // Print the list of sumRGB values with nodes
    cout << "\n\n*******************************************" << endl;
    cout << "SumRGB Values with Nodes in T1:" << endl;
    cout << "Count: " << valuesWithNode.getSize() << endl;
    valuesWithNode.print();

    // Print the list of sumRGB values without nodes
    cout << "\n\n*******************************************" << endl;
    cout << "SumRGB Values without Nodes in T1:" << endl;
    cout << "Count: " << valuesWithoutNode.getSize() << endl;
    valuesWithoutNode.print();
    cout << "\n\n*******************************************\n\n" << endl;

}


// C:\Users\adria\Desktop\foto.bmp