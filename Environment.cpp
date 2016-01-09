#include "environment.h"
#include <iostream>

const GLfloat Environment::MAT_ABIENT[4] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat Environment::MAT_SPECULAR[4] = { 0.5, 0.5, 0.5, 0.5 };
const GLfloat Environment::LIGHT_POSITION[4] = { 0.0, 20.0, 30.0, 2.0 };
const GLfloat Environment::LM_ABIENT[4] = { 0.2, 0.2, 0.2, 1.0 };
const GLfloat Environment::CAMERA_STEP = 3.0;

Environment::Environment() 
{
	textureImg = new TextureLoader();
	glGenTextures(1, &texture[0]);                  // Create The Texture
	textureImg->load(GROUND_TEXTURE);
}
Environment::~Environment() 
{
	free(textureImg);
}


void Environment::draw()
{
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	// Typical Texture Generation Using Data From The Bitmap
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	// Generate The Texture
	glTexImage2D(GL_TEXTURE_2D, 0, 3, textureImg->getImageWidth(), textureImg->getImageHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, textureImg->image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Linear Filtering

	GLfloat fExtent = 60.0f; // total length in each direction
	GLfloat fStep = 1.0f; // length of each step
	GLfloat y = -0.35f; // this is groundLevel / "altitude"
	GLfloat iStrip, iRun;

	glBindTexture(GL_TEXTURE_2D, texture[0]);               // Select Our Texture
	glColor3f(1.0f, 1.0f, 1.0f);
	for (iStrip = -fExtent; iStrip <= fExtent; iStrip += fStep)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0.0f, 1.0f, 0.0f);   // All Point up
		int i = 0;
		for (iRun = fExtent; iRun >= -fExtent; iRun -= fStep)
		{
			if (i % 2 == 1)
			{
				glTexCoord2f(0.0f, 1.0f);
			}
			else
			{
				glTexCoord2f(0.0f, 0.0f);
			}
			glVertex3f(iStrip, y, iRun);
			if (i % 2 == 1)
			{
				glTexCoord2f(1.0f, 1.0f);
			}
			else
			{
				glTexCoord2f(1.0f, 0.0f);
			}
			glVertex3f(iStrip + fStep, y, iRun);
			i++;
		}
		glEnd();
	}
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Environment::brighter()
{
	lightIntensity += 5;
}

void Environment::darker()
{
	lightIntensity -= 5;
}

void Environment::xCamRotAdd()
{
	if (xCamRot < 175)
		xCamRot += CAMERA_STEP;
}

void Environment::xCamRotSub()
{
	if (xCamRot > 5)
		xCamRot -= CAMERA_STEP;
}

GLfloat Environment::getXCamRot() const
{
	return xCamRot;
}

void Environment::yCamRotAdd()
{
		yCamRot += CAMERA_STEP;
		yCamRot = yCamRot == 360 ? 0 : yCamRot;
}

void Environment::yCamRotSub()
{
	yCamRot = yCamRot == 0 ? 360 : yCamRot;
	yCamRot -= CAMERA_STEP;
}

GLfloat Environment::getYCamRot() const
{
	return yCamRot;
}

GLfloat Environment::getIntensity()
{
	return lightIntensity;
}

void Environment::changeCameraMode(){
	cameraMode = !cameraMode;
	if (cameraMode) {
		yCamRot = 180;
		xCamRot = 12;
	}
	else {
		yCamRot = 0;
		xCamRot = 12;
	}
}

bool Environment::getCameraMode() const
{
	return cameraMode;
}
