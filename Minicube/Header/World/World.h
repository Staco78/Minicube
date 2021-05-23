#pragma once

#include <map>
#include <string>
#include <vector>
#include <cmath>

#include <Glm/glm.hpp>

#include "ChunkMap.h"
#include "Chunk.h"
#include "Utils.h"
#include "Camera.h"
#include "Generation/Generation.h"

namespace mc {
	class World {
	public:
		void init(Camera* camera);

		template<class T>
		void setBlock(glm::ivec3 pos) {
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

			chunk->setBlock<Dirt>(glm::vec3(_x, pos.y, _z));
		}


		void update();
		std::vector<Chunk*> getVisibleChunks();
		Generation::Generator* getGenerator() { return &m_generator; }
	private:
		ChunkMap m_chunks;
		Camera* m_camera = nullptr;
		Generation::Generator m_generator;
	};
}