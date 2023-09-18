#pragma warning(disable:4326)
#pragma warning(disable:4101)


#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>


#include "hhh.h"




int main(int argc, char** argv) {

	ThreadHandle Main_Th{};
	Main_Th.argcp = &argc;
	Main_Th.argv = argv;




	dp::Display_Properties Maindp(WINDOW_INIT_SIZE_WIDTH, WINDOW_INIT_SIZE_HEIGHT, 100, 100);
	gls::GL_System* GLS = new gls::GL_System(Main_Th, Maindp, "This is Main Display");

	

	/*
	* Can Add new Display like this
	* 
	* 
	dp::Display_Properties dp(300, 300, 10, 10);
	gld::GLDisplay* Display2 = new gld::GLDisplay(dp, "This is other Display");
	*/



	// if use over 1 display, pleaase change main display
	GLS->GetMainDisplay()->SetThisWindow();
	
	
	

	// Solution #1
	//GLS->GetMainDisplay()->ResisterCallBackFunc((Scene_1_CallbackFunctions::CreateCallBackFunc()));

	// Solution #2
	//GLS->GetMainDisplay()->ResisterCallBackFunc(( Scene2_CallbackFunctions::CreateCallBackFunc() ));


	//Solution #3
	GLS->GetMainDisplay()->ResisterCallBackFunc((Scene3::CreateCallBackFunc()));




	
	

	GLS->Loop();

	return 0;
}


