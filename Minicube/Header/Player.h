#pragma once

#include "Camera.h"

namespace mc {
	class Player {
	public:
		void init(Window* window);
		void update();
		Camera* getCamera() { return &m_camera; }

	private:
		Camera m_camera;
		Window* m_window = nullptr;
	};
}