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

		virtual glm::vec3 GetAcceleration() const = 0;
		virtual glm::vec3 GetOrientation() const = 0;
		virtual bool IsProximity() = 0;

	};
}