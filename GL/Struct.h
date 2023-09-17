#ifndef _GLSYS_STRUCT_NOT_DEFINED
#define _GLSYS_STRUCT_NOT_DEFINED


typedef void GLvoid;


typedef struct _ThreadHandler {
	int* argcp;
	char** argv;
}ThreadHandle;




typedef struct _CALLBACKFUNC {
	GLvoid(*DrawCall)					(GLvoid)					= nullptr;
	GLvoid(*ReShapeCall)				(int, int)					= nullptr;
	GLvoid(*KeyboardInputCall)			(unsigned char, int, int)	= nullptr;
	GLvoid(*KeyboardSpecialInputCall)	(int, int, int)				= nullptr;
	GLvoid(*KeyboardOffCall)			(unsigned char, int, int)	= nullptr;
	GLvoid(*TimerCall)					(int)						= nullptr;
	GLvoid(*IdleCall)					(GLvoid)					= nullptr;
	GLvoid(*MouseCall)					(int, int, int, int)		= nullptr;
	GLvoid(*MouseDragCall)				(int, int)					= nullptr;




}CallbackFunc;




typedef struct _Rect3f {
	float LeftDownX;
	float LeftDownY;
	float RightUpX;
	float RightUpY;
}Rect3f;







typedef struct _GLColor {
	float R;
	float G;
	float B;
	float A;
}GLColor;











#endif
