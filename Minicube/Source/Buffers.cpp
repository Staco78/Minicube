#include "Buffers.h"

namespace mc {
	
	namespace Buffers {

		namespace {
			unsigned int cube_VBO;
		}

		void init() {

			//cube
			glGenBuffers(1, &cube_VBO);
			
			glBindBuffer(GL_ARRAY_BUFFER, cube_VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex::cube), vertex::cube, GL_DYNAMIC_DRAW);
		}

		unsigned int get(utils::Buffer buffer) {
			switch (buffer)
			{
			case utils::Buffer::cube:
				return cube_VBO;
			default:
				return -1;
			}
		}
	}

};