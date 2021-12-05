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


int bbx = 0;
int bby = 720;

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

void background()
{
	glColor3ub(180, 105, 50);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(1280, 0);
	glVertex2i(1280, 200);
	glVertex2i(0, 200);
	glEnd();
}

void board(int x, int y, int w) {
	int h = w;


	//draw board 
	glColor3ub(240, 182, 81);
	rectangle(x, y, w, (h * 0.75));
	//draw small box outline
	glColor3ub(255, 0, 0);

	rectangle(x + (w / 3), y, (w / 3), (h / 3));

	//draw pillar
	glColor3ub(61, 61, 61);
	rectangle(x + (w * 0.375), y - w, (w * 0.25), h);
	//draw net
	glColor3ub(128, 128, 128);
	glBegin(GL_POLYGON);
	glVertex2i(x + (w / 3), y);
	glVertex2i(x + (w * 2 / 3), y);
	glVertex2i(x + (w * 7 / 12), y - (w / 4));
	glVertex2i(x + (w * 5 / 12), y - (w / 4));

	glBegin(GL_POLYGON);
	glEnd();

}

void person2(int x, int y, int w)
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
	h_Oval(20, x - (0.25 * w), y - (7 * w), 4 * w / 5);
	//hand
	glColor3ub(241, 194, 125);
	rectangle(x - (w * 0.5), y - (4.5 * w), w, w * 2.5);
	circle(20, x, y - (2 * w), w / 2);
	//circle(20, x + (3 * w), y - (2 * w), w / 2);
	//face
	glColor3ub(255, 255, 255);
	h_Oval(5, x - (0.35 * w), y + (0.25 * w), w / 3);
	glColor3ub(0, 0, 0);
	circle(5, x - (0.4 * w), y + (0.25 * w), w / 7);
	//mouth
	glColor3ub(184, 105, 106);
	glBegin(GL_LINES);
	glVertex2f(x - (0.15 * w), y - (0.5 * w));
	glVertex2f(x - (0.65 * w), y - (0.5 * w));
	glEnd();

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	bluesky();
	background();
	//person(x, y, 30);

	board(800,400,300);
	person2(700, 400, 50);
	glColor3ub(40, 25, 255);
	basketball(20, bbx - 100, bby, 40);
	glColor3ub(255, 220, 0);
	basketball(20, bbx, bby, 40);
	glColor3ub(255, 100, 0);
	basketball(20, (bbx + 100), bby, 40);

	glutSwapBuffers();
	glFlush();
	
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);

	if (bbx < 500 && bby > 300)
	{
		bbx += 3;
		bby -= 5;
	}
	else if (bbx < 600 && bby > 200)
	{
		bbx += 5;
		bby -= 2;
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