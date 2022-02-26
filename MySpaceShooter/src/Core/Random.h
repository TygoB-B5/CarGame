#pragma once

namespace Core
{
	class Random
	{
	public:
		static int Range(int min, int max) { return s_Random->RangeImpl(min, max); }
		static float Range(float min, float max) { return s_Random->RangeImpl(min, max); }

	private:
		Random();

		int RangeImpl(int min, int max);
		float RangeImpl(float min, float max);

	private:
		static Random* s_Random;
		unsigned int m_Seed = 0;
	};
}