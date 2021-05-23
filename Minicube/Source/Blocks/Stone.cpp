#include "Blocks/Stone.h"

namespace mc {
	void Stone::init(const glm::uvec3& pos) {
		setName("stone");
		Block::init(pos);
	}
}