#pragma once

#include "Glew/glew.h"
#include <Glm/glm.hpp>

#include <map>

#include "Block.h"
#include "Shader.h"

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

	class BlockMap : public std::map<glm::uvec3, Block> {
	public:
		Block* get(glm::ivec3 pos) {

			if (pos.x < 0 || pos.y < 0 || pos.z < 0 || pos.x > 15 || pos.z > 15)
				return nullptr;

			try
			{
				return &at(pos);
			}
			catch (const std::exception&)
			{
				return nullptr;
			}
		}

		Block* get(int x, int y, int z) { return get(glm::ivec3(x, y, z)); }
	};

	class DynamicVBO {
	public:
		void init();
		void addData(std::vector<float>* data);
		void sendData();
		int getSize() { 
			return m_data.size();
		}
		unsigned int getTrianglesCount() { return (getSize() / 5); }
		unsigned int getID();
	private:
		unsigned int ID;
		std::vector<float> m_data;
	};

	class Chunk {
	public:
		void init(glm::ivec2 pos);
		void init(int x, int y) { init(glm::vec2(x, y)); }
		void setBlock(glm::uvec3 pos);
		void setBlock(unsigned int x, unsigned int y, unsigned int z) { setBlock(glm::uvec3(x, y, z)); }
		void draw(Shader* shader);
		void update();
		glm::vec2 getPos() { return m_pos; }
	private:
		DynamicVBO m_VBO;
		unsigned int m_VAO;
		glm::ivec2 m_pos;
		BlockMap m_blocks;
		glm::ivec3 getGlobalBlockPos(glm::ivec3 localPos);
		glm::mat4 m_model = glm::mat4(1.0f);

		void createDynamicVBO();

	};
}