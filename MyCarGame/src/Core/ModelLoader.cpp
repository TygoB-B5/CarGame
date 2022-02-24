#include "ModelLoader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "glm/glm.hpp"

namespace Core
{
	std::vector<Quad> Core::ModelLoader::Load(const std::string& filePath)
	{
		// Open file.
		std::fstream file;
		file.open(filePath.c_str());

		// Check if file is succesfully opened.
		if (!file.is_open())
			std::cout << "File not found - " << filePath;

		// Write words to string vector.
		std::string word;
		std::vector<std::string> words;
		while (file >> word)
			words.push_back(word);
		
		file.close();

		// Create quads and convert string to float.
		std::vector<Quad> quads;
		for (size_t i = 0; i < words.size(); i += 16)
		{
			glm::vec3 vert1 =
			{
				std::stof(words[i]),
				std::stof(words[i + 1]),
				std::stof(words[i + 2]),
			};

			glm::vec3 vert2 =
			{
				std::stof(words[i + 3]),
				std::stof(words[i + 4]),
				std::stof(words[i + 5]),
			};

			glm::vec3 vert3 =
			{
				std::stof(words[i + 6]),
				std::stof(words[i + 7]),
				std::stof(words[i + 8]),
			};
			
			glm::vec3 vert4 = 
			{
				std::stof(words[i + 9]),
				std::stof(words[i + 10]),
				std::stof(words[i + 11]),
			};

			glm::vec4 color =
			{
				std::stof(words[i + 12]),
				std::stof(words[i + 13]),
				std::stof(words[i + 14]),
				std::stof(words[i + 15]),
			};

			quads.push_back(Quad({vert1, vert2, vert3, vert4}, color));
		}

		return quads;
	}
}