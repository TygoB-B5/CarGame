#pragma once

#include "ofMain.h"
#include "Core/Object.h"
#include "Gameplay/SpaceShip.h"

namespace Game
{
	class Game
	{
	public:
		void Setup();
		void Update();
		void Draw();

		void KeyPressed(char key) {}
		void KeyReleased(char key) {}
		void MouseMoved(int x, int y){}
		void MouseDragged(int x, int y, int button) {}
		void MousePressed(int x, int y, int button) {}
		void MouseReleased(int x, int y, int button) {}
		void MouseEntered(int x, int y) {}

	private:
		std::array<std::shared_ptr<SpaceShip>, 2> m_SpaceShips;
		std::vector<std::shared_ptr<Core::Object>> m_RenderObjects;
	};
}