#include "SpaceShip.h"
#include "Core/Time.h"

namespace Game
{
	void SpaceShip::Update()
	{
		UpdateSpaceShipPose();
		UpdateCameraPose();
	}

	const glm::vec3& SpaceShip::GetControllerInput()
	{
		// Calculate Rotation with deadzone
		auto& cont = m_Controller;
		glm::vec3 rotation =
			glm::length(glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0)) > 5 ?
			glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0) : glm::vec3(0, 0, 0);

		return rotation;
	}

	void SpaceShip::UpdateSpaceShipPose()
	{
		m_Object->Rotate(GetControllerInput() * Core::Time::GetDeltaTime());
		m_Object->Translate(m_Object->GetForward() * Core::Time::GetDeltaTime() * 250);
	}

	void SpaceShip::UpdateCameraPose()
	{
		glm::vec3 rot = m_Object->GetRotation();
		rot.y += 180;
		rot.x = -rot.x;

		m_Camera->SetRotation(rot);
		m_Camera->SetPosition(m_Object->GetPosition() + m_Object->GetForward() * 800 + m_Object->GetUp() * 10);
	}

}