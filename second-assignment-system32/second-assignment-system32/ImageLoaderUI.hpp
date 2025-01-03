#ifndef IMAGELOADERUI_HPP
#define IMAGELOADERUI_HPP

#include <string>
#include <iostream>

#include "TinyImageJM.hpp"  // Existing class for BMP image handling
#include "Queue.hpp"   // Queue to hold pixel data
#include "PixelQueue.hpp"   // Queue to hold pixel data
#include "T1.hpp"
#include "T2.hpp"
#include "Timer.hpp"
#include "ImageSaver.hpp"



// User Interface for loading images and managing pixel queues
class ImageLoaderUI
{
public:
    // Constructor
    ImageLoaderUI();

    // Main method to execute the UI process
    void run();

private:
    // Atributes
	Queue queue1;
	Queue queue2;
	T1 tree1;
	T2 tree2;
    
    // Validate and load an image file
    bool loadImage(const string& imageName, TinyImageJM& image);

    // Load pixels from the image into a queue
    void loadPixelsToQueue(TinyImageJM& image, Queue& queue);
	
	void processImageWithTree(T1& tree1, T2& tree2, const TinyImageJM& image, Queue& pixelQueue, unsigned int fileID);
    
    void printNodePresenceListsForT1(T1& tree1);

};


#endif // IMAGELOADERUI_HPP
