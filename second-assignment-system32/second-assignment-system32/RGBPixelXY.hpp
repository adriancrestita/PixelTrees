#ifndef RGBPIXELXY_HPP
#define RGBPIXELXY_HPP

#include <stdlib.h>
#include <math.h>
#include <iostream>


class RGBPixelXY
{
    unsigned int coordX=0;  // from 0 to N
    unsigned int coordY=0;  // from 0 to N
    
    unsigned char colorR=0; // 0-255 (0x00 - 0xff)
    unsigned char colorG=0; // 0-255 (0x00 - 0xff)
    unsigned char colorB=0; // 0-255 (0x00 - 0xff)
	unsigned int sumRGB;
    unsigned int originFile;
 
public:
    RGBPixelXY();
    RGBPixelXY(unsigned int paramX, unsigned int paramY);
    RGBPixelXY(unsigned int paramX, unsigned int paramY, unsigned char paramR, unsigned char paramG, unsigned char paramB);    
    ~RGBPixelXY();

    unsigned int getX() const;
    unsigned int getY() const;
    unsigned char getR() const;
    unsigned char getG() const;
    unsigned char getB() const;
	unsigned int getSumRGB();
    
    void setComponents(unsigned char paramR, unsigned char paramG, unsigned char paramB);
    
    void normalizeToRedGreenOrBlue();
    bool isBlack();
    bool isNotBlack();
    unsigned int getDistACentro(unsigned int width, unsigned int height);
    
    // New methods for originFile
    unsigned int getOriginFile();
    void setOriginFile(unsigned int fileID);
    
    bool getFromRaw(const unsigned char *image, unsigned int width, unsigned int height, unsigned int p_x, unsigned int p_y);
    bool setIntoRaw(unsigned char *image, unsigned int width, unsigned int height, unsigned int p_x, unsigned int p_y);
    
private:
	void calculateSumRGB();
};

#endif // RGBPIXELXY_HPP
