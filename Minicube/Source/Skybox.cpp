#include "Skybox.h"

namespace mc {
	void Skybox::init(Camera* camera) {
		m_camera = camera;

		m_shader.load("Shaders/skybox.vert", "Shaders/skybox.frag");

		unsigned int VBO;
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices::skyboxVertices), &vertices::skyboxVertices[0], GL_DYNAMIC_DRAW);


		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);


		std::vector<std::string> texturesName = {
			"assets/textures/skybox_right.jpg",
			"assets/textures/skybox_left.jpg",
			"assets/textures/skybox_top.jpg",
			"assets/textures/skybox_bottom.jpg",
			"assets/textures/skybox_front.jpg",
			"assets/textures/skybox_back.jpg",
		};

		m_texture = utils::loadCubemap(texturesName);

	}

	void Skybox::setProjection(glm::mat4 projection) {
		m_projection = projection;
	}

	void Skybox::draw() {
		glDepthFunc(GL_LEQUAL);
		m_shader.use();
		m_shader.setMat4("view", glm::mat4(glm::mat3(m_camera->getMatrix())));
		m_shader.setMat4("projection", m_projection);

		glBindVertexArray(m_VAO);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_texture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glDepthFunc(GL_LESS);
	}
}