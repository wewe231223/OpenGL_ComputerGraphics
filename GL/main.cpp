#pragma warning(disable:4326)
#pragma warning(disable:4101)


#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>


#include "GL_System.h"
#include "MainDisplayFunc.h"





void main(int argc, char** argv) {

	ThreadHandle Main_Th{};
	Main_Th.argcp = &argc;
	Main_Th.argv = argv;




	dp::Display_Properties Maindp(860, 600, 100, 100);
	gls::GL_System* GLS = new gls::GL_System(Main_Th, Maindp, "This is Main Display");



	/*
	* Can Add new Display like this
	* 
	* 
	dp::Display_Properties dp(300, 300, 10, 10);
	gld::GLDisplay* Display2 = new gld::GLDisplay(dp, "This is other Display");
	*/



	GLS->GetMainDisplay()->SetThisWindow();
	glutDisplayFunc(MainFunction::drawScene);
	glutReshapeFunc(MainFunction::ReShape);
	glutKeyboardFunc(MainFunction::KeyboardInput);
	glutKeyboardUpFunc(MainFunction::KeyboardUPInput);







	GLS->Loop();
}


