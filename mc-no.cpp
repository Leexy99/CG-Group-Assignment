#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>
#include <time.h>
#define maxWD 1280
#define maxHT 720
#define PI 3.141592653

int x, y;
int cx = 550;
int cy = 500;
int tx = 700;
int ty = 500;
int maxcy = cy + 10;
int mincy = cy - 10;
int maxty = ty + 10;
int minty = ty - 10;
int maxcx = cx + 5;
int maxtx = tx + 5;
int mincx = cx - 5;
int mintx = tx - 5;

float i, j;
int state = 1;

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

void cross(int cx, int cy) {
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2i(cx - 10, cy);
    glVertex2i(cx - 30, cy + 20);
    glVertex2i(cx - 20, cy + 30);
    glVertex2i(cx, cy + 10);
    glVertex2i(cx + 20, cy + 30);
    glVertex2i(cx + 30, cy + 20);
    glVertex2i(cx + 10, cy);
    glVertex2i(cx + 30, cy - 20);
    glVertex2i(cx + 20, cy - 30);
    glVertex2i(cx, cy - 10);
    glVertex2i(cx - 20, cy - 30);
    glVertex2i(cx - 30, cy - 20);
    glVertex2i(cx - 10, cy);
    glEnd();
}
void tick(int tx, int ty) {
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2i(tx, ty - 10);
    glVertex2i(tx + 40, ty + 30);
    glVertex2i(tx, ty - 25);
    glVertex2i(tx - 20, ty);
    glVertex2i(tx, ty - 10);
    glEnd();
}

/*void drawcross(int cx, int cy) {
    glColor3ub(255, 0, 0);
    cross();
}*/

/*void drawtick(int tx, int ty) {
    glColor3ub(0, 255, 0);
    tick();
}*/


void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    switch (state) {
    case 1:
        if (cy <= maxcy || ty <= maxty || cx <= maxcx || tx <= maxtx) {
            cy += 2;
            ty += 2;
            cx += 1;
            tx += 1;
        }
        else {
            state = -1;
        }
        break;
    case -1:
        if (cy > mincy || ty > minty || cx > mincx || tx > mintx) {
            cy -= 2;
            ty -= 2;
            cx -= 1;
            tx -= 1;
        }
        else {
            state = 1;
        }
        break;
    }
}

void rectangle(int x, int y, int w, int h) {
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
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
    rectangle(x-(w*0.5), y - (4.5 * w), w, w*2.5);
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

void dialog(int n, int x, int y, int r)
{
    glColor3ub(255, 255, 255);
    double inc = PI / (double)n;
    glBegin(GL_POLYGON);
    for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
        glVertex2d(r * cos(theta) + x, (3*r/4) * sin(theta) + y);
    }
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

void display_cross_no(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    bluesky();
    background();

    board(800, 400, 300);
    dialog(50, 550, 500, 80);

    cross(cx, cy);
    
    person2(700, 400, 50);
    glFlush();
    glutSwapBuffers();
}



void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(10.0);
    glLineWidth(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1280, 0, 720);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("expression");
    glutTimerFunc(0, timer, 0);
    myInit();
    glutDisplayFunc(display_cross_no);
    glutMainLoop();
}