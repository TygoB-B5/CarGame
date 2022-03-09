#include "SpaceShip.h"

namespace Game
{
	void SpaceShip::Update()
	{
		UpdateSpaceShipPose();
		UpdateCameraPose();
	}

	const glm::vec3& SpaceShip::GetControllerInput()
	{
		// Calculate controller input with deadzone
		auto& cont = m_Controller;
		glm::vec3 rotation =
			glm::length(glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0)) > 5 ?
			glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0) : glm::vec3(0, 0, 0);

		return rotation;
	}

	void SpaceShip::UpdateSpaceShipPose()
	{
		// Get rotation from spaceship
		glm::vec3 rot = m_Object->GetRotation();

		// Corrent Angles
		if (m_Object->GetRotation().x > 180 || m_Object->GetRotation().x < -180)
			rot.x = -rot.x;
		if (m_Object->GetRotation().y > 180 || m_Object->GetRotation().y < -180)
			rot.y = -rot.y;
		if (m_Object->GetRotation().z > 180 || m_Object->GetRotation().z < -180)
			rot.z = -rot.z;

		m_Object->SetRotation(rot);

		// Correct controller input when upside down
		glm::vec3 input = GetControllerInput();
		if (m_Object->GetRotation().x > 90 || m_Object->GetRotation().x < -90)
			input.y = -input.y;

		// Rotate spaceship
		m_Object->Rotate(input * Core::Time::GetDeltaTime());

		// Move spaceship forward
		m_Object->Translate(m_Object->GetForward() * Core::Time::GetDeltaTime() * 150);
	}

	void SpaceShip::UpdateCameraPose()
	{
		// Correct reverse rotation
		glm::vec3 rot = m_Object->GetRotation();
		rot.y += 180;
		rot.x = -rot.x;
		rot.z = -rot.z;

		// Set camera rotation and position
		m_Camera->SetRotation(rot);
		m_Camera->SetPosition(m_Object->GetPosition() + m_Object->GetForward() * 800 + m_Object->GetUp() * 10);
	}

}