#include "PcController.h"


// TODO Maybe use a GUI for the pc controller
namespace Input
{
	void Input::PcController::Setup()
	{

	}

	void Input::PcController::Poll()
	{

	}

	void PcController::KeyPressedEvent(int key)
	{
		if (std::find(m_PressedKeys.begin(), m_PressedKeys.end(), key) == m_PressedKeys.end())
		{
			m_PressedKeys.push_back(key);
		}
	}

	void PcController::KeyReleasedEvent(int key)
	{
		m_PressedKeys.erase(std::remove(m_PressedKeys.begin(), m_PressedKeys.end(), key), m_PressedKeys.end());
	}

	void PcController::MouseMovedEvent(int x, int y)
	{
	}

	bool PcController::IsKeyPressed(int key)
	{
		return std::find(m_PressedKeys.begin(), m_PressedKeys.end(), key) != m_PressedKeys.end();
	}
}