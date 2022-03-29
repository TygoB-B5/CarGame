#include "Bullet.h"

namespace Game
{
	// BULLETPOOL
	void BulletPool::SpawnBullet(const glm::vec3& position, const glm::vec3& rotation)
	{
		// Create bullet prefab
		auto bulletPrefab = std::make_shared<Core::Object>(Core::ModelLoader::Load("../Assets/bullet.txt"));
		bulletPrefab->SetPosition(position);
		bulletPrefab->SetRotation(rotation);
		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
		bullet->SetObject(bulletPrefab);

		// Add bullet to Instanced Bullet vector
		m_Bullets.push_back({ bullet, 0 });
	}

	void BulletPool::Update()
	{
		if (m_Bullets.size() == 0)
			return;

		// Update Bullet state
		for (int i = 0; i < m_Bullets.size(); i++)
		{
			m_Bullets[i].first->Update();
			m_Bullets[i].second += Core::Time::GetDeltaTime();
		}

		// Destroy Bullet if it existed longer than BULLET_LIFETIME
		if (m_Bullets[0].second > BULLET_LIFETIME)
			m_Bullets.erase(m_Bullets.begin());
	}

	std::vector<std::shared_ptr<Core::Object>> BulletPool::GetObjects()
	{
		// Create array and return it (Not efficient but it will do for now)
		std::vector<std::shared_ptr<Core::Object>> arr;
		for (auto& b : m_Bullets)
		{
			arr.push_back(b.first->GetObject());
		}
		return arr;
	}

	// BULLET
	void Bullet::Update()
	{
		// Move bullet forwards
		auto& f = m_Object->GetForward();
		m_Object->Translate(f * BULLET_SPEED * Core::Time::GetDeltaTime());
	}
}