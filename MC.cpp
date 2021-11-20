#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	720

void rectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}


void circle(int n, int x, int y, int r) {
	double inc = PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2d(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void v_Oval(int n, int x, int y, int r) {
	double inc = PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2d(3 * r / 4 * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void h_Oval(int n, int x, int y, int r) {
	double inc = PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2d(r * cos(theta) + x, r / 2 * sin(theta) + y);
	}
	glEnd();
}


void person(int x, int y, int w)
{
	int h = w;

	//head
	glColor3ub(241, 194, 125);
	v_Oval(20, x, y, w);
	//body
	glColor3ub(0, 0, 139);
	circle(20, x, y - (2 * w), w);
	rectangle(x - w, y - (4 * w), w * 2, h * 2);
	//pant and leg
	glColor3ub(0, 0, 205);
	rectangle(x - (0.75 * w), y - (5 * w), w * 1.5, h);
	glColor3ub(241, 194, 125);
	rectangle(x - (0.5 * w), y - (7 * w), w, h * 2);
	glColor3ub(255, 0, 0);
	h_Oval(20, x + (0.25 * w), y - (7 * w), 4 * w / 5);
	//hand
	glColor3ub(241, 194, 125);
	rectangle(x, y - (2.5 * w), w * 2.5, w);
	circle(20, x, y - (2 * w), w / 2);
	circle(20, x + (3 * w), y - (2 * w), w / 2);
	//basketball
	glColor3ub(255, 140, 0);
	circle(20, x + (4 * w), y - (2.5 * w), w);
	//face
	glColor3ub(255, 255, 255);
	h_Oval(5, x + (0.35 * w), y + (0.25 * w), w / 3);
	glColor3ub(0, 0, 0);
	circle(5, x + (0.4 * w), y + (0.25 * w), w / 7);
	//mouth
	glColor3ub(184, 105, 106);
	glBegin(GL_LINES);
	glVertex2f(x + (0.15 * w), y - (0.5 * w));
	glVertex2f(x + (0.65 * w), y - (0.5 * w));
	glEnd();



}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);


	person(500, 400, 30);

	glFlush();
	glutSwapBuffers();
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
	glutCreateWindow("Test");
	glutDisplayFunc(display);
	initGL();

	glutMainLoop();

}