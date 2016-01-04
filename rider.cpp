#define PI 3.14159265
#include "rider.h"
#include <cstdlib>
#include <cmath>

const GLfloat Rider::HEAD_DIFFUSE[4] = { 0.6, 0.6, 0.0, 1.0 };
const GLfloat Rider::BODY_DIFFUSE[4] = { 0.0, 0.0, 0.6, 1.0 };

void Rider::drawBody()
{
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.3, 0.74, 0.0);
	glRotatef(38, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	//glTranslatef(0.55, 0.275, 0.0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	//glTranslatef(-0.55, -0.275, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.12f, 0.15f, 0.6, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.3, 0.73, 0.0);
	glRotatef(38, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	//glTranslatef(0.55, 0.275, 0.0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	//glTranslatef(-0.55, -0.275, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.12, 10, 10);
	glPopMatrix();
}

void Rider::drawLeftLeg()
{
	//udo
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.3, 0.7, -0.09);
	glRotatef(-40, 0, 0, 1);
	glRotatef(sin(1.1+PI+pedalingAngle) * 27, 0, 0, 1);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	//glRotatef(sin((float)frame_no * pedalingSpeed * PI / 180) * 18, 0.0, 0.0, 1.0); old movement
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.055f, 0.035f, 0.45, 10, 10);
	glPopMatrix();

	//³ydka
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	//glTranslatef(sin((float)frame_no * pedalingSpeed * PI / 180) * 0.1*scaleX, sin((float)frame_no * pedalingSpeed * PI / 180) * 0.13 * scaleY, 0.0); old movement
	//glTranslatef(sin((float)frame_no * pedalingSpeed * PI / 180) * 0.08*scaleX, cos((float)frame_no * pedalingSpeed * PI / 180) * 0.08*scaleX, 0.0);
	glTranslatef(0.4, 0.05, -0.09);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glTranslatef(sin(PI+pedalingAngle)*0.2, cos(PI+pedalingAngle)*0.2, 0.0);
	//glRotatef((float)frame_no * 0.1 - 36, 0.0, 0.0, 1.0);
	glRotatef(sin(PI-0.6+pedalingAngle) * 23, 0, 0, 1);
	glRotatef(62, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.035f, 0.035f, 0.46, 10, 10);
	glPopMatrix();
}

void Rider::drawRightLeg()
{
	//udo
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.3, 0.7, 0.09);
	glRotatef(-40, 0, 0, 1);
	glRotatef(sin(1.1+pedalingAngle) * 27, 0, 0, 1);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	//glRotatef(sin((float)frame_no * pedalingSpeed * PI / 180) * 18, 0.0, 0.0, 1.0); old movement
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.055f, 0.035f, 0.45, 10, 10);
	glPopMatrix();

	//³ydka
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.4, 0.05, 0.09);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glTranslatef(sin(pedalingAngle)*0.2, cos(pedalingAngle)*0.2, 0.0);
	
	//glRotatef((float)frame_no * 0.1 - 36, 0.0, 0.0, 1.0);
	glRotatef(sin(-0.6+pedalingAngle) * 23, 0, 0, 1);
	glRotatef(62, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.035f, 0.035f, 0.46, 10, 10);
	glPopMatrix();

}

void Rider::drawLeftArm()
{
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.7, 1.1, -0.15);
	glRotatef(-70-0.5*steeringAngle, 0, 0, 1);
	//glRotatef((float)frame_no * 0.1 - 36, 0.0, 0.0, 1.0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.04f, 0.03f, 0.45, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.7, 1.1, -0.15);
	glTranslatef(cos((-70 -0.5*steeringAngle)* PI / 180)*0.45, sin((-70 - 0.5*steeringAngle)* PI / 180)*0.45, 0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glRotatef(-6 + 0.15*steeringAngle-0.12*abs(steeringAngle), 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.03f, 0.03f, 0.45, 10, 10);
	glPopMatrix();
}

void Rider::drawRightArm()
{
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.7, 1.1, 0.15);
	glRotatef(-70+0.5*steeringAngle, 0, 0, 1);
	//glRotatef((float)frame_no * 0.1 - 36, 0.0, 0.0, 1.0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.04f, 0.03f, 0.45, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.7, 1.1, 0.15);
	glTranslatef(cos((-70 + 0.5*steeringAngle)* PI / 180)*0.45, sin((-70 + 0.5*steeringAngle)* PI / 180)*0.45, 0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glRotatef(-6 - 0.15*steeringAngle - 0.12*abs(steeringAngle), 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.03f, 0.03f, 0.45, 10, 10);
	glPopMatrix();
}

void Rider::drawHead()
{
	//szyja
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.77, 1.1, 0.0);
	glRotatef(38, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	//glTranslatef(0.55, 0.275, 0.0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	//glTranslatef(-0.55, -0.275, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, HEAD_DIFFUSE);
	gluCylinder(quadratic, 0.05f, 0.05f, 0.1, 10, 10);
	glPopMatrix();

	//glowa
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glTranslatef(0.9, 1.2, 0.0);
	glRotatef(38, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	//glTranslatef(0.55, 0.275, 0.0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	//glTranslatef(-0.55, -0.275, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, HEAD_DIFFUSE);
	gluSphere(quadratic, 0.14, 10, 10);
	glPopMatrix();
}

Rider::Rider()
{
}

void Rider::draw()
{
	drawBody();
	drawLeftLeg();
	drawRightLeg();
	drawLeftArm();
	drawRightArm();
	drawHead();
}

void Rider::resetPosition()
{
	xForward = 0.0;
	zForward = 0.0;
}

void Rider::speedUp(){
	if (movementSpeed < 0.001) {
		pedalingSpeed = 1.0;
		movementSpeed += 0.1;
	} else if (pedalingSpeed < 2.0) {
		pedalingSpeed += 0.1;
		movementSpeed += 0.1;
	}
}

void Rider::slowDown(){
	if (pedalingSpeed > 1.0) {
		pedalingSpeed -= 0.1;
		movementSpeed -= 0.1;
	} else if (pedalingSpeed == 1.0) {
		pedalingSpeed = 0.0;
		movementSpeed = 0.0;
	}
}

void Rider::turnLeft()
{
	if (steeringAngle < 60) {
		steeringAngle += 5;
	}
}

void Rider::turnRight()
{
	if (steeringAngle > -60) {
		steeringAngle -= 5;
	}
}

void Rider::setFrameCounter(int frameCounter){
	if (pedalingSpeed < 0.001) {
		this->frameCounter = 0;
	}
	else {
		this->frameCounter = frameCounter;
		pedalingAngle = (float)frameCounter*(1 + pedalingSpeed)*PI / 180.0;
	
	}
}
