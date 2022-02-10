#pragma once

#include "ofMain.h"
#include "Input/Controller.h"

#define ENABLE_PC_CONTROLLER 0

namespace CarGame
{
	class Game
	{
	public:
		void Setup();
		void Update();
		void Draw();

		void KeyPressed(int key);
		void KeyReleased(int key);
		void MouseMoved(int x, int y);
		void MouseDragged(int x, int y, int button);
		void MousePressed(int x, int y, int button);
		void MouseReleased(int x, int y, int button);

	private:
		std::shared_ptr<Input::Controller> m_Controller;
	};
}