#include "Camera.h"

namespace Core
{
	Camera::Camera(float fov, float aspectRatio, float near, float far, ViewportParams viewport)
		: m_Fov(fov), m_AspectRatio(aspectRatio), m_Near(near), m_Far(far), m_Viewport(viewport),
		m_ProjectionMatrix(glm::perspective(glm::radians(fov), aspectRatio, near, far))
	{
		CalculateViewProjectionMatrix();
	}

	void Camera::CalculateViewProjectionMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position);
		glm::mat4 rotatex = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.x), glm::vec3(1, 0, 0));
		glm::mat4 rotatey = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.y), glm::vec3(0, 1, 0));
		glm::mat4 rotatez = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.z), glm::vec3(0, 0, 1));
		m_ViewMatrix = glm::inverse(transform * rotatey * rotatex * rotatez);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}