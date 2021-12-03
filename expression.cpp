#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>
#include <time.h>
#define maxWD 1280
#define maxHT 720

int x, y;
int cx = -600;
int cy = 0;
int tx = 600;
int ty = 0;
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

void cross() {
    glBegin(GL_POLYGON);
    glVertex2i(cx-10, cy);
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
void tick() {
    glBegin(GL_POLYGON);
    glVertex2i(tx , ty-10);
    glVertex2i(tx +40, ty + 30);
    glVertex2i(tx , ty -25);
    glVertex2i(tx - 20, ty );
    glVertex2i(tx, ty-10);
    glEnd();
}
void drawcross(int cx, int cy) {
    glColor3ub(255, 0, 0);
    cross();
}

void drawtick(int tx, int ty) {
    glColor3ub(0, 255, 0);
    tick();
}


void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    switch (state) {
    case 1:
        if (cy <= maxcy||ty<=maxty||cx<=maxcx||tx<=maxtx) {
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

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    drawcross(0, 0);
    drawtick(0, 0);
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
    gluOrtho2D(-1280, 1280, -720, 720);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1360, 768);
    glutCreateWindow("expression");
    glutTimerFunc(0, timer, 0);
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}