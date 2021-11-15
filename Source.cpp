#include <Windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 720
#define PI 3.142

//Draw a rectangle
void rectangle(int x, int y, int w, int h)
{
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

//Draw a circle	
void nGon(int n, int x, int y, int r)
{
	glColor3f(255, 255, 0.0); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
}

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

//Draw a triangle
void suntriangle1() //Center Up
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 80);
	glVertex2f(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 + 60);
}

void suntriangle2() //Left Up Corner
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 30);
}

void suntriangle3() //Left Center
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 20);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 20);
}

void suntriangle4()
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2 + 30, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 + 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 + 30);
}

void suntriangle5() //Center Down
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 80);
	glVertex2f(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 60);
}

void suntriangle6() //Right Down Corner
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2 + 30, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 - 30);
}

void suntriangle7() //Right Center
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2 + 80, SCREEN_HEIGHT / 2);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 - 20);
	glVertex2f(SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2 + 20);
}

void suntriangle8() //Right Up
{
	glColor3f(255, 0.0, 0.0);
	glVertex2f(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 60);
	glVertex2f(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 - 30);
}

void sun()
{
	glBegin(GL_TRIANGLE_FAN);
	nGon(360, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 50);
	glEnd();

	glBegin(GL_TRIANGLES);
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
	//This is the place that all the things get place
	glClear(GL_COLOR_BUFFER_BIT); //Clear the screen and filled with glClearColor
	// sun();
	// cloud();
	tree();
	glFlush(); //Send all the vertex into the screen
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
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); //Setup the window size
	glutCreateWindow("Group Project 1"); //Setup the window with string as title
	glutDisplayFunc(display);

	initGL();
	glutMainLoop(); //Tell the glut I had finished initialisation and start compiling
}