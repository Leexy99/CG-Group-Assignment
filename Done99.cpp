#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

#define PI 3.142
int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720; //Y-Coordinate for static object
int x_position = 1280, y_position = 720; //Y-coordinate of motion object 1
int cloud_x_position = 1280, cloud_y_position = 720; //Y-Coordinate of motion cloud
int state = 1; //Set the ball state to 1 (Original State towards the basketball net)
int ball_WIDTH = SCREEN_WIDTH - 1180, ball_HEIGHT = SCREEN_HEIGHT - 620;
int x = 30, y = 50;
int dx = 10, dy = 15;
int i, a = 0, b = 0;
double radius = 0.30;
int bx = 200;
int by = 310;
int xi = 100, yi = 400;
int position_kelefei = 1;
int CLOUD_WIDTH = SCREEN_WIDTH;
int SCREEN_WIDTH1 = 1280; //X-Coordinate for god entity
int SCREEN_HEIGHT1 = 720; //Y-Coordinate for god entity
int ball_x_position = 1280;
int ball_y_position = 360;
int SCREEN_WIDTH2 = 1280; //X-Coordinate for god entity w animation
int SCREEN_HEIGHT2 = 720; //Y-Coordinate for god entity w animation


//variables for tick and cross

int cx = 550;
int cy = 500;
int tx = 550;
int ty = 500;
int maxcy = cy + 10;
int mincy = cy - 10;
int maxty = ty + 10;
int minty = ty - 10;
int maxcx = cx + 5;
int maxtx = tx + 5;
int mincx = cx - 5;
int mintx = tx - 5;
float yn_i, yn_j;
int yes_no_state = 1;
//-----------------------
//variables for golden balls
int gx_position = 1280;
int gy_position = 720;
int g_ball_x_position = 1280;
int g_ball_y_position = 360;
int bling1_x_position = 320;
int bling1_y_position = 360;
int bling2_x_position = 360;
int bling2_y_position = 360;
int bling3_x_position = 960;
int bling3_y_position = 288;
int bling4_x_position = 1000;
int bling4_y_position = 288;
//int state = 1;
int state_2 = 1;

//variable for blue balls
int bx_position = 1280;
int by_position = 720;
int b_ball_x_position = 1280;
int b_ball_y_position = 360;
//ori ball
int ori_x_position = 1280;
int ori_y_position = 720;
int ori_ball_x_position = 1280;
int ori_ball_y_position = 360;

//variables for god+love
int love_count;
GLfloat love_x_position, love_y_position, th = 0;

//variables in god 3balls
int gbx = 640;
int gby = 360;

//variables in 3balls to mc
int bbx = 0;
int bby = 720;



void street(void)
{
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

	glColor3f(1, 0.5, 0.3);
	glBegin(GL_QUADS);
	glVertex2i(645, 220);
	glVertex2i(640, 20);
	glVertex2i(670, 20);
	glVertex2i(665, 220);
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

	glColor3f(1, 1, 1);
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

void cloudPart(int n, int x, int y, int r)
{
	glColor3f(173, 216, 230); //Setting: Color of the shape; The value is the RGB value
	double inc = 2 * PI / (double)n;
	for (double theta = 0.0; theta <= 2 * PI; theta += inc)
	{
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
}

void cloud()
{
	glBegin(GL_TRIANGLE_FAN);
	cloudPart(360, cloud_x_position / 2 - 300, cloud_y_position / 2 + 250, 70); //Center cloud
	cloudPart(360, cloud_x_position / 2 - 250, cloud_y_position / 2 + 250, 50); //Right part of cloud
	cloudPart(360, cloud_x_position / 2 - 350, cloud_y_position / 2 + 250, 50); //Left part of cloud
	glEnd();
}

void cloud2()
{
	glBegin(GL_TRIANGLE_FAN);
	cloudPart(360, cloud_x_position / 2 + 400, cloud_y_position / 2 + 200, 70); //Center cloud
	cloudPart(360, cloud_x_position / 2 + 450, cloud_y_position / 2 + 200, 50); //Right part of cloud
	cloudPart(360, cloud_x_position / 2 + 350, cloud_y_position / 2 + 200, 50); //Left part of cloud
	glEnd();
}

void cloud3()
{
	glBegin(GL_TRIANGLE_FAN);
	cloudPart(360, cloud_x_position / 2 - 300, cloud_y_position / 2, 70); //Center cloud
	cloudPart(360, cloud_x_position / 2 - 250, cloud_y_position / 2, 50); //Right part of cloud
	cloudPart(360, cloud_x_position / 2 - 350, cloud_y_position / 2, 50); //Left part of cloud
	glEnd();
}

void bluesky()
{
	glColor3f(0.2, 0.7, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, y_position);
	glVertex2i(x_position, y_position);
	glVertex2i(x_position, 0);
	glEnd();
}

void skyWithCloud_1()
{
	bluesky();
	cloud();
	cloud2();
}

void skyWithCloud_2()
{
	bluesky();
	cloud3();
}

void rectangle(int x, int y, int w, int h)
{
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

void board(int x, int y, int w)
{
	int h = 0.75 * w;

	// draw board outline
	glColor3ub(155, 155, 155);
	rectangle(x, 2.5 * y, w, h);
	//draw board 
	glColor3ub(240, 182, 81);
	rectangle(x + w / 60, 2.5 * y, w - 8, h - 2);
	//draw small box outline
	glColor3ub(255, 0, 0);
	rectangle(x + w / 2 - w / 4, 2.5 * y, w / 2, h / 2);
	//draw small box 
	glColor3ub(240, 182, 81);
	rectangle(x + w / 2 - w / 4.5, 2.5 * y, w / 2.2, h / 2.2);
	//draw pillar
	glColor3ub(61, 61, 61);
	rectangle(x + w / 2 - w / 10, y - (h / 1.9), w / 5, 2 * h / 1.5);

	//draw net
	glColor3ub(128, 128, 128);
	glBegin(GL_POLYGON);
	glVertex2i(x + w / 2 - w / 4.5, 2.5 * y);
	glVertex2i(x + w / 1.37, 2.5 * y);
	glVertex2i(x + w / 1.5, 1.8 * y);
	glVertex2i(x + w / 2 - w / 6, 1.8 * y);
	glBegin(GL_POLYGON);
	glEnd();
}

void board_2(int x, int y, int w) {
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

void cloud_kelefei(void) {
	glColor3f(1, 1, 1);
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

void tree_kelefei(void) {
	glColor3f(0.7, 0.2, 0.2);
	glBegin(GL_POLYGON); //1 
	glVertex2i(140, 280);
	glVertex2i(155, 280);
	glVertex2i(155, 340);
	glVertex2i(140, 340);
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

void mountain_kelefei(void) {
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

void background_1()
{
	glColor3ub(180, 105, 50);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(1280, 0);
	glVertex2i(1280, 200);
	glVertex2i(0, 200);
	glEnd();
}

void mountain_mc() {

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

void basketball(int n, int x, int y, int r)
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 100, 0); //Setting: Color of the shape; The value is the RGB value
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

void kelefei(void) {
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

	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 637 + 4 * cos(th);
		y_position = SCREEN_HEIGHT - 200 + 6 * sin(th);
		glColor3f(0, 0, 0);
		glVertex2d(x_position, y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (count = 1; count <= 10000; count++) {
		th = th + 0.001;
		x_position = 667 + 4 * cos(th);
		y_position = SCREEN_HEIGHT - 200 + 6 * sin(th);
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

	glColor3f(1, 0.5, 0.3);
	glBegin(GL_TRIANGLES);
	glVertex2i(647, SCREEN_HEIGHT - 300);
	glVertex2i(657, SCREEN_HEIGHT - 300);
	glVertex2i(652, SCREEN_HEIGHT - 290);
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

void ball(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();
}

void god() {
	//body
	glColor3ub(0, 193, 255);
	rectangle(SCREEN_WIDTH1 * 0.375, SCREEN_HEIGHT1 * 0.425, SCREEN_WIDTH1 * 0.25, SCREEN_HEIGHT1 * 0.3);
	glColor3ub(106, 90, 205);
	trapezium(SCREEN_WIDTH1 * 0.375, SCREEN_HEIGHT1 * 0.0035, SCREEN_WIDTH1 * 0.25, 200);

	//head
	glColor3ub(250, 250, 0);
	triangle_even(SCREEN_WIDTH1 * 0.48, 625, 50, SCREEN_HEIGHT1 * 0.07);
	glColor3ub(255, 0, 0);
	nGon(360, SCREEN_WIDTH1 / 2, SCREEN_HEIGHT1 * 0.8, 50);

	//hands
	glColor3ub(255, 165, 0);
	triangle_right(SCREEN_WIDTH1 * 0.625, SCREEN_HEIGHT1 * 0.60625, 250, SCREEN_HEIGHT1 * 0.1);
	glColor3ub(255, 0, 0);
	nGon(360, SCREEN_WIDTH1 * 0.8425, SCREEN_HEIGHT1 * 0.65, 35);
	glColor3ub(255, 165, 0);
	triangle_left(SCREEN_WIDTH1 * 0.37, SCREEN_HEIGHT1 * 0.60625, 250, SCREEN_HEIGHT1 * 0.1);
	glColor3ub(255, 0, 0);
	nGon(360, SCREEN_WIDTH1 * 0.15, SCREEN_HEIGHT1 * 0.65, 35);

	//legs
	rectangle_left(SCREEN_WIDTH1 * 0.375, SCREEN_HEIGHT1 * 0.05, SCREEN_WIDTH1 * 0.0625, SCREEN_HEIGHT1 * 0.225);
	rectangle_right(SCREEN_WIDTH1 * 0.5625, SCREEN_HEIGHT1 * 0.05, SCREEN_WIDTH1 * 0.0625, SCREEN_HEIGHT1 * 0.225);
}

void balls()
{
	//gold ball
	glColor3ub(255, 220, 0);
	ball(360, ball_x_position * 0.5, ball_y_position, 60);

	//blue ball
	glColor3ub(40, 25, 255);
	ball(360, ball_x_position * 0.25, ball_y_position, 60);

	//ori ball
	glColor3ub(255, 100, 0);
	ball(360, ball_x_position * 0.75, ball_y_position, 60);

}

void god_body() {
	//upper body
	glColor3ub(0, 193, 255);
	rectangle(SCREEN_WIDTH2 * 0.3125, SCREEN_HEIGHT2 * 0.425, SCREEN_WIDTH2 * 0.375, SCREEN_HEIGHT2 * 0.58);

	//lower body
	glColor3ub(106, 90, 205);
	trapezium(SCREEN_WIDTH2 * 0.3125, SCREEN_HEIGHT2 * 0.1, SCREEN_WIDTH2 * 0.375, 200);

	//left leg
	glColor3ub(255, 0, 0);
	rectangle(SCREEN_WIDTH2 * 0.3125, SCREEN_HEIGHT2 * 0.0625, SCREEN_WIDTH2 * 0.125, SCREEN_HEIGHT2 * 0.3);
	//right leg
	rectangle(SCREEN_WIDTH2 * 0.5625, SCREEN_HEIGHT2 * 0.0625, SCREEN_WIDTH2 * 0.125, SCREEN_HEIGHT2 * 0.3);

}

void bling(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x - (w / 2), y + h);
	glVertex2i(x - w, y);
	glVertex2i(x - (w / 2), y - h);
	glEnd();
}

void golden_balls() {
	//gold ball
	glColor3ub(255, 220, 0);
	ball(360, g_ball_x_position * 0.5, g_ball_y_position, g_ball_x_position * 0.25);

}

void golden_balls2() {
	//gold ball
	glColor3ub(255, 220, 0);
	ball(20, gbx, gby, 30);
}

void golden_balls3() {
	//gold ball
	glColor3ub(255, 220, 0);
	ball(20, bbx, bby, 40);
}


void blue_balls() {
	//blue ball
	glColor3ub(40, 25, 255);
	ball(360, b_ball_x_position * 0.5, b_ball_y_position, b_ball_x_position * 0.25);

}

void blue_balls2() {
	//blue ball
	glColor3ub(40, 25, 255);
	ball(20, gbx - 80, gby, 30);

}

void blue_balls3() {
	//blue ball
	glColor3ub(40, 25, 255);
	ball(20, bbx - 100, bby, 40);

}

void ori_balls() {

	glColor3ub(255, 100, 0);
	ball(360, ori_ball_x_position * 0.5, ori_ball_y_position, ori_ball_x_position * 0.25);
}

void ori_balls2() {

	glColor3ub(255, 100, 0);
	ball(20, (gbx + 80), gby, 30);
}

void ori_balls3() {

	glColor3ub(255, 100, 0);
	ball(20, (bbx + 100), bby, 40);
}

void blingbling1() {
	glColor3ub(255, 255, 255);
	bling(bling1_x_position, bling1_y_position, 40, 30);
}

void blingbling2() {
	glColor3ub(255, 255, 255);
	bling(bling2_x_position, bling2_y_position, 40, 30);
}

void blingbling3() {
	glColor3ub(255, 255, 255);
	bling(bling3_x_position, bling3_y_position, 40, 30);
}

void blingbling4() {
	glColor3ub(255, 255, 255);
	bling(bling4_x_position, bling4_y_position, 40, 30);
}


//cross - no
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
//tick - yes
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

void person2(int x, int y, int w) //mc when saying yes or no
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

void dialog(int n, int x, int y, int r)
{
	glColor3ub(255, 255, 255);
	double inc = PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2d(r * cos(theta) + x, (3 * r / 4) * sin(theta) + y);
	}
	glEnd();
}

void love(void) {
	glColor3f(1, 0, 0);

	//--Love 1
	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 350 + 20 * cos(th);
		love_y_position = 530 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 380 + 20 * cos(th);
		love_y_position = 530 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(332, 520);
	glVertex2i(398, 520);
	glVertex2i(365, 490);
	glEnd();

	//--Love 2
	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 880 + 20 * cos(th);
		love_y_position = 530 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 910 + 20 * cos(th);
		love_y_position = 530 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(862, 520);
	glVertex2i(928, 520);
	glVertex2i(895, 490);
	glEnd();

	//--Love 3
	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 220 + 20 * cos(th);
		love_y_position = 330 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 250 + 20 * cos(th);
		love_y_position = 330 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(202, 320);
	glVertex2i(268, 320);
	glVertex2i(235, 290);
	glEnd();

	//--Love 4
	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 1020 + 20 * cos(th);
		love_y_position = 330 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 1050 + 20 * cos(th);
		love_y_position = 330 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(1002, 320);
	glVertex2i(1068, 320);
	glVertex2i(1035, 290);
	glEnd();

	//--Love 5
	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 350 + 20 * cos(th);
		love_y_position = 150 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 380 + 20 * cos(th);
		love_y_position = 150 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(332, 140);
	glVertex2i(398, 140);
	glVertex2i(365, 110);
	glEnd();

	//--Love 6
	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 880 + 20 * cos(th);
		love_y_position = 150 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (love_count = 1; love_count <= 10000; love_count++) {
		th = th + 0.001;
		love_x_position = 910 + 20 * cos(th);
		love_y_position = 150 + 20 * sin(th);
		glVertex2d(love_x_position, love_y_position);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(862, 140);
	glVertex2i(928, 140);
	glVertex2i(895, 110);
	glEnd();
}

bool visible = true;

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

void timer(int value) //Motion
{
	switch (value) {
	case 0:
		glutPostRedisplay();
		glutTimerFunc(1000 / 60, timer, 0);

		if (SCREEN_WIDTH > 500) //Move towards the Basketball Net (Fly UP)
		{
			SCREEN_WIDTH -= 10;
			SCREEN_HEIGHT += 7;
			basketball(360, SCREEN_WIDTH, SCREEN_HEIGHT, 50);
		}
		else if (SCREEN_WIDTH > 400) //Move towards the Basketball Net (Drop DOWN)
		{
			SCREEN_WIDTH -= 10;
			SCREEN_HEIGHT -= 6;
			basketball(360, SCREEN_WIDTH, SCREEN_HEIGHT, 50);
		}
		else if (SCREEN_WIDTH > 200) //Move towards the sky
		{
			SCREEN_WIDTH += 0.5;
			SCREEN_HEIGHT += 10;
			basketball(360, SCREEN_WIDTH, SCREEN_HEIGHT, 50);
		}

		switch (state)
		{
		case 1: //Move to right
			if (cloud_x_position <= 2560)
			{
				cloud_x_position += 10;
			}
			else
			{
				state = -1;
			}
			break;
		case -1: //Move to left
			if (cloud_x_position > 0)
			{
				cloud_x_position -= 10;
			}
			else
			{
				state = 1;
			}
			break;
		}
		break;
	case 1:
		glutPostRedisplay();
		glutTimerFunc(1000 / 60, timer, 1);

		if (ball_WIDTH >= 100 && ball_WIDTH < 320) //Move towards the Basketball Net (Fly UP)
		{
			ball_WIDTH += 3;
			ball_HEIGHT += 5;
			basketball(360, ball_WIDTH, ball_HEIGHT, 50);
		}
		else if (ball_HEIGHT > 320 && ball_WIDTH < 420)
		{
			ball_WIDTH += 3;
			ball_HEIGHT -= 3;
			basketball(360, ball_WIDTH, ball_HEIGHT, 50);
		}
		else if (ball_HEIGHT > 300 && ball_WIDTH >= 420)
		{
			ball_WIDTH += 3;
			ball_HEIGHT += 3;
			basketball(360, ball_WIDTH, ball_HEIGHT, 50);
		}

		switch (state) //Motion for cloud
		{
		case 1: //Move to right
			if (cloud_x_position <= 2560)
			{
				cloud_x_position += 20;
			}
			else
			{
				state = -1;
			}
			break;
		case -1: //Move to left
			if (cloud_x_position > 0)
			{
				cloud_x_position -= 20;
			}
			else
			{
				state = 1;
			}
			break;
		}
		break;
	case 2:
		glutPostRedisplay();
		glutTimerFunc(1000 / 30, timer, 2);

		if (xi < 700)
		{
			xi += 5;
			if ((xi > 100 && xi < 200) || (xi > 300 && xi < 400) || (xi > 500 && xi < 600))
			{
				yi += 1;
			}
			else if ((xi > 200 && xi < 300) || (xi > 400 && xi < 500) || (xi > 600 && xi < 700))
			{
				yi -= 1;
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
		break;

	case 3:
		glutPostRedisplay();
		glutTimerFunc(1000 / 30, timer, 3);

		if (SCREEN_HEIGHT >= -300)
		{
			SCREEN_HEIGHT -= 2;
		}

		switch (position_kelefei)
		{
		case 1: //Move to right
			if (CLOUD_WIDTH <= 1500)
			{
				CLOUD_WIDTH += 2;
			}
			else
			{
				position_kelefei = -1;
			}
			break;
		case -1: //Move to left
			if (CLOUD_WIDTH > 0)
			{
				CLOUD_WIDTH -= 2;
			}
			else
			{
				position_kelefei = 1;
			}
			break;
		}
		break;

	case 4:
		glutPostRedisplay();
		glutTimerFunc(1000 / 30, timer, 4);

		switch (state) {
		case 1:
			if (ball_y_position < 540)
				ball_y_position += 7.5;
			else
				state = -1;
			break;
		case -1:
			if (ball_y_position > 360)
				ball_y_position -= 7.5;
			else
				state = 1;
			break;
		}
		break;

	case 5:
		glutPostRedisplay();
		glutTimerFunc(1000 / 30, timer, 5);

		switch (state) {
		case 1:
			if (bling1_y_position < 370 && bling2_y_position < 370 && bling3_y_position < 298 && bling4_y_position < 298) {
				bling1_y_position += 1;
				bling2_y_position += 1;
				bling3_y_position += 1;
				bling4_y_position += 1;
			}
			else
				state = -1;
			break;
		case -1:
			if (bling1_y_position > 360 && bling2_y_position > 360 && bling3_y_position > 288 && bling4_y_position > 288) {
				bling1_y_position -= 0.7;
				bling2_y_position -= 0.7;
				bling3_y_position -= 0.7;
				bling4_y_position -= 0.7;
			}
			else
				state = 1;
			break;
		}
		break;

	case 6:
		glutPostRedisplay();
		glutTimerFunc(1000 / 30, timer, 6);
		switch (yes_no_state) {
		case 1:
			if (cy <= maxcy || ty <= maxty || cx <= maxcx || tx <= maxtx) {
				cy += 2;
				ty += 2;
				cx += 1;
				tx += 1;
			}
			else {
				yes_no_state = -1;
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
				yes_no_state = 1;
			}
			break;
		}

		break;
	case 7:
		glutPostRedisplay();
		glutTimerFunc(500, timer, 7);

		visible = !visible;
		break;

	case 8:
		glutPostRedisplay();
		glutTimerFunc(1000 / 30, timer, 8);

		if (gbx < 900 && gby > 200)
		{
			gbx += 5;
			gby -= 5;
		}
		else
		{
			gbx += 5;
			gby -= 2;
		}
		break;

	case 9:
		glutPostRedisplay();
		glutTimerFunc(1000 / 30, timer, 9);

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
		break;
	}
}

void display_Boardball()
{
	glClear(GL_COLOR_BUFFER_BIT);
	skyWithCloud_1();
	board(100, 100, 250);
	basketball(360, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 600, 50);
	glFlush();
	glutSwapBuffers();
}

void display_BallBounce()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clear the screen and filled with glClearColor
	skyWithCloud_2();
	basketball(360, ball_WIDTH, ball_HEIGHT, 50);
	glFlush();
	glutSwapBuffers();
}

void display_kelefei()
{
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
	tree_kelefei();
	mountain_kelefei();
	cloud_kelefei();
	kelefei();
	glFlush();
	glutSwapBuffers();
}

void display_mc() {
	glClear(GL_COLOR_BUFFER_BIT);

	//drawing the Mountain
	bluesky();
	mountain_mc();

	//----------
	background_1();
	board_2(800, 400, 200);

	person(xi, yi, 30);
	basketball(20, bx, by, 25);

	glFlush();
	glutSwapBuffers();
}

void display_god() {
	glClear(GL_COLOR_BUFFER_BIT);
	god();
	glFlush();
	glutSwapBuffers();
}

void display_godwballs() {
	glClear(GL_COLOR_BUFFER_BIT);
	god_body();
	balls();
	glFlush();
	glutSwapBuffers();
}

void display_g_balls() {
	glClear(GL_COLOR_BUFFER_BIT);
	golden_balls();
	blingbling1();
	blingbling2();
	blingbling3();
	blingbling4();
	glFlush();
	glutSwapBuffers();
}

void display_b_balls() {
	glClear(GL_COLOR_BUFFER_BIT);
	blue_balls();
	blingbling1();
	blingbling2();
	blingbling3();
	blingbling4();
	glFlush();
	glutSwapBuffers();
}

void display_ori_balls() {
	glClear(GL_COLOR_BUFFER_BIT);
	ori_balls();
	glFlush();
	glutSwapBuffers();
}

void display_cross_no(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	bluesky();
	background_1();

	board_2(800, 400, 300);
	dialog(50, 550, 500, 80);

	cross(cx, cy);

	person2(700, 400, 50);
	glFlush();
	glutSwapBuffers();
}

void display_tick_yes(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	bluesky();
	background_1();

	board_2(800, 400, 300);

	dialog(50, 550, 500, 80);

	tick(tx, ty);

	person2(700, 400, 50);
	glFlush();
	glutSwapBuffers();
}

void display_god_love(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	god();
	if (visible) {
		love();
	}

	glFlush(); //sends all output to display 
	glutSwapBuffers();
}

void display_god_3balls() {
	glClear(GL_COLOR_BUFFER_BIT);

	//bluesky();
	//person(x, y, 30);
	god();
	//glColor3ub(40, 25, 255);
	blue_balls2();
	//glColor3ub(255, 220, 0);
	golden_balls2();
	//glColor3ub(255, 100, 0);
	ori_balls2();

	glFlush();
	glutSwapBuffers();
}

void display_3balls_mc() {
	glClear(GL_COLOR_BUFFER_BIT);

	bluesky();
	background_1();
	//person(x, y, 30);

	board_2(800, 400, 300);
	person2(700, 400, 50);
	//glColor3ub(40, 25, 255);
	blue_balls3();
	//glColor3ub(255, 220, 0);
	golden_balls3();
	//glColor3ub(255, 100, 0);
	ori_balls3();

	glutSwapBuffers();
	glFlush();

}

void display_the_end()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//drawing the Screen

	theEnd();
	beHonest();

	glutSwapBuffers();
	glFlush();
}

void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
	glPointSize(10.0);
	glLineWidth(5.0);
}

void switchDisplay(int value) {
	if (value == 1) //Kelefei appear to join the basketball match
	{
		glutDisplayFunc(display_kelefei);
		glutTimerFunc(1, timer, 3);
		glutTimerFunc(4000, switchDisplay, 2);
	}
	else if (value == 2) //Ball fly towards the net
	{
		glutDisplayFunc(display_Boardball);
		glutTimerFunc(1, timer, 0);
		glutTimerFunc(3000, switchDisplay, 3);
	}
	else if (value == 3) //Ball hit the net, bounce up to the sky
	{
		glutDisplayFunc(display_BallBounce);
		glutTimerFunc(1, timer, 1);
		glutTimerFunc(3000, switchDisplay, 4);
	}
	else if (value == 4) //The god wake up
	{
		glutDisplayFunc(display_god);
		glutTimerFunc(4000, switchDisplay, 5);
	}

	else if (value == 5) //The god summon the balls
	{
		glutDisplayFunc(display_godwballs);
		glutTimerFunc(1, timer, 4);
		glutTimerFunc(4000, switchDisplay, 6);
	}
	else if (value == 6) //Is your basketball is a golden ball?
	{
		glutDisplayFunc(display_g_balls);
		glutTimerFunc(1, timer, 5);
		glutTimerFunc(4000, switchDisplay, 7);
	}
	else if (value == 7) //MC said no
	{
		glutDisplayFunc(display_cross_no);
		glutTimerFunc(1, timer, 6);
		glutTimerFunc(4000, switchDisplay, 8);
	}
	else if (value == 8) //Is your basketball is a blue ball?
	{
		glutDisplayFunc(display_b_balls);
		glutTimerFunc(1, timer, 5);
		glutTimerFunc(4000, switchDisplay, 9);
	}
	else if (value == 9) //MC said no again
	{
		glutDisplayFunc(display_cross_no);
		glutTimerFunc(1, timer, 6);
		glutTimerFunc(4000, switchDisplay, 10);
	}
	else if (value == 10) //Is your basketball is a orange ball?
	{
		glutDisplayFunc(display_ori_balls);
		glutTimerFunc(4000, switchDisplay, 11);
	}
	else if (value == 11) //MC said yes
	{
		glutDisplayFunc(display_tick_yes);
		glutTimerFunc(1, timer, 6);
		glutTimerFunc(4000, switchDisplay, 12);
	}
	else if (value == 12) //God with love around
	{
		glutDisplayFunc(display_god_love);
		glutTimerFunc(500, timer, 7);
		glutTimerFunc(4000, switchDisplay, 13);
	}
	else if (value == 13) //Three balls flying down
	{
		glutDisplayFunc(display_god_3balls);
		glutTimerFunc(500, timer, 8);
		glutTimerFunc(6000, switchDisplay, 14);
	}
	else if (value == 14) //Three balls flying down to MC
	{
		glutDisplayFunc(display_3balls_mc);
		glutTimerFunc(1, timer, 9);
		glutTimerFunc(6000, switchDisplay, 15);
	}
	else if (value == 15) //THE END
	{
		glutDisplayFunc(display_the_end);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Project 1");
	glutDisplayFunc(display_mc);
	glutTimerFunc(0, timer, 2);
	glutTimerFunc(4000, switchDisplay, 1);
	initGL();
	glutMainLoop();
}
