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
    T1 tree1;
    
    // Request first image file name
    cout << "Enter the name of the first BMP image file (including extension):\n ";
    cin >> imageFile1;
    
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
    tree1.printValueLists();
    
    // Request second image file name
    cout << "Enter the name of the second BMP image file (including extension):\n ";
    cin >> imageFile2;
    
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
    
	// Add pixels from the second image to T1 and T2
    processImageWithTree(image2, queue2, 2);
    
    /*
	// Generate output images
    cout << "Creating image 1..." << endl;
    ImageSaver::saveImage1(image1, tree1, imageFile1);
	
    cout << "Creating image 2..." << endl;
    ImageSaver::saveImage2(image2, tree1, imageFile2);
    
    cout << "Creating image 3..." << endl;
    ImageSaver::saveImage3(image2, tree2, imageFile2);
    */
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
    T1 tree1;
    T2 tree2;
    
     // Insert the image pixels into T1 and T2
    tree1.insertFromQueue(queue, fileID);
    tree2.insertFromQueue(queue, fileID);

    // Print success message depending on fileID
    if (fileID == 1) {
        cout << "Image 1 processed and added to T1 and T2." << endl;
    } else if (fileID == 2) {
        cout << "Image 2 processed and added to T1 and T2." << endl;
    } else {
        cout << "Unknown file ID. Image processed and added to T1 and T2." << endl;
    }

    cout << "\n\n*******************************************" << endl;
    cout << "Statistics for Tree T1:" << endl;
    tree1.calculateStatistics();

    // Calculate statistics for T2
    unsigned int t2Depth = tree2.getTreeDepth();
    unsigned int t2MaxNodeElements = tree2.getMaxNodeElements();
    cout << "*******************************************" << endl;
    cout << "Statistics for Tree T2:" << endl;
    tree2.calculateStatistics();
    cout << "*******************************************\n\n" << endl;

}




// C:\Users\adria\Desktop\foto.bmp