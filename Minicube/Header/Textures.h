#pragma once

#include <Glew/glew.h>
#include <map>
#include <string>
#include <iostream>

#include "Utils.h"

namespace mc {
	namespace Textures {
		void init();
		unsigned int getArrayId();
		unsigned int getTextureNumber(const std::string& name);
	}
}