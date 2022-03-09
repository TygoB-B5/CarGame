#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "OscServer.h"
#include "Controller.h"

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
		friend class OscServer;

		OscController(int playerIndex);

		virtual glm::vec3 GetAcceleration() const override { return m_Acceleration; };
		virtual glm::vec3 GetOrientation() const override { return m_Orientation; }
		virtual bool IsProximity() override { return m_IsProximity; }

	private:
		void RecieveOscMessage(const ofxOscMessage& message);

	private:
		glm::vec3 m_Orientation;

		glm::vec3 m_Acceleration;
		glm::vec3 m_OldAcceleration;

		bool m_IsProximity = false;
		int m_PlayerIndex;
		std::string m_PlayerIndexChar;
	};
}