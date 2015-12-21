#include <windows.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cfloat>
#include <GL/gl.h>
#include "glut.h"
#include "environment.h"
#include "bike.h"
#define PI 3.14159265

static Environment* world;
static Bike* bike;
static int frame_no = 0;
static bool rotate_right = false, rotate_left = false, rotate_up = false, rotate_down = false;
static GLfloat Xforward = 0, Zforward = 0, turn = 0, pedalingSpeed = 0, previousTurn = 0, previous2Turn = 0, previous3Turn = 0;
static const GLfloat step = 3.0;
static GLUquadricObj *quadratic = gluNewQuadric();

void init()
{
	srand(time(NULL));

	glMaterialfv(GL_FRONT, GL_AMBIENT, Environment::MAT_ABIENT);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Environment::MAT_SPECULAR);
	glMaterialf(GL_FRONT, GL_SHININESS, 35.0);
	glLightfv(GL_LIGHT0, GL_POSITION, Environment::LIGHT_POSITION);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Environment::LM_ABIENT);

	glEnable(GL_NORMALIZE); // normalize normal vectors

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0, 0.5, 1.0, 1.0f);   // backgroung color
	glutPostRedisplay();

	world = new Environment();
	bike = new Bike();
}

void displayObjects(int frame_no)
{
	glPushMatrix();
	glRotatef(world->getXCamRot(), 1, 0, 0);
	glRotatef(world->getYCamRot(), 0, 1, 0);

	
	world->draw();
	bike->draw();

	glPopMatrix();
}


void display()
{
	static int frameCountSpeed = 0;
	frameCountSpeed++;
	if (frameCountSpeed % 6 == 0)
	{
		frameCountSpeed = 0;
		if (frame_no < 360)
		{
			frame_no++;
		}
		else
		{
			frame_no = 0;
		}
	}

	glMaterialf(GL_FRONT, GL_SHININESS, 35.0 + world->getIntensity());

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffer
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	//glRotatef(frame_no, 0.0, 1.0, 0.0);  obiekty sa szare, tu sie nie obraca kamery
	glMatrixMode(GL_MODELVIEW);
	displayObjects(frame_no);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h)
{
	if (h > 0 && w > 0) 
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (w <= h) 
		{
			glOrtho(-2.25, 2.25, -2.25*h / w, 2.25*h / w, -10.0, 10.0);
		}
		else 
		{
			glOrtho(-2.25*w / h, 2.25*w / h, -2.25, 2.25, -10.0, 10.0);
		}
		glMatrixMode(GL_MODELVIEW);
	}
}

/*
* Keyboart and mouse support
* x,y - mouse position
*/
static void control(unsigned char key, int x, int y)
{
 	switch (key) 
	{
		case 'z' :
			world->darker();
			break;
		case 'x' :
			world->brighter();
			break;
		case 'w' :
			world->xCamRotAdd();
			break;
		case 'a' :
			world->yCamRotAdd();
			break;
		case 's' :
			world->xCamRotSub();
			break;
		case 'd' :
			world->yCamRotSub();
			break;
	}
	glutPostRedisplay(); //window refresh is needed
}

static void specialControl(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		bike->speedUp();
		break;
	case GLUT_KEY_DOWN:
		bike->slowDown();
		break;
	case GLUT_KEY_LEFT:
		bike->turnLeft();
		break;
	case GLUT_KEY_RIGHT:
		bike->turnRight();
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	int scrH = glutGet(GLUT_SCREEN_HEIGHT);
	int scrW = glutGet(GLUT_SCREEN_WIDTH);
	glutInitWindowPosition((scrW - 1200)/2, (scrH-800)/2);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("GKOM - Cyclist");

	glutDisplayFunc(display);			//register displaying function
	glutReshapeFunc(reshape);			//register function responsible for changing parameters afrer window resize
	glutKeyboardFunc(control);			//register control function
	glutSpecialFunc(specialControl);	//register special keys
	glutIdleFunc(display);				//refresh view

	init();								
	glutMainLoop();

	return 0;
}