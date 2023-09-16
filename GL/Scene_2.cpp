#include "Scene_2.h"



namespace Scene2_Variables {

	Rect3f rect1{	-1.0f,	0.0f,	0.0f,	1.0f};
	Rect3f rect2{	-1.0f,	-1.0f,	0.0f,	0.0f};
	Rect3f rect3{	0.0f,	0.0f,	1.0f,	1.0f};
	Rect3f rect4{	0.0f,	-1.0f,	1.0f,	0.0f};

}








GLvoid Scene2_CallbackFuctions::drawScene() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(Scene2_Variables::rect1.LeftDownX,
		Scene2_Variables::rect1.LeftDownY,
		Scene2_Variables::rect1.RightUpX,
		Scene2_Variables::rect1.RightUpY);



	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(Scene2_Variables::rect2.LeftDownX,
		Scene2_Variables::rect2.LeftDownY,
		Scene2_Variables::rect2.RightUpX,
		Scene2_Variables::rect2.RightUpY);



	glColor3f(0.0f, 1.0f, 1.0f);
	glRectf(Scene2_Variables::rect3.LeftDownX,
		Scene2_Variables::rect3.LeftDownY,
		Scene2_Variables::rect3.RightUpX,
		Scene2_Variables::rect3.RightUpY);



	glColor3f(0.5f, 0.5f, 0.5f);
	glRectf(Scene2_Variables::rect4.LeftDownX,
		Scene2_Variables::rect4.LeftDownY,
		Scene2_Variables::rect4.RightUpX,
		Scene2_Variables::rect4.RightUpY);



	glutSwapBuffers();
}










GLvoid Scene2_CallbackFuctions::MouseDragInput(int x, int y)
{


	
	std::cout << "Mouse is Moved : " << x << " , " << y << std::endl;


	
}




CallbackFunc Scene2_CallbackFuctions::CreateCallBackFunc(void) {
	CallbackFunc Func{};


	Func.DrawCall = drawScene;
	Func.MouseDragCall = MouseDragInput;


	return Func;

}