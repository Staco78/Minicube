#pragma once

#include <Glm/glm.hpp>

#include "World/Chunk.h"

namespace mc {

	class ChunkMap : public std::map<glm::ivec2, Chunk> {
	public:
		Chunk* get(glm::ivec2 key);
		Chunk* get(int x, int y) { return get(glm::ivec2(x, y)); }
	};
}