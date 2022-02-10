#include "OscController.h"

namespace Input
{
    void OscController::Setup()
    {
        m_Osc.setup(PORT);
    }

    void OscController::Poll()
    {
        while (m_Osc.hasWaitingMessages())
        {
            ofxOscMessage m;
            m_Osc.getNextMessage(&m);
            ProcessMessage(m);
        }
    }

    void OscController::ProcessMessage(const ofxOscMessage& message)
    {
        std::string adres = message.getAddress();

        // Processing Acceleration
        if (adres == ACC_MSG_NAME_X)
            m_Acceleration.x = message.getArgAsFloat(0) - m_OldAcceleration.x;

        if (adres == ACC_MSG_NAME_Y)
            m_Acceleration.y = message.getArgAsFloat(0) - m_OldAcceleration.y;

        if (adres == ACC_MSG_NAME_Z)
            m_Acceleration.z = message.getArgAsFloat(0) - m_OldAcceleration.z;

        m_OldAcceleration = m_Acceleration;



        // Processing Orientation
        if (adres == ORI_MSG_NAME_X)
            m_Orientation.x = message.getArgAsFloat(0);

        if (adres == ORI_MSG_NAME_Y)
            m_Orientation.y = message.getArgAsFloat(0);

        if (adres == ORI_MSG_NAME_Z)
            m_Orientation.z = message.getArgAsFloat(0);


        //Processing Proximity
        if (adres == PROX_MSG_NAME)
            m_IsProximity = message.getArgAsFloat(0) < 1;
    }
}