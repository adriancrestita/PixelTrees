#include "ImageLoaderUI.hpp"
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
    cout << "First image loaded into the queue successfully." << endl;

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
    cout << "Second image loaded into the queue successfully." << endl;
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

// Method to load pixels into a queue
void ImageLoaderUI::loadPixelsToQueue(TinyImageJM& image, PixelQueue& queue)
{
    queue.loadPixelsIntoQueue(image); // Use PixelQueue to manage pixel data
}
