#include <iostream>
#include<stdlib.h>
#include<GL/glut.h>

using namespace std;

GLfloat v[4][3]= {{0.0,0.0,1.0},{0,1,-1},{-0.8,-0.4,-1},{0.8,-0.4,-1}};
int n;

void triangle(GLfloat* a, GLfloat* b, GLfloat* c)
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void divide_triangle(GLfloat* a, GLfloat* b, GLfloat* c, int m)
{
	GLfloat v1[3], v2[3], v3[3];
	int i;
	if(m>0)
	{
		for(i=0; i<3; i++) v1[i]=(a[i]+b[i])/2;
		for(i=0; i<3; i++) v2[i]=(a[i]+c[i])/2;
		for(i=0; i<3; i++) v3[i]=(b[i]+c[i])/2;
		divide_triangle(a,v1,v2,m-1);
		divide_triangle(c,v2,v3,m-1);
		divide_triangle(b,v3,v1,m-1);
	}
	else (triangle(a,b,c));
}

void tetrahedron(int m)
{
	glColor3f(1.0,0.0,0.0);
	divide_triangle(v[0],v[1],v[2],m);
	glColor3f(0.0,1.0,0.0);
	divide_triangle(v[3],v[2],v[1],m);
	glColor3f(0.0,0.0,1.0);
	divide_triangle(v[0],v[3],v[1],m);
	glColor3f(1.0,1.0,0.0);
	divide_triangle(v[0],v[2],v[3],m);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	tetrahedron(n);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	{
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	}
	else
	{
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	cout<<"Enter the number of divisions: ";
        cin>>n;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3D Gasket");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
	return 0;
}
