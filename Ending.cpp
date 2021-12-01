#include<iostream>
#include<stdlib.h>

#ifdef xian
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else 
#include<glut.h>
#endif

using namespace std;

void beHonest()
{
    //Alphabet B
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.9, -0.2, -1.0);
    glVertex3f(-0.8, -0.2, -1.0);
    glVertex3f(-0.8, -0.35, -1.0);
    glVertex3f(-0.9, -0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.9, -0.35, -1.0);
    glVertex3f(-0.75, -0.35, -1.0);
    glVertex3f(-0.75, -0.55, -1.0);
    glVertex3f(-0.9, -0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.875, -0.25, -1.0);
    glVertex3f(-0.825, -0.25, -1.0);
    glVertex3f(-0.825, -0.35, -1.0);
    glVertex3f(-0.875, -0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.875, -0.4, -1.0);
    glVertex3f(-0.775, -0.4, -1.0);
    glVertex3f(-0.775, -0.5, -1.0);
    glVertex3f(-0.875, -0.5, -1.0);
    glEnd();

    //Alphabet E
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.7, -0.2, -1.0);
    glVertex3f(-0.55, -0.2, -1.0);
    glVertex3f(-0.55, -0.55, -1.0);
    glVertex3f(-0.7, -0.55, -1.0);
    glEnd();
  
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.65, -0.25, -1.0);
    glVertex3f(-0.55, -0.25, -1.0);
    glVertex3f(-0.55, -0.35, -1.0);
    glVertex3f(-0.65, -0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.65, -0.4, -1.0);
    glVertex3f(-0.55, -0.4, -1.0);
    glVertex3f(-0.55, -0.5, -1.0);
    glVertex3f(-0.65, -0.5, -1.0);
    glEnd();

    //Alphabet H
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.4, -0.2, -1.0);
    glVertex3f(-0.25, -0.2, -1.0);
    glVertex3f(-0.25, -0.55, -1.0);
    glVertex3f(-0.4, -0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.35, -0.2, -1.0);
    glVertex3f(-0.3, -0.2, -1.0);
    glVertex3f(-0.3, -0.35, -1.0);
    glVertex3f(-0.35, -0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.35, -0.55, -1.0);
    glVertex3f(-0.3, -0.55, -1.0);
    glVertex3f(-0.3, -0.4, -1.0);
    glVertex3f(-0.35, -0.4, -1.0);
    glEnd();

    //Alphabet O
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.2, -0.2, -1.0);
    glVertex3f(-0.05, -0.2, -1.0);
    glVertex3f(-0.05, -0.55, -1.0);
    glVertex3f(-0.2, -0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.15, -0.25, -1.0);
    glVertex3f(-0.1, -0.25, -1.0);
    glVertex3f(-0.1, -0.5, -1.0);
    glVertex3f(-0.15, -0.5, -1.0);
    glEnd();

    //Alphabet N
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, -0.2, -1.0);
    glVertex3f(0.05, -0.2, -1.0);
    glVertex3f(0.05, -0.55, -1.0);
    glVertex3f(0.0, -0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.1, -0.2, -1.0);
    glVertex3f(0.15, -0.2, -1.0);
    glVertex3f(0.15, -0.55, -1.0);
    glVertex3f(0.1, -0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, -0.2, -1.0);
    glVertex3f(0.05, -0.2, -1.0);
    glVertex3f(0.15, -0.55, -1.0);
    glVertex3f(0.1, -0.55, -1.0);
    glEnd();

    //Alphabet E
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.2, -0.2, -1.0);
    glVertex3f(0.35, -0.2, -1.0);
    glVertex3f(0.35, -0.55, -1.0);
    glVertex3f(0.2, -0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.25, -0.25, -1.0);
    glVertex3f(0.35, -0.25, -1.0);
    glVertex3f(0.35, -0.35, -1.0);
    glVertex3f(0.25, -0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.25, -0.4, -1.0);
    glVertex3f(0.35, -0.4, -1.0);
    glVertex3f(0.35, -0.5, -1.0);
    glVertex3f(0.25, -0.5, -1.0);
    glEnd();

    //Alphabet S
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.4, -0.2, -1.0);
    glVertex3f(0.55, -0.2, -1.0);
    glVertex3f(0.55, -0.55, -1.0);
    glVertex3f(0.4, -0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.45, -0.3, -1.0);
    glVertex3f(0.55, -0.3, -1.0);
    glVertex3f(0.55, -0.35, -1.0);
    glVertex3f(0.45, -0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.4, -0.425, -1.0);
    glVertex3f(0.5, -0.425, -1.0);
    glVertex3f(0.5, -0.475, -1.0);
    glVertex3f(0.4, -0.475, -1.0);
    glEnd();

    //Alphabet T
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.6, -0.2, -1.0);
    glVertex3f(0.75, -0.2, -1.0);
    glVertex3f(0.75, -0.275, -1.0);
    glVertex3f(0.6, -0.275, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.65, -0.2, -1.0);
    glVertex3f(0.7, -0.2, -1.0);
    glVertex3f(0.7, -0.55, -1.0);
    glVertex3f(0.65, -0.55, -1.0);
    glEnd();







}

void theEnd()
{
    //Alphabet T
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.7, 0.9, -1.0);
    glVertex3f(-0.5, 0.9, -1.0);
    glVertex3f(-0.5, 0.8, -1.0);
    glVertex3f(-0.7, 0.8, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.62, 0.9, -1.0);
    glVertex3f(-0.58, 0.9, -1.0);
    glVertex3f(-0.58, 0.3, -1.0);
    glVertex3f(-0.62, 0.3, -1.0);
    glEnd();

    //Alphabet H
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.45, 0.9, -1.0);
    glVertex3f(-0.4, 0.9, -1.0);
    glVertex3f(-0.4, 0.3, -1.0);
    glVertex3f(-0.45, 0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.45, 0.6, -1.0);
    glVertex3f(-0.3, 0.6, -1.0);
    glVertex3f(-0.3, 0.5, -1.0);
    glVertex3f(-0.45, 0.5, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.35, 0.9, -1.0);
    glVertex3f(-0.3, 0.9, -1.0);
    glVertex3f(-0.3, 0.3, -1.0);
    glVertex3f(-0.35, 0.3, -1.0);
    glEnd();

    //Alphabet E
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.25, 0.9, -1.0);
    glVertex3f(-0.2, 0.9, -1.0);
    glVertex3f(-0.2, 0.3, -1.0);
    glVertex3f(-0.25, 0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.2, 0.9, -1.0);
    glVertex3f(-0.1, 0.9, -1.0);
    glVertex3f(-0.1, 0.8, -1.0);
    glVertex3f(-0.2, 0.8, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.2, 0.65, -1.0);
    glVertex3f(-0.1, 0.65, -1.0);
    glVertex3f(-0.1, 0.55, -1.0);
    glVertex3f(-0.2, 0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.2, 0.4, -1.0);
    glVertex3f(-0.1, 0.4, -1.0);
    glVertex3f(-0.1, 0.3, -1.0);
    glVertex3f(-0.2, 0.3, -1.0);
    glEnd();

    //Alphabet E
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, 0.9, -1.0);
    glVertex3f(0.1, 0.9, -1.0);
    glVertex3f(0.1, 0.3, -1.0);
    glVertex3f(0.05, 0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, 0.9, -1.0);
    glVertex3f(0.2, 0.9, -1.0);
    glVertex3f(0.2, 0.8, -1.0);
    glVertex3f(0.05, 0.8, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, 0.65, -1.0);
    glVertex3f(0.2, 0.65, -1.0);
    glVertex3f(0.2, 0.55, -1.0);
    glVertex3f(0.05, 0.55, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, 0.4, -1.0);
    glVertex3f(0.2, 0.4, -1.0);
    glVertex3f(0.2, 0.3, -1.0);
    glVertex3f(0.05, 0.3, -1.0);
    glEnd();

    //Alphabet N
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.25, 0.9, -1.0);
    glVertex3f(0.3, 0.9, -1.0);
    glVertex3f(0.3, 0.3, -1.0);
    glVertex3f(0.25, 0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.25, 0.9, -1.0);
    glVertex3f(0.4, 0.4, -1.0);
    glVertex3f(0.4, 0.3, -1.0);
    glVertex3f(0.25, 0.8, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.35, 0.9, -1.0);
    glVertex3f(0.4, 0.9, -1.0);
    glVertex3f(0.4, 0.3, -1.0);
    glVertex3f(0.35, 0.3, -1.0);
    glEnd();

    //Alphabet D
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.45, 0.9, -1.0);
    glVertex3f(0.55, 0.9, -1.0);
    glVertex3f(0.65, 0.625, -1.0);
    glVertex3f(0.65, 0.575, -1.0);
    glVertex3f(0.55, 0.3, -1.0);
    glVertex3f(0.45, 0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.8, -1.0);
    glVertex3f(0.55, 0.8, -1.0);
    glVertex3f(0.6, 0.625, -1.0);
    glVertex3f(0.6, 0.575, -1.0);
    glVertex3f(0.55, 0.4, -1.0);
    glVertex3f(0.5, 0.4, -1.0);
    glEnd();

}


void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //drawing the Screen
    glPushMatrix();
    theEnd();
    glPopMatrix();

    glPushMatrix();
    beHonest();
    glPopMatrix();
    glutSwapBuffers();
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("The end");
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return(0);
}
