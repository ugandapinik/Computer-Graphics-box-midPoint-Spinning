#include<stdio.h>  
#include<GL/glut.h>  
#include<math.h>  


int xi,yi,xf,yf;  //i= initail; f=final


void putpixel(int x,int y)  //functionality of putpixel
{  
glBegin(GL_POINTS);  
glVertex2i(x,y);  
glEnd();  
glFlush();  
}  

/*

int round(double n)  
{  
return (n>=0)?(int)(n+0.5):(int)(n-0.5);  
}  

*/


void Bresenham_circle(int r)  
{  
int x=0,y=r,d=3-2*r;  
while(x<=y){  
//Here Transform each x,y coordinates by 250 pixels   
putpixel(250+x, 250+y);  
putpixel(250+y, 250+x);  
putpixel(250-x, 250+y);  
putpixel(250-x, 250-y);  
putpixel(250-y, 250+x);  
putpixel(250-y, 250-x);  
putpixel(250+y, 250-x);  
putpixel(250+x, 250-y);  


if(d<0)  
d=d+(4*x)+6;  

else{  
d=d+(4*(x-y))+10;  
y--;  
}  


x++;  
}  
}  



void display()  
{  
glClearColor(0.4,0.7,0.2,1.0);  
glColor3f(0.5,0.3,0.0);  
glClear(GL_COLOR_BUFFER_BIT);  
glutSwapBuffers();  
glFlush();  

xi=0;  
yi=100;  
Bresenham_circle(yi);

}  

/*
void shohan(int y,int x)
{
xi=0;  
yi=5;  
Bresenham_circle(yi);
}

*/

/*
void mouse(int btn,int state,int y,int x)  
{  
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
{  
xi=0;  
yi=y;  
Bresenham_circle(yi);  
}  
}  

*/




void myinit()  
{  
glViewport(0,0,400,400);  
glMatrixMode(GL_PROJECTION);  
glLoadIdentity();  
gluOrtho2D(0.0,400.0,0.0,400.0);  
glMatrixMode(GL_MODELVIEW);  
}  



int main(int argc,char** argv)  
{  
glutInit(&argc,argv);  
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
glutInitWindowSize(400,400);  
glutCreateWindow("Midpoint-Circle");  
glutDisplayFunc(display);  
myinit();  
glutMainLoop();  
return 0;  
}