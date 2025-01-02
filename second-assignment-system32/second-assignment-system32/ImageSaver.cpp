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
    int width = image1.getWidth(); // Get the image width
    int height = image1.getHeight(); // Get the image height
    unsigned char* outputImage1 = new unsigned char[width * height * 3]; // Allocate buffer for RGB image
    fillBlack(outputImage1, width, height); // Fill the buffer with black

    // Iterate through nodes in tree1
    for (unsigned int i = 0; i <= 765; ++i)
    {
        // Process nodes that belong to file 1 and contain pixel data
        if (tree1.contains(i) && tree1.getNodeOriginFile(i) == 1)
        {
            List<RGBPixelXY> nodePixels = tree1.getNodePixels(i); // Get list of pixels for the node
            auto current = nodePixels.getHead(); // Get the first pixel in the list
            while (current)
            {
                RGBPixelXY& pixel = current->data; // Access pixel data
                unsigned int cx = pixel.getX();
                unsigned int cy = pixel.getY();
                // Place the pixel into the raw output image buffer
                pixel.setIntoRaw(outputImage1, width, height, cx, cy);
                current = current->next; // Move to the next pixel
            }
        }
    }

    TinyImageJM outputImageWrapper1; // Wrapper to manage the image
    // Assign buffer to the wrapper and free the previous image memory
    outputImageWrapper1.setNewImagePointerWithOldRemoval(outputImage1, width, height);
    // Save the output image to disk with a suffix "_image1"
    outputImageWrapper1.saveImageToDisk(baseFilename, "_image1");
    delete[] outputImage1;
    cout << "Image 1 generated and saved" << endl;
}

// Saves the second image
void ImageSaver::saveImage2(const TinyImageJM& image2, T1& tree1, const string& baseFilename)
{
    int width = image2.getWidth(); // Get image dimensions
    int height = image2.getHeight();
    unsigned char* outputImage2 = new unsigned char[width * height * 3]; // Allocate image buffer
    fillBlack(outputImage2, width, height); // Initialize the buffer with black

    // Iterate through nodes in tree1
    for (unsigned int i = 0; i <= 765; ++i)
    {
        if (tree1.contains(i)) // Check if the tree contains the node
        {
            List<RGBPixelXY> nodePixels = tree1.getNodePixels(i); // Get the pixel list
            auto current = nodePixels.getHead();
            while (current)
            {
                RGBPixelXY& pixel = current->data; // Access pixel data
                unsigned int cx = pixel.getX();
                unsigned int cy = pixel.getY();
                // Place the pixel into the raw output image buffer
                pixel.setIntoRaw(outputImage2, width, height, cx, cy);
                current = current->next; // Move to the next pixel
            }
        }
    }

    TinyImageJM outputImageWrapper2; // Wrapper to manage the image
    // Assign buffer to the wrapper and free the previous image memory
    outputImageWrapper2.setNewImagePointerWithOldRemoval(outputImage2, width, height);
    // Save the output image to disk with a suffix "_image2"
    outputImageWrapper2.saveImageToDisk(baseFilename, "_image2");
    cout << "Image 2 generated and saved" << endl;
}

// Saves the third image
void ImageSaver::saveImage3(const TinyImageJM& image2, T2& tree2, const string& baseFilename)
{
    int width = image2.getWidth(); // Get image dimensions
    int height = image2.getHeight();
    unsigned char* outputImage3 = new unsigned char[width * height * 3]; // Allocate image buffer
    fillBlack(outputImage3, width, height); // Initialize the buffer with black

    // Iterate through nodes in tree2
    for (unsigned int i = 0; i <= 765; ++i)
    {
        if (tree2.contains(i)) // Check if the tree contains the node
        {
            List<RGBPixelXY> nodePixels = tree2.getNodePixels(i); // Get the pixel list
            auto current = nodePixels.getHead();
            while (current)
            {
                RGBPixelXY& pixel = current->data; // Access pixel data
                unsigned int cx = pixel.getX();
                unsigned int cy = pixel.getY();
                // Place the pixel into the raw output image buffer
                pixel.setIntoRaw(outputImage3, width, height, cx, cy);
                current = current->next; // Move to the next pixel
            }
        }
    }

    TinyImageJM outputImageWrapper3; // Wrapper to manage the image
    // Assign buffer to the wrapper and free the previous image memory
    outputImageWrapper3.setNewImagePointerWithOldRemoval(outputImage3, width, height);
    // Save the output image to disk with a suffix "_image3"
    outputImageWrapper3.saveImageToDisk(baseFilename, "_image3");
    cout << "Image 3 generated and saved" << endl;
}
