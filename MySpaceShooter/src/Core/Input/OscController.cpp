#include "OscController.h"

namespace Input
{
    OscController::OscController(int playerIndex)
        : m_PlayerIndex(playerIndex)
    {
        OscServer::AddController(this);
        m_PlayerIndexChar = std::to_string(m_PlayerIndex);
    }

    void OscController::RecieveOscMessage(const ofxOscMessage& message)
    {
        std::string adres = message.getAddress();

        // Processing Acceleration
        if (adres == ACC_MSG_NAME_X + m_PlayerIndexChar)
            m_Acceleration.x = message.getArgAsFloat(0) - m_OldAcceleration.x;

        if (adres == ACC_MSG_NAME_Y + m_PlayerIndexChar)
            m_Acceleration.y = message.getArgAsFloat(0) - m_OldAcceleration.y;

        if (adres == ACC_MSG_NAME_Z + m_PlayerIndexChar)
            m_Acceleration.z = message.getArgAsFloat(0) - m_OldAcceleration.z;

        m_OldAcceleration = m_Acceleration;



        // Processing Orientation
        if (adres == (ORI_MSG_NAME_X + m_PlayerIndexChar))
            m_Orientation.x = message.getArgAsFloat(0);

        if (adres == (ORI_MSG_NAME_Y + m_PlayerIndexChar))
            m_Orientation.y = message.getArgAsFloat(0);

        if (adres == (ORI_MSG_NAME_Z + m_PlayerIndexChar))
            m_Orientation.z = message.getArgAsFloat(0);


        //Processing Proximity
        if (adres == PROX_MSG_NAME + m_PlayerIndexChar)
            m_IsProximity = message.getArgAsFloat(0) < 1;
    }
}