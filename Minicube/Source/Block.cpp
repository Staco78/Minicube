#include "Block.h"

namespace mc {
	void Block::init(glm::ivec3 pos) {
		Drawable::init(Buffers::get(utils::Buffer::cube), "texture", pos);
		m_pos = pos;
	}
}