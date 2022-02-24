#include "Game.h"

#include "Core/Time.h"
#include "Core/Random.h"
#include "Core/Renderer/Renderer.h"
#include "Core/ModelLoader.h"

namespace CarGame
{
	void Game::Setup()
	{
		Core::Renderer::Init();

		m_Camera = std::make_shared<Core::Camera>(90, (float)ofGetWidth() / (float)ofGetHeight(), 0.1f, 10000);

#if ENABLE_DEBUG_CONTROLLER 
		m_Controller = std::make_shared<Input::DebugController>();
#else
		m_Controller = std::make_shared<Input::OscController>();
#endif

		m_Objects.push_back(Core::Object(Core::ModelLoader::Load("Assets/floor.txt")));

		{
			for (size_t i = 0; i < 1000; i++)
			{

				glm::vec4 color = { 100, 100, 100, 225 };
				if (i % 2 == 0)
					color = { 70, 70, 70, 225 };


				std::array<glm::vec3, 4> poses2;
				poses2[0] = { -50 , 0, 0 + (25 * i) };
				poses2[1] = { 50 , 0, 0 + (25 * i) };
				poses2[2] = { 50, 0, 25 + (25 * i) };
				poses2[3] = { -50, 0, 25 + (25 * i) };

				Core::Quad quad(poses2, color);

				m_Objects.push_back(Core::Object(quad));
			}
		}


	}

	void Game::Update()
	{
		Core::Time::Tick();
		m_Controller->Poll();
	}

	void Game::Draw()
	{
		Core::Renderer::Clear(glm::vec4(153, 255, 225, 225));

		m_Camera->SetRotation(m_CameraRot);
		m_Camera->SetPosition(m_CameraPos);

		Core::Renderer::Begin(*m_Camera);

		for (auto& obj : m_Objects)
			obj.Update();

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