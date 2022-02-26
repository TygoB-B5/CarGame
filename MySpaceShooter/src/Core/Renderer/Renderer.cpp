#include "Renderer.h"
#include "ofGLRenderer.h"
#include "GLFW/glfw3.h"
#include "glm/gtc/matrix_transform.hpp";

namespace Core
{
	Renderer* Renderer::s_Renderer = new Renderer();

	void Renderer::InitImpl()
	{
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		m_ViewPortCenter = { ofGetWidth() * 0.5f, ofGetHeight() * 0.5, 0, 0};
	}

	void Renderer::BeginImpl(const Camera& camera)
	{
		m_ViewProjectionMatrix = camera.GetViewProjectionMatrix();
		glBegin(GL_QUADS);
	}

	void Renderer::EndImpl()
	{
		glEnd();
	}

	void Renderer::ClearImpl(const glm::vec4& color)
	{
		glClearColor(color.r / 255., color.g / 255., color.b / 255., color.a / 255.);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::DrawQuadFromPointsImpl(const std::array<glm::vec3, 4> points, const glm::vec4& color)
	{
		DrawQuadFromPointsImpl(points[0], points[1], points[2], points[3], color);
	}

	void Renderer::DrawQuadFromPointsImpl(const glm::vec3& point1, const glm::vec3& point2, const glm::vec3& point3, const glm::vec3& point4, const glm::vec4& color)
	{
		glm::vec4 p1 = m_ViewPortCenter - m_ViewProjectionMatrix * glm::vec4(point1.x, point1.y, point1.z, -1);
		glm::vec4 p2 = m_ViewPortCenter - m_ViewProjectionMatrix * glm::vec4(point2.x, point2.y, point2.z, -1);
		glm::vec4 p3 = m_ViewPortCenter - m_ViewProjectionMatrix * glm::vec4(point3.x, point3.y, point3.z, -1);
		glm::vec4 p4 = m_ViewPortCenter - m_ViewProjectionMatrix * glm::vec4(point4.x, point4.y, point4.z, -1);

		glColor4f(color.r / 225., color.g / 225., color.b / 225., color.a / 225.);
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glVertex3f(p3.x, p3.y, p3.z);
		glVertex3f(p4.x, p4.y, p4.z);
	}
}