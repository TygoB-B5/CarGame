#pragma once

#include "ofMain.h"
#include "Controller.h"

//  KeyCodes for Arrow Keys
#define LEFT_ARROW 12
#define UP_ARROW 13
#define RIGHT_ARROW 14
#define DOWN_ARROW 15

// Orientation //
#define ORI_X_PLUS_BTN 0
#define ORI_X_MIN_BTN 0

#define ORI_Y_PLUS_BTN RIGHT_ARROW
#define ORI_Y_MIN_BTN LEFT_ARROW


#define ORI_Z_PLUS_BTN 0
#define ORI_Z_MIN_BTN 0

#define ORI_SPEED 10

// Acceleration //
#define ACC_X_PLUS_BTN 0
#define ACC_X_MIN_BTN 0

#define ACC_Y_PLUS_BTN 0
#define ACC_Y_MIN_BTN 0

#define ACC_Z_PLUS_BTN 0
#define ACC_Z_MIN_BTN 0

#define ACC_SPEED 0;

// Proximity //
#define PROX_BTN 'p'

///////////////////////////////////////////////////////////
// TODO Maybe use a GUI as debug controller in the future//
///////////////////////////////////////////////////////////

namespace Input
{
	class DebugController : public Controller
	{
	public:
		virtual void Setup() override;
		virtual void Poll() override;

		virtual void ResetAcceleration() override;

		virtual void KeyPressedEvent(char key) override;
		virtual void KeyReleasedEvent(char key) override;
		virtual void MouseMovedEvent(int x, int y) override;

		// Vectors //
		virtual ofVec3f GetAcceleration() const override { return m_Acceleration; }
		virtual ofVec3f GetOrientation() const override { return m_Orientation; }

		// Buttons //
		virtual bool IsProximity() override { return IsKeyPressed(PROX_BTN); }

	private:
		bool IsKeyPressed(int key);
		void CalculateAccelerationDifference();

	private:
		bool m_IsProximity = false;

		ofVec3f m_Orientation;

		ofVec3f m_Acceleration;
		ofVec3f m_OldAcceleration, m_NewAcceleration;

		std::vector<char> m_PressedKeys;
	};
}