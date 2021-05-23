#pragma once

#include <Glm/glm.hpp>

#include "Generation/Generation.h"
#include "World/Chunk.h"



namespace mc {

	class ChunkMap : public std::map<glm::ivec2, Chunk> {
	public:
		void init(Generation::Generator* generator) { mp_generator = generator; }
		Chunk* get(glm::ivec2 key);
		Chunk* get(int x, int y) { return get(glm::ivec2(x, y)); }

	private:
		Generation::Generator* mp_generator = nullptr;
	};
}