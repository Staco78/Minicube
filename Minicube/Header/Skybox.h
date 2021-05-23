#pragma once

#include <Glm/glm.hpp>

#include "Shader.h"
#include "Utils.h"
#include "Camera.h"

namespace mc {
	class Skybox {
	public:
		void init(Camera* camera);
		void draw();
		void setProjection(glm::mat4 projection);
	private:
		Shader m_shader;
		Camera* m_camera = nullptr;
		glm::mat4 m_projection;
		unsigned int m_VAO;
		unsigned int m_texture;
	};
}