#pragma once

#include "Controller.h"

namespace Input
{
	class PcController : public Controller
	{
	public:
		virtual void Setup() override;
		virtual void Poll() override;

		virtual void KeyPressedEvent(int key) override;
		virtual void KeyReleasedEvent(int key) override;
		virtual void MouseMovedEvent(int x, int y) override;

		virtual ofVec3f GetAcceleration() const override { return m_Acceleration; }
		virtual ofVec3f GetOrientation() const override { return m_Orientation; }
		virtual bool IsProximity() override { return IsKeyPressed(34); }

	private:
		bool IsKeyPressed(int key);

	private:
		ofxOscReceiver m_Osc;

		bool m_IsProximity = false;

		ofVec3f m_Orientation;

		ofVec3f m_Acceleration;
		ofVec3f m_OldAcceleration;

		std::vector<int> m_PressedKeys;
	};
}