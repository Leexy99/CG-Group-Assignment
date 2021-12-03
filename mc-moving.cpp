/*#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

GLint b = 300;
float  counter = 600.0;
void initOpenGl()
{
    glClearColor(0.5, 0.5, 0.5, 1); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void wheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
    }

    glEnd();

}

void car()
{


    //Bottom Part
    glLoadIdentity();
    counter = counter - 0.1;
    glTranslated(counter, 100, 0.0);
    //glScaled(0.1,0.1,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(100, 160);
    glVertex2f(450, 160);
    glVertex2f(450, 100);

    //Top Part
    glBegin(GL_POLYGON);
    glVertex2f(150, 160);
    glVertex2f(200, 200);
    glVertex2f(400, 200);
    glVertex2f(450, 160);

    glEnd();

    wheel(200, 100);
    wheel(380, 100);

}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    //Push and pop matrix for separating circle object from Background
    glColor3f(0.0, 1.0, 0.0);
    car();
    glutSwapBuffers();
    glFlush();


}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Car Moving");
    initOpenGl();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
*/


#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.141592653

#define SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	720
//#define FPS	30

int x = 100;
int y = 400;

int bx = 200;
int by = 310;

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
	glColor3f(255, 255, 0.0); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
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

void mountain() {

	///mountain3
	glBegin(GL_POLYGON);
	glColor3f(0.11, 0.20, 0.20);
	glVertex2i(-50, 200);
	glVertex2i(500, 200);
	glVertex2i(225, 500);
	glEnd();

	///mountain1&2
	glBegin(GL_POLYGON);
	glColor3f(0.11, 0.23, 0.36);
	glVertex2i(50, 200);
	glVertex2i(800, 200);
	glVertex2i(700, 350); //here
	glVertex2i(450, 350); //here
	glVertex2i(300, 300);
	glVertex2i(250, 325); //
	glVertex2i(200, 325); //
	glEnd();

	///mountain_Snow1
	glBegin(GL_POLYGON);
	glColor3f(1.25, 0.924, 0.930);
	glVertex2i(450, 350);
	glVertex2i(700, 350);
	glVertex2i(650, 400);
	glEnd();

	///mountain_Snow2
	glBegin(GL_POLYGON);
	glColor3f(1.25, 0.924, 0.930);
	glVertex2i(200, 325);
	glVertex2i(250, 325);
	glVertex2i(225, 340);
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

/*void ball(int x, int y, int r)
{
	glColor3ub(180, 105, 50);
	circle(30, x, y, r);
	circle(30, x + (5 * r), y, r);
	circle(30, x + (2*(5*r)), y, r);
}*/


void display() {
	glClear(GL_COLOR_BUFFER_BIT);


	//drawing the Mountain
	bluesky();
	mountain();


	//----------
	background();
	board(800, 400, 200);
	
	person(x, y, 30);
	basketball(20, bx, by, 25);

	glFlush();
	glutSwapBuffers();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer, 0);

	if (x < 700)
	{
		x += 5;
		if ((x > 100 && x < 200) || (x > 300 && x < 400) || (x > 500 && x < 600))
		{
			y += 1;
		}
		else if ((x > 200 && x < 300) || (x > 400 && x < 500) || (x > 600 && x < 700))
		{
			y -= 1;

		}	
	}

	if (bx < 800)
	{
		bx += 5;
		if ((bx > 200 && bx < 300) || (bx > 400 && bx < 500) || (bx > 600 && bx < 700))
		{
			by -= 5;
		}
		else if ((bx > 300 && bx < 400) || (bx > 500 && bx < 600) || (bx > 700 && bx < 800))
		{
			by += 5;
		}
	}

	//glutPostRedisplay();

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
	glutTimerFunc(0, timer, 0);
	initGL();

	glutMainLoop();

}