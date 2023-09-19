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
std::uniform_real_distribution<float> VectorGenerater(-0.005f, 0.005f);



Square::Square() {
	this->color.R = ColorGenerater(gen);
	this->color.G = ColorGenerater(gen);
	this->color.B = ColorGenerater(gen);


	this->vectorX = VectorGenerater(gen);
	this->vectorY = VectorGenerater(gen);



	std::cout << this->vectorX << " , " << this->vectorY << std::endl;



	this->Width = SQUARE_WIDTH;
	this->Height = SQUARE_HEIGHT;

	this->x = GLPositionGenerater(gen);
	this->y = GLPositionGenerater(gen);

	float ScreenW = static_cast<float>(WINDOW_INIT_SIZE_WIDTH);
	float ScreenH = static_cast<float>(WINDOW_INIT_SIZE_HEIGHT);


	this->Width = SQUARE_WIDTH * (ScreenH * 0.001f);
	this->Height = SQUARE_HEIGHT * (ScreenW * 0.001f);


	this->LeftPivotX = this->x - this->Width / 2;
	this->RightPivotX = this->x + this->Width / 2;

	this->DownPivotY = this->y - this->Height / 2;
	this->UpPivotY = this->y + this->Height / 2;
	




	this->DrawCoordinate.LeftDownX = this->x - (this->Width / 2);
	this->DrawCoordinate.LeftDownY = this->y - (this->Height / 2);

	this->DrawCoordinate.RightUpX = this->x + (this->Width / 2);
	this->DrawCoordinate.RightUpY = this->y + (this->Height / 2);


	


}


Square::Square(int pixelX, int pixelY) {
	this->color.R = ColorGenerater(gen);
	this->color.G = ColorGenerater(gen);
	this->color.B = ColorGenerater(gen);


	this->vectorX = VectorGenerater(gen);
	this->vectorY = VectorGenerater(gen);


	

	this->Width = SQUARE_WIDTH;
	this->Height = SQUARE_HEIGHT;






	this->x = static_cast<float>(pixelX) / glutGet(GLUT_WINDOW_WIDTH) * 2.0f - 1.0f;
	this->y = 1.0f - static_cast<float>(pixelY) / glutGet(GLUT_WINDOW_HEIGHT) * 2.0f;

	std::cout << x << " , " << y << std::endl;






	float ScreenW = static_cast<float>(WINDOW_INIT_SIZE_WIDTH);
	float ScreenH = static_cast<float>(WINDOW_INIT_SIZE_HEIGHT);


	this->Width = SQUARE_WIDTH * (ScreenH * 0.001f);
	this->Height = SQUARE_HEIGHT * (ScreenW * 0.001f);


	this->LeftPivotX = this->x - this->Width / 2;
	this->RightPivotX = this->x + this->Width / 2;

	this->DownPivotY = this->y - this->Height / 2;
	this->UpPivotY = this->y + this->Height / 2;





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

void Square::VectorMove(){



	






	this->x = this->x + this->vectorX;
	this->y = this->y + this->vectorY;

	this->LeftPivotX = this->x - this->Width / 2;
	this->RightPivotX = this->x + this->Width / 2;

	this->DownPivotY = this->y - this->Height / 2;
	this->UpPivotY = this->y + this->Height / 2;


	std::cout << LeftPivotX << std::endl;

	this->VectorReflect();



}


void Square::VectorReflect() {

	if (this->LeftPivotX <= -1.0f || this->RightPivotX >= 1.0f) {
		this->vectorX = -1.0f * this->vectorX;
	}


	if (this->DownPivotY <= -1.0f || this->UpPivotY >= 1.0f) {
		this->vectorY = -1.0f * this->vectorY;
	}

	



}



void Square::Mempos() {
	this->memX = x;
	this->memY = y;

}



void Square::Rtnpos() {
	this->x = this->memX;
	this->y = this->memY;


}



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


Scene3::Scene MainScene;




















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

		if (Button == GLUT_LEFT_BUTTON) {
			if (!this->Generate_Rand_Position && !this->Rects_Move_Following_vector) {
				if (static_cast<int>(this->Rects.size()) != 5) {
					Square NewSqare(x,y);
					this->Rects.push_back(NewSqare);
					std::cout << "New Square!" << std::endl;

				}
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

void Scene3::Scene::KeyboardDown(unsigned char key,int x,int y){


	if (this->Generate_Rand_Position) {

		if (key == 'c') {

			if (!this->Rects_Move_Following_vector) {

				if (static_cast<int>(this->Rects.size()) != 5) {
					Square NewSqare;
					this->Rects.push_back(NewSqare);
					std::cout << "New Square!" << std::endl;

				}
			}
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

	
	


	if (key == 'p') {
		std::vector<Square>().swap(this->Rects);
	}

	glutPostRedisplay();
}


void Scene3::Scene::KeyboardUP(unsigned char key) {

}

void Scene3::Scene::SpecialKeyDown(int key, int x, int y){
	if (key == GLUT_KEY_SHIFT_L) {
		this->Generate_Rand_Position = false;
	}

	if (key == GLUT_KEY_CTRL_L) {

		if (this->Rects_Move_Following_vector) {
			this->Rects_Move_Following_vector = false;

			for (auto& i : this->Rects) {
				i.Rtnpos();
			}

		}
		else {
			this->Rects_Move_Following_vector = true;

			for (auto& i : this->Rects) {
				i.Mempos();
			}

		}
	}



	glutPostRedisplay();

}

void Scene3::Scene::SpecialKeyUp(int key, int x, int y ){
	if (key == GLUT_KEY_SHIFT_L) {
		this->Generate_Rand_Position = true;
	}




	glutPostRedisplay();


}




int FPS = 0;




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
	MainScene.KeyboardDown(key,x,y);
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




GLvoid Scene3::SpecialKeyboardCall(int k, int x, int y) {
	MainScene.SpecialKeyDown(k, x, y);
	glutPostRedisplay();
}

GLvoid Scene3::SpecialKeyboardoffCall(int k, int x, int y) {
	MainScene.SpecialKeyUp(k, x, y);
	glutPostRedisplay();
}



std::string FPSstring;
std::string Timestring;
std::string TotalString;
const std::string inWord("FPS : ");
const std::string Pt("                        Program is running for... ");
int t = 0;
int playtime = 0;




GLvoid Scene3::MyTimer(int value) {


	t += 1;

	
	if (MainScene.Rects_Move_Following_vector) {

		for (auto& i : MainScene.Rects) {
			std::cout << "Rect is Moving" << std::endl;
			i.VectorMove();
		}
		std::cout << "Moving..." << std::endl;

		glutPostRedisplay();

	}

	




	if (t == 1000) {
		t = 0;
		playtime = glutGet(GLUT_ELAPSED_TIME) / 1000;


		Timestring.clear();
		FPSstring.clear();
		FPSstring += inWord;
		FPSstring += std::to_string(FPS);
		FPS = 0;

		Timestring += Pt;
		Timestring += std::to_string(playtime);


		TotalString = FPSstring + Timestring;

	

		std::cout << TotalString << std::endl;


		
		glutSetWindowTitle(TotalString.c_str());
	}


	

	return glutTimerFunc(1, Scene3::MyTimer, value);
	
}






CallbackFunc Scene3::CreateCallBackFunc(void) {
	CallbackFunc Func{};


	Func.DrawCall = drawScene;
	Func.MouseCall = MouseClickCall;
	Func.KeyboardInputCall = KeyboardCall;
	Func.KeyboardOffCall = KeyboardoffCall;
	Func.KeyboardSpecialInputCall = SpecialKeyboardCall;
	Func.KeyboardSpecialOffCall = SpecialKeyboardoffCall;
	Func.MouseDragCall = MouseDragCall;
	Func.TimerCall = MyTimer;
	
	return Func;
}
