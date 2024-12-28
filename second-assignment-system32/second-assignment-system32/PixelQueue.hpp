#ifndef PIXELQUEUE_HPP
#define PIXELQUEUE_HPP

#include "Queue.hpp"
#include "TinyImageJM.hpp"
#include "PixelVector.hpp"
#include <iostream>

using namespace std;

class PixelQueue 
{
public:
    //Load pixels into a queue
    void loadPixelsIntoQueue(TinyImageJM& image);

    //Getter of the pixel queue
    Queue& getPixelQueue();
    
    // Sort the queue by SumRGB using StaticArray
    Queue sortQueueBySumRGB(const Queue& queue, const TinyImageJM& image);
    
private:
    Queue pixelQueue;  // Cola para almacenar los píxeles
};

#endif // PIXELQUEUE_HPP
