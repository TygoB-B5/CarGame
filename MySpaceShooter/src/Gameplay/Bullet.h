#pragma once
#include "Core/Core.h"

#define BULLET_SPEED 1000
#define BULLET_LIFETIME 4

namespace Game
{
	class Bullet;

	class BulletPool
	{
	public:
		void SpawnBullet(const glm::vec3& position, const glm::vec3& rotation);
		void Update();
		std::vector<std::shared_ptr<Core::Object>> GetObjects();

	private:
		std::vector<std::pair<std::shared_ptr<Bullet>, float>> m_Bullets;

	};

	class Bullet : public Core::GameplayObject
	{
	public:
		Bullet(int ownerID = 0)
			: m_OwnerID(ownerID)
		{}

		friend class BulletPool;

		virtual void SetObject(const std::shared_ptr<Core::Object>& object) override { m_Object = object; }
		virtual const std::shared_ptr<Core::Object>& GetObject() override { return m_Object; }

	private:
		void Update();

	private:
		std::shared_ptr<Core::Object> m_Object;
		int m_OwnerID;
	};
}