#pragma once

#include "ofMain.h"

namespace Core
{
	class Time
	{
	public:
		Time() : m_TimeStep(1), m_DeltaTime(0), m_OldTime(0), m_ElapsedTime(0), m_Frames(0), m_ElapsedRealTime(0), m_FrameTime(0) {}

		// Returns time in between frames in seconds.
		static float GetDeltaTime() { return s_Time->GetDeltaTimeImpl(); }

		// Returns total elapsed time.
		static float GetElapsedTime() { return s_Time->GetElapsedTimeImpl(); }

		// Returns total elapsed time in realtime.
		static float GetElapsedRealTime() { return s_Time->GetElapsedRealTimeImpl(); }

		// Returns framerate.
		static float GetFps() { return s_Time->GetFpsImpl(); }

		// Returns time in between frames in milliseconds.
		static float GetFrameTime() { return s_Time->GetFrameTimeImpl(); }

		static void Tick() { s_Time->TickImpl(); }

		// Sets the timestep at which your application will run.
		static void SetTimeStep(float timeStep) { s_Time->SetTimeStepImpl(timeStep); }

	private:
		float GetDeltaTimeImpl() const { return m_DeltaTime; }
		float GetElapsedTimeImpl() const { return m_ElapsedTime; }
		float GetElapsedRealTimeImpl() const { return m_ElapsedRealTime; }
		float GetFpsImpl() const { return 1.0f / m_DeltaTime; }
		float GetFrameTimeImpl() const { return m_FrameTime; }

		void TickImpl();

		void SetTimeStepImpl(float timeStep);

	private:
		static Time* s_Time;

		float m_DeltaTime;
		float m_ElapsedTime;
		float m_ElapsedRealTime;
		float m_TimeStep;
		float m_OldTime;
		float m_FrameTime;
		uint32_t m_Frames;
	};
}