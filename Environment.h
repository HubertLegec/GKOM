#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include<stdio.h>
#include<windows.h>
#include "textureLoader.h"
#include <cfloat>
#include <GL/gl.h>
#include "glut.h"



class Environment {
private:
	int imageWidth;
	int imageHeight;
	GLuint texture[1];
	char* GROUND_TEXTURE = "grass2.bmp";
	TextureLoader *textureImg;
public:
	const static GLfloat MAT_ABIENT[4];
	const static GLfloat MAT_SPECULAR[4];
	static const GLfloat LIGHT_POSITION[4];
	static const GLfloat LM_ABIENT[4];


	Environment();
	~Environment();
	void draw();
};

#endif //ENVIRONMENT_H