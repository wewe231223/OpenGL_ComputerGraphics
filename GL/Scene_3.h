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

	Rect3f Mem{};

	float vectorX{};
	float vectorY{};



public:
	GLColor color;

	float Width;
	float Height;

	float x; // for GL Coordinate 
	float y; // for GL Coordinate

	bool Picking = false;

	Square();
	Square(int, int);

	void draw();


	void VectorMove();


	void Mempos();
	void Rtnpos();


	bool Inside(int, int);

};


namespace Scene3 {
	class Scene {
	private:
		bool Generate_Rand_Position = true;
		
	public:
		std::vector<Square> Rects;
		GLColor BackGroundColor{0.0f,0.0f,0.0f,1.0f};
		
		bool Rects_Move_Following_vector = false;

		
		Scene();




		void Click(int,int,int, int);
		void Drag(int, int);
		void KeyboardDown(unsigned char,int,int);
		void KeyboardUP(unsigned char);
		void SpecialKeyDown(int,int,int);
		void SpecialKeyUp(int, int, int);

		
	};




	GLvoid drawScene(GLvoid);
	GLvoid MouseClickCall(int, int, int, int);
	GLvoid MouseDragCall(int, int);
	GLvoid KeyboardCall(unsigned char, int, int);
	GLvoid KeyboardoffCall(unsigned char, int, int);
	GLvoid SpecialKeyboardCall(int, int, int);
	GLvoid SpecialKeyboardoffCall(int, int, int);
	
	GLvoid MyTimer(int);


	CallbackFunc CreateCallBackFunc(void);
}