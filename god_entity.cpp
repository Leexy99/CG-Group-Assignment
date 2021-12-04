#include <windows.h>
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <math.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PI 3.142

//body
void rectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x + w, y);
		glVertex2i(x + w, y + h);
		glVertex2i(x , y +h);
	glEnd();
}

//left leg
void rectangle_left(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

//right leg
void rectangle_right(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}


//circle
void nGon(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
		for (double theta = 0.0; theta <= 2*PI; theta += inc) {
			glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
			}
	
	glEnd();
}

//bottom
void trapezium(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x - w / 8, y + h);
	glVertex2i(x + w + w / 8, y + h);
	glVertex2i(x + w, y + h + h / 2);
	glVertex2i(x, y + h + h / 2);
	glEnd();
}

//right hand
void triangle_right(int x, int y, int w, int h) {
	glBegin(GL_TRIANGLES);
		glVertex2i(x, y);
		glVertex2i(x + w, y + h);
		glVertex2i(x + w, y);
	glEnd();
}

//left hand
void triangle_left(int x, int y, int w, int h) {
	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x - w, y + h);
	glVertex2i(x-w , y);
	glEnd();
}

//hat
void triangle_even(int x, int y, int w, int h) {
	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x+(0.5*w) , y+h);
	glEnd();
}

void god() {
	//body
	glColor3ub(0, 193, 255);
	rectangle(SCREEN_WIDTH * 0.375, SCREEN_HEIGHT * 0.425, SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.3);
	glColor3ub(106, 90, 205);
	trapezium(SCREEN_WIDTH*0.375, SCREEN_HEIGHT*0.0035, SCREEN_WIDTH*0.25, 200);
	
	//head
	glColor3ub(250, 250, 0);
	triangle_even(SCREEN_WIDTH*0.48, 625, 50, SCREEN_HEIGHT * 0.07);
	glColor3ub(255, 0, 0);
	nGon(360, SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.8, 50);

	//hands
	glColor3ub(255, 165, 0);
	triangle_right(SCREEN_WIDTH * 0.625, SCREEN_HEIGHT * 0.60625, 250, SCREEN_HEIGHT * 0.1);
	glColor3ub(255, 0, 0);
	nGon(360, SCREEN_WIDTH * 0.8425, SCREEN_HEIGHT * 0.65, 35);
	glColor3ub(255, 165, 0);
	triangle_left(SCREEN_WIDTH * 0.37, SCREEN_HEIGHT * 0.60625, 250, SCREEN_HEIGHT * 0.1);
	glColor3ub(255, 0, 0);
	nGon(360, SCREEN_WIDTH * 0.15, SCREEN_HEIGHT * 0.65, 35);

	//legs
	rectangle_left(SCREEN_WIDTH * 0.375, SCREEN_HEIGHT* 0.05, SCREEN_WIDTH * 0.0625, SCREEN_HEIGHT * 0.225);
	rectangle_right(SCREEN_WIDTH * 0.5625, SCREEN_HEIGHT * 0.05, SCREEN_WIDTH * 0.0625, SCREEN_HEIGHT * 0.225);
}




void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	god();
	glFlush();
	glutSwapBuffers();
}



void initGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}


int  main(int argc , char** argv ) {
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("God character haha");
	glutDisplayFunc(display);

	initGL();
	glutMainLoop();

}
