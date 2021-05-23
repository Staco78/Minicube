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

		glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));
		glEnableVertexAttribArray(2);

		m_model = glm::translate(m_model, glm::vec3(pos.x * 16, 0, pos.y * 16));

	}

	void Chunk::update() {
		createDynamicVBO();

		glBindVertexArray(m_VAO);
		m_VBO.sendData();
		
	}

	void Chunk::draw(Shader* shader) {

		shader->use();
		shader->setMat4("model", m_model);
		glBindVertexArray(m_VAO);
		glBindTexture(GL_TEXTURE_2D_ARRAY, Textures::getArrayId());
		glDrawArrays(GL_TRIANGLES, 0, m_VBO.getTrianglesCount());

	}

	void Chunk::createDynamicVBO() {
		
		for (auto& [pos, block] : m_blocks)
		{
			if (m_blocks.get(pos.x + 1, pos.y, pos.z) == nullptr)
				m_VBO.addData(block->getFaces()->get(utils::Side::left)->getChunkVertices(pos));
			if (m_blocks.get(pos.x - 1, pos.y, pos.z) == nullptr)
				m_VBO.addData(block->getFaces()->get(utils::Side::right)->getChunkVertices(pos));
			if (m_blocks.get(pos.x, pos.y + 1, pos.z) == nullptr)
				m_VBO.addData(block->getFaces()->get(utils::Side::top)->getChunkVertices(pos));
			if (m_blocks.get(pos.x, pos.y - 1, pos.z) == nullptr)
				m_VBO.addData(block->getFaces()->get(utils::Side::bottom)->getChunkVertices(pos));
			if (m_blocks.get(pos.x, pos.y, pos.z + 1) == nullptr)
				m_VBO.addData(block->getFaces()->get(utils::Side::back)->getChunkVertices(pos));
			if (m_blocks.get(pos.x, pos.y, pos.z - 1) == nullptr)
				m_VBO.addData(block->getFaces()->get(utils::Side::front)->getChunkVertices(pos));
		}
	}

	void Chunk::generate(Generation::Generator* generator) {
	
		for (int x = 0; x < 16; x++)
			for (int z = 0; z < 16; z++) {
				int height = generator->perlinNoise((m_pos.x * 16 + x) * 0.01, (m_pos.y * 16 + z) * 0.01) * 60;
				setBlock<Grass>(glm::vec3(x, height--, z));
				setBlock<Dirt>(glm::vec3(x, height--, z));
				setBlock<Dirt>(glm::vec3(x, height--, z));

				for (; height >= 0; height--)
					setBlock<Stone>(glm::vec3(x, height, z));
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

		//m_data.erase(m_data.begin(), m_data.end());

	}

	unsigned int DynamicVBO::getID() {
		return ID;
	}
}