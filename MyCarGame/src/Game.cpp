#include "Game.h"

#include "Input/OscController.h"
#include "Input/PcController.h"

namespace CarGame
{
	ofBoxPrimitive box;
	ofEasyCam camera;


	void Game::Setup()
	{
#if ENABLE_PC_CONTROLLER  
		m_Controller = std::make_shared<Input::OscController>();
#else
		m_Controller = std::make_shared<Input::PcController>();
#endif
	}

	void Game::Update()
	{

	}

	void Game::Draw()
	{
		camera.begin();
		box.rotate(ofGetElapsedTimef(), 1.0, 0.0, 0.0);
		box.rotate(ofGetElapsedTimef(), 0, 1.0, 0.0);
		box.draw();
		camera.end();
	}

	void Game::KeyPressed(int key)
	{
		m_Controller->KeyPressedEvent(key);
	}

	void Game::KeyReleased(int key)
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
}