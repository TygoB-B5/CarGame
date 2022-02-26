#pragma once

#include "ofMain.h"

namespace Input
{
	class Controller
	{
	public:
		virtual void Setup() {}
		virtual void Poll() {}
		virtual void ResetAcceleration() {}
		virtual void KeyPressedEvent(char key) {}
		virtual void KeyReleasedEvent(char key) {}
		virtual void MouseMovedEvent(int x, int y) {}

		virtual ofVec3f GetAcceleration() const = 0;
		virtual ofVec3f GetOrientation() const = 0;
		virtual bool IsProximity() = 0;

	};
}