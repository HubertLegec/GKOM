#include "bike.h"

const GLfloat Bike::OPONY_DIFFUSE[4] = { 0.2, 0.2, 0.2, 1.0 };
const GLfloat Bike::szprychy_diffuse[4] = { 0.4, 0.4, 0.4, 1.0 };
const GLfloat Bike::rower_diffuse[4] = { 0.8, 0.0, 0.0, 1.0 };
static GLUquadricObj *quadratic = gluNewQuadric();

void Bike::drawFrontWheel()
{
	glPushMatrix();
	glTranslatef(1.2, 0.0, 0.0);
	glRotatef(steeringAngle, 0, 1, 0); // skrecanie
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	glutSolidTorus(0.04, 0.3, 30, 30);
	glPopMatrix();
}

void Bike::drawRearWheel()
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, OPONY_DIFFUSE);
	glutSolidTorus(0.035, 0.3, 30, 30);
	glPopMatrix();
}

void Bike::drawFrame()
{
	glPushMatrix();  //rama ukos
	//glTranslatef(offsetX, 0.0, offsetZ);
	//glTranslatef(Xforward, -0.35*(1 - scaleY), Zforward);
	glTranslatef(0.4, 0.0, 0.0);
	//glScalef(scaleX, scaleY, scaleZ);
	//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
	glRotatef(28, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, rower_diffuse);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.9, 10, 10);
	glPopMatrix();

	//rama pozioma
	glPushMatrix();
	glTranslatef(0.33, 0.5, 0.0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.87, 10, 10);
	glPopMatrix();

	//rama pionowa
	glPushMatrix();
	glTranslatef(0.32, 0.6, 0.0);
	glRotatef(7, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.6, 10, 10);
	glPopMatrix();

	//pod kierownica
	glPushMatrix();
	glTranslatef(1.2, 0.6, 0.0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.23, 10, 10);
	glPopMatrix();

	//support
	glPushMatrix();
	glTranslatef(0.4, 0.0, -0.07);
	gluCylinder(quadratic, 0.04f, 0.04f, 0.14, 10, 10);
	glPopMatrix();

	//wsporniki tylnego kola
	//poziome
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.06);
	glRotatef(-2, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.4, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.06);
	glRotatef(2, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.4, 10, 10);
	glPopMatrix();
	//skoœne
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.06);
	glRotatef(54, 0, 0, 1);
	glRotatef(-3, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.62, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.06);
	glRotatef(54, 0, 0, 1);
	glRotatef(3, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.62, 10, 10);
	glPopMatrix();


	//osie
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.07);
	gluCylinder(quadratic, 0.01f, 0.01f, 0.14, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 0.0, -0.07);
	gluCylinder(quadratic, 0.01f, 0.01f, 0.14, 10, 10);
	glPopMatrix();

	//widelki
	glPushMatrix();
	glTranslatef(1.2, 0.37, -0.07);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.14, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 0.39, -0.06);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.40, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 0.39, 0.06);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.02f, 0.02f, 0.40, 10, 10);
	glPopMatrix();

	//kierownica
	glPushMatrix();
	glTranslatef(1.2, 0.6, -0.27);
	gluCylinder(quadratic, 0.015f, 0.015f, 0.54, 10, 10);
	glPopMatrix();

}

void Bike::drawSpokes()
{
	for (int i = 0; i < 6; i++)
	{
		//rear
		glPushMatrix();
		//glTranslatef(offsetX, 0.0, offsetZ);
		//glTranslatef(Xforward, -0.35*(1 - scaleY), Zforward);
		//glTranslatef(-0.65*scaleX, -0.28*scaleY, 0.0);
		//glScalef(scaleX, scaleY, scaleZ);
		//glTranslatef(0.0, 0.28, 0.0);
		//glRotatef(previous3Turn, 0, 1, 0); // skrecanie opoznione
		//if (pedalingSpeed > 0.1)
		//{
		//	glRotatef((float)frameCounter + 30 * i, 0.0, 0.0, -1.0);
		//}
		//else
		{
			glRotatef(30 * i, 0.0, 0.0, -1.0);
		}
		glTranslatef(0.0, -0.28, 0.0);  // bo sie obraca wokol konca a nie srodka
		glRotatef(90, 0, 0, 1);
		glRotatef(90, 0, 1, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, szprychy_diffuse);
		gluCylinder(quadratic, 0.01f, 0.01f, 0.56, 10, 10);
		glPopMatrix();

		//front
		glPushMatrix();
		//glTranslatef(offsetX, 0.0, offsetZ);
		//glTranslatef(((int)abs(turn) % 180)*-0.0013 * scaleX, 0.0, 0.0); // emuluje wspolosiowosc
		//glTranslatef(Xforward, -0.35*(1 - scaleY), Zforward);
		glTranslatef(1.2, -0.28, 0.0);
		//glScalef(scaleX, scaleY, scaleZ);
		glTranslatef(0.0, 0.28, 0.0);
		glRotatef(steeringAngle, 0, 1, 0); // skrecanie
		//if (pedalingSpeed > 0.1)
		//{
		//	glRotatef((float)frameCounter + 30 * i, 0.0, 0.0, -1.0);
		//}
		//else
		{
			glRotatef(30 * i, 0.0, 0.0, -1.0);
		}
		glTranslatef(0.0, -0.28, 0.0);
		glRotatef(90, 0, 0, 1);
		glRotatef(90, 0, 1, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, szprychy_diffuse);
		gluCylinder(quadratic, 0.01f, 0.01f, 0.56, 10, 10);
		glPopMatrix();
	}
}

Bike::Bike() {

}

void Bike::slowDown() {
	movementSpeed -= 0.1;
}

void Bike::draw()
{
	drawRearWheel();
	drawFrontWheel();
	drawSpokes();
	drawFrame();
}

void Bike::speedUp() {
	movementSpeed += 0.1;
}

void Bike::turnLeft() {

}

void Bike::turnRight() {

}
