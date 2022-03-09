#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ViewportParams.h"

namespace Core
{
	class Camera
	{
	public:
		Camera(float fov, float aspectRatio, float near, float far, ViewportParams viewport);

		void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; CalculateViewProjectionMatrix(); }
		void SetPosition(const glm::vec3& position) { m_Position = position; CalculateViewProjectionMatrix(); }
		const glm::vec3& GetPosition() const { return m_Position; }
		const glm::vec3& GetRotation() const { return m_Rotation; }
		const ViewportParams& GetViewport() const { return m_Viewport; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

	private:
		void CalculateViewProjectionMatrix();
		
	private:
		float m_Fov = 90;
		float m_AspectRatio = 16.0f / 9.0f;
		float m_Near = 0.1f;
		float m_Far = 1000.0f;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
		glm::vec3 m_Position = {0, 0, 0};
		glm::vec3 m_Rotation = { 0, 0, 0 };
		ViewportParams m_Viewport;
	};
}