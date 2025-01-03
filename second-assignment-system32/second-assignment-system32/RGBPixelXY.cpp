#include "RGBPixelXY.hpp"
 
using namespace std;

// empty constructor, all 0, again
RGBPixelXY::RGBPixelXY()
{
    coordX=0;
    coordY=0;
    colorR=0;
    colorG=0;
    colorB=0;
    originFile=0;
    calculateSumRGB();
}

RGBPixelXY::RGBPixelXY(unsigned int paramX, unsigned int paramY)
{
    coordX=paramX;
    coordY=paramY;
    colorR=0;
    colorG=0;
    colorB=0;    
    calculateSumRGB();
    originFile=0;
}

RGBPixelXY::RGBPixelXY(unsigned int paramX, unsigned int paramY, unsigned char paramR, unsigned char paramG, unsigned char paramB)
{
    coordX=paramX;
    coordY=paramY;
    colorR=paramR;
    colorG=paramG;
    colorB=paramB;
	calculateSumRGB();
    originFile=0;
}

RGBPixelXY::~RGBPixelXY()
{
}

unsigned int RGBPixelXY::getX() const
{
    return coordX;
}

unsigned int RGBPixelXY::getY() const
{
    return coordY;
}

unsigned char RGBPixelXY::getR() const
{
    return colorR;
}

unsigned char RGBPixelXY::getG() const
{
    return colorG;
}

unsigned char RGBPixelXY::getB() const
{
    return colorB;
}

unsigned int RGBPixelXY::getSumRGB() const
{
    return sumRGB;
}

void RGBPixelXY::setComponents(unsigned char paramR, unsigned char paramG, unsigned char paramB)
{
    colorR=paramR;
    colorG=paramG;
    colorB=paramB;
    calculateSumRGB();
}

void RGBPixelXY::calculateSumRGB() 
{
    sumRGB = static_cast<unsigned int>(colorR) + static_cast<unsigned int>(colorG) + static_cast<unsigned int>(colorB);
}

unsigned int RGBPixelXY::getOriginFile() {
    return originFile;
}

void RGBPixelXY::setOriginFile(unsigned int fileID) {
    if (fileID == 1 || fileID == 2) {
        originFile = fileID;
    } else {
        originFile = 0; // Default to 0 if invalid value is provided
    }
}

void RGBPixelXY::normalizeToRedGreenOrBlue()
{
    if (colorR>190 && colorG<100 && colorB<100)
    {
        colorR=255;
        colorG=0;
        colorB=0;
    }
    else
    {
        if (colorR<100 && colorG>190 && colorB<100)
        {
            colorR=0;
            colorG=255;
            colorB=0;
        }
        else
        {
            if (colorR<100 && colorG<100 && colorB>190)
            {
                colorR=0;
                colorG=0;
                colorB=255;
            }
            else
            {
                colorR=0;
                colorG=0;
                colorB=0;                
            }                    
        }        
    }
}

bool RGBPixelXY::isBlack()
{
    return 0==(colorR+colorG+colorB);  // si la suma de los tres componentes es 0, el pixel es de color negro
}

bool RGBPixelXY::isNotBlack()
{
    return 0!=(colorR+colorG+colorB);  // si la suma de los tres componentes no es 0, el pixel no es de color negro
}

unsigned int RGBPixelXY::getDistACentro(unsigned int width, unsigned int height)
{
    //std::cout << "dist: X " << coordX << "  Y " << coordY << "W: " <<  width << "H: " <<  height << std::endl;

    long difX = std::abs((long)coordX - (long)width/2);
    long difY = std::abs((long)coordY - (long)height/2);

    //std::cout << "dist: X " << difX << "  Y " << difY << "dist: " << std::sqrt((difX*difX)+(difY*difY)) << std::endl;
    
    return std::sqrt((difX*difX)+(difY*difY));
}

bool RGBPixelXY::getFromRaw(const unsigned char *image, unsigned int width, unsigned int height, unsigned int p_x, unsigned int p_y)
{
    bool result = false; // no success
    
    if (height < 1 || width < 1 || p_x < 0 || p_y < 0 || p_x >= width || p_y >= height)
    {
        result = false;
    }
    else
    {
        int rowPix = width*3;

        colorB = *(image+((p_y*rowPix)+(p_x*3)+0));  // blue
        colorG = *(image+((p_y*rowPix)+(p_x*3)+1));  // green
        colorR = *(image+((p_y*rowPix)+(p_x*3)+2));  // red
        result = true;
    }
    
    return result;
}

bool RGBPixelXY::setIntoRaw(unsigned char *image, unsigned int width, unsigned int height, unsigned int p_x, unsigned int p_y) 
{
    bool result = false; // no success
    
    if (height < 1 || width < 1 || p_x < 0 || p_y < 0 || p_x >= width || p_y >= height)
    {
        result = false;
    }
    else
    {
        int baseIndex = (p_y * width * 3) + (p_x * 3);
        image[baseIndex + 0] = colorB; // Blue
        image[baseIndex + 1] = colorG; // Green
        image[baseIndex + 2] = colorR; // Red
        result = true;
    }
    
    return result;
}