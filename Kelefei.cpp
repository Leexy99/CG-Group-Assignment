#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define SCREEN_WIDTH 1280
#define SCREEN_LENGTH 720
#define PI 3.141592653589793238

void myInit(void){
    glClearColor(0.0, 0.0, 0.0, 0.0); // sets background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, SCREEN_WIDTH, 0.0, SCREEN_LENGTH);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT); // clears the screen
    glColor3f(1.0f, 0.5f, 0.0f); // sets the drawing colour
    glPointSize(4.0);

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(1280, 0);
    glVertex2i(1280, 300);
    glVertex2i(0, 300);
    glEnd();

    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 300);
    glVertex2i(1280, 300);
    glVertex2i(1280, 720);
    glVertex2i(0, 720);
    glEnd();

    //hat
    glColor3f(1.0f,0.0f,0.4f);
    glBegin(GL_TRIANGLES);
    glVertex2i(580, 450);
    glVertex2i(720, 450);
    glVertex2i(650, 550);
    glEnd();

    glColor3f(0.9f,1.0f,0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(600, 450);
    glVertex2i(600, 478);

    glVertex2i(610, 450);
    glVertex2i(610, 490);
     
    glVertex2i(620, 450);
    glVertex2i(620, 505);

    glVertex2i(630, 450);
    glVertex2i(630, 520);

    glVertex2i(640, 450);
    glVertex2i(640, 535);

    glVertex2i(650, 450);
    glVertex2i(650, 548);

    glVertex2i(660, 450);
    glVertex2i(660, 535);

    glVertex2i(670, 450);
    glVertex2i(670, 520);

    glVertex2i(680, 450);
    glVertex2i(680, 505);

    glVertex2i(690, 450);
    glVertex2i(690, 490);

    glVertex2i(700, 450);
    glVertex2i(700, 478);

    glEnd();

    //face
    glColor3f(1.0f, 1.0f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2i(580, 340);
    glVertex2i(720, 340);
    glVertex2i(720, 450);
    glVertex2i(580, 450);
    glEnd();

    //eye
    GLfloat x_position, y_position, th = 0;
    int count;
    glColor3f(0.0f, 0.0f, 0.0f);
    for (count = 1; count <= 10000; count++){
        th = th + 0.01;
        x_position = 620 + 10 * cos(th);
        y_position = 410 + 20 * sin(th);
        glBegin(GL_POINTS);
        glVertex2f(x_position, y_position);
        glEnd();
    }

    for (count = 1; count <= 10000; count++) {
        th = th + 0.01;
        x_position = 680 + 10 * cos(th);
        y_position = 410 + 20 * sin(th);
        glBegin(GL_POINTS);
        glVertex2f(x_position, y_position);
        glEnd();
    }

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 620 + 5 * cos(th);
        y_position = 410 + 10 * sin(th);
        glColor3f(0.0f,0.0f, 0.0f);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 680 + 5 * cos(th);
        y_position = 410 + 10 * sin(th);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(x_position, y_position);
    }
    glEnd(); 

    //mouth
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(635, 350);
    glVertex2i(665, 350);
    glVertex2i(665, 370);
    glVertex2i(635, 370);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(635, 350);
    glVertex2i(635, 370);

    glVertex2i(635, 350);
    glVertex2i(665, 350);

    glVertex2i(665, 350);
    glVertex2i(665, 370);

    glVertex2i(665, 370);
    glVertex2i(635, 370);

    glVertex2i(635, 360);
    glVertex2i(665, 360);
    glEnd();

    //body
    glColor3f(1.0f, 1.0f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2i(610, 340);
    glVertex2i(600, 240);
    glVertex2i(700, 240);
    glVertex2i(690, 340);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.9f);
    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 590 + 30 * cos(th);
        y_position = 310 + 10 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 710 + 30 * cos(th);
        y_position = 310 + 10 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 620 + 10 * cos(th);
        y_position = 230 + 30 * sin(th);
        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2d(x_position, y_position);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 680 + 10 * cos(th);
        y_position = 230 + 30 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2i(605, 280);
    glVertex2i(695, 280);
    glEnd();

    glBegin(GL_POLYGON);
    for (count = 1; count <= 10000; count++) {
        th = th + 0.001;
        x_position = 650 + 5 * cos(th);
        y_position = 270 + 5 * sin(th);
        glVertex2d(x_position, y_position);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(610, 340);
    glVertex2i(650, 330);

    glVertex2i(650, 330);
    glVertex2i(690, 340);

    glVertex2i(650, 330);
    glVertex2i(650, 280);

    glVertex2i(590, 320);
    glVertex2i(590, 300);

    glVertex2i(710, 320);
    glVertex2i(710, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(645, 310);
    glVertex2i(655, 310);
    glVertex2i(655, 320);
    glVertex2i(645, 320);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(645, 290);
    glVertex2i(655, 290);
    glVertex2i(655, 300);
    glVertex2i(645, 300);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2i(640, 240);
    glVertex2i(660, 240);
    glVertex2i(650, 260);
    glEnd();

    glFlush(); //sends all output to display 
}
int main(int argc, char** argv){
    glutInit(&argc, argv); 

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets the display mode

    glutInitWindowSize(SCREEN_WIDTH, SCREEN_LENGTH); //sets the window size

    glutCreateWindow("Kelefei"); //creates the window and sets the title

    glutDisplayFunc(myDisplay); //runs function

    myInit(); 

    glutMainLoop(); 
}