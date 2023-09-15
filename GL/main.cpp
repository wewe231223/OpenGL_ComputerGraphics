#pragma warning(disable:4326)
#pragma warning(disable:4101)


#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>


#include "GL_System.h"


GLvoid drawScene(GLvoid);
GLvoid ReShape(int w, int h);
GLvoid KeyboardIO(unsigned char key, int x, int y);


void main(int argc, char** argv) {

	ThreadHandle Main_Th{};
	Main_Th.argcp = &argc;
	Main_Th.argv = argv;




	dp::Display_Properties Maindp(FULLHDX, FULLHDY, 100, 100);
	gls::GL_System* GLS = new gls::GL_System(Main_Th, Maindp, "This is Main Display");



	/*
	* Can Add new Display like this
	* 
	* 
	dp::Display_Properties dp(300, 300, 10, 10);
	gld::GLDisplay* Display2 = new gld::GLDisplay(dp, "This is other Display");
	*/



	GLS->GetMainDisplay()->SetThisWindow();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(ReShape);
	glutKeyboardFunc(KeyboardIO);









	GLS->Loop();
}


GLvoid drawScene() {



	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();

}


GLvoid ReShape(int w, int h) {


	glViewport(0, 0, w, h);

}


GLvoid KeyboardIO(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'f':
		std::cout << "f is pushed" << std::endl;
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}