#include "Textures.h"

namespace mc {
	namespace Textures {

		namespace {

			unsigned int arrayID;

			void addTexture(const std::string& name, int count) {
				int width, height, nrChannels;
				unsigned char* data = stbi_load(name.c_str(), &width, &height, &nrChannels, 0);
				if (data)
				{
					glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0,
						0, 0, count,
						width, height, 1,
						GL_RGBA, GL_UNSIGNED_BYTE, data);
					stbi_image_free(data);
				}
				else
				{
					std::cout << "Failed to load texture" << std::endl;
					stbi_image_free(data);
					return;
				}
			}

			unsigned int loadTextureArray(const std::vector<std::string>& textures, int width, int height) {
				unsigned int ID;

				glGenTextures(1, &ID);
				glBindTexture(GL_TEXTURE_2D_ARRAY, ID);

				glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				
				glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8,
					width, height, textures.size(), 0,
					GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

				for (int i = 0; i < textures.size(); i++) {
					addTexture(textures[i], i);
				}

				glGenerateMipmap(GL_TEXTURE_2D_ARRAY);

				return ID;
			}
		}

		void init() {
			std::vector<std::string> textures;
			textures.push_back("dirt.png");
			textures.push_back("furnace_front.png");
			arrayID = loadTextureArray(textures, 16, 16);
		}

		unsigned int getArrayId() {
			return arrayID;
		}

	}
}