#include <Windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

#define PI 3.142
int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;

//Draw a circle	
void sunCore(int n, int x, int y, int r)
{
	glColor3f(255, 255, 0.0); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
}

//Draw a triangle
void suntriangle1() //Center Up
{
	glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 80);
	glVertex2f(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 + 60);
}

void suntriangle2() //Left Up Corner
{
	glVertex2f(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 30);
}

void suntriangle3() //Left Center
{
	glVertex2f(SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 20);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 20);
}

void suntriangle4() //Left Down Corner
{
	glVertex2f(SCREEN_WIDTH / 2 + 30, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 + 30);
}

void suntriangle5() //Center Down
{
	glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 80);
	glVertex2f(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 60);
}

void suntriangle6() //Right Down Corner
{
	glVertex2f(SCREEN_WIDTH / 2 + 30, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 - 30);
}

void suntriangle7() //Right Center
{
	glVertex2f(SCREEN_WIDTH / 2 + 80, SCREEN_HEIGHT / 2);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 - 20);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 + 20);
}

void suntriangle8() //Right Up Corner
{
	glVertex2f(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 30);
}

void sun()
{
	glBegin(GL_TRIANGLE_FAN);
	sunCore(360, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 50);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(255, 0.0, 0.0);
	suntriangle1();
	suntriangle2();
	suntriangle3();
	suntriangle4();
	suntriangle5();
	suntriangle6();
	suntriangle7();
	suntriangle8();
	glEnd();
}

void display()
{
	//This is the place that all the things get place
	glClear(GL_COLOR_BUFFER_BIT); //Clear the screen and filled with glClearColor
	sun();
	glFlush();
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
	glutInitDisplayMode(GLUT_RGB); //RGB mode and DOUBLE BUFFER DISPLAY mode
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); //Setup the window size
	glutCreateWindow("Group Project 1"); //Setup the window with string as title
	glutDisplayFunc(display);

	initGL();
	glutMainLoop(); //Tell the glut I had finished initialisation and start compiling
}