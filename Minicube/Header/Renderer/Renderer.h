#pragma once

#include <Glew/glew.h>
#include <string>

#include "Window.h"
#include "Camera.h"
#include "World/World.h"

#include "Block.h"

namespace mc {
	class Renderer {
	public:
		~Renderer();

		void init(Camera* camera, World* world);
		void release();
		void render();
		Window* getWindow() { return &m_window; }
	private:
		Window m_window;
		Shader shader;
		Camera* m_camera = nullptr;
		World* m_world = nullptr;
		glm::mat4 projection = glm::mat4(1.0f);

	};
}