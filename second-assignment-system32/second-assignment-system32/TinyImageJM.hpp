/*
 * TinyImage
 * A tiny C++ BMP image loading and saving library for data structures basic course.
 * Based on the library created by Charles Dong
 * Author: Jose-Maria Gutierrez-Martinez
*/

#ifndef TINYIMAGEJM_HPP
#define TINYIMAGEJM_HPP

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h> 


class TinyImageJM
{
    std::string original_fn;
	int internal_width;
    int internal_height;
    unsigned char * internal_image;
    unsigned char * internal_palette;   // palette data (if uses palette)
    std::string internal_name;
    std::string internal_error;
    bool imageValid;
    FILE *filePointer;
    
    bool isBMP();
    bool openFile(std::string p_flags);
    
public:
    TinyImageJM(std::string p_name);
    
    bool loadImageFromDisk();        /* returns isValid() */
    bool isValid();

    unsigned char * getImagePointertoInternal();
    int getWidth();
    int getHeight();
    std::string getInternalError();
    std::string getFilename();
    bool releaseImageMemory();
    
    void setNewImagePointerWithOldRemoval(unsigned char * p_image, int p_width, int p_height);
	
	std::string renameFile(const std::string& filename, const std::string& suffix);

    
    int saveImageToDisk(std::string p_name, std::string suffix);
    
    ~TinyImageJM();  /* release memory */
};

#endif // TINYIMAGEJM_HPP