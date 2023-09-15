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
			Rand
		};
		

		void NewColor(GLColor& MainColor,GLColor& MemColor,PrivateFuction::Colors::ColorName c){


			if (c == ColorName::Mem) {
				MainColor.R = MemColor.R;
				MainColor.G = MemColor.G;
				MainColor.B = MemColor.B;
				MainColor.A = MemColor.A;
			}


			if (c == ColorName::Blue) {
				MemColor.R = MainColor.R;
				MemColor.G = MainColor.G;
				MemColor.B = MainColor.B;
				MemColor.A = MainColor.A;



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
				MemColor.R = MainColor.R;
				MemColor.G = MainColor.G;
				MemColor.B = MainColor.B;
				MemColor.A = MainColor.A;



				MainColor.R = 0.0f;
				MainColor.G = 1.0f;
				MainColor.B = 0.0f;
				MainColor.A = 1.0f;
				return;
			}

			if (c == ColorName::Rand) {
				MainColor.R = static_cast<float>(MainFunctionVariables::dis(MainFunctionVariables::gen));
				MainColor.G = static_cast<float>(MainFunctionVariables::dis(MainFunctionVariables::gen));
				MainColor.B = static_cast<float>(MainFunctionVariables::dis(MainFunctionVariables::gen));
				MainColor.A = 1.0f;


			}



		}




	}
}



GLvoid MainFunction::drawScene() {



	glClearColor(MainFunctionVariables::DisplayColor.R, MainFunctionVariables::DisplayColor.G, MainFunctionVariables::DisplayColor.B, MainFunctionVariables::DisplayColor.A);
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();

}


GLvoid MainFunction::ReShape(int w, int h) {


	glViewport(0, 0, w, h);

}



GLvoid MainFunction::KeyboardInput(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'f':
		
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor, 
			MainFunctionVariables::MemoryColor, 
			PrivateFuction::Colors::ColorName::Blue);
		
		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case 'a':
		PrivateFuction::Colors::NewColor(
			MainFunctionVariables::DisplayColor,
			MainFunctionVariables::MemoryColor,
			PrivateFuction::Colors::ColorName::Rand);

		glClear(GL_COLOR_BUFFER_BIT);
		break;


	case 't':
		MainFunctionVariables::TimerEnable = true;
		glutTimerFunc(100, MainFunction::MyTimer, 1);
		break;

	case 'q':
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}

	glutPostRedisplay();

}

GLvoid MainFunction::MyTimer(int Value) {

	PrivateFuction::Colors::NewColor(
		MainFunctionVariables::DisplayColor,
		MainFunctionVariables::MemoryColor,
		PrivateFuction::Colors::ColorName::Rand);

	glutPostRedisplay();


	if(MainFunctionVariables::TimerEnable)glutTimerFunc(100, MainFunction::MyTimer, 1);
}

GLvoid MainFunction::KeyboardUPInput(unsigned char key, int x, int y) {

	if (key == 't') {
		MainFunctionVariables::TimerEnable = false;
	}
	PrivateFuction::Colors::NewColor(
		MainFunctionVariables::DisplayColor,
		MainFunctionVariables::MemoryColor,
		PrivateFuction::Colors::ColorName::Mem);


	glutPostRedisplay();
}