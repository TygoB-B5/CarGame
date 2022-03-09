#include "Game.h"
#include "Core/Core.h"

namespace Game
{
	void Game::Setup()
	{
		Core::Renderer::Init();
		Input::OscServer::Init();

		// Assign SpaceShip data
		m_SpaceShips[0] = std::make_shared<SpaceShip>();
		m_SpaceShips[0]->SetCamera(std::make_shared<Core::Camera>(90, ((float)ofGetWidth() / 4) / (float)ofGetHeight(), 0.01f, 10000, Core::ViewportParams(0, 0, (float)ofGetWidth() / 2, (float)ofGetHeight())));
		m_SpaceShips[0]->SetObject(std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship1.txt")));
		m_SpaceShips[0]->SetController(std::make_shared<Input::OscController>(0));
		
		m_SpaceShips[1] = std::make_shared<SpaceShip>();
		m_SpaceShips[1]->SetCamera(std::make_shared<Core::Camera>(90, ((float)ofGetWidth() / 4) / (float)ofGetHeight(), 0.01f, 10000, Core::ViewportParams((float)ofGetWidth() / 2, 0, (float)ofGetWidth() / 2, (float)ofGetHeight())));
		m_SpaceShips[1]->SetObject(std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship2.txt")));
		m_SpaceShips[1]->SetController(std::make_shared<Input::OscController>(1));

		//Rotate Spaceship in the opposite direction
		m_SpaceShips[1]->GetObject()->SetRotation({ 0, 180, 0 });

		// Create VisibilityCubes
		m_VisibilityCubes[0] = std::make_shared<VisibilityCube>();
		m_VisibilityCubes[0]->SetObject(std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/cube.txt")));

		m_VisibilityCubes[1] = std::make_shared<VisibilityCube>();
		m_VisibilityCubes[1]->SetObject(std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/cube.txt")));

		// Push models to Rendering Stack
		m_GlobalRenderObjects.push_back(m_SpaceShips[0]->GetObject());
		m_GlobalRenderObjects.push_back(m_SpaceShips[1]->GetObject());


		// Add cubes with Random positions and sizes to Rendering Stack
		for (size_t i = 0; i < 1000; i++)
		{
			auto obj = std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/star.txt"));
			obj->SetPosition(glm::vec3(Core::Random::Range(-PLAYFIELD_SIZE, PLAYFIELD_SIZE), Core::Random::Range(-PLAYFIELD_SIZE, PLAYFIELD_SIZE), Core::Random::Range(-PLAYFIELD_SIZE, PLAYFIELD_SIZE)));
			obj->SetScale(glm::vec3(Core::Random::Range(5, 10), Core::Random::Range(5, 10), Core::Random::Range(5, 10)));
			obj->SetRotation(glm::vec3(Core::Random::Range(-180, 180), Core::Random::Range(-180, 180), Core::Random::Range(-180, 180)));
			m_GlobalRenderObjects.push_back(obj);
		}
	}

	void Game::Update()
	{
		Core::Time::Tick();
		Input::OscServer::Update();


		// Update Logic
		for (size_t i = 0; i < 2; i++)
		{
			float dist = glm::distance(m_SpaceShips[0]->GetObject()->GetPosition(), m_SpaceShips[1]->GetObject()->GetPosition());
			m_VisibilityCubes[i]->SetSize(dist * pow(0.1f, 2));
			m_VisibilityCubes[i]->GetObject()->SetPosition(m_SpaceShips[i]->GetObject()->GetPosition());

			m_SpaceShips[i]->Update();
		}
	}

	void Game::Draw()
	{
		Core::Renderer::Clear(glm::vec4(7, 0, 51,  225));

		// Render Objects
		for (size_t i = 0; i < 2; i++)
		{
			Core::Renderer::SetViewport(m_SpaceShips[i]->GetCamera()->GetViewport());
			Core::Renderer::Begin(m_SpaceShips[i]->GetCamera());

			for (auto& obj : m_GlobalRenderObjects)
				obj->Draw();

			m_VisibilityCubes[i == 1 ? 0 : 1]->GetObject()->Draw();

			Core::Renderer::End();
		}
	}
}