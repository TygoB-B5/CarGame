#pragma once

#include "ofMain.h"
#include "Core/Input/OscServer.h"
#include "Core/Input/OscController.h"
#include "Core/Input/DebugController.h"
#include "Core/Renderer/Camera.h"
#include "Core/Object.h"
#include "Core/Time.h"
#include "Core/Random.h"
#include "Core/Renderer/Renderer.h"
#include "Core/ModelLoader.h"


#define ENABLE_DEBUG_CONTROLLER 0

namespace CarGame
{
	struct PlayerParams
	{
		PlayerParams()
		{}

		PlayerParams(int playerNumber, std::shared_ptr<Input::Controller> controller,
			std::shared_ptr<Core::Camera> camera, std::shared_ptr<Core::Object> spaceShip,
			Core::ViewportParams viewport)
			: PlayerNumber(playerNumber), Controller(controller), Camera(camera), SpaceShip(spaceShip), Viewport(viewport)
		{}

		std::shared_ptr<Input::Controller> Controller;
		std::shared_ptr<Core::Camera> Camera;
		std::shared_ptr<Core::Object> SpaceShip;

		Core::ViewportParams Viewport;
		int PlayerNumber = 0;
	};

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
		std::array<PlayerParams, 2> m_Players;

		std::vector<std::shared_ptr<Core::Object>> m_Objects;

	};
}