#include <windows.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <cfloat>
#include <GL/gl.h>
#include "glut.h"
#include "Environment.h"
#define PI 3.14159265

static Environment* world;
static int frame_no = 0;
static bool rotate_right = false, rotate_left = false, rotate_up = false, rotate_down = false, companyOn = false;
static GLfloat Xrot = 12, Yrot = 0, Zrot = 0, Xforward = 0, Zforward = 0, turn = 0, movementSpeed = 0, pedalingSpeed = 0, previousTurn = 0, previous2Turn = 0, previous3Turn = 0, intensity = 0.0;
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

	glEnable(GL_NORMALIZE); // dbaj o ot zeby wektory normalne mialy dlugosc jednostkowa

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0, 0.5, 1.0, 1.0f);   // kolor tla
	glutPostRedisplay();

	world = new Environment();
}

void displayObjects(int frame_no)
{
	glPushMatrix();
	glRotatef(Xrot, 1, 0, 0);
	glRotatef(Yrot, 0, 1, 0);
	glRotatef(Zrot, 0, 0, 1);
	
	world->draw();

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

	glMaterialf(GL_FRONT, GL_SHININESS, 35.0 + intensity);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //wyczysc bufory
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	//glRotatef(frame_no, 0.0, 1.0, 0.0);  obiekty sa szare, tu sie nie obraca kamery
	glMatrixMode(GL_MODELVIEW);
	displayObjects(frame_no);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glFlush(); //wyswietl
	glutSwapBuffers();   // zamien bufory
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
	
	}
	glutPostRedisplay(); //window refresh is needed
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
	glutIdleFunc(display);				//refresh view

	init();								
	glutMainLoop();

	return 0;
}