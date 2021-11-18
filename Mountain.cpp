#include<iostream>
#include<stdlib.h>

#ifdef xian
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else 
#include<glut.h>
#endif

using namespace std;

void mountain() {
    ///mountain
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex3f(-0.9, -0.7, -1.0);
    glVertex3f(-0.5, -0.1, -1.0);
    glVertex3f(-0.2, -0.7, -1.0);
    glVertex3f(0.1, -0.7, -1.0);
    glVertex3f(0.5, 0.2, -1.0);
    glVertex3f(0.8, -0.7, -1.0);
    glEnd();

    ///mountain_Snow1
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex3f(-0.45, -0.2, -1.0);
    glVertex3f(-0.5, -0.1, -1.0);
    glVertex3f(-0.57, -0.2, -1.0);
    glEnd();

    ///mountain_Snow2
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex3f(0.04, -0.1, -1.0);
    glVertex3f(0.5, 0.2, -1.0);
    glVertex3f(0.6, -0.1, -1.0);
    glEnd();
}


void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //drawing the Mountain
    glPushMatrix();
    mountain();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Mountain");
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return(0);
}