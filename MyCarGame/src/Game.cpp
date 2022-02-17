#include "Game.h"

#include "Core/Time.h"
#include "Core/Random.h"

namespace CarGame
{
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
		Core::Time::Tick();
		m_Controller->Poll();
	}

	glm::mat4 m_Projection;
	glm::mat4 m_ViewProjectionMatrix;

	glm::vec3 m_CameraPos = { 0, 0, -5 };

	void Game::Draw()
	{
		m_Projection = glm::perspective(100.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
		m_ViewProjectionMatrix = glm::inverse(glm::translate(glm::mat4(1.0f), m_CameraPos)) * m_Projection;

		glm::vec3 pos = m_ViewProjectionMatrix * glm::vec4(10, 1, 10, -1);

		
		for (size_t i = 0; i < 10; i++)
		{
		glColor4f(i % 2 == 0 ? 0 : 1.0f, i % 2 != 0 ? 0 : 1.0f, 0.0, 1.0);
		glBegin(GL_QUADS);
		glVertex3f(pos.x, pos.y, pos.z);
		glVertex3f(pos.x + (100 * i), pos.y, pos.z);
		glVertex3f(pos.x + (100 * i), pos.y, pos.z + (10 * i));
		glVertex3f(pos.x, pos.y, pos.z + (100 * i));
		glEnd();
		}
	}

	void Game::KeyPressed(char key)
	{
		if (key == 'w')
			m_CameraPos.y--;
		if (key == 's')
			m_CameraPos.y++;

		if (key == 'd')
			m_CameraPos.x++;
		if (key == 'a')
			m_CameraPos.x--;
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