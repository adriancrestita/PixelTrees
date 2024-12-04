#ifndef PIXELQUEUE_HPP
#define PIXELQUEUE_HPP

#include "Queue.hpp"
#include "RGBPixelXY.hpp"
#include "TinyImageJM.hpp"

using namespace std;

class PixelQueue 
{
public:
    //Load pixels into a queue
    void loadPixelsIntoQueue(TinyImageJM& image);

    //Getter of the pixel queue
    Queue& getPixelQueue();

private:
    Queue pixelQueue;  // Cola para almacenar los píxeles
};

#endif // PIXELQUEUE_HPP
