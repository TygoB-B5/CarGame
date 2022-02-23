#include "Game.h"

#include "Core/Time.h"
#include "Core/Random.h"
#include "Core/Renderer/Renderer.h"

namespace CarGame
{
	void Game::Setup()
	{
		m_Camera = std::make_shared<Core::Camera>(90, ofGetWidth() / ofGetHeight(), 0.1f, 1000.0f);

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

	void Game::Draw()
	{
		Core::Renderer::Clear(glm::vec4(0, 50, 50, 225));

		m_Camera->SetPosition(m_CameraPos);	
		Core::Renderer::Begin(*m_Camera);

		std::array<glm::vec3, 4> poses;
		poses[0] = { -50, 0, -50 };
		poses[1] = { 50, 0, -50};
		poses[2] = { 50, 0, 50 };
		poses[3] = { -50, 0, 50 };

		glm::vec4 color = { 0, 225, 100, 225 };

		Core::Renderer::DrawQuadFromPoints(poses, color);

		std::array<glm::vec3, 4> poses2;
		poses2[0] = { -5, -10, -5 };
		poses2[1] = { 5, -10, -5 };
		poses2[2] = { 5, -10, 5 };
		poses2[3] = { -5, -10, 5 };

		glm::vec4 color2 = { 225, 10, 90, 225 };

		Core::Renderer::DrawQuadFromPoints(poses2, color2);

		Core::Renderer::End();
	}

	void Game::KeyPressed(char key)
	{
		if (key == 'w')
			m_CameraPos.y++;
		if (key == 's')
			m_CameraPos.y--;

		if (key == 'd')
			m_CameraPos.x--;
		if (key == 'a')
			m_CameraPos.x++;

		if (key == 'q')
			m_CameraPos.z--;

		if (key == 'e')
			m_CameraPos.z++;
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