#pragma once

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>	

#include <iostream>
#include <random>
#include <vector>
#include <string>

#include "Struct.h"



class Square {
private:
	Rect3f DrawCoordinate{};






public:
	GLColor color;

	float Width;
	float Height;

	float x; // for GL Coordinate 
	float y; // for GL Coordinate

	bool Picking = false;

	Square();

	void draw();

	bool Inside(int, int);

};


namespace Scene3 {
	class Scene {
	public:
		std::vector<Square> Rects;
		GLColor BackGroundColor{0.0f,0.0f,0.0f,1.0f};
		
		
		Scene();




		void Click(int,int,int, int);
		void Drag(int, int);
		void KeyboardDown(unsigned char);
		void KeyboardUP(unsigned char);


		
	};




	GLvoid drawScene(GLvoid);
	GLvoid MouseClickCall(int, int, int, int);
	GLvoid MouseDragCall(int, int);
	GLvoid KeyboardCall(unsigned char, int, int);
	GLvoid KeyboardoffCall(unsigned char, int, int);
	GLvoid MyTimer(int);

	CallbackFunc CreateCallBackFunc(void);
}