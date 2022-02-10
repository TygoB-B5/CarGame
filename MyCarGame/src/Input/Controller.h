#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

namespace Input
{
	class Controller
	{
	public:
		virtual void Setup() {}
		virtual void Poll() {}
		virtual void KeyPressedEvent(int key) {}
		virtual void KeyReleasedEvent(int key) {}
		virtual void MouseMovedEvent(int x, int y) {}

		virtual ofVec3f GetAcceleration() const = 0;
		virtual ofVec3f GetOrientation() const = 0;
		virtual bool IsProximity() = 0;
	};
}