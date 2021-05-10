#include "World/Chunk.h"

namespace mc {
	void Chunk::init(int x, int y) {
		m_pos = glm::ivec2(x, y);
	}

	void Chunk::setBlock(glm::uvec3 pos) {
		if (pos.x > 15 || pos.y > 15)
			assert(true);
		blocks.erase(pos);
		blocks[pos].init(getGlobalBlockPos(pos));
	}

	void Chunk::draw(Shader* shader) {
		for (auto & [pos, block] : blocks)
		{
			block.draw(shader);
		}
	}

	glm::ivec3 Chunk::getGlobalBlockPos(glm::ivec3 localPos) {
		return glm::ivec3(m_pos.x * 16, 0, m_pos.y * 16) + localPos;
	}
}