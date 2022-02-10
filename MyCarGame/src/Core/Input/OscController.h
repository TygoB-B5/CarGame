#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Controller.h"

#define PORT 80

#define ACC_MSG_NAME_X "/acc/x"
#define ACC_MSG_NAME_Y "/acc/y"
#define ACC_MSG_NAME_Z "/acc/z"
#define ORI_MSG_NAME_X "/ori/x"
#define ORI_MSG_NAME_Y "/ori/y"
#define ORI_MSG_NAME_Z "/ori/z"
#define PROX_MSG_NAME "/prox"

namespace Input
{
	class OscController : public Controller
	{
	public:
		virtual void Setup() override;
		virtual void Poll() override;
		virtual ofVec3f GetAcceleration() const override { return m_Acceleration; };
		virtual ofVec3f GetOrientation() const override { return m_Orientation; }
		virtual bool IsProximity() override { return m_IsProximity; }

	private:
		void ProcessMessage(const ofxOscMessage& message);

	private:
		ofxOscReceiver m_Osc;

		ofVec3f m_Orientation;

		ofVec3f m_Acceleration;
		ofVec3f m_OldAcceleration;

		bool m_IsProximity = false;
	};
}