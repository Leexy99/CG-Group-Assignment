#include <Windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define window_width  1080  
#define window_height 720 
void DrawFilledBall() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    int i, x, y;
    double radius = 0.30;     
    glColor3ub(222, 139, 16);
    double twicePi = 2.0 * 3.142;
    x = 0, y = 0;
    glBegin(GL_TRIANGLE_FAN); 
    glVertex2f(x, y); 
    for (i = 0; i <= 20; i++) {
        glVertex2f(
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
        );
    }
    glEnd(); 
}

void DrawBallLine(float r, int num_segments) {
    glColor3ub(255,255,255);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++) {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        float x = r * cosf(theta); 
        float y = r * sinf(theta);
        glVertex2f(x, y );
    }
    glEnd();
}

void ballvert(){
    GLfloat triangleVert[] = {
        320,240,0,
        370,290,0,
        420,240,0
    };
}

void main_loop_function() {
    int c;
    DrawFilledBall();
    DrawBallLine(0.3, 100);
    glutSwapBuffers();
    c = getchar();
}
void GL_Setup(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    gluPerspective(45, (float)width / height, .1, 100);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(window_width, window_height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("basketball");
    glutIdleFunc(main_loop_function);
    GL_Setup(window_width, window_height);
    glutMainLoop();
}