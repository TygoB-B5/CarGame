#pragma once

#include "glm/glm.hpp"
#include "Core/Input/Controller.h"
#include "Core/Renderer/Camera.h"
#include "Core/Object.h"

namespace Game
{
	class SpaceShip
	{
	public:
		SpaceShip()
		{}

		SpaceShip(std::shared_ptr<Input::Controller> controller,
			std::shared_ptr<Core::Camera> camera, std::shared_ptr<Core::Object> spaceShip)
			: m_Controller(controller), m_Camera(camera), m_Object(spaceShip)
		{}

		void Update();

		void SetObject(const std::shared_ptr<Core::Object>& object) { m_Object = object; }
		void SetCamera(const std::shared_ptr<Core::Camera>& camera) { m_Camera = camera; }
		void SetController(const std::shared_ptr<Input::Controller>& controller) { m_Controller = controller; }

		const std::shared_ptr<Core::Object>& GetObject() const { return m_Object; }
		const std::shared_ptr<Core::Camera>& GetCamera() const { return m_Camera; }

	private:
		const glm::vec3& GetControllerInput();
		void UpdateSpaceShipPose();
		void UpdateCameraPose();

	private:
		std::shared_ptr<Core::Object> m_Object;
		std::shared_ptr<Input::Controller> m_Controller;
		std::shared_ptr<Core::Camera> m_Camera;
	};
}
