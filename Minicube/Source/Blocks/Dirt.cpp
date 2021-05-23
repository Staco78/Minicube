#include "Blocks/Dirt.h"

namespace mc {
	void Dirt::init(const glm::uvec3& pos) {
		setName("dirt");
		Block::init(pos);
	}
}