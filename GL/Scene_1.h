#ifndef _HEDER_Scene1
#define _HEDER_Scene1



#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>


#include <iostream>
#include <random>

#include "Struct.h"








namespace Scene1_Functions {
	namespace Colors {
		enum ColorName;

		void NewColor(GLColor&, GLColor&, ColorName);


	}





}



/*

typedef struct _CALLBACKFUNC {



	GLvoid(*DrawCall)					(GLvoid)							= nullptr;
	GLvoid(*ReShapeCall)				(int, int)							= nullptr;
	GLvoid(*KeyboardInputCall)			(unsigned char, int, int)			= nullptr;
	GLvoid(*KeyboardSpecialInputCall)	(int, int, int)						= nullptr;
	GLvoid(*KeyboardOffCall)			(unsigned char, int, int)			= nullptr;
	GLvoid(*TimerCall)					(int)								= nullptr;
	GLvoid(*IdleCall)					(GLvoid)							= nullptr;




}CallbackFunc;





*/





namespace Scene_1_CallbackFunctions {



	GLvoid drawScene(GLvoid);
	GLvoid ReShape(int,int);
	GLvoid KeyboardInput(unsigned char , int , int);
	GLvoid KeyboardUPInput(unsigned char, int, int);
	GLvoid MyTimer(int);


	CallbackFunc CreateCallBackFunc(void);
}






#endif // _HEDER_Scene1
