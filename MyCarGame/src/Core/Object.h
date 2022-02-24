#pragma once

#include "glm/glm.hpp"
#include <array>
#include <vector>

namespace Core
{
	class Quad
	{
	public:
		Quad(const std::array<glm::vec3, 4>& positions, const glm::vec4& color);
		const std::array<glm::vec3, 4>& GetVertices() { return m_Vertices; }
		const glm::vec4& GetColor() { return m_Color; }

	private:
		std::array<glm::vec3, 4> m_Vertices;
		glm::vec4 m_Color;
	};

	class Object
	{
	public:
		Object(const std::vector<Quad>& quads);
		Object(const Quad& quads);

		void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateModelMatrix(); }
		void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; RecalculateModelMatrix(); }
		void SetScale(const glm::vec3& scale) { m_Scale = scale; RecalculateModelMatrix(); }

		const std::vector<Quad>& GetQuads() { return m_Quads; }

		void Update();

	private:
		void RecalculateModelMatrix();

	private:
		glm::vec3 m_Position = { 0, 0, 0 };
		glm::vec3 m_Rotation = { 0, 0, 0 };
		glm::vec3 m_Scale = { 1, 1, 1 };

		glm::mat4 m_ModelMatrix = glm::mat4(1.0f);

		std::vector<Quad> m_Quads;
	};
}