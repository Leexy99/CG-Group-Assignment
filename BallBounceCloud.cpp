#include <Windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280; //X-Coordinate for static object
int SCREEN_HEIGHT = 720; //Y-Coordinate for static object
int x_position = 1280; //X-Coordinate of motion object 1
int y_position = 720; //Y-coordinate of motion object 1
int cloud_x_position = 1280; //X-coordinate of motion cloud
int cloud_y_position = 720; //Y-Coordinate of motion cloud
int ball_WIDTH = SCREEN_WIDTH - 1180;
int ball_HEIGHT = SCREEN_HEIGHT - 620;

#define PI 3.142
int state = 1;
float x = 40;

float circlePoints = 100;

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
	cloudPart(360, cloud_x_position / 2 - 300, cloud_y_position / 2, 70);
	cloudPart(360, cloud_x_position / 2 - 250, cloud_y_position / 2, 50);
	cloudPart(360, cloud_x_position / 2 - 350, cloud_y_position / 2, 50);
	glEnd();
}

void bluesky()
{
	glColor3ub(0.0, 0.0, 255);
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

void timer(int) //Motion of the object
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	if (ball_WIDTH >= 100 && ball_WIDTH < 320) //Move towards the Basketball Net (Fly UP)
	{
		ball_WIDTH += 3;
		ball_HEIGHT += 5;
		basketball(360, ball_WIDTH, ball_HEIGHT, 50);
	}
	else if (ball_HEIGHT > 320 && ball_WIDTH < 420)
	{
		ball_WIDTH += 3;
		ball_HEIGHT -= 3;
		basketball(360, ball_WIDTH, ball_HEIGHT, 50);
	}
	else if (ball_HEIGHT > 300 && ball_WIDTH >= 420)
	{
		ball_WIDTH += 3;
		ball_HEIGHT += 3;
		basketball(360, ball_WIDTH, ball_HEIGHT, 50);
	}

	switch (state) //Motion for cloud
	{
	case 1: //Move to right
		if (cloud_x_position <= 2560)
		{
			cloud_x_position += 2;
		}
		else
		{
			state = -1;
		}
		break;
	case -1: //Move to left
		if (cloud_x_position > 0)
		{
			cloud_x_position -= 2;
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
	skyWithCloud();
	basketball(360, ball_WIDTH, ball_HEIGHT, 50);
	glFlush();
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