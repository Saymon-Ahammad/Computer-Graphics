#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
using namespace std;

int x=100;
int y=200;

void myInit ()
{

	//glClearColor(0.0, 1.0, 0.0, 0.0);
	//glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
	//glColor3f(0.0, 0.2, 0.0);
	glClearColor(128.0f/255.0f,0, 0, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	// setting window dimension in X- and Y- direction
	glOrtho(0, 500, 0, 500, -10.0, 10.0);


}
void circle(float x,float y)
{
    float x1,y1,x2,y2;
    float radius=100;
    x1=x;
    y1=y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253,253,229);
glVertex2f(x1,y1);
float angle;
for (angle=0;angle<=360;angle+=0.5)
{
    x2 = x1+sin((angle*3.1416)/180)*radius;
    y2 = y1+cos((angle*3.1416)/180)*radius;
    glVertex2f(x2,y2);
}

glEnd();




}

void circleRe(int x,int y,int r,int g,int b)
{
    float x1,y1,x2,y2;
    float radiusx=550;
     float radiusy=120;
    x1=x;
    y1=y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r,g,b);
glVertex2f(x1,y1);
float angle;
for (angle=0;angle<=360;angle+=0.1)
{
    int tx=rand() % 2;
    int ty=rand() % 70;
    x2 = tx+x1+sin((angle*3.1416)/180)*radiusx;
    y2 = ty+y1+cos((angle*3.1416)/180)*radiusy;
    glVertex2f(x2,y2);
}

glEnd();


}
void pahar(int x,int y,int r,int g,int b)
{
    circleRe(x,y,r,g,b);


}
void grave(int x,int y)
{

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f( x,y );
glVertex2f( x+70, y );
glVertex2f( x+70, y+100);
glVertex2f( x, y+100);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(0,0,0);


glVertex2f( x+35, y+100 );
glVertex2f( x, y+100 );
glVertex2f( x+5, y+102 );
glVertex2f( x+10, y+103 );
glVertex2f( x+15, y+104 );
glVertex2f( x+20, y+105 );
glVertex2f( x+25, y+106 );
glVertex2f( x+30, y+107 );
glVertex2f( x+35, y+108 );
glVertex2f( x+40, y+107 );
glVertex2f( x+45, y+106 );
glVertex2f( x+50, y+105 );
glVertex2f( x+55, y+104 );
glVertex2f( x+60, y+103 );
glVertex2f( x+65, y+102 );
glVertex2f( x+70, y+101 );
glVertex2f( x+75, y+100 );

glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);

glVertex2f( x+40, y+100 );
glVertex2f( x+30,y+100 );
glVertex2f( x+30, y+200);
glVertex2f( x+40, y+200);
glEnd();


glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f( x+10, y+160 );
glVertex2f( x+60,y+160 );
glVertex2f( x+60, y+170);
glVertex2f( x+10, y+170);
glEnd();



}
void display ()
{



glClear(GL_COLOR_BUFFER_BIT);

//Triangle

/*
//lines
glBegin(GL_LINES);
glColor3f(0,1,0);
glVertex2f( 250,500 );
glVertex2f( 250, 0 );
glEnd();

//point

glPointSize(100);
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2f( 100,100 );
glEnd();

//Quads
glBegin(GL_QUADS);
glColor3ub(128,0,0);
glVertex2f( 0,0 );
glVertex2f( 200, 0 );
glVertex2f( 200, 200);
glVertex2f( 0, 200);
glEnd();

//polygon
glBegin(GL_POLYGON);
glColor3f(0,1,0);
glVertex2f( 100,100 );
glVertex2f( 100, 0 );
glVertex2f( 50, 0 );
glVertex2f( 10, 50 );
glVertex2f( 50, 200 );

glEnd();

*/

glBegin(GL_QUADS);

glColor3ub(114,116,119);
glVertex2f( 0,0 );
glVertex2f( 500, 0 );

glColor3ub(0,0,0);
glVertex2f( 500, 500);

glVertex2f( 0, 500);
glEnd();


circle( x, y);
pahar(50,-30,61,61,61);
pahar(-100,-70,0,0,0);
grave(120,80);
//circle( x, y);
//ghash(50,-30,61,61,61);
//ghash(-100,-70,0,0,0);
//grave(100,80);

/*
glBegin(GL_TRIANGLE_FAN);
glColor3ub(64,29,50);

glVertex2f( 250, 250 );
glVertex2f( 0,100 );
glVertex2f( 0, 150 );
glVertex2f( 250, 140 );
glVertex2f( 350, 150 );
glVertex2f( 500, 160 );
glVertex2f( 500, 100 );
glEnd();
*/




glFlush();
}
void update(int val) {


	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}
int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 0);

	// Giving name to window
	glutCreateWindow("bahubali 3");
	myInit();

	glutDisplayFunc(display);
	//glutTimerFunc(25, update, 0);
    //update(0);
	glutMainLoop();
}
