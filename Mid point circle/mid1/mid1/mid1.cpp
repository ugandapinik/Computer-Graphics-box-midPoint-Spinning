#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
 
const GLdouble twoPi = 6.283185;
GLsizei winWidth = 640, winHeight = 480;
 
struct scrPt
{
	GLint x,y;
};
 
class screenPt
{
	private:
		GLint x,y;
 
	public:
		screenPt()
		{
			x = y = 0;}
		void setCoords(GLint xCoordValue, GLint yCoordValue)
		{
			x = xCoordValue;
			y = yCoordValue;}
 
		GLint getx() const
		{
			return x;}
 
		GLint gety() const
		{
			return y;}
 
		void incrementx()
		{
			x++;}
 
		void decrementy()
		{	
			y--;}
};
 
void circlePlotPoints(GLint,GLint,screenPt);
void circleMidPoint(GLint, GLint);
void setPixel(GLint,GLint);
void PieChart();
void DrawCircle();
void init();
 
void init()
{
	glClearColor (1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,600,0,500);
}
 
void circleMidPoint(scrPt circCtr, GLint radius)
{
	GLint xc = circCtr.x;
	GLint yc = circCtr.y;
 
	screenPt circPt;
	GLint p = 1 - radius;
 
	circPt.setCoords(0,radius);
	circlePlotPoints(xc,yc,circPt);
	while(circPt.getx() < circPt.gety())
	{
		circPt.incrementx();
		if(p < 0)
			p += 2 * circPt.getx();
		else
		{
			circPt.decrementy();
			p += 2 * (circPt.getx() - circPt.gety()) + 1;
		}
		circlePlotPoints(xc,yc,circPt);
	}
}
 
 
void setPixel(GLint xCoord, GLint yCoord)
{
	glBegin(GL_POINTS);
		glVertex2i (xCoord,yCoord);
	glEnd();
}
 
 
void circlePlotPoints(GLint xc, GLint yc, screenPt circPt)
{
	setPixel(xc + circPt.getx(), yc + circPt.gety());
	setPixel(xc - circPt.getx(), yc + circPt.gety());
	setPixel(xc + circPt.getx(), yc - circPt.gety());
	setPixel(xc - circPt.getx(), yc - circPt.gety());
	setPixel(xc + circPt.getx(), yc + circPt.gety());
	setPixel(xc - circPt.getx(), yc + circPt.gety());
	setPixel(xc + circPt.getx(), yc - circPt.gety());
	setPixel(xc - circPt.getx(), yc - circPt.gety());
}
 
 
void PieChart()
{
	scrPt circCtr;
	GLint radius = winWidth / 4;
 
	circCtr.x = winWidth / 2;
	circCtr.y = winHeight / 2;
	circleMidPoint(circCtr,radius);
}
void DrawCircle()
{   glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	PieChart();
	glFlush();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Circle");
  init();
  glutDisplayFunc(DrawCircle);
  glutMainLoop();
  return(0);
}