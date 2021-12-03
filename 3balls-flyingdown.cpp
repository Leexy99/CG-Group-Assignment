#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	720
#define FPS	30


int bx = 640;
int by = 360;


void basketball(int n, int x, int y, int r)
{
	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(255, 255, 0.0); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}


void bluesky()
{
	glColor3f(0.2, 0.7, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, 720);
	glVertex2i(1280, 720);
	glVertex2i(1280, 0);
	glEnd();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	bluesky();
	//person(x, y, 30);
	glColor3ub(40, 25, 255);
	basketball(20, bx - 80, by, 30);
	glColor3ub(255, 220, 0);
	basketball(20, bx, by, 30);
	glColor3ub(255, 100, 0);
	basketball(20, (bx + 80), by, 30);

	glFlush();
	glutSwapBuffers();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);

	if (bx < 900 && by > 200)
	{
		bx += 5;
		by -= 5;
	}
	else
	{
		bx += 5;
		by -= 2;
	}

}


void initGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

	glPointSize(10.0);
	glLineWidth(5.0);
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Group project 1");
	glutDisplayFunc(display);
	glutTimerFunc(1000, timer, 0);
	initGL();

	glutMainLoop();
}