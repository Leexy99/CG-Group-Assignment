#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>


#define SCREEN_WIDTH	1080
#define SCREEN_HEIGHT	720

int x = 30;
int y = 50;
int dx = 10;
int dy = 15;


void rectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}


void board(int x, int y, int w) {
	int h = 0.75 * w;

	// draw board outline
	glColor3ub(155,155,155);
	rectangle(x, 2.5*y, w, h);
	//draw board 
	glColor3ub(240, 182, 81);
	rectangle(x + w / 60, 2.5 * y, w-8, h-2);
	//draw small box outline
	glColor3ub(255,0,0);
	rectangle(x+w/2-w/4, 2.5 * y, w/2, h/2);
	//draw small box 
	glColor3ub(240, 182, 81);
	rectangle(x + w / 2 - w / 4.5, 2.5 * y, w / 2.2, h / 2.2);
	//draw pillar
	glColor3ub(61, 61, 61);
	rectangle(x + w / 2 - w / 10, y -(h/1.9), w / 5, 2*h / 1.5);
	//draw net
	glColor3ub(128, 128, 128);
	glBegin(GL_POLYGON);
	glVertex2i(x + w / 2 - w / 4.5, 2.5 * y);
	glVertex2i(x + w /1.37, 2.5 * y);
	glVertex2i(x + w /1.5, 1.8*y );
	glVertex2i(x + w / 2 - w /6, 1.8 * y);
	
	glBegin(GL_POLYGON);
	glEnd();

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	board(100, 100, 250);

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
	glutCreateWindow("board draft");
	glutDisplayFunc(display);
	initGL();

	glutMainLoop();

}