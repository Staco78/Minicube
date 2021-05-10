#pragma once
#include "Drawable.h"

#include <Glm/glm.hpp>

#include "Buffers.h"

namespace mc {

	class Block : public Drawable {
	public:
		void init(int x, int y, int z) { init(glm::ivec3(x, y, z)); }
		void init(glm::ivec3 pos);
	private:
		glm::uvec2 m_pos;
	};

}