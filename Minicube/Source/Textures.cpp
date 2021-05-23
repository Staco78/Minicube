#include "Textures.h"

namespace mc {
	namespace Textures {

		namespace {

			class textureMap : public std::map<std::string, unsigned int> {
			public:
				void add(const std::string& name) {
					int x = size();
					operator[](name) = x;

					std::cout << name << " ==> " << x << std::endl;

				}
			};

			unsigned int arrayID;
			textureMap texturesName;


			void addTexture(const std::string& name, int count) {
				int width, height, nrChannels;
				unsigned char* data = stbi_load(std::string("assets/textures/" + name).c_str(), &width, &height, &nrChannels, 0);
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

			unsigned int loadTextureArray(const textureMap& textures, int width, int height) {
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

				for (auto it = textures.begin(); it != textures.end(); it++) {
					addTexture(it->first, it->second);
				}

				glGenerateMipmap(GL_TEXTURE_2D_ARRAY);

				return ID;
			}

		}

		void init() {
			
			texturesName.add("dirt.png");
			texturesName.add("stone.png");
			texturesName.add("grass.png");
			arrayID = loadTextureArray(texturesName, 16, 16);
		}

		unsigned int getArrayId() {
			return arrayID;
		}

		unsigned int getTextureNumber(const std::string& name) {
			return texturesName.at(name + ".png");
		}

	}
}