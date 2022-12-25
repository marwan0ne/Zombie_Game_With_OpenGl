#include<Windows.h>
#include<mmsystem.h>
#include "TextureBuilder.h"
#include<string>
#include <glut.h>
#include<math.h>
using namespace std;

#define GLUT_KEY_ESCAPE 27

GLuint texID;
int rep = 1;
int counter = 1;
int sword = 0;
float bullet_x, main_x, zombie_x = 0;
float  main_y = 0;
bool  playing = true;
bool little = true;
bool won = false;
int healths = 90;
int big_zombie_health = 120;
int human_health = 100;
GLUquadricObj* gl = gluNewQuadric();
GLUquadricObj* gl2 = gluNewQuadric();
void timer(int valu) {
	if (sword >= 50) {

		if (human_health > 0 && little)
			human_health -= 10;
		else if (sword == 120) {
			if (human_health >= 20)
				human_health -= 20;
			else if (human_health >= 0)
				human_health -= human_health;
		}
		if (human_health == 0) {
			playing = false;
			little = true;
			human_health = 100;
			healths = 90;
			big_zombie_health = 120;
		}
		sword = 0;
	}
	else {
		if (healths == 0)
			sword += 120;
		else
			sword += 50;
	}
	glutPostRedisplay();
	glutTimerFunc(1000, timer, 0);

}

int c = 0;
void C(int x, int y) {
	glPushMatrix();
	glTranslated(x, y, 0);
	glColor3f(c, c, c);
	gluDisk(gl, 30, 40, 40, 40);
	glPopMatrix();
	int x_start = x + 25;
	int x_end = x_start + 55;
	int y_start = y + 32;
	int y_end = y_start - 72;

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(x_start, y_start);
	glVertex2f(x_end, y_start);
	glVertex2f(x_end, y_end);
	glVertex2f(x_start, y_end);
	glEnd();


}
void I() {

	glBegin(GL_QUADS);
	glColor3f(c, c, c);
	glVertex2f(190, 392);
	glVertex2f(205, 392);
	glVertex2f(205, 320);
	glVertex2f(190, 320);
	glEnd();

}
void head() {

	glBegin(GL_POLYGON);
	glColor3f(1, c, c);

	glVertex2f(200, 395);

	glVertex2f(100, 395);
	glVertex2f(75, 425);
	glVertex2f(100, 425);
	glVertex2f(80, 470);
	glVertex2f(125, 450);
	glVertex2f(125, 475);
	glVertex2f(160, 440);

	glVertex2f(160, 525);
	glVertex2f(182, 510);
	glVertex2f(198, 555);
	glVertex2f(215, 510);
	glVertex2f(235, 525);
	glVertex2f(235, 440);

	glVertex2f(270, 475);
	glVertex2f(270, 450);
	glVertex2f(315, 470);
	glVertex2f(295, 425);
	glVertex2f(320, 425);
	glVertex2f(295, 395);
	glEnd();
	glPushMatrix();
	glTranslated(135, 360, 0);
	glColor3f(1, 1, 1);
	gluDisk(gl, 0, 50, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(260, 360, 0);
	glColor3f(1, 1, 1);
	gluDisk(gl, 0, 50, 50, 50);
	glPopMatrix();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(170, 405);
	glVertex2f(225, 405);
	glVertex2f(225, 310);
	glVertex2f(170, 310);
	glEnd();

}
void bullet() {
	glPushMatrix();
	glTranslated(bullet_x, 0, 0);
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(220, 225, 0);
	gluDisk(gl, 0, 5, 10, 10);
	glPopMatrix();
	glPopMatrix();
}
void health() {
	glColor3f(1, 1, 1);
	glRasterPos2d(80, 520);
	string countsa = to_string(human_health);
	for (int i = 0; i < size(countsa); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, countsa[i]);
	}
	glRasterPos2d(110, 520);
	string dividee = "/";
	for (int i = 0; i < size(dividee); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, dividee[i]);
	}
	glRasterPos2d(120, 520);
	string onehunder = "100";
	for (int i = 0; i < size(onehunder); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, onehunder[i]);
	}
	glColor3f(1, 1, 1);
	glRasterPos2d(510, 520);

	string onehund;
	if (healths > 0)
		onehund = "90";
	else
		onehund = "120";
	for (int i = 0; i < size(onehund); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, onehund[i]);
	}
	glRasterPos2d(500, 520);
	string divide = "/";
	for (int i = 0; i < size(divide); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, divide[i]);
	}
	glRasterPos2d(470, 520);
	string counts;
	if (healths > 0)
		counts = to_string(healths);
	else
		counts = to_string(big_zombie_health);
	for (int i = 0; i < size(counts); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, counts[i]);
	}

}

void human_head() {
	glPushMatrix();
	glColor3f(0.9, 0.7, 0.5);
	glTranslated(100, 300, 0);
	gluDisk(gl, 0, 35, 50, 50);
	glPopMatrix();
}
void zombie1_head() {
	glPushMatrix();
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glTranslated(416.44932, 287.18414, 0);
	gluDisk(gl, 0, 35, 50, 50);
	glPopMatrix();

}
void zombie2_head() {
	//z2
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glBegin(GL_POLYGON);
	glVertex2i(488.86818, 512.49219);
	glVertex2i(488.86818, 410.4807);
	glVertex2i(503.81814, 364.75141);
	glVertex2i(588.24144, 395.53074);
	glVertex2i(588.46786, 512.49219);
	glEnd();

	glPushMatrix();
	glColor3f(0.5882352941176471, 0, 0);
	glTranslated(508.41006, 403.52944, 0);
	gluDisk(gl, 0, 5, 50, 50);
	glPopMatrix();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2i(488.86818, 512.49219);
	glVertex2i(488.86818, 410.4807);
	glVertex2i(503.81814, 364.75141);
	glVertex2i(588.24144, 395.53074);
	glVertex2i(588.46786, 512.49219);
	glEnd();
}
void human_eyes()
{
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(100, 300, 0);

	gluDisk(gl, 0, 5, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(122.86166, 301.64748, 0);
	gluDisk(gl, 0, 5, 50, 50);
	glPopMatrix();
}
void zombie1_eye() {
	//z1
	glPushMatrix();
	glColor3f(0.9803921568627451, 0, 0);
	glTranslated(388.88318, 286.34138, 0);
	gluDisk(gl, 0, 12, 50, 50);
	glPopMatrix();



	glPushMatrix();
	glColor3f(0.9803921568627451, 0, 0);
	glTranslated(416.44932, 287.18414, 0);
	gluDisk(gl, 0, 9, 50, 50);
	glPopMatrix();

}
void zombei2_eye() {
	//z2


	glPushMatrix();
	glColor3f(0.9803921568627451, 0, 0);
	glTranslated(541.27908, 470.99914, 0);
	gluDisk(gl, 0, 11, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9803921568627451, 0, 0);
	glTranslated(500.27908, 470.99914, 0);
	gluDisk(gl, 0, 14, 50, 50);
	glPopMatrix();


}
void zombie1_mouth() {
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(394.57429, 265.61884);
	glVertex2f(413.22779, 265.40686);
	glEnd();

}

void human_nose()
{
	glPushMatrix();
	glTranslated(113.04614, 295.03953, 0);

	glTranslated(-300.0, -300.0, 0);
	glBegin(GL_TRIANGLES);

	glColor3f(0, 0, 0);
	glVertex3f(298, 295, 0);
	glVertex3f(300, 305, 0);
	glVertex3f(305, 295, 0);
	glEnd();
	glPopMatrix();

}
void zombie1_nose() {
	glPushMatrix();
	glTranslated(396.48204, 279.69628, 0);
	glTranslated(-295.58802, -300.73361, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex3f(298, 295, 0);
	glVertex3f(305, 305, 0);
	glVertex3f(305, 295, 0);
	glEnd();
	glPopMatrix();

}
void zombie2_nose() {
	glPushMatrix();
	glTranslated(513.75403, 454.22595, 0);
	glTranslated(-310.58802, -307.73361, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex3f(285, 285, 0);
	glVertex3f(300, 305, 0);
	glVertex3f(305, 285, 0);
	glEnd();
	glPopMatrix();
}
void human_neck()
{
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.7, 0.5);
	glVertex2f(106.15268, 271.92225);
	glVertex2f(91.68378, 271.92225);
	glVertex2f(91.68378, 251.80144);
	glVertex2f(106.15268, 251.80144);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(106.15268, 271.92225);
	glVertex2f(91.68378, 271.92225);
	glVertex2f(91.68378, 251.80144);
	glVertex2f(106.15268, 251.80144);
	glEnd();
}
void zombie1_neck() {
	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(406.71782, 259.38333);
	glVertex2f(424.53745, 258.91439);
	glVertex2f(423.02742, 238.18886);
	glVertex2f(409.06251, 237.81219);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(406.71782, 259.38333);
	glVertex2f(424.53745, 258.91439);
	glVertex2f(423.02742, 238.18886);
	glVertex2f(409.06251, 237.81219);
	glEnd();
}
void zombie2_neck() {
	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(520.62831, 370.09389);
	glVertex2f(539.53665, 376.86086);
	glVertex2f(544.2697, 344.87506);
	glVertex2f(518.59688, 347.80728);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(520.62831, 370.09389);
	glVertex2f(539.53665, 376.86086);
	glVertex2f(544.2697, 344.87506);
	glVertex2f(518.59688, 347.80728);
	glEnd();
}
void human_body()
{
	//side arm
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.7, 0.5);
	glVertex2f(130.66072, 251.26687);
	glVertex2f(145.26994, 251.26687);
	glVertex2f(148.99667, 178.14817);
	glVertex2f(137.15371, 178.22075);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(130.66072, 251.26687);
	glVertex2f(145.26994, 251.26687);
	glVertex2f(148.99667, 178.14817);
	glVertex2f(137.15371, 178.22075);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6, 0, 0.6);
	glVertex2f(130.66072, 251.26687);
	glVertex2f(145.26994, 251.26687);
	glVertex2f(148.99667, 220.14817);
	glVertex2f(132.15371, 220.22075);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(130.66072, 251.26687);
	glVertex2f(145.26994, 251.26687);
	glVertex2f(148.99667, 220.14817);
	glVertex2f(132.15371, 220.22075);
	glEnd();

	//body
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(66.2073, 252.17465);
	glVertex2f(134.03295, 251.3767);
	glVertex2f(133.235, 162.00643);
	glVertex2f(66.2073, 161.20848);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(66.2073, 252.17465);
	glVertex2f(134.03295, 251.3767);
	glVertex2f(133.235, 162.00643);
	glVertex2f(66.2073, 161.20848);
	glEnd();
}
void zombie1_body() {
	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(376.7058, 242.87432);
	glVertex2f(457.83204, 242.81219);
	glVertex2f(446.57753, 125.79218);
	glVertex2f(393.58756, 125.26112);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(376.7058, 242.87432);
	glVertex2f(457.83204, 242.81219);
	glVertex2f(446.57753, 125.79218);
	glVertex2f(393.58756, 125.26112);
	glEnd();
}
void zombie2_body() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(469.37606, 356.41049);
	glVertex2f(597.11405, 340.44324);
	glVertex2f(574.96051, 173.93862);
	glVertex2f(479.15702, 156.69399);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(469.37606, 356.41049);
	glVertex2f(597.11405, 340.44324);
	glVertex2f(574.96051, 173.93862);
	glVertex2f(479.15702, 156.69399);
	glEnd();

}
void human_leg() {
	//shorts
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(65.19876, 161.93597);
	glVertex2i(110.2073, 161.20848);
	glVertex2f(100.29725, 19.48639);
	glVertex2f(62.62064, 19.91806);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(100.19214, 161.99436);
	glVertex2f(132.52059, 161.00474);
	glVertex2f(141.61706, 19.48639);
	glVertex2f(110, 19.48639);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(73.94671, 35.4327);
	glVertex2f(93.83754, 35.85488);
	glVertex2f(91.29725, 19.48639);
	glVertex2f(76.62064, 19.91806);
	glTranslated(250.0, 70.0, 0);
	glTranslated(-250, -70, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(119.19214, 35.99436);
	glVertex2f(135.52059, 35.00474);
	glVertex2f(133.61706, 20);
	glVertex2f(120, 20);
}
void zombie1_leg() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(446.57753, 125.79218);
	glVertex2f(402.58756, 125.26112);
	glVertex2f(429.308, 22.13865);
	glVertex2f(439.51071, 22.99071);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(395.28288, 124.79218);
	glVertex2f(420.75782, 124.79218);
	glVertex2f(411.05052, 22.45939);
	glVertex2f(399.77385, 22.99637);
	glEnd();
}
void zombie2_leg() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(479.23667, 157.06712);
	glVertex2f(521.60666, 163.822);
	glVertex2f(511.10995, 23.20779);
	glVertex2f(468.73737, 23.84648);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(505.80316, 160.48793);
	glVertex2f(573.93492, 175.37434);
	glVertex2f(574.7599, 23.73338);
	glVertex2f(530.16767, 23.38814);
	glEnd();
}
void human_arms() {
	//gun
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(192.64632, 232.10973);
	glVertex2f(193.1867, 220.4915);
	glVertex2f(233.05989, 220.57238);
	glVertex2f(232.71091, 229.9946);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(192.64632, 232.10973);
	glVertex2f(193.1867, 220.4915);
	glVertex2f(233.05989, 220.57238);
	glVertex2f(232.71091, 229.9946);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(193.1867, 220.4915);
	glVertex2f(188.05306, 202.65886);
	glVertex2f(198.323, 202.48058);
	glVertex2f(201.09242, 220.31624);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(193.1867, 220.4915);
	glVertex2f(188.05306, 202.65886);
	glVertex2f(198.323, 202.48058);
	glVertex2f(201.09242, 220.31624);
	glEnd();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(203.39732, 217.7806, 0);
	gluDisk(gl, 0, 5, 50, 50);
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.7, 0.5);
	glVertex2f(81.41366, 234.13858);
	glVertex2f(81.41366, 207.88225);
	glVertex2f(199.38892, 210.9285);
	glVertex2f(199.19263, 224.42982);
	glVertex2f(102.72647, 208.1774);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(81.41366, 234.13858);
	glVertex2f(81.41366, 207.88225);
	glVertex2f(102.72647, 208.1774);
	glVertex2f(193.38892, 210.9285);
	glVertex2f(193.19263, 224.42982);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0, 0.6);
	glVertex2f(81.41366, 249.13858);
	glVertex2f(81.41366, 207.88225);
	glVertex2f(110.38892, 200.9285);
	glVertex2f(110.19263, 234.42982);
	glVertex2f(90.72647, 208.1774);
	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(110.38892, 200.9285);
	glVertex2f(110.19263, 234.42982);
	glVertex2f(81.41366, 249.13858);
	glVertex2f(81.41366, 207.88225);
	glVertex2f(90.72647, 208.1774);
	glEnd();

}
void zombie1_arm() {
	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(302.56754, 227.16231);
	glVertex2f(302.61364, 215.3993);
	glVertex2f(380.73312, 215.19143);
	glVertex2f(378.88703, 227.28688);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(302.56754, 227.16231);
	glVertex2f(302.61364, 215.3993);
	glVertex2f(380.73312, 215.19143);
	glVertex2f(378.88703, 227.28688);
	glEnd();
	glPushMatrix();
	glTranslated(-sword, -sword, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.6313725490196078, 0, 0);
	glVertex2f(216.48051, 333.92689);
	glVertex2f(258.78607, 263.60818);
	glVertex2f(305.14089, 200.06476);
	glVertex2f(324.21789, 200.42376);

	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(216.48051, 333.92689);
	glVertex2f(258.78607, 263.60818);
	glVertex2f(305.14089, 200.06476);
	glVertex2f(324.21789, 200.42376);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(288.69909, 245.42511);
	glVertex2f(281.41255, 231.72336);
	glVertex2f(305.14089, 200.42376);
	glVertex2f(324.21789, 200.42376);
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(352.56754, 230.16231);
	glVertex2f(352.61364, 210.3993);
	glVertex2f(380.73312, 210.19143);
	glVertex2f(378.88703, 230.28688);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(352.56754, 230.16231);
	glVertex2f(352.61364, 210.3993);
	glVertex2f(380.73312, 210.19143);
	glVertex2f(378.88703, 230.28688);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(300.56754, 215.16231);
	glVertex2f(300.61364, 205.3993);
	glVertex2f(420.73312, 195.19143);
	glVertex2f(420.88703, 210.28688);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(300.56754, 215.16231);
	glVertex2f(300.61364, 205.3993);
	glVertex2f(420.73312, 195.19143);
	glVertex2f(420.88703, 210.28688);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(385.56754, 220.16231);
	glVertex2f(385.61364, 190.3993);
	glVertex2f(420.73312, 190.19143);
	glVertex2f(420.88703, 220.28688);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(385.56754, 220.16231);
	glVertex2f(385.61364, 190.3993);
	glVertex2f(420.73312, 190.19143);
	glVertex2f(420.88703, 220.28688);
	glEnd();
}
void zombie2_arm() {

	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(353.97927, 324.3528);
	glVertex2f(357.75309, 303.5968);
	glVertex2f(470.36316, 316.37077);
	glVertex2f(471.68131, 335.08843);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(353.97927, 324.3528);
	glVertex2f(357.75309, 303.5968);
	glVertex2f(470.36316, 316.37077);
	glVertex2f(471.68131, 335.08843);
	glEnd();


	//sowrd
	glPushMatrix();
	glTranslated(-sword, -sword, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.6313725490196078, 1, 1);
	glVertex2f(235.76443, 457.91855);
	glVertex2f(312.91728, 350.34939);
	glVertex2f(381.59449, 275.31318);
	glVertex2f(400.67149, 281.67218);

	glEnd();
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(235.76443, 455.91855);
	glVertex2f(312.91728, 350.34939);
	glVertex2f(381.59449, 275.31318);
	glVertex2f(400.67149, 281.67218);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(349.68403, 337.1636);
	glVertex2f(340, 320);
	glVertex2f(381.59449, 275.31318);
	glVertex2f(400.67149, 281.67218);
	glEnd();
	glPopMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(541.25499, 330.01353);
	glVertex2f(567.19999, 335.20253);
	glVertex2f(569.91488, 292.64415);
	glVertex2f(546.71552, 290.79874);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(541.25499, 330.01353);
	glVertex2f(567.19999, 335.20253);
	glVertex2f(569.91488, 292.64415);
	glVertex2f(546.71552, 290.79874);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0862745098039216, 0.7098039215686275, 0.0431372549019608);
	glVertex2f(367.09391, 295.57744);
	glVertex2f(367, 280);
	glVertex2f(548.91552, 290.79874);
	glVertex2f(543.8156, 306.61649);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(367.09391, 295.57744);
	glVertex2f(367, 280);
	glVertex2f(548.91552, 290.79874);
	glVertex2f(543.8156, 306.61649);
	glEnd();

	//z2 shirt
	glBegin(GL_QUADS);
	glColor3f(0.5607843137254902, 0.2274509803921569, 0.0549019607843137);
	glVertex2f(541.25499, 330.01353);
	glVertex2f(567.19999, 335.20253);
	glVertex2f(569.91488, 292.64415);
	glVertex2f(546.71552, 290.79874);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(541.25499, 330.01353);
	glVertex2f(567.19999, 335.20253);
	glVertex2f(569.91488, 292.64415);
	glVertex2f(546.71552, 290.79874);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5607843137254902, 0.2274509803921569, 0.0549019607843137);
	glVertex2f(443.97927, 340.3528);
	glVertex2f(443.75309, 302.5968);
	glVertex2f(470.36316, 312.37077);
	glVertex2f(471.68131, 340.08843);
	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(443.97927, 340.3528);
	glVertex2f(443.75309, 302.5968);
	glVertex2f(470.36316, 312.37077);
	glVertex2f(471.68131, 340.08843);
	glEnd();

}
void human_hair() {
	glPushMatrix();
	glTranslated(69.86674, 289.71916, 0);
	glColor3f(0, 0, 0);
	gluDisk(gl, 0, 5, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glTranslated(76.62026, 290.6401, 0);
	glColor3f(0, 0, 0);
	gluDisk(gl, 0, 7, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glTranslated(71.70861, 286.64938, 0);
	glColor3f(0, 0, 0);
	gluDisk(gl, 0, 7, 50, 50);
	glPopMatrix();


}

void Display(void) {
	if (playing) {

		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texID);
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(rep, 0.0f); glVertex3f(600, 0, 0);
		glTexCoord2f(rep, rep); glVertex3f(600, 600, 0);
		glTexCoord2f(0.0f, rep); glVertex3f(0, 600, 0);
		glEnd();
		glPopMatrix();
		glRasterPos2d(10, 500);
		health();

		glPushMatrix();
		glTranslated(10 + main_x, 10 + main_y, 0);
		bullet();
		human_neck();
		human_hair();
		human_head();
		human_eyes();
		human_nose();
		human_body();
		human_arms();
		human_leg();
		glPopMatrix();

		if (healths == 0 && big_zombie_health != 0) {
			glPushMatrix();
			zombie2_neck();
			zombie2_head();
			zombei2_eye();
			zombie2_nose();
			zombie2_body();
			zombie2_arm();
			zombie2_leg();
			glPopMatrix();
		}

		else {
			glPushMatrix();
			zombie1_neck();
			zombie1_head();
			zombie1_eye();
			zombie1_mouth();
			zombie1_nose();
			zombie1_body();
			zombie1_arm();
			zombie1_leg();
			glPopMatrix();
		}

	}
	else if (won) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1, 1, 1, 0);
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texID);
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(rep, 0.0f); glVertex3f(600, 0, 0);
		glTexCoord2f(rep, rep); glVertex3f(600, 600, 0);
		glTexCoord2f(0.0f, rep); glVertex3f(0, 600, 0);
		glEnd();
		glPopMatrix();
		head();
		C(140, 360);
		I();
		C(265, 360);
		glFlush();
		won = true;
		playing = false;
	}
	else if (!won) {
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texID);
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(rep, 0.0f); glVertex3f(600, 0, 0);
		glTexCoord2f(rep, rep); glVertex3f(600, 600, 0);
		glTexCoord2f(0.0f, rep); glVertex3f(0, 600, 0);
		glEnd();
		glPopMatrix();
		glRasterPos2d(300, 300);
		char scorecounter[] = "Game over";
		for (int i = 0; i < strlen(scorecounter); i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scorecounter[i]);
		}
		playing = true;

	}

	glFlush();
}
void Keyboard(unsigned char key, int x, int y) {
	if (key == GLUT_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key == 'a') {
		main_x -= 50;
		if (main_x <= -300) {
			main_x = 0;

		}
	}
	if (key == 'd') {
		main_x += 50;
		if (main_x >= 600) {
			main_x = 0;
		}

	}
	if (key == 'w') {
		main_y += 50;
		if (main_y >= 600) {
			main_y = 0;
		}

	}

	if (key == 's') {
		main_y -= 50;
		if (main_y <= -300) {
			main_y = 0;
		}
	}
	if (key == 'f') {
		bullet_x += 50;
		if (bullet_x >= 600)
			bullet_x = 0;

		if (bullet_x >= 240) {
			if (big_zombie_health > 0 && !little)
				big_zombie_health -= 30;
			if (big_zombie_health == 0) {
				won = true;
				playing = false;
			}

			if (healths > 0)
				healths -= 30;
			if (healths == 0) {
				little = false;
			}

			bullet_x = 0;
		}


	}
	glutPostRedisplay();
}

void main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitWindowSize(800, 700);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("texture");
	glutDisplayFunc(Display);

	if (playing) {
		glutKeyboardFunc(Keyboard);
		glutTimerFunc(0, timer, 0);
	}


	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);

	gluOrtho2D(0, 600, 0, 600);
	loadBMP(&texID, "textures/metal.bmp", true);
	glutMainLoop();
}