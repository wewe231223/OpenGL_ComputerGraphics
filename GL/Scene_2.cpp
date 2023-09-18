#include "Scene_2.h"

#define OriginRatio 1.0f
#define Reduction_Coefficient 0.8f
#define Enrargement_Coefficient 1.25f

namespace Scene2_Variables {

	Rect3f rect1{	-1.0f,	0.0f,	0.0f,	1.0f};
	Rect3f rect2{	-1.0f,	-1.0f,	0.0f,	0.0f};
	Rect3f rect3{	0.0f,	0.0f,	1.0f,	1.0f};
	Rect3f rect4{	0.0f,	-1.0f,	1.0f,	0.0f};
	
	const Rect3f OriginalRect1{ -1.0f,	0.0f,	0.0f,	1.0f };
	const Rect3f OriginalRect2{ -1.0f,	-1.0f,	0.0f,	0.0f };
	const Rect3f OriginalRect3{ 0.0f,	0.0f,	1.0f,	1.0f };
	const Rect3f OriginalRect4{ 0.0f,	-1.0f,	1.0f,	0.0f };


	


	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 1.0);

	float Rect1_ratio = 1.0f;
	float Rect2_ratio = 1.0f;
	float Rect3_ratio = 1.0f;
	float Rect4_ratio = 1.0f;


	GLColor RectColor1 = {
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	1.0f
	};

	GLColor RectColor2 = {
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	1.0f
	};

	GLColor RectColor3 = {
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	1.0f
	};

	GLColor RectColor4 = {
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	static_cast<float>(dis(gen)),
	1.0f
	};


	GLColor BackGroundColor = {
		0.0f,
		0.0f,
		0.0f,
		1.0f

	};

}


namespace Scene2_Functions {


	Rect3f Reduction(Rect3f r,float ratio) {
		Rect3f result{};



		
		float CenterX = (r.LeftDownX + r.RightUpX) / 2;
		float CenterY = (r.LeftDownY + r.RightUpY) / 2;


		float HalfWidth = abs((r.LeftDownX + r.RightUpX)) / 2;
		float HalfHeight = abs((r.LeftDownY + r.RightUpY)) / 2 ;

		std::cout << HalfHeight << " " << HalfWidth <<std::endl;

		HalfHeight = HalfHeight * ratio;
		HalfWidth = HalfWidth * ratio;

		result.LeftDownX = CenterX - HalfWidth ;
		result.LeftDownY = CenterY - HalfHeight;
		
		result.RightUpX = CenterX + HalfWidth;
		result.RightUpY = CenterY + HalfHeight ;


		

		return result;


	}



	void ConvertCoordinate(int pixelX, int pixelY, float& glX, float& glY){
		int Width = glutGet(GLUT_WINDOW_WIDTH);
		int Height = glutGet(GLUT_WINDOW_HEIGHT);

		glX = static_cast<float>(pixelX) / static_cast<float>(Width) * 2.0f - 1.0f;
		glY = 1.0f - static_cast<float>(pixelY) / static_cast<float>(Height) * 2.0f;
	}


	bool InsideRect(Rect3f r, int x, int y) {



		float Glx, Gly;


		ConvertCoordinate(x, y, Glx, Gly);

		//std::cout << Glx << " , " << Gly << std::endl;
		//std::cout << "Left Down " << std::endl << "( " << r.LeftDownX << " , " << r.LeftDownY << " )" << std::endl;
		//std::cout << "Right Up " << std::endl << "( " << r.RightUpX << " , " << r.RightUpY << " )" << std::endl;

		if (Glx > r.LeftDownX && Glx < r.RightUpX) {
			if (Gly > r.LeftDownY && Gly < r.RightUpY) {
				return true;
			}
		}

		return false;
	}



}









GLvoid Scene2_CallbackFunctions::drawScene() {
	glClearColor(
		Scene2_Variables::BackGroundColor.R, 
		Scene2_Variables::BackGroundColor.G, 
		Scene2_Variables::BackGroundColor.B, 
		Scene2_Variables::BackGroundColor.A);


	glClear(GL_COLOR_BUFFER_BIT);

	std::cout << "ReDrawed ================================================" << std::endl;

	
	glColor3f(
		Scene2_Variables::RectColor1.R,
		Scene2_Variables::RectColor1.G, 
		Scene2_Variables::RectColor1.B);


	glRectf(Scene2_Variables::rect1.LeftDownX,
		Scene2_Variables::rect1.LeftDownY,
		Scene2_Variables::rect1.RightUpX,
		Scene2_Variables::rect1.RightUpY);







	glColor3f(
		Scene2_Variables::RectColor2.R,
		Scene2_Variables::RectColor2.G,
		Scene2_Variables::RectColor2.B);



	glRectf(Scene2_Variables::rect2.LeftDownX,
		Scene2_Variables::rect2.LeftDownY,
		Scene2_Variables::rect2.RightUpX,
		Scene2_Variables::rect2.RightUpY);





	glColor3f(
		Scene2_Variables::RectColor3.R,
		Scene2_Variables::RectColor3.G,
		Scene2_Variables::RectColor3.B);


	glRectf(Scene2_Variables::rect3.LeftDownX,
		Scene2_Variables::rect3.LeftDownY,
		Scene2_Variables::rect3.RightUpX,
		Scene2_Variables::rect3.RightUpY);






	glColor3f(
		Scene2_Variables::RectColor4.R,
		Scene2_Variables::RectColor4.G,
		Scene2_Variables::RectColor4.B);



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


	



	glutPostRedisplay();
}







GLvoid Scene2_CallbackFunctions::MouseInput(int Button, int state, int x, int y){

	if (Button == GLUT_LEFT_BUTTON) {
		// Left Button
		if (state == GLUT_DOWN) {
			if (Scene2_Functions::InsideRect(Scene2_Variables::rect1, x, y)) {
				Scene2_Variables::RectColor1.R = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor1.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor1.B = Scene2_Variables::dis(Scene2_Variables::gen);


			}
			else if(Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect1,x,y)){


				Scene2_Variables::BackGroundColor.R  = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.B = Scene2_Variables::dis(Scene2_Variables::gen);




			}
			

			if (Scene2_Functions::InsideRect(Scene2_Variables::rect2, x, y)) {
				Scene2_Variables::RectColor2.R = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor2.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor2.B = Scene2_Variables::dis(Scene2_Variables::gen);


			}
			else if (Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect2, x, y)) {

				Scene2_Variables::BackGroundColor.R = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.B = Scene2_Variables::dis(Scene2_Variables::gen);

			}


			if (Scene2_Functions::InsideRect(Scene2_Variables::rect3, x, y)) {
				Scene2_Variables::RectColor3.R = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor3.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor3.B = Scene2_Variables::dis(Scene2_Variables::gen);

				

			}
			else if (Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect3, x, y)) {


				Scene2_Variables::BackGroundColor.R = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.B = Scene2_Variables::dis(Scene2_Variables::gen);

			}


			if (Scene2_Functions::InsideRect(Scene2_Variables::rect4, x, y)) {
				Scene2_Variables::RectColor4.R = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor4.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::RectColor4.B = Scene2_Variables::dis(Scene2_Variables::gen);


			}
			else if (Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect4, x, y)) {


				Scene2_Variables::BackGroundColor.R = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.G = Scene2_Variables::dis(Scene2_Variables::gen);
				Scene2_Variables::BackGroundColor.B = Scene2_Variables::dis(Scene2_Variables::gen);

			}




			glutPostRedisplay();
		}
		else {

		}

		

		

	}
	else {
		// Right button 
		if (state == GLUT_DOWN) {

			if (Scene2_Functions::InsideRect(Scene2_Variables::rect1, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect1_ratio = Scene2_Variables::Rect1_ratio * Reduction_Coefficient;

				Scene2_Variables::Rect1_ratio = std::clamp(Scene2_Variables::Rect1_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect1 = Scene2_Functions::Reduction(Scene2_Variables::rect1, Scene2_Variables::Rect1_ratio );

			}
			else if (Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect1, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect1_ratio = Scene2_Variables::Rect1_ratio * Enrargement_Coefficient;

				Scene2_Variables::Rect1_ratio = std::clamp(Scene2_Variables::Rect1_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect1 = Scene2_Functions::Reduction(Scene2_Variables::rect1, Scene2_Variables::Rect1_ratio);




			}


			if (Scene2_Functions::InsideRect(Scene2_Variables::rect2, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect2_ratio = Scene2_Variables::Rect2_ratio * Reduction_Coefficient;

				Scene2_Variables::Rect2_ratio = std::clamp(Scene2_Variables::Rect2_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect2 = Scene2_Functions::Reduction(Scene2_Variables::rect2, Scene2_Variables::Rect2_ratio );
			}
			else if (Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect2, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect2_ratio = Scene2_Variables::Rect2_ratio * Enrargement_Coefficient;

				Scene2_Variables::Rect2_ratio = std::clamp(Scene2_Variables::Rect2_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect2 = Scene2_Functions::Reduction(Scene2_Variables::rect2, Scene2_Variables::Rect2_ratio);




			}



			if (Scene2_Functions::InsideRect(Scene2_Variables::rect3, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect3_ratio = Scene2_Variables::Rect3_ratio * Reduction_Coefficient;

				Scene2_Variables::Rect3_ratio = std::clamp(Scene2_Variables::Rect3_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect3 = Scene2_Functions::Reduction(Scene2_Variables::rect3, Scene2_Variables::Rect3_ratio );
			}
			else if (Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect3, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect3_ratio = Scene2_Variables::Rect3_ratio * Enrargement_Coefficient;

				Scene2_Variables::Rect3_ratio = std::clamp(Scene2_Variables::Rect3_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect3 = Scene2_Functions::Reduction(Scene2_Variables::rect3, Scene2_Variables::Rect3_ratio);




			}



			if (Scene2_Functions::InsideRect(Scene2_Variables::rect4, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect4_ratio = Scene2_Variables::Rect4_ratio * Reduction_Coefficient;

				Scene2_Variables::Rect4_ratio = std::clamp(Scene2_Variables::Rect4_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect4 = Scene2_Functions::Reduction(Scene2_Variables::rect4, Scene2_Variables::Rect4_ratio);
			}
			else if (Scene2_Functions::InsideRect(Scene2_Variables::OriginalRect4, x, y)) {
				std::cout << "Mouse Inside !" << std::endl;
				Scene2_Variables::Rect4_ratio = Scene2_Variables::Rect4_ratio * Enrargement_Coefficient;

				Scene2_Variables::Rect4_ratio = std::clamp(Scene2_Variables::Rect4_ratio, 0.0001f, 1.0f);


				Scene2_Variables::rect4 = Scene2_Functions::Reduction(Scene2_Variables::rect4, Scene2_Variables::Rect4_ratio);




			}



			glutPostRedisplay();
		}





	}





}








CallbackFunc Scene2_CallbackFunctions::CreateCallBackFunc(void) {
	CallbackFunc Func{};


	Func.DrawCall = drawScene;
	Func.MouseDragCall = MouseDragInput;
	Func.KeyboardInputCall = KeyboardInput;
	Func.MouseCall = MouseInput;

	return Func;

}