#ifndef BIKE_H
#define BIKE_H

#include <Windows.h>
#include <GL/gl.h>
#include "glut.h"

class Bike {
private:
	int frameCounter = 0;
	int steeringAngle = 0;
	GLfloat movementSpeed = 0.0;
	const static GLfloat OPONY_DIFFUSE[4];
	const static GLfloat szprychy_diffuse[4];
	const static GLfloat rower_diffuse[4];

	void drawFrontWheel();
	void drawRearWheel();
	void drawFrame();
	void drawSpokes();
public:
	Bike();
	void draw();
	void speedUp();
	void slowDown();
	void turnLeft();
	void turnRight();
};

#endif
