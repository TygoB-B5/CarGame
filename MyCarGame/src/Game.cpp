#include "Game.h"

#include "Core/Time.h"

namespace CarGame
{
	ofBoxPrimitive box;
	ofEasyCam camera;

	void Game::Setup()
	{
#if ENABLE_DEBUG_CONTROLLER  
		m_Controller = std::make_shared<Input::DebugController>();
#else
		m_Controller = std::make_shared<Input::OscController>();
#endif
	}

	void Game::Update()
	{
		Time::TimeData::Tick();
		m_Controller->Poll();
	}


	void Game::Draw()
	{
		camera.begin();
		box.setPosition(-m_Controller->GetOrientation().y * 3, 0, -1000);
		box.draw();
		camera.end();
	}

	void Game::KeyPressed(char key)
	{
		m_Controller->KeyPressedEvent(key);
	}

	void Game::KeyReleased(char key)
	{
		m_Controller->KeyReleasedEvent(key);
	}

	void Game::MouseMoved(int x, int y)
	{
		m_Controller->MouseMovedEvent(x, y);
	}

	void Game::MouseDragged(int x, int y, int button)
	{
	}

	void Game::MousePressed(int x, int y, int button)
	{
	}

	void Game::MouseReleased(int x, int y, int button)
	{
	}

	void Game::MouseEntered(int x, int y)
	{
		m_Controller->ResetAcceleration();
	}
}