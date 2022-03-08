#pragma once

#include "glm/glm.hpp"
#include <array>
#include <vector>

namespace Core
{
	struct Quad;

	class Object
	{
	public:
		Object(const std::vector<Quad>& quads);
		Object(const Quad& quads);

		void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateModelMatrix(); }
		void Translate(const glm::vec3& direction) { m_Position += direction; RecalculateModelMatrix(); }
		void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation; RecalculateModelMatrix(); }
		void Rotate(const glm::vec3& rotation) { m_Rotation += rotation; RecalculateModelMatrix(); }
		void SetScale(const glm::vec3& scale) { m_Scale = scale; RecalculateModelMatrix(); }

		const glm::vec3 GetRight() const { return -glm::normalize(glm::vec3((float)m_ModelMatrix[0][0], (float)m_ModelMatrix[0][1], (float)m_ModelMatrix[0][2])); }
		const glm::vec3 GetUp() const { return -glm::normalize(glm::vec3((float)m_ModelMatrix[1][0], (float)m_ModelMatrix[1][1], (float)m_ModelMatrix[1][2])); }
		const glm::vec3 GetForward() const { return -glm::normalize(glm::vec3((float)m_ModelMatrix[2][0], (float)m_ModelMatrix[2][1], (float)m_ModelMatrix[2][2])); }
		const glm::vec3& GetPosition() const { return m_Position; }
		const glm::vec3& GetRotation() const { return m_Rotation; }

		const std::vector<Quad>& GetQuads() { return m_Quads; }

		void Draw();

	private:
		void RecalculateModelMatrix();

	private:
		glm::vec3 m_Position = { 0, 0, 0 };
		glm::vec3 m_Rotation = { 0, 0, 0 };
		glm::vec3 m_Scale = { 1, 1, 1 };

		glm::mat4 m_ModelMatrix = glm::mat4(1.0f);

		std::vector<Quad> m_Quads;


		// Hard Coded DirectionalLight
		glm::vec3 dirLight = { -0.3f, -0.7f, 0.5f };
		float ambientStrength = 0.5;
	};

	struct Quad
	{
	public:
		Quad(const std::array<glm::vec3, 4>& positions, const glm::vec4& color)
		{
			m_Vertices = positions;
			m_Color = color;
		}

		const std::array<glm::vec3, 4>& GetVertices() { return m_Vertices; }
		const glm::vec4& GetColor() { return m_Color; }

	private:
		std::array<glm::vec3, 4> m_Vertices;
		glm::vec4 m_Color;
	};
}