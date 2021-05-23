#include "Block.h"

namespace mc {
	void Block::init(const glm::uvec3& pos) {
		m_pos = pos;
		m_faces.init(m_name);
	}
}