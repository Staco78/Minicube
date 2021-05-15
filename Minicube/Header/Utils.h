#pragma once

#include <Glew/glew.h>

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <Glm/glm.hpp>

#include "stb_image.h"

namespace std
{
	template<> struct less<glm::ivec2>
	{
		bool operator() (const glm::ivec2& left, const glm::ivec2& right) const {
			if (left.x == right.x)
				return left.y < right.y;
			else
				return left.x < right.x;
		}
	};
}


namespace mc {
	namespace vertices {
		namespace cube {
			static std::vector<float> back = {
				// Back face
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
				 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right         
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
			};
			static std::vector<float> front = {
				// Front face
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
				 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
				 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
				-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
			};
			static std::vector<float> left = {
				// Left face
				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
				-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
			};
			static std::vector<float> right = {
				// Right face
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
				 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right         
				 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
				 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left     
			};
			static std::vector<float> bottom = {
				// Bottom face
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
				 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
				 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
			};
			static std::vector<float> top = {
				// Top face
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
				 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right     
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
				-0.5f,  0.5f,  0.5f,  0.0f, 0.0f  // bottom-left        
			};
		}
	}
	namespace utils {	
		enum class Buffer
		{
			cube
		};

		enum class Side {
			back,
			front,
			left,
			right,
			bottom,
			top
		};

		static unsigned int loadTexture(std::string path) {
			unsigned int texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			// d�finit les options de la texture actuellement li�e
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			// charge et g�n�re la texture
			int width, height, nrChannels;
			unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
				stbi_image_free(data);
				return texture;
			}
			else
			{
				std::cout << "Failed to load texture" << std::endl;
				stbi_image_free(data);
				return 0;
			}
		}
	}

	static double frameTime;
	static double lastFrame;

}