#pragma once

#include "Renderer/Renderer.h"
#include "Buffers.h"
#include "Camera.h"
#include "Textures.h"

namespace mc {
	class Game {
	public:
		~Game();

		void init(Renderer* renderer);
		void start();
		void release();
	private:
		Renderer* m_renderer;
		Camera m_camera;
	};
}