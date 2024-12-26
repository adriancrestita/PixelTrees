#ifndef IMAGELOADERUI_HPP
#define IMAGELOADERUI_HPP

#include <string>
#include "TinyImageJM.hpp"  // Existing class for BMP image handling
#include "PixelQueue.hpp"   // Queue to hold pixel data

// User Interface for loading images and managing pixel queues
class ImageLoaderUI
{
public:
    // Constructor
    ImageLoaderUI();

    // Main method to execute the UI process
    void run();

private:
    // Validate and load an image file
    bool loadImage(const std::string& imageName, TinyImageJM& image);

    // Load pixels from the image into a queue
    void loadPixelsToQueue(TinyImageJM& image, PixelQueue& queue);

    // Attributes for pixel queues
    PixelQueue queue1; // Queue for the first image
    PixelQueue queue2; // Queue for the second image
};

#endif // IMAGELOADERUI_HPP
