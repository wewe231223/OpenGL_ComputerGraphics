#ifndef _HEADER_SCENE2
#define _HEADER_SCENE2

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#include <iostream>
#include <random>


#include "Struct.h"




namespace Scene2_Functions {
	Rect3f Reduction(Rect3f, float);
	bool InsideRect(Rect3f, int, int);
}


namespace Scene2_CallbackFunctions {
	GLvoid drawScene(GLvoid);
	GLvoid ReShape(int, int);
	GLvoid KeyboardInput(unsigned char, int, int);

	GLvoid MouseInput(int, int, int, int);

	GLvoid MouseDragInput(int,int);


	CallbackFunc CreateCallBackFunc(void);
}













#endif // !_HEADER_SCENE2
