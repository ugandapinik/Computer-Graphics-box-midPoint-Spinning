#include <iostream>
#include <GL/glut.h>
using namespace std;


static GLfloat spin = 0.0;
static GLfloat spin_speed = 4.0;
float spin_x = 0;
float spin_y = 0;
float spin_z = 1;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -40.0;
// assuming work-window width=50unit, height=25unit;
void init()
{
glClearColor(0,0,0,0);
glShadeModel(GL_SMOOTH); // Enable Smooth Shading
glClearDepth(1.0f); // Depth Buffer Setup
glEnable(GL_DEPTH_TEST); // Enables Depth Testing
}
//------- custom functions starts -------
void setSpin(float x, float y, float z)
{
spin_x = x;
spin_y = y;
spin_z = z;
}
void reset()
{
spin_x = 0;
spin_y = 1;
spin_z = 0;
translate_x = 0.0;
translate_y = 0.0;
translate_z = -30.0;
}
//------- custom functions ends -------
void reshape(int w,int h)
{
glViewport(0,0, (GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void Tri(){
glBegin(GL_TRIANGLES);
glColor3f(0.5,0.6,0.2);
//      glVertex3f(-1.0f,-0.25f,0.0f);//triangle one first vertex
//      glVertex3f(-0.5f,-0.25f,0.0f);//triangle one second vertex
//      glVertex3f(-0.75f,0.25f,0.0f);//triangle one third vertex
glVertex2i(0, 0);
glVertex2i(15, -6);
glVertex2i(15, 6);
glFlush ();

glColor3f(0.5,0.6,0.2);
glVertex2i(0, 0);
glVertex2i(-15,6);
glVertex2i(-15,-6);
glFlush();

glColor3f(0.5,0.6,0.2);
glVertex2i(0,0);
glVertex2i(-6,15);
glVertex2i(6,15);
glFlush();

glColor3f(0.5,0.6,0.2);
glVertex2i(0,0);
glVertex2i(6,-15);
glVertex2i(-6,-15);
glEnd();

}
void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(translate_x, translate_y, translate_z);
glRotatef(spin,spin_x,spin_y,spin_z);
//******************************************//
//------- custom code starts -------
Tri();
glFlush();

//------- custom code ends -------
//******************************************//
glutSwapBuffers();
}
void spinDisplay(void)
{
spin=spin+spin_speed;
if(spin>360.0)
{
spin=spin-360.0;
}
glutPostRedisplay();
}
void spinDisplayReverse(void)
{
spin=spin-spin_speed;
if(spin<360.0)
{
spin=spin+360.0;
}
glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
switch(button)
{
case GLUT_LEFT_BUTTON:
if(state==GLUT_DOWN)
glutIdleFunc(spinDisplay);
break;
case GLUT_MIDDLE_BUTTON:
if(state==GLUT_DOWN)
{
glutIdleFunc(NULL);
}
break;
case GLUT_RIGHT_BUTTON:
if(state==GLUT_DOWN)
glutIdleFunc(spinDisplayReverse);
break;
default:
break;
}
}
void keyboard(unsigned char key, int x, int y)
{
//-------- spin --------
if(key=='x')
{
setSpin(1.0,0.0,0.0);
glutPostRedisplay();
}
else if(key=='y')
{
setSpin(0.0,1.0,0.0);
glutPostRedisplay();
}
else if(key=='z')
{
setSpin(0.0,0.0,1.0);
glutPostRedisplay();
}
else if(key=='a')
{
setSpin(1.0,1.0,1.0);
glutPostRedisplay();
}
//-------- spin --------
//-------- zoom --------
else if(key=='i')
{
translate_z++;
glutPostRedisplay();
}
else if(key=='o')
{
translate_z--;
glutPostRedisplay();
}
//-------- zoom --------
//-------- reset -------
else if(key=='r')
{
reset();
glutPostRedisplay();
}
//-------- reset -------
}

void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1024, 768);
glutInitWindowPosition (0, 0);
glutCreateWindow ("Rotation");
init ();
glutDisplayFunc(myDisplay);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);




glutMainLoop();
}









