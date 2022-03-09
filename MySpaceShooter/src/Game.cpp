#include "Game.h"
#include "Core/Time.h"
#include "Core/Input/OscController.h"
#include "Core/Renderer/Camera.h"
#include "Core/Renderer/ViewportParams.h"
#include "Core/Renderer/Renderer.h"
#include "Core/ModelLoader.h"

namespace Game
{
	void Game::Setup()
	{
		Core::Renderer::Init();
		Input::OscServer::Init();

		// Craete and assign Spaceship objects
		std::shared_ptr<Core::Object> spec1 = std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship1.txt"));
		std::shared_ptr<Core::Object> spec2 = std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship2.txt"));

		// Assign SpaceShip data
		m_SpaceShips[0] = std::make_shared<SpaceShip>();
		m_SpaceShips[0]->SetCamera(std::make_shared<Core::Camera>(60, ((float)ofGetWidth() / 4) / (float)ofGetHeight(), 0.01f, 10000, Core::ViewportParams(0, 0, (float)ofGetWidth() / 2, (float)ofGetHeight())));
		m_SpaceShips[0]->SetObject(std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship1.txt")));
		m_SpaceShips[0]->SetController(std::make_shared<Input::OscController>(0));
		
		m_SpaceShips[1] = std::make_shared<SpaceShip>();
		m_SpaceShips[1]->SetCamera(std::make_shared<Core::Camera>(60, ((float)ofGetWidth() / 4) / (float)ofGetHeight(), 0.01f, 10000, Core::ViewportParams((float)ofGetWidth() / 2, 0, (float)ofGetWidth() / 2, (float)ofGetHeight())));
		m_SpaceShips[1]->SetObject(std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship2.txt")));
		m_SpaceShips[1]->SetController(std::make_shared<Input::OscController>(1));

		m_RenderObjects.push_back(m_SpaceShips[0]->GetObject());
		m_RenderObjects.push_back(m_SpaceShips[1]->GetObject());
	}

	void Game::Update()
	{
		// Update time tick
		Core::Time::Tick();
		Input::OscServer::Update();
	}

	void Game::Draw()
	{
		Core::Renderer::Clear(glm::vec4(27, 16, 101,  225));

		// Loop through all players
		for (auto& ship : m_SpaceShips)
		{
			ship->Update();
			Core::Renderer::SetViewport(ship->GetCamera()->GetViewport());
			Core::Renderer::Begin(ship->GetCamera());

			for (auto& obj : m_RenderObjects)
				obj->Draw();

			Core::Renderer::End();
		}
	}
}