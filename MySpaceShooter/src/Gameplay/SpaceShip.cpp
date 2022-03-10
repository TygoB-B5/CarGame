#include "SpaceShip.h"

namespace Game
{
	void SpaceShip::Update()
	{
		UpdateSpaceShipPosition();
		UpdateSpaceShipRotation();
		UpdateCameraPose();
		UpdateSpaceshipGun();
	}

	glm::vec3 SpaceShip::GetControllerIRotationnput()
	{
		// Calculate controller input with deadzone
		auto& cont = m_Controller;
		glm::vec3 rotation =
			glm::length(glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0)) > DEADZONE ?
			glm::vec3(cont->GetOrientation().z, -cont->GetOrientation().x, 0) : glm::vec3(0, 0, 0);

		return rotation;
	}

	bool SpaceShip::GetControllerButtonInput()
	{
		std::cout << m_Controller->IsProximity() << "\n";
		return m_Controller->IsProximity();
	}

	void SpaceShip::UpdateSpaceShipRotation()
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
		glm::vec3 input = GetControllerIRotationnput();
		if (m_Object->GetRotation().x > 90 || m_Object->GetRotation().x < -90)
			input.y = -input.y;

		// Rotate spaceship
		m_Object->Rotate(input * Core::Time::GetDeltaTime());
	}

	void SpaceShip::UpdateSpaceShipPosition()
	{
		// Move spaceship forward
		m_Object->Translate(m_Object->GetForward() * Core::Time::GetDeltaTime() * SPACESHIP_SPEED);

		// Move spaceship back if it goes out of bounds
		glm::vec3 pos = m_Object->GetPosition();
		if (m_Object->GetPosition().x > PLAYFIELD_SIZE || m_Object->GetPosition().x < -PLAYFIELD_SIZE)
			pos.x = -pos.x;
		if (m_Object->GetPosition().y > PLAYFIELD_SIZE || m_Object->GetPosition().y < -PLAYFIELD_SIZE)
			pos.y = -pos.y;
		if (m_Object->GetPosition().z > PLAYFIELD_SIZE || m_Object->GetPosition().z < -PLAYFIELD_SIZE)
			pos.z = -pos.z;

		m_Object->SetPosition(pos);
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

	void SpaceShip::UpdateSpaceshipGun()
	{
		// If button is held shoot at BULLET SHOOT SPEED rate
		if (GetControllerButtonInput() && m_ShootTime > BULLET_SHOOT_SPEED)
		{
			m_ShootTime = 0;
			m_BulletPool.SpawnBullet(m_Object->GetPosition(), m_Object->GetRotation());
		}

		m_ShootTime += Core::Time::GetDeltaTime();

		m_BulletPool.Update();
	}

}