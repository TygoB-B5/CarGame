#pragma once

namespace Core
{
	struct ViewportParams
	{
		ViewportParams(int x = 0, int y = 0, int width = 100, int height = 100)
			: X(x), Y(y), Width(width), Height(height)
		{}

		int X, Y, Width, Height;
	};
}