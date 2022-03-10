#pragma once

#include <string>
#include <vector>
#include "Object.h"

// MODEL LAYOUT
/////////////////////////
// Vertex 1: x1, y1, z1//
// Vertex 2: x2, y2, z2//
// Vertex 3: x3, y3, z3//
// Vertex 4: x4, y4, z4//
// Color   : r, g, b, a//
/////////////////////////

namespace Core
{
	class ModelLoader
	{
	public:
		static std::vector<Quad> Load(const std::string& filePath);
	};
}