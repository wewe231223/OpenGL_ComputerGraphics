#include "Scene_3.h"



std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis(0.f,1.f);


Scene_3::Scene_3() {
	Rect r(dis(gen), dis(gen), dis(gen), 0.5f, 0.5f, -0.4f, -0.4f);
	this->RectArr.push_back(r);
	
	
}

Scene_3 Scene;



GLvoid Scene3_CallbackFunctions::drawScene(GLvoid) {
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);


	// draw code is here
	std::vector<Rect>::iterator iter;

	for (iter = Scene.RectArr.begin(); iter != Scene.RectArr.end(); ++iter) {

		glColor3f((*iter).color.R, (*iter).color.G, (*iter).color.B);
		glRectf((*iter).r.LeftDownX, (*iter).r.LeftDownY, (*iter).r.RightUpX, (*iter).r.RightUpY);

	}
	glutSwapBuffers();

}



CallbackFunc Scene3_CallbackFunctions::CreateCallBackFunc() {
	CallbackFunc result;

	result.DrawCall = drawScene;

	return result;
}