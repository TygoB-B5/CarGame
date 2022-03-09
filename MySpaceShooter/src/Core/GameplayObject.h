#pragma once
#include "Core/Core.h"

namespace Core
{
	class GameplayObject
	{
		virtual void SetObject(const std::shared_ptr<Core::Object>& object) = 0;
		virtual const std::shared_ptr<Core::Object>& GetObject() const = 0;
	};
}