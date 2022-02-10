#include "Time.h"

namespace Time
{
	TimeData* TimeData::s_Time = new TimeData();

	void TimeData::TickImpl()
	{
		float currentTime = ofGetElapsedTimef();
		float newTime = currentTime;
		float frameTime = newTime - m_OldTime;

		m_FrameTime = frameTime * 1000;
		m_DeltaTime = frameTime * m_TimeStep;
		m_ElapsedTime = currentTime * m_TimeStep;
		m_ElapsedRealTime = currentTime;
		m_OldTime = newTime;
	}

	void TimeData::SetTimeStepImpl(float timeStep)
	{
		m_TimeStep = timeStep;
	}
}
