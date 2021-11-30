#include <Windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 720
int state = 1;
float x = 20;

float circlePoints = 100;

void treepart1() //Right Up
{
	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 30);
	glVertex2f(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2);
	glVertex2f(SCREEN_WIDTH / 2 + 30, SCREEN_HEIGHT / 2);
}

void treepart2()
{
	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	glVertex2f(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 - 30);
	glVertex2f(SCREEN_WIDTH / 2 + 30, SCREEN_HEIGHT / 2 - 30);
}

void treepart3()
{
	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 30);
	glVertex2f(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 + 30, SCREEN_HEIGHT / 2 - 60);
}

void treepart4()
{
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex2i(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 - 60);
	glVertex2i(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 60);
	glVertex2i(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 - 120);
	glVertex2i(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 120);
}

void tree()
{
	glBegin(GL_TRIANGLES);
	treepart1();
	treepart2();
	treepart3();
	glEnd();
	glBegin(GL_QUADS);
	treepart4();
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clear the screen and filled with glClearColor
	tree();
	glutSwapBuffers(); 
}

void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Setting up a camera for 2-Dimension
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

	glPointSize(1.0); //Setup the Points Size to 10 pixels
	glLineWidth(1.0); //Setup the Line Width to 10 pixels
}

void timer(int) //Motion of the object
{
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	switch (state)
	{
	case 1: //Move to right
		if (x < 1280)
		{
			x += 20;
		}
		else
		{
			state = -1;
		}
		break;
	case 2:
		if (x > 0)
		{
			x += 20;
		}
		else
		{
			state = 1;
		}
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //RGB mode and DOUBLE BUFFER DISPLAY mode
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); //Setup the window size
	glutCreateWindow("Group Project 1"); //Setup the window with string as title
	glutDisplayFunc(display);
	glutTimerFunc(0, timer,0); //Call the function after 1 second, as we are not passing any value, the 3rd parameter is 0

	initGL();
	glutMainLoop(); //Tell the glut I had finished initialisation and start compiling
}