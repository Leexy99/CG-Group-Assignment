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
int state = 1;



void ball(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();
}

void rectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void trapezium(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x - w / 8, y + h);
	glVertex2i(x + w + w / 8, y + h);
	glVertex2i(x + w, y + h + h / 2);
	glVertex2i(x, y + h + h / 2);
	glEnd();
}

void triangle(int x, int y, int w, int h) {
	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x + w, y);
	glEnd();
}

void triangle_invert(int x, int y, int w, int h) {
	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x - w, y);
	glVertex2i(x - w, y + h);
	glEnd();
}




void balls()
{
	//gold ball
	glColor3ub(255, 220, 0);
	ball(360, ball_x_position * 0.5, ball_y_position, 60);

	//blue ball
	glColor3ub(40, 25, 255);
	ball(360, ball_x_position * 0.25, ball_y_position, 60);

	//ori ball
	glColor3ub(255, 100, 0);
	ball(360, ball_x_position * 0.75, ball_y_position , 60);

	
}

void god_body() {
	//upper body
	glColor3ub(0, 193, 255);
	rectangle(SCREEN_WIDTH * 0.3125, SCREEN_HEIGHT * 0.425, SCREEN_WIDTH * 0.375, SCREEN_HEIGHT * 0.58);

	//lower body
	glColor3ub(106, 90, 205);
	trapezium(SCREEN_WIDTH * 0.3125, SCREEN_HEIGHT * 0.1, SCREEN_WIDTH * 0.375, 200);

	//left leg
	glColor3ub(255, 0, 0);
	rectangle(SCREEN_WIDTH * 0.3125, SCREEN_HEIGHT * 0.0625, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.3);
	//right leg
	rectangle(SCREEN_WIDTH * 0.5625, SCREEN_HEIGHT * 0.0625, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.3);

}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);



	switch (state) {
	case 1: 
		if (ball_y_position < 540)
			ball_y_position += 7.5;
		else
			state = -1;
		break;
	case -1:
		if (ball_y_position > 360)
			ball_y_position -= 7.5;
		else
			state = 1;
		break;
	}

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	god_body();
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
	glutCreateWindow("God character haha");
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);

	initGL();
	glutMainLoop();
}