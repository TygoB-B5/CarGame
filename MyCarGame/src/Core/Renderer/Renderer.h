#pragma once
#include "glm/glm.hpp"
#include <array>
#include "Camera.h"

namespace Core
{
	class Renderer
	{
	public:
		static void Begin(const Camera& camera) { s_Renderer->BeginImpl(camera); }
		static void End() { s_Renderer->EndImpl(); }
		static void Clear(const glm::vec4 color) { s_Renderer->ClearImpl(color); }
		static void DrawQuadFromPoints(const std::array<glm::vec3, 4> points, const glm::vec4 color) { s_Renderer->DrawQuadFromPointsImpl(points, color); }
		static void DrawQuadFromPoints(const glm::vec3& point1, const glm::vec3& point2, const glm::vec3& point3, const glm::vec3& point4, const glm::vec4 color) { s_Renderer->DrawQuadFromPointsImpl(point1, point2, point3, point4, color); }

	private:
		void BeginImpl(const Camera& camera);
		void EndImpl();
		void ClearImpl(const glm::vec4& color);
		void DrawQuadFromPointsImpl(const std::array<glm::vec3, 4> points, const glm::vec4& color);
		void DrawQuadFromPointsImpl(const glm::vec3& point1, const glm::vec3& point2, const glm::vec3& point3, const glm::vec3& point4, const glm::vec4& color);

	private:
		glm::mat4 m_ViewProjectionMatrix;
		static Renderer* s_Renderer;
	};
}