#include "ChunkMap.h"

namespace mc {
	Chunk* ChunkMap::get(glm::ivec2 key) {

		auto it = find(key);

		if (it == end()) {
			operator[](key).init(key);
			return &at(key);
		}

		return &it->second;
	}
}