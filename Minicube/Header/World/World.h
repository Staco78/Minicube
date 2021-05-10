#pragma once

#include <map>
#include <string>
#include <vector>
#include <cmath>

#include <Glm/glm.hpp>

#include "Chunk.h"
#include "Utils.h"
#include "ChunkMap.h"
#include "Camera.h"

namespace mc {
	class World {
	public:
		void init(Camera* camera);
		void setBlock(glm::ivec3 pos);
		void setBlock(int x, int y, int z) { setBlock(glm::ivec3(x, y, z)); }
		std::vector<Chunk*> getVisibleChunks();
	private:
		ChunkMap m_chunks;
		Camera* m_camera = nullptr;
	};
}