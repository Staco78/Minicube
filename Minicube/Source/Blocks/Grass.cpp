#include "Blocks/Grass.h"

namespace mc {
	void Grass::init(const glm::uvec3& pos) {
		setName("grass");
		Block::init(pos);
	}
}