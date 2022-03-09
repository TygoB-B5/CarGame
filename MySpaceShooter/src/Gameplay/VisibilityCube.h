#pragma once

#include "Core/Core.h"

namespace Game
{
	class VisibilityCube : public Core::GameplayObject
	{
	public:
		void SetSize(float size);

		virtual void SetObject(const std::shared_ptr<Core::Object>& object) override { m_Object = object; }
		virtual const std::shared_ptr<Core::Object>& GetObject() const override { return m_Object; }

	private:
		std::shared_ptr<Core::Object> m_Object;
	};
}
