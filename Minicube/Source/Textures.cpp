#include "Textures.h"

namespace mc {
	namespace Textures {
		namespace {
			std::map<std::string, unsigned int> textures;
		}

		void init() {
			textures["texture"] = utils::loadTexture("dirt.png");
		}

		unsigned int loadTexture(const std::string& name) {
			return textures.at(name);
		}
	}
}