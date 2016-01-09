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
	bool cameraMode = false;
	GLfloat xCamRot = 12.0;
	GLfloat yCamRot = 0.0;
	GLfloat zCamRot = 0.0;
	GLfloat lightIntensity = 0.0;
	GLuint texture[1];
	char* GROUND_TEXTURE = "grass2.bmp";
	TextureLoader *textureImg;
public:
	const static GLfloat CAMERA_STEP;
	const static GLfloat MAT_ABIENT[4];
	const static GLfloat MAT_SPECULAR[4];
	const static GLfloat LIGHT_POSITION[4];
	const static GLfloat LM_ABIENT[4];


	Environment();
	~Environment();
	void draw();
	void brighter();
	void darker();
	void xCamRotAdd();
	void xCamRotSub();
	GLfloat getXCamRot() const;
	void yCamRotAdd();
	void yCamRotSub();
	GLfloat getYCamRot() const;
	GLfloat getIntensity();
	void changeCameraMode();
	bool getCameraMode() const;
};

#endif //ENVIRONMENT_H