#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
#define PI 3.141592653589793238

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // sets background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT);
}

void street(void) {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2i(600, 500);
    glVertex2i(0, 200);
    glVertex2i(1280, 200);
    glVertex2i(700, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(1280, 0);
    glVertex2i(1280, 200);
    glVertex2i(0, 200);
    glEnd();

    glColor3f(1,0.5,0.3);
    glBegin(GL_QUADS);
    glVertex2i(645,220);
    glVertex2i(640,20);
    glVertex2i(670,20);
    glVertex2i(665,220);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(648, 420);
    glVertex2i(645, 340);
    glVertex2i(660, 340);
    glVertex2i(657, 420);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(650, 500);
    glVertex2i(647, 480);
    glVertex2i(658, 480);
    glVertex2i(655, 500);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2i(600, 500);
    glVertex2i(0, 200);
    glVertex2i(0, 190);
    glVertex2i(600, 500);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(700, 500);
    glVertex2i(1280, 190);
    glVertex2i(1280, 200);
    glVertex2i(700, 500);
    glEnd();
}

int CLOUD_WIDTH = SCREEN_WIDTH;
void cloud(void) {
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    double inc = 2 * PI / (double)360;
    for (double theta = 0.0; theta <= 2 * PI; theta += inc)
    {
        glVertex2i(30 * cos(theta) + CLOUD_WIDTH - 930, 30 * sin(theta) + 650);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    inc = 2 * PI / (double)360;
    for (double theta = 0.0; theta <= 2 * PI; theta += inc)
    {
        glVertex2i(20 * cos(theta) + CLOUD_WIDTH - 900, 20 * sin(theta) + 650);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    inc = 2 * PI / (double)360;
    for (double theta = 0.0; theta <= 2 * PI; theta += inc)
    {
        glVertex2i(20 * cos(theta) + CLOUD_WIDTH - 960, 20 * sin(theta) + 650);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    inc = 2 * PI / (double)360;
    for (double theta = 0.0; theta <= 2 * PI; theta += inc)
    {
        glVertex2i(30 * cos(theta) + CLOUD_WIDTH - 430, 30 * sin(theta) + 650);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    inc = 2 * PI / (double)360;
    for (double theta = 0.0; theta <= 2 * PI; theta += inc)
    {
        glVertex2i(20 * cos(theta) + CLOUD_WIDTH - 400, 20 * sin(theta) + 650);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    inc = 2 * PI / (double)360;
    for (double theta = 0.0; theta <= 2 * PI; theta += inc)
    {
        glVertex2i(20 * cos(theta) + CLOUD_WIDTH - 460, 20 * sin(theta) + 650);
    }
    glEnd();
}

void tree(void) {
    glColor3f(0.7,0.2,0.2);
    glBegin(GL_POLYGON); //1 
    glVertex2i(140,280);
    glVertex2i(155,280);
    glVertex2i(155,340);
    glVertex2i(140,340);
    glEnd();

    glBegin(GL_POLYGON); //2
    glVertex2i(360, 390);
    glVertex2i(370, 390);
    glVertex2i(370, 430);
    glVertex2i(360, 430);
    glEnd();

    glBegin(GL_POLYGON); //3
    glVertex2i(1125, 280);
    glVertex2i(1140, 280);
    glVertex2i(1140, 340);
    glVertex2i(1125, 340);
    glEnd();

    glBegin(GL_POLYGON); //4
    glVertex2i(915, 390);
    glVertex2i(925, 390);
    glVertex2i(925, 430);
    glVertex2i(915, 430);
    glEnd();

    glColor3f(0.3, 0.5, 0.3);
    glBegin(GL_TRIANGLES); //1
    glVertex2i(70, 320);
    glVertex2i(220, 320);
    glVertex2i(150, 380);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(70, 350);
    glVertex2i(220, 350);
    glVertex2i(150, 410);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(70, 380);
    glVertex2i(220, 380);
    glVertex2i(150, 440);
    glEnd();

    glBegin(GL_TRIANGLES); //2
    glVertex2i(325, 420);
    glVertex2i(405, 420);
    glVertex2i(365, 460);
    glEnd();

    glBegin(GL_TRIANGLES); 
    glVertex2i(325, 440);
    glVertex2i(405, 440);
    glVertex2i(365, 480);
    glEnd();

    glBegin(GL_TRIANGLES); 
    glVertex2i(325, 460);
    glVertex2i(405, 460);
    glVertex2i(365, 500);
    glEnd();

    glBegin(GL_TRIANGLES); //3
    glVertex2i(1055, 320);
    glVertex2i(1205, 320);
    glVertex2i(1135, 380);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1055, 350);
    glVertex2i(1205, 350);
    glVertex2i(1135, 410);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1055, 380);
    glVertex2i(1205, 380);
    glVertex2i(1135, 440);
    glEnd();

    glBegin(GL_TRIANGLES); //4
    glVertex2i(880, 420);
    glVertex2i(960, 420);
    glVertex2i(920, 460);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(880, 440);
    glVertex2i(960, 440);
    glVertex2i(920, 480);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(880, 460);
    glVertex2i(960, 460);
    glVertex2i(920, 500);
    glEnd();
}

void mountain(void) {
    glColor3f(0.8, 0.5, 0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 500);
    glVertex2i(250, 500);
    glVertex2i(120, 560);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(120, 500);
    glVertex2i(320, 500);
    glVertex2i(230, 550);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(220, 500);
    glVertex2i(420, 500);
    glVertex2i(320, 560);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(350, 500);
    glVertex2i(600, 500);
    glVertex2i(450, 570);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(540, 500);
    glVertex2i(780, 500);
    glVertex2i(630, 580);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(650, 500);
    glVertex2i(950, 500);
    glVertex2i(820, 570);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(800, 500);
    glVertex2i(1080, 500);
    glVertex2i(960, 580);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(960, 500);
    glVertex2i(1280, 500);
    glVertex2i(1150, 570);
    glEnd();
}

int position = 1;
void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/20, timer, 0);

    if (SCREEN_HEIGHT>=-300)
    {
        SCREEN_HEIGHT -= 2;
    }

    switch (position)
    {
    case 1: //Move to right
        if (CLOUD_WIDTH <= 1500)
        {
            CLOUD_WIDTH += 2;
        }
        else
        {
            position = -1;
        }
        break;
    case -1: //Move to left
        if (CLOUD_WIDTH > 0)
        {
            CLOUD_WIDTH -= 2;
        }
        else
        {
            position = 1;
        }
        break;
    }
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT); // clears the screen
    glPointSize(4.0);

    glColor3f(0.2, 0.7, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 500);
    glVertex2i(1280, 500);
    glVertex2i(1280, 720);
    glVertex2i(0, 720);
    glEnd();

    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(1280, 0);
    glVertex2i(1280, 500);
    glVertex2i(0, 500);
    glEnd();

    street();
    tree();
    mountain();
    cloud();

    //face
    glColor3f(1.0f, 1.0f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2i(612, SCREEN_HEIGHT - 240);
    glVertex2i(692, SCREEN_HEIGHT - 240);
    glVertex2i(692, SCREEN_HEIGHT - 170);
    glVertex2i(612, SCREEN_HEIGHT - 170);
    glEnd();

    //hair
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);

    glVertex2i(622, SCREEN_HEIGHT - 180);
    glVertex2i(627, SCREEN_HEIGHT - 170);

    glVertex2i(632, SCREEN_HEIGHT - 180);
    glVertex2i(637, SCREEN_HEIGHT - 170);

    glVertex2i(642, SCREEN_HEIGHT - 180);
    glVertex2i(647, SCREEN_HEIGHT - 170);

    glVertex2i(652, SCREEN_HEIGHT - 180);
    glVertex2i(657, SCREEN_HEIGHT - 170);

    glVertex2i(662, SCREEN_HEIGHT - 180);
    glVertex2i(667, SCREEN_HEIGHT - 170);

    glVertex2i(672, SCREEN_HEIGHT - 180);
    glVertex2i(677, SCREEN_HEIGHT - 170);

    glEnd();

    //eye
    GLfloat x_position, y_position, th = 0;
    int count;
    glColor3f(0.0f, 0.0f, 0.0f);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.01;
        x_position = 637 + 5 * cos(th);
        y_position = SCREEN_HEIGHT - 200 + 10 * sin(th);
        glBegin(GL_POINTS);
        glVertex2f(x_position, y_position);
        glEnd();
    }

    for (count = 1; count <= 10000; count++) {
        th = th + 0.01;
        x_position = 667 + 5 * cos(th);
        y_position = SCREEN_HEIGHT - 200 + 10 * sin(th);
        glBegin(GL_POINTS);
        glVertex2f(x_position, y_position);
        glEnd();
    }

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 637 + 2 * cos(th);
        y_position = SCREEN_HEIGHT - 200 + 4 * sin(th);
        glColor3f(0,0,0);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 667 + 2 * cos(th);
        y_position = SCREEN_HEIGHT - 200 + 4 * sin(th);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    //mouth
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(642, SCREEN_HEIGHT - 235);
    glVertex2i(662, SCREEN_HEIGHT - 235);
    glVertex2i(662, SCREEN_HEIGHT - 220);
    glVertex2i(642, SCREEN_HEIGHT - 220);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(642, SCREEN_HEIGHT - 235);
    glVertex2i(642, SCREEN_HEIGHT - 220);

    glVertex2i(642, SCREEN_HEIGHT - 235);
    glVertex2i(662, SCREEN_HEIGHT - 235);

    glVertex2i(662, SCREEN_HEIGHT - 235);
    glVertex2i(662, SCREEN_HEIGHT - 220);

    glVertex2i(662, SCREEN_HEIGHT - 220);
    glVertex2i(642, SCREEN_HEIGHT - 220);

    glVertex2i(642, SCREEN_HEIGHT - 228);
    glVertex2i(662, SCREEN_HEIGHT - 228);
    glEnd();

    //body
    glColor3f(1.0f, 1.0f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2i(627, SCREEN_HEIGHT - 240);
    glVertex2i(622, SCREEN_HEIGHT - 300);
    glVertex2i(682, SCREEN_HEIGHT - 300);
    glVertex2i(677, SCREEN_HEIGHT - 240);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.9f);
    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 617 + 20 * cos(th);
        y_position = SCREEN_HEIGHT - 255 + 5 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 687 + 20 * cos(th);
        y_position = SCREEN_HEIGHT - 255 + 5 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 634 + 5 * cos(th);
        y_position = SCREEN_HEIGHT - 305 + 20 * sin(th);
        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 669 + 5 * cos(th);
        y_position = SCREEN_HEIGHT - 305 + 20 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(624, SCREEN_HEIGHT - 278);
    glVertex2i(680, SCREEN_HEIGHT - 278);

    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 652 + 3 * cos(th);
        y_position = SCREEN_HEIGHT - 285 + 3 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(627, SCREEN_HEIGHT - 240);
    glVertex2i(652, SCREEN_HEIGHT - 245);

    glVertex2i(652, SCREEN_HEIGHT - 245);
    glVertex2i(677, SCREEN_HEIGHT - 240);

    glVertex2i(652, SCREEN_HEIGHT - 245);
    glVertex2i(652, SCREEN_HEIGHT - 278);

    glVertex2i(617, SCREEN_HEIGHT - 250);
    glVertex2i(617, SCREEN_HEIGHT - 260);

    glVertex2i(687, SCREEN_HEIGHT - 250);
    glVertex2i(687, SCREEN_HEIGHT - 260);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(647, SCREEN_HEIGHT - 255);
    glVertex2i(657, SCREEN_HEIGHT - 255);
    glVertex2i(657, SCREEN_HEIGHT - 250);
    glVertex2i(647, SCREEN_HEIGHT - 250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(647, SCREEN_HEIGHT - 270);
    glVertex2i(657, SCREEN_HEIGHT - 270);
    glVertex2i(657, SCREEN_HEIGHT - 265);
    glVertex2i(647, SCREEN_HEIGHT - 265);
    glEnd();

    glColor3f(1,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(647, SCREEN_HEIGHT - 300);
    glVertex2i(657, SCREEN_HEIGHT - 300);
    glVertex2i(652, SCREEN_HEIGHT - 290);
    glEnd();

    glFlush(); //sends all output to display 
    glutSwapBuffers();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //sets the display mode

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); //sets the window size

    glutCreateWindow("Kelefei"); //creates the window and sets the title

    glutDisplayFunc(myDisplay); //runs function
    glutTimerFunc(0, timer, 0);
    myInit();

    glutMainLoop();
}