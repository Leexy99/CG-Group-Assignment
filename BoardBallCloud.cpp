#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280; //X-Coordinate for static object
int SCREEN_HEIGHT = 720; //Y-Coordinate for static object
int x_position = 1280; //X-Coordinate of motion object 1
int y_position = 720; //Y-coordinate of motion object 1
int cloud_x_position = 1280; //X-coordinate of motion cloud
int cloud_y_position = 720; //Y-Coordinate of motion cloud
int state = 1; //Set the ball state to 1 (Original State towards the basketball net)
#define PI 3.142

int x = 30, y = 50;
int dx = 10, dy = 15;
int i, a = 0, b = 0;
double radius = 0.30;

void cloudPart(int n, int x, int y, int r)
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
	cloudPart(360, cloud_x_position / 2 - 300, cloud_y_position / 2 + 250, 70); //Center cloud
	cloudPart(360, cloud_x_position / 2 - 250, cloud_y_position / 2 + 250, 50); //Right part of cloud
	cloudPart(360, cloud_x_position / 2 - 350, cloud_y_position / 2 + 250, 50); //Left part of cloud
	glEnd();
}

void cloud2()
{
	glBegin(GL_TRIANGLE_FAN);
	cloudPart(360, cloud_x_position / 2 + 400, cloud_y_position / 2 + 200, 70); //Center cloud
	cloudPart(360, cloud_x_position / 2 + 450, cloud_y_position / 2 + 200, 50); //Right part of cloud
	cloudPart(360, cloud_x_position / 2 + 350, cloud_y_position / 2 + 200, 50); //Left part of cloud
	glEnd();
}

void bluesky()
{
	glColor3f(0.2, 0.7, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, y_position);
	glVertex2i(x_position, y_position);
	glVertex2i(x_position, 0);
	glEnd();
}

void skyWithCloud()
{
	bluesky();
	cloud();
	cloud2();
}

void rectangle(int x, int y, int w, int h)
{
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void board(int x, int y, int w)
{
	int h = 0.75 * w;

	// draw board outline
	glColor3ub(155, 155, 155);
	rectangle(x, 2.5 * y, w, h);
	//draw board 
	glColor3ub(240, 182, 81);
	rectangle(x + w / 60, 2.5 * y, w - 8, h - 2);
	//draw small box outline
	glColor3ub(255, 0, 0);
	rectangle(x + w / 2 - w / 4, 2.5 * y, w / 2, h / 2);
	//draw small box 
	glColor3ub(240, 182, 81);
	rectangle(x + w / 2 - w / 4.5, 2.5 * y, w / 2.2, h / 2.2);
	//draw pillar
	glColor3ub(61, 61, 61);
	rectangle(x + w / 2 - w / 10, y - (h / 1.9), w / 5, 2 * h / 1.5);
	
	//draw net
	glColor3ub(128, 128, 128);
	glBegin(GL_POLYGON);
		glVertex2i(x + w / 2 - w / 4.5, 2.5 * y);
		glVertex2i(x + w / 1.37, 2.5 * y);
		glVertex2i(x + w / 1.5, 1.8 * y);
		glVertex2i(x + w / 2 - w / 6, 1.8 * y);
	glBegin(GL_POLYGON);
	glEnd();
}

void basketball(int n, int x, int y, int r)
{
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(255, 255, 0.0); //Setting: Color of the shape; The value is the RGB value
		double inc = 2 * PI / (double)n;
		for (double theta = 0.0; theta <= 2 * PI; theta += inc)
		{
			glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
		}
	glEnd();
}

void timer(int) //Motion
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	if (SCREEN_WIDTH > 500) //Move towards the Basketball Net (Fly UP)
	{
		SCREEN_WIDTH -= 10;
		SCREEN_HEIGHT += 3;
		basketball(360, SCREEN_WIDTH, SCREEN_HEIGHT, 50);
	}
	else if (SCREEN_WIDTH > 400) //Move towards the Basketball Net (Drop DOWN)
	{
		SCREEN_WIDTH -= 10;
		SCREEN_HEIGHT -= 6;
		basketball(360, SCREEN_WIDTH, SCREEN_HEIGHT, 50);
	}
	else if (SCREEN_WIDTH > 200) //Move towards the sky
	{
		SCREEN_WIDTH += 0.5;
		SCREEN_HEIGHT += 10;
		basketball(360, SCREEN_WIDTH, SCREEN_HEIGHT, 50);
	}

	switch (state)
	{
	case 1: //Move to right
		if (cloud_x_position <= 2560)
		{
			cloud_x_position += 10;
		}
		else
		{
			state = -1;
		}
		break;
	case -1: //Move to left
		if (cloud_x_position > 0)
		{
			cloud_x_position -= 10;
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
	glClear(GL_COLOR_BUFFER_BIT);
	skyWithCloud();
	board(100, 100, 250);
	basketball(360, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 600, 50);
	glFlush();
	glutSwapBuffers();
}

void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

	glPointSize(10.0);
	glLineWidth(5.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Board and Basketball");
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0); //Call the function after 1 second, as we are not passing any value, the 3rd parameter is 0

	initGL();
	glutMainLoop();
}