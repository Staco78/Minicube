#include "Drawable.h"

namespace mc {
	void Drawable::init(unsigned int vertex_buffer_id, std::string textureName) {
		m_textureName = textureName;

		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);


		m_model = glm::translate(m_model, glm::vec3(0.0, 0.0, 0.0));
	}

	void Drawable::draw(Shader shader) {
		shader.use();
		shader.setMat4("model", m_model);
		glBindTexture(GL_TEXTURE0, Textures::loadTexture(m_textureName));
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}