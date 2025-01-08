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

/*
 * saveImage1:
 *   - Image size = dimensions of image1
 *   - Only paint pixels from T1 where the node's pixel-list
 *     has a majority of originFile=1 vs. originFile=2
 *   - All other positions remain black.
 */
void ImageSaver::saveImage1(const TinyImageJM& image1, T1& tree1, const string& baseFilename)
{
	int width = image1.getWidth();
    int height = image1.getHeight();

    // Allocate memory for the image
    unsigned char* internal_image = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);
    
    // Fill the image with black
    fillBlack(internal_image, width, height);

    // Process the tree nodes
    Queue pixelQueue = tree1.exportPixelsMajorityFile1();

    while (!pixelQueue.isEmpty()) 
    {
        RGBPixelXY pixel = pixelQueue.peek();

        int x = pixel.getX();
        int y = pixel.getY();
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            int index = (y * width + x) * 3;
            internal_image[index] = pixel.getR();
            internal_image[index + 1] = pixel.getG();
            internal_image[index + 2] = pixel.getB();
        }

        pixelQueue.dequeue();
    }

    // Save the image
    TinyImageJM outputImage;
    outputImage.setNewImagePointerWithOldRemoval(internal_image, width, height);
    outputImage.saveImageToDisk(baseFilename, "_image1");
}

/*
 * saveImage2:
 *   - Image size = dimensions of image2
 *   - Paint ALL pixels from T1 (tree1), ignoring originFile
 *   - Others remain black
 */
void ImageSaver::saveImage2(const TinyImageJM& image2, T1& tree1, const string& baseFilename)
{
    int width = image2.getWidth();
    int height = image2.getHeight();

    // Allocate memory for the image
    unsigned char* internal_image = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);

    // Fill the image with black
    fillBlack(internal_image, width, height);

    // Process the tree nodes
    Queue pixelQueue = tree1.exportAllPixels();

    while (!pixelQueue.isEmpty()) 
    {
        
        RGBPixelXY pixel = pixelQueue.peek();

        int x = pixel.getX();
        int y = pixel.getY();
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            int index = (y * width + x) * 3;
            internal_image[index] = pixel.getR();
            internal_image[index + 1] = pixel.getG();
            internal_image[index + 2] = pixel.getB();
        }
        pixelQueue.dequeue();
    }

    // Save the image
    TinyImageJM outputImage;
    outputImage.setNewImagePointerWithOldRemoval(internal_image, width, height);
    outputImage.saveImageToDisk(baseFilename, "_image2");
}

/*
 * saveImage3:
 *   - Image size = dimensions of image2 (same as saveImage2)
 *   - Paint ALL pixels from T2
 *   - Others remain black
 */
void ImageSaver::saveImage3(const TinyImageJM& image2, T2& tree2, const string& baseFilename)
{
    int width = image2.getWidth();
    int height = image2.getHeight();

    // Allocate memory for the image
    unsigned char* internal_image = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 3);
	
    // Fill the image with black
    fillBlack(internal_image, width, height);

    // Process the tree nodes
    Queue pixelQueue = tree2.exportAllPixels();

    while (!pixelQueue.isEmpty()) {
       
        RGBPixelXY pixel = pixelQueue.peek();

        int x = pixel.getX();
        int y = pixel.getY();
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            int index = (y * width + x) * 3;
            internal_image[index] = pixel.getR();
            internal_image[index + 1] = pixel.getG();
            internal_image[index + 2] = pixel.getB();
        }
        pixelQueue.dequeue();
    }

    // Save the image
    TinyImageJM outputImage;
    outputImage.setNewImagePointerWithOldRemoval(internal_image, width, height);
    outputImage.saveImageToDisk(baseFilename, "_image3");
}
