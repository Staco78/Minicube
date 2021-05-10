#pragma once

#include <Glew/glew.h>

#include "Utils.h"

namespace mc {

	namespace Buffers {
		 void init();
		 unsigned int get(mc::utils::Buffer buffer);
		
	};
}