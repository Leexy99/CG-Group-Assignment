#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
#define PI 3.142

void myInit(void){
    glClearColor(0.0, 0.0, 0.0, 0.0); // sets background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT);
}

int count;
GLfloat x_position, y_position, th = 0;
void love(void) {
    glColor3f(1,0,0);

	//--Love 1
    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 350 + 20 * cos(th);
        y_position = 530 + 20 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 380 + 20 * cos(th);
        y_position = 530 + 20 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(332, 520);
    glVertex2i(398, 520);
    glVertex2i(365, 490);
    glEnd();

	//--Love 2
	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 880 + 20 * cos(th);
		y_position = 530 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 910 + 20 * cos(th);
		y_position = 530 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(862, 520);
	glVertex2i(928, 520);
	glVertex2i(895, 490);
	glEnd();

	//--Love 3
	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 220 + 20 * cos(th);
		y_position = 330 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 250 + 20 * cos(th);
		y_position = 330 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(202, 320);
	glVertex2i(268, 320);
	glVertex2i(235, 290);
	glEnd();

	//--Love 4
	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 1020 + 20 * cos(th);
		y_position = 330 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 1050 + 20 * cos(th);
		y_position = 330 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(1002, 320);
	glVertex2i(1068, 320);
	glVertex2i(1035, 290);
	glEnd();

	//--Love 5
	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 350 + 20 * cos(th);
		y_position = 150 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 380 + 20 * cos(th);
		y_position = 150 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(332, 140);
	glVertex2i(398, 140);
	glVertex2i(365, 110);
	glEnd();

	//--Love 6
	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 880 + 20 * cos(th);
		y_position = 150 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 910 + 20 * cos(th);
		y_position = 150 + 20 * sin(th);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(862, 140);
	glVertex2i(928, 140);
	glVertex2i(895, 110);
	glEnd();
}

bool visible = true;

void blink(int) {
	glutTimerFunc(1000,blink,0);
	glutPostRedisplay();
	visible = !visible;
}

void rectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
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
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
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
	glVertex2i(x - w, y);
	glEnd();
}

//hat
void triangle_even(int x, int y, int w, int h) {
	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + (0.5 * w), y + h);
	glEnd();
}

void god() {
	//body
	glColor3ub(0, 193, 255);
	rectangle(SCREEN_WIDTH * 0.375, SCREEN_HEIGHT * 0.425, SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.3);
	glColor3ub(106, 90, 205);
	trapezium(SCREEN_WIDTH * 0.375, SCREEN_HEIGHT * 0.0035, SCREEN_WIDTH * 0.25, 200);

	//head
	glColor3ub(250, 250, 0);
	triangle_even(SCREEN_WIDTH * 0.48, 625, 50, SCREEN_HEIGHT * 0.07);
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
	rectangle_left(SCREEN_WIDTH * 0.375, SCREEN_HEIGHT * 0.05, SCREEN_WIDTH * 0.0625, SCREEN_HEIGHT * 0.225);
	rectangle_right(SCREEN_WIDTH * 0.5625, SCREEN_HEIGHT * 0.05, SCREEN_WIDTH * 0.0625, SCREEN_HEIGHT * 0.225);
}
void myDisplay(void){
	god();
	if (visible) {
		love();
	}
	
    glFlush(); //sends all output to display 
	glutSwapBuffers();
}
int main(int argc, char** argv){
    glutInit(&argc, argv); 

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //sets the display mode

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); //sets the window size

    glutCreateWindow("Love"); //creates the window and sets the title

    glutDisplayFunc(myDisplay); //runs function
	glutTimerFunc(1000, blink, 0);
    myInit(); 

    glutMainLoop(); 
}