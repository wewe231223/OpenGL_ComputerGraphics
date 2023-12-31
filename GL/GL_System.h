#ifndef _HEADER_GL_SYSTEMS
#define _HEADER_GL_SYSTEMS

#define FULLHDX 1920
#define FULLHDY 1080

typedef int GLSERROR;
#define GLUT_IS_NOT_INITIALIZED 0x01

#include <iostream>


#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>


#include "Struct.h"


#ifndef _GLUINITED_IS_DEFINED
#define _GLUINITED_IS_DEFINED
static bool GLUTINITED = false;
#endif




namespace dp {
	class Display_Properties {
	public:
		int Sw;
		int Sh;
		int Px;
		int Py;


	public:
		Display_Properties();
		Display_Properties(int SizeW, int SizeH, int PosX, int PosY) : Sw(SizeW), Sh(SizeH), Px(PosX), Py(PosY) {}
		Display_Properties(const Display_Properties&);
	};
}


namespace gld {
	class GLDisplay {

	private:
		dp::Display_Properties* Dp = nullptr;
		CallbackFunc CallBack;




		int WindowNo;
	public:
		GLDisplay();
		GLDisplay(const dp::Display_Properties&, const char*);
		void ModifyTitle(const char*);
		void SetThisWindow();




	public:

		void ResisterCallBackFunc(CallbackFunc Cf);


	};
}









namespace gls {

	class GL_System
	{
	private:
		gld::GLDisplay* MainDisplay = nullptr;


		~GL_System();

	public:

		GL_System(const ThreadHandle&, const dp::Display_Properties&, const char*);
		
		gld::GLDisplay* GetMainDisplay();



		void Loop();
	};

}




#endif // !_HEADER_GL_SYSTEMS

