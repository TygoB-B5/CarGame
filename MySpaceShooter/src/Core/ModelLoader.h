#pragma once

#include <string>
#include <vector>
#include "Object.h"

namespace Core
{
	class ModelLoader
	{
	public:
		static std::vector<Quad> Load(const std::string& filePath);
	};
}