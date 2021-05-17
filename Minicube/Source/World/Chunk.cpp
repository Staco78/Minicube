#include "World/Chunk.h"

namespace mc {
	void Chunk::init(glm::ivec2 pos) {
		m_pos = pos;
		m_VBO.init();

		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO.getID());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 1, GL_INT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));
		glEnableVertexAttribArray(2);

		m_model = glm::translate(m_model, glm::vec3(pos.x * 16, 0, pos.y * 16));

	}

	void Chunk::setBlock(glm::uvec3 pos) {
		if (pos.x > 15 || pos.z > 15)
			assert(false);
		m_blocks.erase(pos);
		m_blocks[pos].init(pos);
	}

	void Chunk::update() {
		createDynamicVBO();

		glBindVertexArray(m_VAO);
		m_VBO.sendData();

		int size;
		glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);

		
	}

	void Chunk::draw(Shader* shader) {

		shader->use();
		shader->setMat4("model", m_model);
		glBindVertexArray(m_VAO);
		glBindTexture(GL_TEXTURE_2D_ARRAY, Textures::getArrayId());
		glDrawArrays(GL_TRIANGLES, 0, m_VBO.getTrianglesCount());

	}

	glm::ivec3 Chunk::getGlobalBlockPos(glm::ivec3 localPos) {
		return glm::ivec3(m_pos.x * 16, 0, m_pos.y * 16) + localPos;
	}

	void Chunk::createDynamicVBO() {
		
		for (auto& [pos, block] : m_blocks)
		{

			/*m_VBO.addData(&block.getFaces()->get(utils::Side::front)->getChunkVertices(pos));
			m_VBO.addData(&block.getFaces()->get(utils::Side::back)->getChunkVertices(pos));
			m_VBO.addData(&block.getFaces()->get(utils::Side::bottom)->getChunkVertices(pos));
			m_VBO.addData(&block.getFaces()->get(utils::Side::top)->getChunkVertices(pos));
			m_VBO.addData(&block.getFaces()->get(utils::Side::left)->getChunkVertices(pos));
			m_VBO.addData(&block.getFaces()->get(utils::Side::right)->getChunkVertices(pos));*/

			if (m_blocks.get(pos.x + 1, pos.y, pos.z) == nullptr)
				m_VBO.addData(block.getFaces()->get(utils::Side::left)->getChunkVertices(pos, 1));
			if (m_blocks.get(pos.x - 1, pos.y, pos.z) == nullptr)
				m_VBO.addData(block.getFaces()->get(utils::Side::right)->getChunkVertices(pos, 1));
			if (m_blocks.get(pos.x, pos.y + 1, pos.z) == nullptr)
				m_VBO.addData(block.getFaces()->get(utils::Side::top)->getChunkVertices(pos, 1));
			if (m_blocks.get(pos.x, pos.y - 1, pos.z) == nullptr)
				m_VBO.addData(block.getFaces()->get(utils::Side::bottom)->getChunkVertices(pos, 1));
			if (m_blocks.get(pos.x, pos.y, pos.z + 1) == nullptr)
				m_VBO.addData(block.getFaces()->get(utils::Side::back)->getChunkVertices(pos, 1));
			if (m_blocks.get(pos.x, pos.y, pos.z - 1) == nullptr)
				m_VBO.addData(block.getFaces()->get(utils::Side::front)->getChunkVertices(pos, 1));
			


		}

	}



	//dynamicVBO

	void DynamicVBO::init() {
		glGenBuffers(1, &ID);
	}

	void DynamicVBO::addData(std::vector<float>* data) {
		m_data.insert(m_data.end(), data->begin(), data->end());
		delete data;
	}
	
	void DynamicVBO::sendData() {
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(float), m_data.data(), GL_DYNAMIC_DRAW);

	}

	unsigned int DynamicVBO::getID() {
		return ID;
	}
}