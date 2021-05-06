#pragma once

#include <Glew/glew.h>
#include <string>

#include "Window.h"
#include "Buffers.h"
#include "Camera.h"

#include "Block.h"

namespace mc {
	class Renderer {
	public:
		~Renderer();

		void init(Camera* camera);
		void release();
		void render();
		void postInit() { block.init(); }
		Window* getWindow() { return &m_window; }
	private:
		Window m_window;
		Block block;
		Shader shader;
		Camera* m_camera;
		glm::mat4 projection = glm::mat4(1.0f);

	};
}