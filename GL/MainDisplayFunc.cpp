#include "MainDisplayFunc.h"


namespace MainFunctionVariables {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 1.0);




	GLColor DisplayColor{ 0.0f,0.0f,0.0f,0.0f };
	GLColor MemoryColor{ 0.0f,0.0f,0.0f,0.0f };


	bool TimerEnable = false;
}


namespace PrivateFuction {
	namespace Colors {


		enum ColorName {
			Mem,
			Blue,
			Red,
			Green,
			Turquoise,
			Magenta,
			Yellow,
			White,
			Black,
			Rand
		};
		

		void NewColor(GLColor& MainColor,GLColor& MemColor,PrivateFuction::Colors::ColorName c){


			if (c == ColorName::Mem) {
				MainColor.R = MemColor.R;
				MainColor.G = MemColor.G;
				MainColor.B = MemColor.B;
				MainColor.A = MemColor.A;


				return;
			}

			if (c == ColorName::Turquoise) {
				MainColor.R = 0.0f;
				MainColor.G = 1.0f;
				MainColor.B = 1.0f;
				MainColor.A = 1.0f;

				return;
			}

			if (c == ColorName::Magenta) {
				MainColor.R = 1.0f;
				MainColor.G = 0.0f;
				MainColor.B = 1.0f;
				MainColor.A = 1.0f;

				return;
			}

			if (c == ColorName::Yellow) {
				MainColor.R = 1.0f;
				MainColor.G = 1.0f;
				MainColor.B = 0.0f;
				MainColor.A = 1.0f;

				return;
			}


			if (c == ColorName::White) {
				MainColor.R = 1.0f;
				MainColor.G = 1.0f;
				MainColor.B = 1.0f;
				MainColor.A = 1.0f;

				return;
			}

			if (c == ColorName::Black) {
				MainColor.R = 0.0f;
				MainColor.G = 0.0f;
				MainColor.B = 0.0f;
				MainColor.A = 0.0f;

				return;
			}


			if (c == ColorName::Blue) {
				MainColor.R = 0.0f;
				MainColor.G = 0.0f;
				MainColor.B = 1.0f;
				MainColor.A = 1.0f;
				return;
			}

			if (c == ColorName::Red) {
				MemColor.R = MainColor.R;
				MemColor.G = MainColor.G;
				MemColor.B = MainColor.B;
				MemColor.A = MainColor.A;



				MainColor.R = 1.0f;
				MainColor.G = 0.0f;
				MainColor.B = 0.0f;
				MainColor.A = 1.0f;
				return;
			}


			if (c == ColorName::Green) {

				MainColor.R = 0.0f;
				MainColor.G = 0.0f;
				MainColor.B = 0.0f;
				MainColor.A = 1.0f;
				return;
			}

			if (c == ColorName::Rand) {
				MainColor.R = static_cast<float>(MainFunctionVariables::dis(MainFunctionVariables::gen));
				MainColor.G = static_cast<float>(MainFunctionVariables::dis(MainFunctionVariables::gen));
				MainColor.B = static_cast<float>(MainFunctionVariables::dis(MainFunctionVariables::gen));
				MainColor.A = 1.0f;

				return;
			}



		}




	}
}



GLvoid FunctionSet_1::drawScene() {



	glClearColor(MainFunctionVariables::DisplayColor.R, MainFunctionVariables::DisplayColor.G, MainFunctionVariables::DisplayColor.B, MainFunctionVariables::DisplayColor.A);
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();

}


GLvoid FunctionSet_1::ReShape(int w, int h) {


	glViewport(0, 0, w, h);

}



GLvoid FunctionSet_1::KeyboardInput(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'c':
		
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor, 
			MainFunctionVariables::MemoryColor, 
			PrivateFuction::Colors::ColorName::Turquoise);
		
		glClear(GL_COLOR_BUFFER_BIT);
		break;





	case 'm':
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor,
			MainFunctionVariables::MemoryColor,
			PrivateFuction::Colors::ColorName::Magenta);

		glClear(GL_COLOR_BUFFER_BIT);
		break;


	case 'y':
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor,
			MainFunctionVariables::MemoryColor,
			PrivateFuction::Colors::ColorName::Yellow);

		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case 'a':
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor,
			MainFunctionVariables::MemoryColor,
			PrivateFuction::Colors::ColorName::Rand);

		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case 'w':
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor,
			MainFunctionVariables::MemoryColor,
			PrivateFuction::Colors::ColorName::White);

		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case 'k':
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor,
			MainFunctionVariables::MemoryColor,
			PrivateFuction::Colors::ColorName::Black);

		glClear(GL_COLOR_BUFFER_BIT);
		break;





	

	case 't':
		MainFunctionVariables::TimerEnable = true;
		glutTimerFunc(100, FunctionSet_1::MyTimer, 1);
		break;

	case 'q':
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}

	glutPostRedisplay();

}

GLvoid FunctionSet_1::MyTimer(int Value) {

	PrivateFuction::Colors::NewColor(
		MainFunctionVariables::DisplayColor,
		MainFunctionVariables::MemoryColor,
		PrivateFuction::Colors::ColorName::Rand);

	glutPostRedisplay();


	if(MainFunctionVariables::TimerEnable)glutTimerFunc(100, FunctionSet_1::MyTimer, 1);
}

GLvoid FunctionSet_1::KeyboardUPInput(unsigned char key, int x, int y) {

	if (key == 't') {
		MainFunctionVariables::TimerEnable = false;
	}


	glutPostRedisplay();
}




GLvoid FunctionSet_2::drawScene(GLvoid) {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-1.f, 0 , 0 , 1.f );

	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(-1.f, -1.f, 0, 0);


	glColor3f(0.0f, 1.0f, 1.0f);
	glRectf(0, 0, 1.f, 1.f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glRectf(0, -1.f, 1.f, 0);




	glutSwapBuffers();

}




