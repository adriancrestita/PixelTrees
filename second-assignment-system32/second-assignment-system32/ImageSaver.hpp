#ifndef IMAGESAVER_HPP
#define IMAGESAVER_HPP

#include "RGBPixelXY.hpp"
#include "TinyImageJM.hpp"
#include "T1.hpp"
#include "T2.hpp"
#include "Queue.hpp"

using namespace std;

class ImageSaver
{
public:
    // Save image 1 based on image1 size, pixels from T1, originFile1
    static void saveImage1(TinyImageJM& image1, T1& tree1, string& baseFilename);

    // Save image 2 based on image2 size, all pixels from T1
    static void saveImage2(TinyImageJM& image2, T1& tree1, string& baseFilename);

    // Save image 3 based on image2 size, all pixels from T2
    static void saveImage3(TinyImageJM& image2, T2& tree2, string& baseFilename);

private:
    // Helper function to fill remaining pixels with black
    static void fillBlack(unsigned char* image, int width, int height);
};

#endif // IMAGESAVER_HPP
