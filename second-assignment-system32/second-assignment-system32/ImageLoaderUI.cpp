#include "ImageLoaderUI.hpp"
#include "Queue.hpp"

#include <iostream>

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
        /*
        // Print queue contents
        cout << "Queue contents (First Image):" << endl;
        printQueue(queue1);    
        */
        
        // Sort the queue by SumRGB
        PixelQueue pixelQueueManager;
        Queue sortedQueue = pixelQueueManager.sortQueueBySumRGB(queue1, image1);

        // Print sorted queue contents
        cout << "Sorted Queue by SumRGB:" << endl;
        printQueue(sortedQueue); 
    }
    
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
        /*
        // Print queue contents
        cout << "Queue contents (Second Image):" << endl;
        printQueue(queue2);  
        */
    }
 
}
//   C:\Users\adria\Desktop\logo.bmp            C:/Users/adria/Desktop/pinguino.bmp


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


// Helper function to print the queue contents
void ImageLoaderUI::printQueue(const Queue& queue) const
{
    Queue tempQueue = queue.copy(); // Create a copy to avoid modifying the original queue

    while (!tempQueue.isEmpty())
    {
        RGBPixelXY pixel = tempQueue.peek();
        cout << "Pixel (" << pixel.getX() << ", " << pixel.getY()
             << ") - SumRGB: " << pixel.getSumRGB() << endl;
        tempQueue.dequeue();
    }
}