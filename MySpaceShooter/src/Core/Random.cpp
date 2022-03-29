#include "Random.h"
#include <cstdlib>
#include <ctime>

namespace Core
{
	Random* Random::s_Random = new Random();

	Random::Random()
	{
		// Set random seed to system time
		m_Seed = std::time(nullptr);
		srand(m_Seed);
	}

	int Random::RangeImpl(int min, int max)
	{
		// Create Random Int
		int range = (max + 1) - min;
		int val = std::rand() % range + min;
		return val;
	}

	float Random::RangeImpl(float min, float max)
	{
		// Create Random Float
		float rand = std::rand() / (float)RAND_MAX;
		float range = max - min;
		float val = (rand * range) + min;
		return val;
	}
}