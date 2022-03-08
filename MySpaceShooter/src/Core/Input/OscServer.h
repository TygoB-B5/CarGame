#pragma once
#include "ofMain.h"
#include "ofxOsc.h"
#include "OscController.h"

#define PORT 80

namespace Input
{
	class OscController;

	class OscServer
	{
	public:
		static void Init() { s_OscServer->InitImpl(); }
		static void Update() { s_OscServer->UpdateImpl(); }
		static void AddController(OscController* controller) { s_OscServer->AddControllerImpl(controller); }

	private:
		void InitImpl();
		void UpdateImpl();
		void AddControllerImpl(OscController* controller);

	private:
		ofxOscReceiver m_Osc;
		std::vector<OscController*> m_Controllers;

	private:
		static OscServer* s_OscServer;
	};
}