#pragma once

#include "../Block.h"

namespace mc {

	class Grass : public Block {
	public:
		void init(const glm::uvec3& pos);
	};

}