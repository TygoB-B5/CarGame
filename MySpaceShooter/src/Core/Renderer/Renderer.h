#pragma once
#include "glm/glm.hpp"
#include <array>
#include <memory>
#include "Camera.h"

namespace Core
{
	struct ViewportParams
	{
		ViewportParams(int x = 0, int y = 0, int width = 100, int height = 100)
			: X(x), Y(y), Width(width), Height(height)
		{}

		int X, Y, Width, Height;
	};

	class Renderer
	{
	public:
		static void Init() { s_Renderer->InitImpl(); }
		static void SetViewport(int x, int y, int width, int height) { s_Renderer->SetViewportImpl(x, y, width, height); }
		static void SetViewport(const ViewportParams& viewport);
		static void Begin(const std::shared_ptr<Camera>& camera) { s_Renderer->BeginImpl(camera); }
		static void End() { s_Renderer->EndImpl(); }
		static void Clear(const glm::vec4 color) { s_Renderer->ClearImpl(color); }
		static void DrawQuadFromPoints(const std::array<glm::vec3, 4> points, const glm::vec4 color) { s_Renderer->DrawQuadFromPointsImpl(points, color); }
		static void DrawQuadFromPoints(const glm::vec3& point1, const glm::vec3& point2, const glm::vec3& point3, const glm::vec3& point4, const glm::vec4 color) { s_Renderer->DrawQuadFromPointsImpl(point1, point2, point3, point4, color); }

	private:
		~Renderer() { delete s_Renderer; }

		void InitImpl();
		void SetViewportImpl(int x, int y, int width, int height);
		void BeginImpl(const std::shared_ptr<Camera>& camera);
		void EndImpl();
		void ClearImpl(const glm::vec4& color);
		void DrawQuadFromPointsImpl(const std::array<glm::vec3, 4> points, const glm::vec4& color);
		void DrawQuadFromPointsImpl(const glm::vec3& point1, const glm::vec3& point2, const glm::vec3& point3, const glm::vec3& point4, const glm::vec4& color);

	private:
		glm::mat4 m_ViewProjectionMatrix;
		glm::vec4 m_ViewPortCenter;

		static Renderer* s_Renderer;
	};
}