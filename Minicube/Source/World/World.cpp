#include "World/World.h"

namespace mc {
	void World::init(Camera* camera) {
		m_camera = camera;
	}

	void World::setBlock(glm::ivec3 pos) {
		Chunk* chunk = m_chunks.get(floor(pos.x / 16.0), floor(pos.z / 16.0));

		int _x;
		int _z;

		if (pos.x % 16 == 0)
			_x = 0;
		else
			if (pos.x >= 0)
				_x = pos.x % 16;
			else
				_x = 16 + (pos.x % 16);

		if (pos.z % 16 == 0)
			_z = 0;
		else
			if (pos.z >= 0)
				_z = pos.z % 16;
			else
				_z = 16 + (pos.z % 16);

		chunk->setBlock(_x, pos.y, _z);


	}

	void World::update() {
		for (auto iterator = m_chunks.begin(); iterator != m_chunks.end(); iterator++) {
			iterator->second.update();
		}
	}

	std::vector<Chunk*> World::getVisibleChunks() {

		int renderDistance = 10;
		std::vector<Chunk*> chunks;

		Chunk* playerChunk = m_chunks.get(floor(m_camera->getPosition().x / 16.0), floor(m_camera->getPosition().z / 16.0));
		for (int x = playerChunk->getPos().x - renderDistance; x <= playerChunk->getPos().x + renderDistance; x++)
			for (int y = playerChunk->getPos().y - renderDistance; y <= playerChunk->getPos().y + renderDistance; y++)
				chunks.push_back(m_chunks.get(x, y));
		return chunks;
	}

}