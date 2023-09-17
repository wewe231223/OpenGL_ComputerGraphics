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

	if (!GLUTINITED) exit(EXIT_FAILURE);
	this->Dp = new dp::Display_Properties(otherDp);
	// GLinit이 되어있지 않다면 GLUT_IS_NOT_INITIALIZED throw
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
	if (glutGetWindow() != this->WindowNo) {
		glutSetWindow(this->WindowNo);		
	}
}

void gld::GLDisplay::ResisterCallBackFunc(CallbackFunc Cf)
{
	this->SetThisWindow();
	
	this->CallBack.DrawCall = Cf.DrawCall;
	if (this->CallBack.DrawCall != nullptr) {
		glutDisplayFunc(this->CallBack.DrawCall);
	}


	this->CallBack.IdleCall = Cf.IdleCall;
	if (this->CallBack.IdleCall != nullptr) {
		glutIdleFunc(this->CallBack.IdleCall);
	}



	this->CallBack.KeyboardInputCall = Cf.KeyboardInputCall;
	if (this->CallBack.KeyboardInputCall != nullptr) {
		glutKeyboardFunc(this->CallBack.KeyboardInputCall);
	}



	this->CallBack.KeyboardOffCall = Cf.KeyboardOffCall;
	if (this->CallBack.KeyboardOffCall != nullptr) {
		glutKeyboardUpFunc(this->CallBack.KeyboardOffCall);
	}




	this->CallBack.KeyboardSpecialInputCall = Cf.KeyboardSpecialInputCall;
	if (this->CallBack.KeyboardSpecialInputCall != nullptr) {
		glutSpecialFunc(this->CallBack.KeyboardSpecialInputCall);
	}



	this->CallBack.ReShapeCall = Cf.ReShapeCall;
	if (this->CallBack.ReShapeCall != nullptr) {
		glutReshapeFunc(this->CallBack.ReShapeCall);
	}


	this->CallBack.TimerCall = Cf.TimerCall;
	if (this->CallBack.TimerCall != nullptr) {
		glutTimerFunc(1,this->CallBack.TimerCall,1);
	}



	this->CallBack.MouseCall = Cf.MouseCall;
	if (this->CallBack.MouseCall != nullptr) {
		glutMouseFunc(this->CallBack.MouseCall);
	}


	this->CallBack.MouseDragCall = Cf.MouseDragCall;
	if (this->CallBack.MouseDragCall != nullptr) {
		glutMotionFunc(this->CallBack.MouseDragCall);
	}
	
	


	


}






gls::GL_System::GL_System(const ThreadHandle& Th, const dp::Display_Properties& MainDp, const char* MainDisplayTitle) {
	glutInit(Th.argcp, Th.argv);
	GLUTINITED = true;
	this->MainDisplay = new gld::GLDisplay(MainDp, MainDisplayTitle);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {

		std::cerr << "Unable to Init GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		std::cout << "GLEW INITIALIZED " << std::endl;
	}
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