#include "Block.h"

namespace mc {
	void Block::init(glm::uvec3 pos) {
		m_pos = pos;
		m_faces.init();
	}
}