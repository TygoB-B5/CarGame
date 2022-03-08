#include "OscServer.h"

namespace Input
{
    OscServer* OscServer::s_OscServer = new OscServer();

    void OscServer::InitImpl()
    {
        m_Osc.setup(PORT);
    }

    void OscServer::UpdateImpl()
	{
        while (m_Osc.hasWaitingMessages())
        {
            ofxOscMessage m;
            m_Osc.getNextMessage(m);

            for (auto& controller : m_Controllers)
                controller->RecieveOscMessage(m);
        }
	}

    void OscServer::AddControllerImpl(OscController* controller)
    {
        m_Controllers.push_back(controller);
    }
}