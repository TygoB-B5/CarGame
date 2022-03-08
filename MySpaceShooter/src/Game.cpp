#include "Game.h"

namespace CarGame
{
	void Game::Setup()
	{
		Core::Renderer::Init();
		Input::OscServer::Init();

		// Craete and assign Spaceship objects
		std::shared_ptr<Core::Object> spec1 = std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship1.txt"));
		std::shared_ptr<Core::Object> spec2 = std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/spaceship2.txt"));
		spec1->SetScale({ 3.0f, 3.0f, 3.0f });
		spec2->SetScale({ 3.0f, 3.0f, 3.0f });
		// Assign player data
		m_Players[0] = PlayerParams(0,
			std::make_shared<Input::OscController>(0),
			std::make_shared<Core::Camera>(50, ((float)ofGetWidth() / 2) / (float)ofGetHeight(), 0.01f, 10000),
			spec2,
			Core::ViewportParams(0, 0, (float)ofGetWidth() / 2, (float)ofGetHeight()));

		m_Players[1] = PlayerParams(1,
			std::make_shared<Input::OscController>(1),
			std::make_shared<Core::Camera>(60, ((float)ofGetWidth() / 2) / (float)ofGetHeight(), 0.01f, 10000),
			spec1,
			Core::ViewportParams((float)ofGetWidth() / 2, 0, (float)ofGetWidth() / 2, (float)ofGetHeight()));

		// Create floor object & Push objects to Render list
		m_Objects.push_back(std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/floor.txt")));
		m_Objects.push_back(spec2);
		m_Objects.push_back(spec1);
	}

	void Game::Update()
	{
		// Update time tick
		Core::Time::Tick();
		Input::OscServer::Update();
	}

	void Game::Draw()
	{
		Core::Renderer::Clear(glm::vec4(153, 255, 225, 225));

		// Loop through all players
		for (auto& player : m_Players)
		{

			// Calculate Rotation with deadzone
			Input::Controller* cont = player.Controller.get();
			glm::vec3 rotation =
				glm::length(glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0)) > 5 ?
				glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0) : glm::vec3(0, 0, 0);

			// Update spaceship position and rotation
			player.SpaceShip->Rotate(rotation * Core::Time::GetDeltaTime());
			player.SpaceShip->Translate(player.SpaceShip->GetForward() * Core::Time::GetDeltaTime() * 250);

			// Update camera position and rotation
			glm::vec3 rot = player.SpaceShip->GetRotation();
			rot.y += 180;
			rot.x = -rot.x;

			player.Camera->SetRotation(rot);
			player.Camera->SetPosition(player.SpaceShip->GetPosition() + player.SpaceShip->GetForward() * 800 + player.SpaceShip->GetUp() * 10);


			Core::Renderer::SetViewport(player.Viewport);
			Core::Renderer::Begin(player.Camera);

			// Draw objects
			for (auto& obj : m_Objects)
				obj->Draw();

			Core::Renderer::End();
		}
	}
}