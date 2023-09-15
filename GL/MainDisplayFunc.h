#ifndef _HEDER_MAINDISPLAYFUNC
#define _HEDER_MAINDISPLAYFUNC



#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#include <iostream>
#include <random>


#ifndef _GLCOLOR_IS_DEFINED
#define _GLCOLOR_IS_DEFINED
typedef struct _GLColor {
	float R;
	float G;
	float B;
	float A;
}GLColor;

#endif


namespace MainFunction {


	GLvoid drawScene(GLvoid);


	GLvoid ReShape(int, int );


	GLvoid KeyboardInput(unsigned char , int , int);

	GLvoid KeyboardUPInput(unsigned char, int, int);

	GLvoid MyTimer(int);


}

namespace PrivateFuction {
	namespace Colors {
		enum ColorName;

		void NewColor(GLColor&,GLColor&,ColorName);
		

	}





}

























#endif // _HEDER_MAINDISPLAYFUNC
