#pragma once

#include "../Block.h"

namespace mc {
	class Stone : public Block {
	public:
		//void init(int x, int y, int z) { init(glm::uvec3(x, y, z)); }
		void init(const glm::uvec3& pos);
	private:

	};
}