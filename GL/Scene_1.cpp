#include "Scene_1.h"




namespace Scene1_Variables {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 1.0);




	GLColor DisplayColor{ 0.0f,0.0f,0.0f,0.0f };
	GLColor MemoryColor{ 0.0f,0.0f,0.0f,0.0f };


	bool TimerEnable = false;
}


namespace Scene1_Functions {
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
		

		void NewColor(GLColor& MainColor,GLColor& MemColor,Scene1_Functions::Colors::ColorName c){


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
				MainColor.R = static_cast<float>(Scene1_Variables::dis(Scene1_Variables::gen));
				MainColor.G = static_cast<float>(Scene1_Variables::dis(Scene1_Variables::gen));
				MainColor.B = static_cast<float>(Scene1_Variables::dis(Scene1_Variables::gen));
				MainColor.A = 1.0f;

				return;
			}



		}




	}
}


GLvoid Scene_1_CallbackFunctions::drawScene() {



	glClearColor(Scene1_Variables::DisplayColor.R, Scene1_Variables::DisplayColor.G, Scene1_Variables::DisplayColor.B, Scene1_Variables::DisplayColor.A);
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();

}


GLvoid Scene_1_CallbackFunctions::ReShape(int w, int h) {


	glViewport(0, 0, w, h);

}



GLvoid Scene_1_CallbackFunctions::KeyboardInput(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'c':
		
		Scene1_Functions::Colors::NewColor(
			Scene1_Variables::DisplayColor, 
			Scene1_Variables::MemoryColor, 
			Scene1_Functions::Colors::ColorName::Turquoise);
		
		glClear(GL_COLOR_BUFFER_BIT);
		break;





	case 'm':
		Scene1_Functions::Colors::NewColor(
			Scene1_Variables::DisplayColor,
			Scene1_Variables::MemoryColor,
			Scene1_Functions::Colors::ColorName::Magenta);

		glClear(GL_COLOR_BUFFER_BIT);
		break;


	case 'y':
		Scene1_Functions::Colors::NewColor(
			Scene1_Variables::DisplayColor,
			Scene1_Variables::MemoryColor,
			Scene1_Functions::Colors::ColorName::Yellow);

		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case 'a':
		Scene1_Functions::Colors::NewColor(
			Scene1_Variables::DisplayColor,
			Scene1_Variables::MemoryColor,
			Scene1_Functions::Colors::ColorName::Rand);

		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case 'w':
		Scene1_Functions::Colors::NewColor(
			Scene1_Variables::DisplayColor,
			Scene1_Variables::MemoryColor,
			Scene1_Functions::Colors::ColorName::White);

		glClear(GL_COLOR_BUFFER_BIT);
		break;

	case 'k':
		Scene1_Functions::Colors::NewColor(
			Scene1_Variables::DisplayColor,
			Scene1_Variables::MemoryColor,
			Scene1_Functions::Colors::ColorName::Black);

		glClear(GL_COLOR_BUFFER_BIT);
		break;





	

	case 't':
		if (Scene1_Variables::TimerEnable) {
			Scene1_Variables::TimerEnable = false;
			break;
		}
		Scene1_Variables::TimerEnable = true;
		glutTimerFunc(10, Scene_1_CallbackFunctions::MyTimer, 1);
		break;

	case 'q':
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}

	glutPostRedisplay();

}

GLvoid Scene_1_CallbackFunctions::MyTimer(int Value) {

	Scene1_Functions::Colors::NewColor(
		Scene1_Variables::DisplayColor,
		Scene1_Variables::MemoryColor,
		Scene1_Functions::Colors::ColorName::Rand);

	glutPostRedisplay();


	if(Scene1_Variables::TimerEnable)glutTimerFunc(100, Scene_1_CallbackFunctions::MyTimer, 1);
}

GLvoid Scene_1_CallbackFunctions::KeyboardUPInput(unsigned char key, int x, int y) {

	if (key == 't') {
		//Scene1_Variables::TimerEnable = false;
	}


	glutPostRedisplay();
}



CallbackFunc Scene_1_CallbackFunctions::CreateCallBackFunc(void) {
	CallbackFunc Func;

	Func.DrawCall = drawScene;
	Func.ReShapeCall = ReShape;
	Func.KeyboardInputCall = KeyboardInput;
	Func.KeyboardOffCall = KeyboardUPInput;
	Func.TimerCall = MyTimer;


	return Func;
}



