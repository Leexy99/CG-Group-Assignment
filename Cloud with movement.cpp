#include <Windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
#define PI 3.142
int state = 1;
float x = 40;

float circlePoints = 100;

void cloudPart1(int n, int x, int y, int r)
{
	glColor3f(173, 216, 230); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
}

void cloudPart2(int n, int x, int y, int r)
{
	glColor3f(173, 216, 230); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
}

void cloudPart3(int n, int x, int y, int r)
{
	glColor3f(173, 216, 230); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
}

void cloud()
{
	glBegin(GL_TRIANGLE_FAN);
	cloudPart1(360, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 70);
	cloudPart1(360, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2, 50);
	cloudPart1(360, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2, 50);
	glEnd();
}

void timer(int) //Motion of the object
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	switch (state)
	{
	case 1: //Move to right
		if (SCREEN_WIDTH <= 2560)
		{
			SCREEN_WIDTH += 10;
		}
		else
		{
			state = -1;
		}
		break;
	case -1: //Move to left
		if (SCREEN_WIDTH > 0)
		{
			SCREEN_WIDTH -= 10;
		}
		else
		{
			state = 1;
		}
		break;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clear the screen and filled with glClearColor
	cloud();
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //RGB mode and DOUBLE BUFFER DISPLAY mode
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); //Setup the window size
	glutCreateWindow("Group Project 1"); //Setup the window with string as title
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0); //Call the function after 1 second, as we are not passing any value, the 3rd parameter is 0


	initGL();
	glutMainLoop(); //Tell the glut I had finished initialisation and start compiling
}