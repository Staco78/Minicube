#include "Game.h"

namespace mc {
	void Game::init(Renderer* renderer) {
		m_renderer = renderer;
		m_renderer->init(&m_camera);
		Buffers::init();
		Textures::init();
		m_renderer->postInit();
		m_camera.init(m_renderer->getWindow());
	}

	void Game::start() {
		while (m_renderer->getWindow()->isOpen()) {
			m_camera.update();
			m_renderer->render();
			glfwPollEvents();
		}
	}

	void Game::release() {
		m_renderer = nullptr;
	}

	Game::~Game() {
		release();
	}
}