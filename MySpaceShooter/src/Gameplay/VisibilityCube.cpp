#include "VisibilityCube.h"

namespace Game
{
	void VisibilityCube::SetSize(float size)
	{
		if (size < 0)
			size = 0;

		m_Object->SetScale({ size, size, size });
	}

}