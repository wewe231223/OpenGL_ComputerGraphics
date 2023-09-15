#include "GL_System.h"



dp::Display_Properties::Display_Properties() {
	this->Px = 0;
	this->Py = 0;
	this->Sh = 0;
	this->Sw = 0;

}


dp::Display_Properties::Display_Properties(const Display_Properties& other) {
	memcpy(this, &other, sizeof(Display_Properties));
}








gld::GLDisplay::GLDisplay() {

	this->WindowNo = -1;

}

gld::GLDisplay::GLDisplay(const dp::Display_Properties& otherDp, const char* Title) {

	if (!GLUTINITED) {
		std::cout << "Display Initialization Failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	
	this->Dp = new dp::Display_Properties(otherDp);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(this->Dp->Px, this->Dp->Py);
	glutInitWindowSize(this->Dp->Sw, this->Dp->Sh);

	this->WindowNo = glutCreateWindow(Title);
	glutSetWindow(this->WindowNo);

}


void gld::GLDisplay::ModifyTitle(const char* newTitle) {
	glutSetWindow(this->WindowNo);
	glutSetWindowTitle(newTitle);
}




void gld::GLDisplay::SetThisWindow() {
	glutSetWindow(this->WindowNo);
}








gls::GL_System::GL_System(const ThreadHandle& Th,const gld::GLDisplay* Maindisplay) {
	glutInit(Th.argcp, Th.argv);
	GLUTINITED = true;
	
	this->MainDisplay = MainDisplay;

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {

		std::cerr << "Unable to Init GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		std::cout << "GLEW INITIALIZED " << std::endl;
	}
}


void gls::GL_System::ApplyMainDisplay(gld::GLDisplay* Maindisplay) {
	this->MainDisplay = Maindisplay;
}




gls::GL_System::~GL_System() {
	glutLeaveMainLoop();
}


gld::GLDisplay * gls::GL_System::GetMainDisplay() {
	return this->MainDisplay;
}



void gls::GL_System::Loop() {
	glutMainLoop();
}