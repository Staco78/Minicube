#pragma once

#include "Glew/glew.h"
#include <Glm/glm.hpp>

#include <map>

#include "Block.h"

namespace std {
	template<> struct less<glm::uvec3>
	{
		bool operator() (const glm::uvec3& left, const glm::uvec3& right) const {
			if (left.y == right.y && left.x == right.x)
				return left.z < right.z;
			else if (left.x == right.x)
				return left.y < right.y;
			else
				return left.x < right.x;
		}

	};
}

namespace mc {
	class Chunk {
	public:
		void init(int x, int y);
		void setBlock(glm::uvec3 pos);
		void setBlock(int x, int y, int z) { setBlock(glm::uvec3(x, y, z)); }
		void draw(Shader* shader);
		glm::vec2 getPos() { return m_pos; }
	private:
		glm::ivec2 m_pos;
		std::map<glm::uvec3, Block> blocks;
		glm::ivec3 getGlobalBlockPos(glm::ivec3 localPos);
	};
}