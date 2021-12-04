#include <windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>


int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
#define PI 3.142
int x_position = 1280;
int y_position = 720;
int ball_x_position = 1280;
int ball_y_position = 360;



void ball(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();
}


void balls() {
	//blue ball
	glColor3ub(255, 100, 0);
	ball(360, ball_x_position * 0.5, ball_y_position, ball_x_position * 0.25);
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	balls();
	//glFlush();
	glutSwapBuffers();
}


void initGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Blingbling effect lai");
	glutDisplayFunc(display);

	initGL();
	glutMainLoop();
}