#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include<stdio.h>
#include<windows.h>

const int BITMAP_ID = 0x4D42;

// based on www.opengl-tutorial.org/beginners-tutorials
class TextureLoader 
{
public:
	TextureLoader();
	~TextureLoader();
	bool load(char *name);
	int getImageWidth() const;
	int getImageHeight() const;
	unsigned int ID;
	unsigned char *image;
private:
	int imageWidth;
	int imageHeight;
};

#endif// TEXTURELOADER_H