#pragma once

#include <string>
#include <iostream>

#include "stb_image.h"

namespace mc {
	namespace vertex {
		static float cube[] = {
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};
	}
	namespace utils {	
		enum class Buffer
		{
			cube
		};

		static unsigned int loadTexture(std::string path) {
			unsigned int texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			// définit les options de la texture actuellement liée
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			// charge et génère la texture
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

}