#include "World/World.h"

namespace mc {
	void World::init(Camera* camera) {
		m_camera = camera;
		m_generator.init();
		m_chunks.init(&m_generator);
	}


	void World::update() {
		for (auto iterator = m_chunks.begin(); iterator != m_chunks.end(); iterator++) {
			iterator->second.update();
		}
	}

	std::vector<Chunk*> World::getVisibleChunks() {

		int renderDistance = 1;
		std::vector<Chunk*> chunks;

		Chunk* playerChunk = m_chunks.get(floor(m_camera->getPosition().x / 16.0), floor(m_camera->getPosition().z / 16.0));
		for (int x = playerChunk->getPos().x - renderDistance; x <= playerChunk->getPos().x + renderDistance; x++)
			for (int y = playerChunk->getPos().y - renderDistance; y <= playerChunk->getPos().y + renderDistance; y++)
				chunks.push_back(m_chunks.get(x, y));
		return chunks;
	}

}