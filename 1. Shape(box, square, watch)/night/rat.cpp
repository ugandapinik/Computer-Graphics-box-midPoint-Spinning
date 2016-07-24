#include <stdio.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glPointSize(4.0);

//Box for rectenagle 

glBegin(GL_LINE_LOOP);
glVertex2i(10, 50);
glVertex2i(10, 100);
glVertex2i(90, 100);
glVertex2i(90, 50);
glEnd();

//Line joining left higher to right lower
glBegin(GL_LINES);
glVertex2i(10, 100);
glVertex2i(90, 50);
glEnd();

//Line joining left lower to right higher
glBegin(GL_LINES);
glVertex2i(90, 100);
glVertex2i(10, 50);
glEnd();

//Box1 for qube

glBegin(GL_LINE_LOOP);
glVertex2i(110, 50);
glVertex2i(110, 100);
glVertex2i(190, 100);
glVertex2i(190, 50);
glEnd();

//Box2 for qube

glBegin(GL_LINE_LOOP);
glVertex2i(130, 70);
glVertex2i(130, 120);
glVertex2i(210, 120);
glVertex2i(210, 70);
glEnd();

//Line joining left higher to higher
glBegin(GL_LINES);
glVertex2i(110, 100);
glVertex2i(130, 120);
glEnd();

//Line joining right higher to higher
glBegin(GL_LINES);
glVertex2i(190, 100);
glVertex2i(210, 120);
glEnd();

//Line joining left lower to lower
glBegin(GL_LINES);
glVertex2i(110, 50);
glVertex2i(130, 70);
glEnd();

//Line joining right lower to lower
glBegin(GL_LINES);
glVertex2i(190, 50);
glVertex2i(210, 70);
glEnd();

//Polygon
glBegin(GL_LINE_LOOP);
glVertex2i(230, 85);
glVertex2i(260, 120);
glVertex2i(360, 120);
glVertex2i(390, 85);
glVertex2i(360, 50);
glVertex2i(260, 50);
glEnd();

//Triangle at Polygon 
glBegin(GL_LINE_LOOP);
glVertex2i(270, 85);
glVertex2i(300, 100);
glVertex2i(300, 70);
glEnd();

//Square at Polygon 
glBegin(GL_LINE_LOOP);
glVertex2i(320, 100);
glVertex2i(350, 100);
glVertex2i(350, 70);
glVertex2i(320, 70);
glEnd();

//Polygon for watch
glBegin(GL_LINE_LOOP);
glVertex2i(430, 170);
glVertex2i(510, 170);
glVertex2i(530, 150);
glVertex2i(530, 70);
glVertex2i(510, 50);
glVertex2i(430, 50);
glVertex2i(410, 70);
glVertex2i(410, 150);
glEnd();

//Centre for watch
glBegin(GL_LINE_LOOP);
glVertex2i(465, 115);
glVertex2i(475, 115);
glVertex2i(475, 105);
glVertex2i(465, 105);
glEnd();

//Stick1 for watch
glBegin(GL_LINE_STRIP);
glVertex2i(465, 115);
glVertex2i(440, 80);
glVertex2i(445, 76);
glVertex2i(465, 105);
glEnd();

//Stick1 line for watch
glBegin(GL_LINES);
glVertex2i(443, 78);
glVertex2i(439, 74);
glEnd();

//Stick2 line for watch
glBegin(GL_LINES);
glVertex2i(465, 115);
glVertex2i(465, 150);
glVertex2i(475, 115);
glVertex2i(475, 150);
glEnd();

//Stick2 head for watch
glBegin(GL_LINE_LOOP);
glVertex2i(465, 150);
glVertex2i(475, 150);
glVertex2i(470, 160);
glEnd();

//Stick3 for watch
glBegin(GL_LINE_STRIP);
glVertex2i(475, 115);
glVertex2i(510, 115);
glVertex2i(510, 120);
glVertex2i(520, 110);
glVertex2i(510, 100);
glVertex2i(510, 105);
glVertex2i(475, 105);

glEnd();

glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (150, 150);
glutCreateWindow ("This window will show some graphics");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}