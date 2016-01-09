#ifndef RIDER_H
#define RIDER_H

#include <Windows.h>
#include <GL/gl.h>
#include "glut.h"

class Rider {
private:
	static const GLfloat HEAD_DIFFUSE[4];
	static const GLfloat BODY_DIFFUSE[4];
	GLUquadricObj *quadratic = gluNewQuadric();
	GLfloat pedalingSpeed = 0;
	GLfloat movementSpeed = 0;
	float pedalingAngle = 0;
	int frameCounter = 0;
	int steeringAngle = 0;
	GLfloat xForward = 0;
	GLfloat zForward = 0;
	GLfloat angle = 0;
	void drawBody();
	void drawLeftLeg();
	void drawRightLeg();
	void drawLeftArm();
	void drawRightArm();
	void drawHead();
public:
	Rider();
	void draw();
	void resetPosition();
	void speedUp();
	void slowDown();
	void turnLeft();
	void turnRight();
	void setFrameCounter(int frameCounter);
};

#endif