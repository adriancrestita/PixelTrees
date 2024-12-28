#include "PixelQueue.hpp"
#include "StaticArray.hpp"
#include "Queue.hpp"

#include <iostream>

using namespace std;

void PixelQueue::loadPixelsIntoQueue(TinyImageJM& image)
{
	unsigned char* imageData = image.getImagePointertoInternal(); //pointer to the memory where the image is located
	int width = image.getWidth();
	int height = image.getHeight();
	
	//Iterate in each pixel and add it to the queue
	for (int y=0; y<height; y++)
	{
		for (int x=0; x<width; x++)
		{			
			// (y*width*3) gave us all the previous bytes, we *3 because each pixel has 3 bytes
			//(x*3) gave us the bytes completed in this row
			//complete expression give us all the bytes from the egining to the (x,y) position
			unsigned char* rPointer = imageData + (y*width*3)+(x*3); 
			unsigned char* gPointer = rPointer+1;
			unsigned char* bPointer = rPointer+2;
			
			//Obtaining RGB values from the previous pointers
			//Points to the value of the red pixel in x,y
			unsigned char R = *rPointer; 
			unsigned char G = *gPointer;
			unsigned char B = *bPointer;
			
			//Creating a pixel object and add it to the queue
			RGBPixelXY pixel(x,y,R,G,B);
			pixelQueue.enqueue(pixel);
		}
	} 	
	cout << "Pixels pushed into the queue" << endl; 
}

Queue& PixelQueue::getPixelQueue()
{
	return pixelQueue; 
}

Queue PixelQueue::sortQueueBySumRGB(const Queue& queue, const TinyImageJM& image)
{
    // Validate the queue
    if (queue.isEmpty())
    {
        cerr << "Error: Cannot sort an empty queue." << endl;
        return Queue(); // Return an empty queue
    }

    // Create a PixelVector to store pixels from the queue
    PixelVector pixelVector;

    // Copy pixels from the queue to the PixelVector
    Queue tempQueue = queue.copy();
    while (!tempQueue.isEmpty())
    {
        pixelVector.pushBack(tempQueue.peek());
        tempQueue.dequeue();
    }

    cout << "Successfully loaded " << pixelVector.getSize() << " pixels into PixelVector." << endl;

    // Sort the PixelVector using Bubble Sort
    pixelVector.bubbleSort();
    cout << "PixelVector sorted successfully using BubbleSort." << endl;

    // Create a new queue to hold the sorted pixels
    Queue sortedQueue;
    for (size_t i = 0; i < pixelVector.getSize(); i++)
    {
        sortedQueue.enqueue(pixelVector[i]);
    }

    cout << "Sorted queue created successfully." << endl;

    // Return the sorted queue
    return sortedQueue;
}