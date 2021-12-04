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
int bling1_x_position = 320;
int bling1_y_position = 360;
int bling2_x_position = 360;
int bling2_y_position = 360;
int bling3_x_position = 960;
int bling3_y_position = 288;
int bling4_x_position = 1000;
int bling4_y_position = 288;
int state = 1;
int state_2 = 1;



void ball(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();
}

void bling(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x - (w / 2), y + h);
	glVertex2i(x - w, y);
	glVertex2i(x - (w / 2), y - h);
	glEnd();
}




void balls() {
	//blue ball
	glColor3ub(40, 25, 255);
	ball(360, ball_x_position * 0.5, ball_y_position, ball_x_position * 0.25);

}

void blingbling1() {
	glColor3ub(255, 255, 255);
	bling(bling1_x_position, bling1_y_position, 40, 30);
}

void blingbling2() {
	glColor3ub(255, 255, 255);
	bling(bling2_x_position, bling2_y_position, 40, 30);
}

void blingbling3() {
	glColor3ub(255, 255, 255);
	bling(bling3_x_position, bling3_y_position, 40, 30);
}

void blingbling4() {
	glColor3ub(255, 255, 255);
	bling(bling4_x_position, bling4_y_position, 40, 30);
}


void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	switch (state) {
	case 1:
		if (bling1_y_position < 370 && bling2_y_position < 370 && bling3_y_position < 298 && bling4_y_position < 298) {
			bling1_y_position += 1;
			bling2_y_position += 1;
			bling3_y_position += 1;
			bling4_y_position += 1;
		}
		else
			state = -1;
		break;
	case -1:
		if (bling1_y_position > 360 && bling2_y_position > 360 && bling3_y_position > 288 && bling4_y_position > 288) {
			bling1_y_position -= 0.7;
			bling2_y_position -= 0.7;
			bling3_y_position -= 0.7;
			bling4_y_position -= 0.7;
		}
		else
			state = 1;
		break;
	}

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	balls();
	blingbling1();
	blingbling2();
	blingbling3();
	blingbling4();
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
	glutTimerFunc(0, timer, 0);

	initGL();
	glutMainLoop();
}