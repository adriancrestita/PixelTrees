// ImageSaver.cpp

// Includes the header file for the ImageSaver class and dependencies
#include "ImageSaver.hpp"

// Helper function to fill an image buffer with black pixels
void ImageSaver::fillBlack(unsigned char* image, int width, int height)
{
    int totalPixels = width * height; // Calculate total pixels in the image
    for (int i = 0; i < totalPixels * 3; i++) // Loop over all channels (RGB)
    {
        image[i] = 0; // Set pixel to black
    }
}

// Saves the first image
void ImageSaver::saveImage1(const TinyImageJM& image1, T1& tree1, const string& baseFilename)
{
    int width = image1.getWidth();
    int height = image1.getHeight();
    unsigned char* newImageData = new unsigned char[width * height * 3];

    // Fill the image with black
    fillBlack(newImageData, width, height);

    // Process the tree nodes
    Queue pixelQueue;
    tree1.insertFromQueue(pixelQueue, 1); // Traverse the tree into a queue

    while (!pixelQueue.isEmpty()) {
        RGBPixelXY pixel = pixelQueue.peek();

        if (pixel.getOriginFile() == 1) {
            int index = (pixel.getY() * width + pixel.getX()) * 3;
            newImageData[index] = pixel.getR();
            newImageData[index + 1] = pixel.getG();
            newImageData[index + 2] = pixel.getB();
        }

        pixelQueue.dequeue();
    }

    // Save the image
    TinyImageJM outputImage;
    outputImage.setNewImagePointerWithOldRemoval(newImageData, width, height);
    outputImage.saveImageToDisk(baseFilename, "_image1");

    // Free memory
    delete[] newImageData;
}

// Saves the second image
void ImageSaver::saveImage2(const TinyImageJM& image2, T1& tree1, const string& baseFilename)
{
    int width = image2.getWidth();
    int height = image2.getHeight();
    unsigned char* newImageData = new unsigned char[width * height * 3];

    // Fill the image with black
    fillBlack(newImageData, width, height);

    // Process the tree nodes
    Queue pixelQueue;
    tree1.insertFromQueue(pixelQueue, 1); // Traverse the tree into a queue

    while (!pixelQueue.isEmpty()) {
        RGBPixelXY pixel = pixelQueue.peek();

        int index = (pixel.getY() * width + pixel.getX()) * 3;
        newImageData[index] = pixel.getR();
        newImageData[index + 1] = pixel.getG();
        newImageData[index + 2] = pixel.getB();

        pixelQueue.dequeue();
    }

    // Save the image
    TinyImageJM outputImage;
    outputImage.setNewImagePointerWithOldRemoval(newImageData, width, height);
    outputImage.saveImageToDisk(baseFilename, "_image2");

    // Free memory
    delete[] newImageData;
}

// Saves the third image
void ImageSaver::saveImage3(const TinyImageJM& image2, T2& tree2, const string& baseFilename)
{
    int width = image2.getWidth();
    int height = image2.getHeight();
    unsigned char* newImageData = new unsigned char[width * height * 3];

    // Fill the image with black
    fillBlack(newImageData, width, height);

    // Process the tree nodes
    Queue pixelQueue;
    tree2.insertFromQueue(pixelQueue, 2); // Traverse the tree into a queue

    while (!pixelQueue.isEmpty()) {
        RGBPixelXY pixel = pixelQueue.peek();

        int index = (pixel.getY() * width + pixel.getX()) * 3;
        newImageData[index] = pixel.getR();
        newImageData[index + 1] = pixel.getG();
        newImageData[index + 2] = pixel.getB();

        pixelQueue.dequeue();
    }

    // Save the image
    TinyImageJM outputImage;
    outputImage.setNewImagePointerWithOldRemoval(newImageData, width, height);
    outputImage.saveImageToDisk(baseFilename, "_image3");

    // Free memory
    delete[] newImageData;
}
