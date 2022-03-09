#pragma once

#include "glm/glm.hpp"
#include "Core/Core.h"

#define PLAYFIELD_SIZE 2000
#define SPACESHIP_SPEED 150

#define DEADZONE 5

namespace Game
{
	class SpaceShip : public Core::GameplayObject
	{
	public:
		SpaceShip()
		{}

		SpaceShip(std::shared_ptr<Input::Controller> controller,
			std::shared_ptr<Core::Camera> camera, std::shared_ptr<Core::Object> spaceShip)
			: m_Controller(controller), m_Camera(camera), m_Object(spaceShip)
		{}

		void Update();

		virtual void SetObject(const std::shared_ptr<Core::Object>& object) override { m_Object = object; }
		virtual const std::shared_ptr<Core::Object>& GetObject() const override{ return m_Object; }

		void SetCamera(const std::shared_ptr<Core::Camera>& camera) { m_Camera = camera; }
		void SetController(const std::shared_ptr<Input::Controller>& controller) { m_Controller = controller; }
		const std::shared_ptr<Core::Camera>& GetCamera() const { return m_Camera; }

	private:
		const glm::vec3& GetControllerInput();
		void UpdateSpaceShipRotation();
		void UpdateSpaceShipPosition();
		void UpdateCameraPose();

	private:
		std::shared_ptr<Core::Object> m_Object;
		std::shared_ptr<Input::Controller> m_Controller;
		std::shared_ptr<Core::Camera> m_Camera;
	};
}
