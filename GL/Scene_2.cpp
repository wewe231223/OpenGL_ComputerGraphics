#include "Scene_2.h"

#define OriginRatio 1.0f
#define Coefficient 0.99f

namespace Scene2_Variables {

	Rect3f rect1{	-1.0f,	0.0f,	0.0f,	1.0f};
	Rect3f rect2{	-1.0f,	-1.0f,	0.0f,	0.0f};
	Rect3f rect3{	0.0f,	0.0f,	1.0f,	1.0f};
	Rect3f rect4{	0.0f,	-1.0f,	1.0f,	0.0f};
	
	GLColor DisplayColor{};


	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 1.0);

	float ratio = 1.0f;

}


namespace Scene2_Functions {


	Rect3f Reduction(Rect3f r,float ratio) {
		Rect3f result{};



		
		float CenterX = (r.LeftDownX + r.RightUpX) / 2;
		float CenterY = (r.LeftDownY + r.RightUpY) / 2;


		float HalfWidth = (r.LeftDownX + r.RightUpX) / 2;
		float HalfHeight = (r.LeftDownY + r.RightUpY) / 2 ;




		HalfHeight = HalfHeight * ratio;
		HalfWidth = HalfWidth * ratio;

		

		result.LeftDownX = CenterX - HalfWidth ;
		result.LeftDownY = CenterY - HalfHeight;
		
		result.RightUpX = CenterX + HalfWidth;
		result.RightUpY = CenterY + HalfHeight ;


		

		return result;


	}


	bool InsideRect(Rect3f r, int x, int y) {
		if (static_cast<float>(x) > r.LeftDownX || static_cast<float>(x) < r.RightUpX) {
			if (static_cast<float>(x) > r.LeftDownY || static_cast<float>(x) < r.RightUpY) {
				return true;
			}
		}

		return false;
	}


}









GLvoid Scene2_CallbackFunctions::drawScene() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	std::cout << "ReDrawed ================================================" << std::endl;

	
	glColor3f(static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)));


	glRectf(Scene2_Variables::rect1.LeftDownX,
		Scene2_Variables::rect1.LeftDownY,
		Scene2_Variables::rect1.RightUpX,
		Scene2_Variables::rect1.RightUpY);



	glColor3f(static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)));


	glRectf(Scene2_Variables::rect2.LeftDownX,
		Scene2_Variables::rect2.LeftDownY,
		Scene2_Variables::rect2.RightUpX,
		Scene2_Variables::rect2.RightUpY);



	glColor3f(static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)));


	glRectf(Scene2_Variables::rect3.LeftDownX,
		Scene2_Variables::rect3.LeftDownY,
		Scene2_Variables::rect3.RightUpX,
		Scene2_Variables::rect3.RightUpY);


	glColor3f(static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)),
		static_cast<float>(Scene2_Variables::dis(Scene2_Variables::gen)));



	glRectf(Scene2_Variables::rect4.LeftDownX,
		Scene2_Variables::rect4.LeftDownY,
		Scene2_Variables::rect4.RightUpX,
		Scene2_Variables::rect4.RightUpY);



	glutSwapBuffers();
}










GLvoid Scene2_CallbackFunctions::MouseDragInput(int x, int y)
{


	
//	std::cout << "Mouse is Moved : " << x << " , " << y << std::endl;


	
}




GLvoid Scene2_CallbackFunctions::ReShape(int w, int h) {
	glViewport(0, 0, w, h);
}


GLvoid Scene2_CallbackFunctions::KeyboardInput(unsigned char key, int x, int y) {

	Scene2_Variables::ratio = Scene2_Variables::ratio * Coefficient;


	std::cout << Scene2_Variables::ratio << std::endl;
	

	Scene2_Variables::rect1 = Scene2_Functions::Reduction(Scene2_Variables::rect1, Scene2_Variables::ratio);
	Scene2_Variables::rect2 = Scene2_Functions::Reduction(Scene2_Variables::rect2, Scene2_Variables::ratio);
	Scene2_Variables::rect3 = Scene2_Functions::Reduction(Scene2_Variables::rect3, Scene2_Variables::ratio);
	Scene2_Variables::rect4 = Scene2_Functions::Reduction(Scene2_Variables::rect4, Scene2_Variables::ratio);


	glutPostRedisplay();
}







GLvoid Scene2_CallbackFunctions::MouseInput(int Button, int state, int x, int y){

	if (Button == GLUT_LEFT) {
		// Left Button


		



	}
	else {
		// Right button 






	}





}








CallbackFunc Scene2_CallbackFunctions::CreateCallBackFunc(void) {
	CallbackFunc Func{};


	Func.DrawCall = drawScene;
	Func.MouseDragCall = MouseDragInput;
	Func.KeyboardInputCall = Scene2_CallbackFunctions::KeyboardInput;

	return Func;

}