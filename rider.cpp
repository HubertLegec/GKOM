#define PI 3.14159265
#include "rider.h"
#include <cstdlib>
#include <cmath>

const GLfloat Rider::HEAD_DIFFUSE[4] = { 0.6, 0.6, 0.0, 1.0 };
const GLfloat Rider::BODY_DIFFUSE[4] = { 0.0, 0.0, 0.6, 1.0 };

void Rider::drawBody(){
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.3, 0.74, 0.0);
	glRotatef(38, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.12f, 0.15f, 0.6, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.3, 0.73, 0.0);
	glRotatef(38, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.12, 10, 10);
	glPopMatrix();
}

void Rider::drawLeftLeg(){
	//udo
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.3, 0.7, -0.09);
	glRotatef(sin(1.1+PI+pedalingAngle) * 27 - 40, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.06f, 0.04f, 0.45, 10, 10);
	glPopMatrix();

	//kolano
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.3, 0.7, -0.09);
	glRotatef(sin(1.1 + PI + pedalingAngle) * 27 - 40, 0, 0, 1);
	glTranslatef(0.44, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.04, 10, 10);
	glPopMatrix();

	//³ydka
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.4 + sin(PI+pedalingAngle)*0.2, 0.05 + cos(PI+pedalingAngle)*0.2, -0.09);
	glRotatef(62 + sin(PI-0.6+pedalingAngle) * 23, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.04f, 0.035f, 0.46, 10, 10);
	glPopMatrix();

	//stopa
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.4 + sin(PI + pedalingAngle)*0.2, 0.05 + cos(PI + pedalingAngle)*0.2, -0.09);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.035f, 0.035f, 0.15, 10, 10);
	glPopMatrix();
}

void Rider::drawRightLeg(){
	//udo
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.3, 0.7, 0.09);
	glRotatef(sin(1.1+pedalingAngle) * 27 - 40, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.06f, 0.04f, 0.45, 10, 10);
	glPopMatrix();

	//kolano
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.3, 0.7, 0.09);
	glRotatef(sin(1.1 + pedalingAngle) * 27 - 40, 0, 0, 1);
	glTranslatef(0.44, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.04, 10, 10);
	glPopMatrix();

	//³ydka
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.4 + sin(pedalingAngle)*0.2, 0.05 + cos(pedalingAngle)*0.2, 0.09);
	glRotatef(sin(-0.6+pedalingAngle) * 23, 0, 0, 1);
	glRotatef(62, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.04f, 0.035f, 0.46, 10, 10);
	glPopMatrix();

	//stopa
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.4 + sin(pedalingAngle)*0.2 - 0.03, 0.05 + cos(pedalingAngle)*0.2, 0.09);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.035f, 0.035f, 0.15, 10, 10);
	glPopMatrix();
}

void Rider::drawLeftArm(){
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7, 1.09, -0.14);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7, 1.1, -0.15);
	glRotatef(-70 - 0.5*steeringAngle, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.04f, 0.03f, 0.45, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7, 1.1, -0.15);
	glRotatef(-70 - 0.5*steeringAngle, 0, 0, 1);
	glTranslatef(0.45, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.04, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7 + cos((-70 - 0.5*steeringAngle)* PI / 180)*0.45, 1.1 + sin((-70 - 0.5*steeringAngle)* PI / 180)*0.45, -0.15);
	glRotatef(-6 + 0.15*steeringAngle-0.12*abs(steeringAngle), 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.03f, 0.03f, 0.45, 10, 10);
	glPopMatrix();
}

void Rider::drawRightArm(){
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7, 1.09, 0.14);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.05, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7, 1.1, 0.15);
	glRotatef(-70 + 0.5*steeringAngle, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.04f, 0.03f, 0.45, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7, 1.1, 0.15);
	glRotatef(-70 + 0.5*steeringAngle, 0, 0, 1);
	glTranslatef(0.45, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluSphere(quadratic, 0.04, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.7 + cos((-70 + 0.5*steeringAngle)* PI / 180)*0.45, 1.1 + sin((-70 + 0.5*steeringAngle)* PI / 180)*0.45, 0.15);
	glRotatef(-6 - 0.15*steeringAngle - 0.12*abs(steeringAngle), 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BODY_DIFFUSE);
	gluCylinder(quadratic, 0.03f, 0.03f, 0.45, 10, 10);
	glPopMatrix();
}

void Rider::drawHead(){
	//szyja
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.77, 1.1, 0.0);
	glRotatef(38, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, HEAD_DIFFUSE);
	gluCylinder(quadratic, 0.05f, 0.05f, 0.1, 10, 10);
	glPopMatrix();

	//glowa
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(angle * 180 / PI, 0, 1, 0);
	glTranslatef(0.9, 1.2, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, HEAD_DIFFUSE);
	gluSphere(quadratic, 0.14, 10, 10);
	glPopMatrix();
}

Rider::Rider(){

}

void Rider::draw(){
	drawBody();
	drawLeftLeg();
	drawRightLeg();
	drawLeftArm();
	drawRightArm();
	drawHead();
}

void Rider::resetPosition(){
	xForward = 0;
	zForward = 0;
	steeringAngle = 0;
	angle = 0;
	pedalingSpeed = 0;
	movementSpeed = 0;
}

void Rider::speedUp(){
	if (movementSpeed < 0.001) {
		pedalingSpeed = 1.0;
		movementSpeed = 0.6;
	} else if(pedalingSpeed < 4.0) {
		pedalingSpeed += 0.2;
		movementSpeed += 0.2;
	}
}

void Rider::slowDown(){
	if (pedalingSpeed > 1.0) {
		pedalingSpeed -= 0.2;
		movementSpeed -= 0.2;
	} else if(pedalingSpeed <= 1.0) {
		pedalingSpeed = 0.0;
		movementSpeed = 0.0;
	}
}

void Rider::turnLeft(){
	if (steeringAngle < 60) {
		steeringAngle += 5;
	}
}

void Rider::turnRight(){
	if (steeringAngle > -60) {
		steeringAngle -= 5;
	}
}

void Rider::setFrameCounter(int frameCounter){
	if (pedalingSpeed < 0.001) {
		this->frameCounter = 0;
	} else{
		this->frameCounter = frameCounter;
		pedalingAngle = (float)frameCounter*(1 + pedalingSpeed)*PI / 180.0;
	
		angle += 0.01*steeringAngle*PI / 180;
		xForward += cos(angle)*0.01;
		zForward -= sin(angle)*0.01;
	}
}