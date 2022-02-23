#include "Game.h"

#include "Core/Time.h"
#include "Core/Random.h"
#include "Core/Renderer/Renderer.h"

namespace CarGame
{
	void Game::Setup()
	{
		Core::Renderer::Init();

		m_Camera = std::make_shared<Core::Camera>(90, (float)ofGetWidth() / (float)ofGetHeight(), 0.1f, 1000.0f);
			
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
		m_CameraPos.z -= 10 * Core::Time::GetDeltaTime();
		Core::Renderer::Clear(glm::vec4(153, 255, 225, 225));
		m_Camera->SetRotation(m_CameraRot);
		m_Camera->SetPosition(m_CameraPos);	
		Core::Renderer::Begin(*m_Camera);

		glm::vec4 color = { 76, 153, 0, 225 };

		std::array<glm::vec3, 4> poses;
		poses[0] = { -5000, -10, -5000 };
		poses[1] = { 5000, -10, -5000 };
		poses[2] = { 5000, -10, 5000 };
		poses[3] = { -5000, -10, 5000 };

		Core::Renderer::DrawQuadFromPoints(poses, color);


		for (size_t i = 0; i < 10000; i++)
		{
			glm::vec4 color2 = { 100, 100, 100, 225 };
			if(i % 2 == 0)
				color2 = { 70, 70, 70, 225 };

			std::array<glm::vec3, 4> poses2;
			poses2[0] = { -50 , -9, 0 + (25 * i) };
			poses2[1] = { 50 , -9, 0 + (25 * i) };
			poses2[2] = { 50, -9, 25 + (25 * i) };
			poses2[3] = { -50, -9, 25 + (25 * i) };

			Core::Renderer::DrawQuadFromPoints(poses2, color2);
		}

		glm::vec4 color3 = { 102, 51, 0, 225 };

		glm::vec3 a = { 0, 0, -m_CameraPos.z - 5};

		std::array<glm::vec3, 4> poses3;
		poses3[0] = { -20 , -9, 0 };
		poses3[1] = { 0 , 0, 0 };
		poses3[2] = { 0, 0, -25 };
		poses3[3] = { -20, -9, -25 };

		poses3[0] += a; poses3[1] += a; poses3[2] += a; poses3[3] += a;

		std::array<glm::vec3, 4> poses4;
		poses4[0] = { 20 , -9, 0 };
		poses4[1] = { 0 , 0, 0 };
		poses4[2] = { 0, 0, -25 };
		poses4[3] = { 20, -9, -25 };

		poses4[0] += a; poses4[1] += a; poses4[2] += a; poses4[3] += a;

		Core::Renderer::DrawQuadFromPoints(poses3, color3);
		Core::Renderer::DrawQuadFromPoints(poses4, color3 - glm::vec4(10, 10, 10, 0));

		Core::Renderer::End();
	}

	void Game::KeyPressed(char key)
	{
		float dt = Core::Time::GetDeltaTime();
		if (key == 'w')
			m_CameraPos.y+=100*dt;
		if (key == 's')
			m_CameraPos.y-= 100 * dt;

		if (key == 'd')
			m_CameraPos.x-= 100 * dt;
		if (key == 'a')
			m_CameraPos.x+= 100 * dt;

		if (key == 'q')
			m_CameraPos.z-= 100 * dt;

		if (key == 'e')
			m_CameraPos.z+= 100 * dt;

		if (key == 'z')
			m_CameraRot.y-= 10 * dt;
		if(key == 'c')
			m_CameraRot.y+= 10 * dt;

		if (key == 'r')
			m_CameraRot.x-= 100 * dt;
		if (key == 'f')
			m_CameraRot.x+= 100 * dt;

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