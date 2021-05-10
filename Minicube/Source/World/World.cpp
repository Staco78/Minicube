#include "World/World.h"

namespace mc {
	void World::init(Camera* camera) {
		m_camera = camera;
	}

	void World::setBlock(glm::ivec3 pos) {
		Chunk* chunk = m_chunks.get(floor(pos.x / 16.0), floor(pos.z / 16.0));
		chunk->setBlock(pos.x % 16, pos.y, pos.z % 16);
	}

	std::vector<Chunk*> World::getVisibleChunks() {
		int renderDistance = 4;
		std::vector<Chunk*> chunks;
		Chunk* playerChunk = m_chunks.get(floor(m_camera->getPosition().x / 16.0), floor(m_camera->getPosition().z / 16.0));
		for (int x = playerChunk->getPos().x - renderDistance; x <= playerChunk->getPos().x + renderDistance; x++)
			for (int y = playerChunk->getPos().y - renderDistance; y <= playerChunk->getPos().y + renderDistance; y++)
				chunks.push_back(m_chunks.get(x, y));
		return chunks;
	}

}