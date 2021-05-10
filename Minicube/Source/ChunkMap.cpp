#include "ChunkMap.h"

namespace mc {
	Chunk* ChunkMap::get(glm::ivec2 key) {
		try
		{
			//std::cout << key.x << "    " << key.y << std::endl;
			return &at(key);
		}
		catch (const std::exception&)
		{
			//std::cout << "salut		" << key.x << ":" << key.y << std::endl;
			operator[](key).init(key.x, key.y);
			return &at(key);
		}
	}
}