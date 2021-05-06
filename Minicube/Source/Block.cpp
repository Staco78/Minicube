#include "Block.h"

namespace mc {
	void Block::init() {
		Drawable::init(Buffers::get(utils::Buffer::cube), "texture");
	}
}