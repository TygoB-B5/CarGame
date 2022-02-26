#pragma once
#include "Object.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Renderer/Renderer.h"

namespace Core
{
	Object::Object(const std::vector<Quad>& quads)
	{
		for (auto& quad : quads)
			m_Quads.push_back(quad);

		RecalculateModelMatrix();
	}

	Object::Object(const Quad& quad)
	{
		m_Quads.push_back(quad);

		RecalculateModelMatrix();
	}

	void Object::Update()
	{
		for (auto& quad : m_Quads)
		{
			auto& quadVertices = quad.GetVertices();

			glm::vec4 p1 = m_ModelMatrix * glm::vec4{ quadVertices[0].x, quadVertices[0].y, quadVertices[0].z, -1 };
			glm::vec4 p2 = m_ModelMatrix * glm::vec4{ quadVertices[1].x, quadVertices[1].y, quadVertices[1].z, -1 };
			glm::vec4 p3 = m_ModelMatrix * glm::vec4{ quadVertices[2].x, quadVertices[2].y, quadVertices[2].z, -1 };
			glm::vec4 p4 = m_ModelMatrix * glm::vec4{ quadVertices[3].x, quadVertices[3].y, quadVertices[3].z, -1 };
			Core::Renderer::DrawQuadFromPoints(p1, p2, p3, p4, quad.GetColor());
		}
	}

	void Object::RecalculateModelMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position);
		glm::mat4 rotatex = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.x), glm::vec3(1, 0, 0));
		glm::mat4 rotatey = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.y), glm::vec3(0, 1, 0));
		glm::mat4 rotatez = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.z), glm::vec3(0, 0, 1));
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), m_Scale);

		m_ModelMatrix = glm::inverse(transform * rotatey * rotatex * rotatez* scale);
	}

	// QUAD CLASS

	Quad::Quad(const std::array<glm::vec3, 4>& positions, const glm::vec4& color)
	{
		m_Vertices = positions;
		m_Color = color;
	}
}