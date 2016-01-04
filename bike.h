#ifndef BIKE_H
#define BIKE_H

#include <Windows.h>
#include <GL/gl.h>
#include "glut.h"

class Bike {
private:
	GLUquadricObj *quadratic = gluNewQuadric();
	int frameCounter = 0;
	float steeringAngle = 0;
	float bikeAngle = 0;
	float wheelBase = 1.2;
	float pedalingAngle = 0.0;
	GLfloat pedalingSpeed = 0.0;
	GLfloat movementSpeed = 0.0;
	GLfloat xForward = 0.0;
	GLfloat zForward = 0.0;
	const static GLfloat OPONY_DIFFUSE[4];
	const static GLfloat SPOKES_DIFFUSE[4];
	const static GLfloat BIKE_DIFFUSE[4];
	const static GLfloat PEDAL_VERTICES[24]; //8 vertices
	const static GLubyte PEDAL_INDICES[36];
	const static GLfloat SADDLE_VERTICES[24];
	const static GLubyte SADDLE_INDICES[36];

	void drawFrontWheel();
	void drawRearWheel();
	void drawFrame();
	void drawSpokes();
	void drawHandlebar();
	void drawPedals();
public:
	Bike();
	void draw();
	void speedUp();
	void slowDown();
	void turnLeft();
	void turnRight();
	void resetPosition();
	void setFrameCounter(int frameCounter);
};

#endif
