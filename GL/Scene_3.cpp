#include "Scene_3.h"


/*

1200 x 800

3 : 2

0.1 x 0.8
->0.08


0.1 * 


0.1 * 1.2
->0.12





*/
#define SQUARE_WIDTH 0.2f 
#define SQUARE_HEIGHT 0.2f



std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> ColorGenerater(0.f,1.0f);
std::uniform_real_distribution<float> GLPositionGenerater(-1.0f, 1.0f);




Square::Square() {
	this->color.R = ColorGenerater(gen);
	this->color.G = ColorGenerater(gen);
	this->color.B = ColorGenerater(gen);


	this->Width = SQUARE_WIDTH;
	this->Height = SQUARE_HEIGHT;

	this->x = GLPositionGenerater(gen);
	this->y = GLPositionGenerater(gen);

	float ScreenW = static_cast<float>(WINDOW_INIT_SIZE_WIDTH);
	float ScreenH = static_cast<float>(WINDOW_INIT_SIZE_HEIGHT);


	this->Width = SQUARE_WIDTH * (ScreenH * 0.001f);
	this->Height = SQUARE_HEIGHT * (ScreenW * 0.001f);




	this->DrawCoordinate.LeftDownX = this->x - (this->Width / 2);
	this->DrawCoordinate.LeftDownY = this->y - (this->Height / 2);

	this->DrawCoordinate.RightUpX = this->x + (this->Width / 2);
	this->DrawCoordinate.RightUpY = this->y + (this->Height / 2);


	


}


void Square::draw() {




	float ScreenW = static_cast<float>(glutGet(GLUT_WINDOW_WIDTH));
	float ScreenH = static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT));


	this->Width = SQUARE_WIDTH * (ScreenH * 0.001f);
	this->Height = SQUARE_HEIGHT * (ScreenW * 0.001f);




	this->DrawCoordinate.LeftDownX = this->x - (this->Width / 2);
	this->DrawCoordinate.LeftDownY = this->y - (this->Height / 2);

	this->DrawCoordinate.RightUpX = this->x + (this->Width / 2);
	this->DrawCoordinate.RightUpY = this->y + (this->Height / 2);

	glColor3f(this->color.R, this->color.G, this->color.B);
	glRectf(this->DrawCoordinate.LeftDownX, this->DrawCoordinate.LeftDownY,
		this->DrawCoordinate.RightUpX, this->DrawCoordinate.RightUpY);





	
	if (this->Picking) {
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);

		glVertex2f(this->DrawCoordinate.LeftDownX, this->DrawCoordinate.LeftDownY);
		glVertex2f(this->DrawCoordinate.LeftDownX + this->Width, this->DrawCoordinate.LeftDownY);
		glVertex2f(this->DrawCoordinate.LeftDownX + this->Width, this->DrawCoordinate.LeftDownY + this->Height);
		glVertex2f(this->DrawCoordinate.LeftDownX, this->DrawCoordinate.LeftDownY + this->Height);
		glEnd();
	}



}




Scene3::Scene MainScene;





bool Square::Inside(int pixelX, int pixelY) {

	int Width = glutGet(GLUT_WINDOW_WIDTH);
	int Height = glutGet(GLUT_WINDOW_HEIGHT);

	float glX, glY;

	glX = static_cast<float>(pixelX) / static_cast<float>(Width) * 2.0f - 1.0f;
	glY = 1.0f - static_cast<float>(pixelY) / static_cast<float>(Height) * 2.0f;

	if (this->DrawCoordinate.LeftDownX < glX && this->DrawCoordinate.RightUpX > glX) {
		if (this->DrawCoordinate.LeftDownY < glY && this->DrawCoordinate.RightUpY > glY) {
			return true;
		}
	}
	return false;
}




Scene3::Scene::Scene() {
	Square NewSquare;
	NewSquare.x = 0.0f;
	NewSquare.y = 0.0f;
	this->Rects.push_back(NewSquare);
}



// Just on Click 
void Scene3::Scene::Click(int Button,int State,int x, int y) {

	if (State == GLUT_DOWN) {

		for (auto iter = this->Rects.rbegin(); iter != this->Rects.rend(); ++iter) {
			if ((*iter).Inside(x, y)) {
				(*iter).Picking = true;
				break;
			}
		}




	}
	else if (State == GLUT_UP) {

		for (auto& i : this->Rects) {

			if (i.Picking) {
				
				i.Picking = false;
			}
		}

	}
	
	


}


void Scene3::Scene::Drag(int pixelX, int pixelY) {

	int Width = glutGet(GLUT_WINDOW_WIDTH);
	int Height = glutGet(GLUT_WINDOW_HEIGHT);

	float glX, glY;

	glX = static_cast<float>(pixelX) / static_cast<float>(Width) * 2.0f - 1.0f;
	glY = 1.0f - static_cast<float>(pixelY) / static_cast<float>(Height) * 2.0f;

	

	for (auto iter = this->Rects.rbegin(); iter != this->Rects.rend(); ++iter) {
		if ((*iter).Picking) {
			(*iter).x = glX;
			(*iter).y = glY;
			break;
		}
	}


	
}

void Scene3::Scene::KeyboardDown(unsigned char key){
	if (key == 'c') {
		if (static_cast<int>(this->Rects.size()) != 5) {
			Square NewSqare;
			this->Rects.push_back(NewSqare);
			std::cout << "New Square!" << std::endl;

		}
	}

	if (key == 'r') {

		for (auto& i : this->Rects) {
			i.color.R = ColorGenerater(gen);
			i.color.G = ColorGenerater(gen);
			i.color.B = ColorGenerater(gen);
		}


	}
	
	if (key == 't') {


		this->BackGroundColor.R = ColorGenerater(gen);
		this->BackGroundColor.G = ColorGenerater(gen);
		this->BackGroundColor.B = ColorGenerater(gen);



	}


	glutPostRedisplay();
}


void Scene3::Scene::KeyboardUP(unsigned char key) {

}




int FPS = 0;
std::string FPSstring;
const std::string inWord("FPS : ");



GLvoid Scene3::drawScene(GLvoid) {
	FPS += 1;
	glClearColor(
		MainScene.BackGroundColor.R, 
		MainScene.BackGroundColor.G, 
		MainScene.BackGroundColor.B, 
		1.0f);



	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& s : MainScene.Rects) {
		s.draw();
	}
	
	glutSwapBuffers();
}


GLvoid Scene3::KeyboardCall(unsigned char key, int x, int y) {
	MainScene.KeyboardDown(key);
}
GLvoid Scene3::KeyboardoffCall(unsigned char key, int x, int y) {
	MainScene.KeyboardUP(key);
}

GLvoid Scene3::MouseClickCall(int Button, int State, int x, int y) {
	MainScene.Click(Button,State,x, y);

	glutPostRedisplay();
}

GLvoid Scene3::MouseDragCall(int x, int y){
	MainScene.Drag(x, y);
	glutPostRedisplay();

	return GLvoid();
}





GLvoid Scene3::MyTimer(int value) {


	FPSstring.clear();
	FPSstring += inWord;
	FPSstring += std::to_string(FPS);
	FPS = 0;
	
	std::cout << FPSstring << std::endl;
	std::cout << "This is 1s Function !" << std::endl;


	glutSetWindowTitle(FPSstring.c_str());




	return glutTimerFunc(1000, Scene3::MyTimer, value);
	
}






CallbackFunc Scene3::CreateCallBackFunc(void) {
	CallbackFunc Func{};


	Func.DrawCall = drawScene;
	Func.MouseCall = MouseClickCall;
	Func.KeyboardInputCall = KeyboardCall;
	Func.KeyboardOffCall = KeyboardoffCall;
	Func.MouseDragCall = MouseDragCall;
	Func.TimerCall = MyTimer;
	return Func;
}
