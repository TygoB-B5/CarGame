#include "Time.h"

namespace Core
{
	Time* Time::s_Time = new Time();

	void Time::TickImpl()
	{	
		// Update Tick values
		float currentTime = ofGetElapsedTimef();
		float newTime = currentTime;
		float frameTime = newTime - m_OldTime;

		m_FrameTime = frameTime * 1000;
		m_DeltaTime = frameTime * m_TimeStep;
		m_ElapsedTime = currentTime * m_TimeStep;
		m_ElapsedRealTime = currentTime;
		m_OldTime = newTime;
	}

	void Time::SetTimeStepImpl(float timeStep)
	{
		m_TimeStep = timeStep;
	}
}
