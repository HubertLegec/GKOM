#define PI 3.14159265
#include "bike.h"
#include <cmath>
#include <iostream>

const GLfloat Bike::OPONY_DIFFUSE[4] = { 0, 0, 0, 1 };
const GLfloat Bike::SPOKES_DIFFUSE[4] = { 0.4, 0.4, 0.4, 1.0 };
const GLfloat Bike::BIKE_DIFFUSE[4] = { 0.8, 0.001, 0.05, 1.0 };
const GLfloat Bike::PEDAL_VERTICES[24] = { -0.04, -0.02, 0.06,
											0.04, -0.02, 0.06,
											0.04, -0.02, -0.06,
											-0.04, -0.02, -0.06,
											-0.04, 0.02, 0.06,
											0.04, 0.02, 0.06,
											0.04, 0.02, -0.06,
											-0.04, 0.02, -0.06 };
const GLubyte Bike::PEDAL_INDICES[36] = { 0, 1, 2,
											2, 3, 0,
											0, 3, 4,
											3, 4, 7,
											3, 2, 7,
											7, 2, 6,
											1, 2, 5,
											5, 2, 6,
											0, 1, 5,
											0, 5, 4,
											4, 7, 6,
											6, 5, 4 };
const GLfloat Bike::SADDLE_VERTICES[24] = { -0.12, 0.0, 0.05,
											0.12, 0.0, 0.05,
											0.12, 0.0, -0.05,
											-0.12, 0.0, -0.05,
											-0.12, 0.04, 0.05,
											0.12, 0.04, 0.05,
											0.12, 0.04, -0.05,
											-0.12, 0.04, -0.05 };
const GLubyte Bike::SADDLE_INDICES[36] = { 0, 1, 2,
											2, 3, 0,
											0, 3, 4,
											3, 4, 7,
											3, 2, 7,
											7, 2, 6,
											1, 2, 5,
											5, 2, 6,
											0, 1, 5,
											0, 5, 4,
											4, 7, 6,
											6, 5, 4 };

void Bike::drawFrontWheel()
{
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle*180/PI, 0, 1, 0);
	glTranslatef(0.6, 0.0, 0.0);
	glRotatef(steeringAngle, 0, 1, 0); // skrecanie
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	glutSolidTorus(0.04, 0.3, 30, 30);
	glPopMatrix();
}

void Bike::drawRearWheel()
{
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle*180/PI, 0, 1, 0);
	glTranslatef(-0.6, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	glutSolidTorus(0.035, 0.3, 30, 30);
	glPopMatrix();
}

void Bike::drawFrame()
{
	glPushMatrix();  //rama ukos
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle*180/PI, 0, 1, 0);
	glTranslatef(-0.2, 0.0, 0.0);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glRotatef(28, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	glColor4fv(BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.9, 10, 10);
	glPopMatrix();

	//rama pozioma
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle*180/PI, 0, 1, 0);
	glTranslatef(-0.27, 0.5, 0.0);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.87, 10, 10);
	glPopMatrix();

	//rama pionowa
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle*180/PI, 0, 1, 0);
	glTranslatef(-0.28, 0.6, 0.0);
	glRotatef(7, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.6, 10, 10);
	glPopMatrix();

	//pod kierownica
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.6, 0.0);
	glRotatef(90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.23, 10, 10);
	glPopMatrix();

	//support
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.2, 0.0, -0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.04f, 0.04f, 0.14, 10, 10);
	glPopMatrix();

	//wsporniki tylnego kola
	//poziome
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.6, 0.0, -0.06);
	glRotatef(-2, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.4, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.6, 0.0, 0.06);
	glRotatef(2, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.4, 10, 10);
	glPopMatrix();
	//skoœne
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.6, 0.0, -0.06);
	glRotatef(54, 0, 0, 1);
	glRotatef(-3, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.62, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.6, 0.0, 0.06);
	glRotatef(54, 0, 0, 1);
	glRotatef(3, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.62, 10, 10);
	glPopMatrix();

	//osie
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.6, 0.0, -0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.01f, 0.01f, 0.14, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.0, -0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.01f, 0.01f, 0.14, 10, 10);
	glPopMatrix();

	//widelki
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.37, 0);
	glRotatef(steeringAngle, 0, 1, 0);
	glTranslatef(0, 0, -0.07);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.14, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.39, 0);
	glRotatef(steeringAngle, 0, 1, 0);
	glTranslatef(0, 0, -0.06);
	glRotatef(90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.40, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.39, 0);
	glRotatef(steeringAngle, 0, 1, 0);
	glTranslatef(0, 0, 0.06);
	glRotatef(90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, BIKE_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.40, 10, 10);
	glPopMatrix();

	//siode³ko
	glEnableClientState(GL_VERTEX_ARRAY);
	glPushMatrix();
	glVertexPointer(3, GL_FLOAT, 0, SADDLE_VERTICES);
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.3, 0.6, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, SADDLE_INDICES); // draw specified vertices
	glPopMatrix();
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Bike::drawSpokes(){
	for (int i = 0; i < 6; i++){
		//rear
		glPushMatrix();
		glTranslatef(xForward, 0.0, zForward);
		glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
		glTranslatef(-0.6, 0, 0);
		//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
		if (pedalingSpeed >= 1){
			glRotatef((float)frameCounter*(1.3 + pedalingSpeed) + 30 * i, 0.0, 0.0, -1.0);
		}else{
			glRotatef(30 * i, 0.0, 0.0, -1.0);
		}
		glTranslatef(0.0, -0.28, 0.0);
		glRotatef(90, 0, 0, 1);
		glRotatef(90, 0, 1, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, SPOKES_DIFFUSE);
		gluCylinder(quadratic, 0.01f, 0.01f, 0.56, 10, 10);
		glPopMatrix();

		//front
		glPushMatrix();
		//glTranslatef(((int)abs(turn) % 180)*-0.0013 * scaleX, 0.0, 0.0); // emuluje wspolosiowosc
		glTranslatef(xForward, 0.0, zForward);
		glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
		glTranslatef(0.6, -0.28, 0.0);
		glTranslatef(0.0, 0.28, 0.0);
		glRotatef(steeringAngle, 0, 1, 0); // skrecanie
		if (pedalingSpeed >= 1){
			glRotatef((float)frameCounter*(1.3 + pedalingSpeed) + 30 * i, 0.0, 0.0, -1.0);
		} else {
			glRotatef(30 * i, 0.0, 0.0, -1.0);
		}
		glTranslatef(0.0, -0.28, 0.0);
		glRotatef(90, 0, 0, 1);
		glRotatef(90, 0, 1, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, SPOKES_DIFFUSE);
		gluCylinder(quadratic, 0.01f, 0.01f, 0.56, 10, 10);
		glPopMatrix();
	}
}

void Bike::drawHandlebar()
{
	//kierownica
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.6, 0);
	glRotatef(steeringAngle, 0, 1, 0);
	glTranslatef(0, 0, -0.27);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.54, 10, 10);
	glPopMatrix();

	//raczki kierownicy
	glPushMatrix();  
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.6, 0);
	glRotatef(steeringAngle, 0, 1, 0);
	glTranslatef(0, 0, -0.27);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(0.6, 0.6, 0);
	glRotatef(steeringAngle, 0, 1, 0);
	glTranslatef(0, 0, 0.17);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.1, 10, 10);
	glPopMatrix();
}

void Bike::drawPedals()
{
	//prawy peda³
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.2, 0.0, 0.06);
	glRotatef(180.0, 0.0, 0.0, -1.0);
	if (pedalingSpeed >= 1) {
		glRotatef((float)frameCounter*(1 + pedalingSpeed), 0.0, 0.0, -1.0);
	}
	glRotatef(90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.2, 10, 4);
	glPopMatrix();

	//lewy peda³
	glPushMatrix();
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.2, 0.0, -0.06);
	if (pedalingSpeed >= 1) {
		glRotatef((float)frameCounter*(1+pedalingSpeed), 0.0, 0.0, -1.0);
	}
	glRotatef(90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.2, 10, 4);
	glPopMatrix();

	glEnableClientState(GL_VERTEX_ARRAY);
	// prawy peda³
	glPushMatrix();
	glVertexPointer(3, GL_FLOAT, 0, PEDAL_VERTICES);
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.2, 0.0, 0.12);
	if (pedalingSpeed >= 1) {
		glTranslatef(sin(pedalingAngle)*0.2, cos(pedalingAngle)*0.2, 0.0);
	} else {
		glTranslatef(0.0, 0.2, 0.0);
	}
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, PEDAL_INDICES); // draw specified vertices
	glPopMatrix();

	//lewy peda³
	glPushMatrix();
	glVertexPointer(3, GL_FLOAT, 0, PEDAL_VERTICES);
	glTranslatef(xForward, 0.0, zForward);
	glRotatef(bikeAngle * 180 / PI, 0, 1, 0);
	glTranslatef(-0.2, 0.0, -0.12);
	if (pedalingSpeed >= 1) {
		glTranslatef(sin(PI+pedalingAngle)*0.2, cos(PI+pedalingAngle)*0.2, 0.0);
	}
	else {
		glTranslatef(0.0, -0.2, 0.0);
	}
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, PEDAL_INDICES); // draw specified vertices
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
}

Bike::Bike() {

}

void Bike::slowDown() {
	if (pedalingSpeed > 1.0) {
		pedalingSpeed -= 0.1;
		movementSpeed -= 0.1;
	}else if(pedalingSpeed == 1.0){
		pedalingSpeed = 0.0;
		movementSpeed = 0.0;
	}
}

void Bike::draw()
{
	drawRearWheel();
	drawFrontWheel();
	drawSpokes();
	drawFrame();
	drawHandlebar();
	drawPedals();
}

void Bike::speedUp() {
	if (movementSpeed < 0.001) {
		pedalingSpeed = 1.0;
		movementSpeed += 0.1;
	}else if(pedalingSpeed < 2.0){
		pedalingSpeed += 0.1;
		movementSpeed += 0.1;
	}
}

void Bike::turnLeft() {
	if (steeringAngle < 60) {
		steeringAngle += 5;
	}
}

void Bike::turnRight() {
	if (steeringAngle > -60) {
		steeringAngle -= 5;
	}
}

void Bike::resetPosition(){
	xForward = 0.0;
	zForward = 0.0;
	steeringAngle = 0.0;
	bikeAngle = 0.0;
	pedalingSpeed = 0.0;
	movementSpeed = 0.0;
}

void Bike::setFrameCounter(int frameCounter)
{
	if (pedalingSpeed < 0.001) {
		this->frameCounter = 0;
	}
	else {
		this->frameCounter = frameCounter;
		pedalingAngle = (float)frameCounter*(1 + pedalingSpeed)*PI / 180.0;
		//calculate bike position
		float frontWheelX, frontWheelZ, rearWheelX, rearWheelZ;

		frontWheelX = xForward + wheelBase / 2 * cos(bikeAngle);
		frontWheelZ = zForward + wheelBase / 2 * sin(bikeAngle);

		rearWheelX = xForward - wheelBase / 2 * cos(bikeAngle);
		rearWheelZ = zForward - wheelBase / 2 * sin(bikeAngle);

		rearWheelX += movementSpeed * 0.05 * cos(bikeAngle);
		rearWheelZ += movementSpeed * 0.05 * sin(bikeAngle);

		frontWheelX += movementSpeed * 0.05 * cos(bikeAngle + steeringAngle*PI/180);
		frontWheelZ += movementSpeed * 0.05 * sin(bikeAngle + steeringAngle*PI/180);

		xForward = (frontWheelX + rearWheelX) / 2;
		zForward = (frontWheelZ + rearWheelZ) / 2;

		bikeAngle = atan2(frontWheelZ - rearWheelZ, frontWheelX - rearWheelX);
	}
}
