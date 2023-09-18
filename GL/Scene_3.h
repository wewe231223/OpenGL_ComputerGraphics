#pragma once

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>	

#include <random>
#include <vector>

#include "Struct.h"


class Rect{
public:

	Rect3f r{};
	GLColor color{};
	float x;
	float y;
	bool Picking = false;

	
	Rect(const Rect& other) {
		this->color.R = other.color.R;
		this->color.G = other.color.G;
		this->color.B = other.color.B;
		this->color.A = other.color.A;

		this->r.LeftDownX = other.r.LeftDownX;
		this->r.LeftDownY = other.r.LeftDownY;
		this->r.RightUpX = other.r.RightUpX;
		this->r.RightUpY = other.r.RightUpY;

		this->x = other.x;
		this->y = other.y;
	}

	Rect(float r, float g, float b,float W,float H, float x, float y) {
		this->color.R = r;
		this->color.G = g;
		this->color.B = b;
		this->color.A = 1.0f;

		float Halfw = W / 2;
		float Halfh = H / 2;


		this->r.LeftDownX = x - Halfw;
		this->r.LeftDownY = y - Halfh;

		this->r.RightUpX = x + Halfw;
		this->r.RightUpY = y + Halfh;



		this->x = x;
		this->y = y;

	}


};




class Scene_3{
public:
	std::vector<Rect> RectArr;


public:
	Scene_3();




};


namespace Scene3_CallbackFunctions {

	GLvoid drawScene(GLvoid);
	CallbackFunc CreateCallBackFunc();



}




