#pragma once

#include <Glew/glew.h>
#include <map>
#include <string>

#include "Utils.h"

namespace mc {
	namespace Textures {
		void init();
		unsigned int loadTexture(const std::string& name);
	}
}