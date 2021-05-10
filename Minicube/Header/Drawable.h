#pragma once 

#include "Utils.h"
#include "Shader.h"
#include "Textures.h"

#include <Glm/glm.hpp>
#include <Glm/gtc/matrix_transform.hpp>
#include <Glm/gtc/type_ptr.hpp>

namespace mc {
	class Drawable {
	public:
		void init(unsigned int vertex_buffer_id, std::string textureName, glm::vec3 pos);
		void draw(Shader* shader);
		void draw(Shader shader);
	private:
		unsigned int m_VAO;
		glm::mat4 m_model = glm::mat4(1.0f);
		std::string m_textureName;
	};
}