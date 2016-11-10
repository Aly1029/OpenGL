

#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, w / h, 0.1, 10);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glutSolidTeapot(1.0);// чайник
	
	//glutSolidCube(1.0);
	//glutSolidDodecahedron();
	//glutSolidOctahedron();	
	glutWireIcosahedron();	
	glClearColor(0.3, 0.2, 0.6, 1.0);
	glColor3f(0.0, 0.0, 1.0);


	glPushMatrix();
	glTranslatef(-0.6, 0, 0);
	glutSolidTeapot(0.15);
	glTranslatef(-0.6, 0, 0);
	glutSolidTeapot(0.17);
	glTranslatef(-0.6, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutWireTeapot(0.19);
	glPopMatrix();

	


	glutSwapBuffers();
}




int main(int argc, char* argv[]) {

		glutInit(&argc, argv);	
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutCreateWindow("Hello, GL");
		glutReshapeFunc(changeViewPort);
		glutDisplayFunc(render);
		

	
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}