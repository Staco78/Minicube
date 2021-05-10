#include "Game.h"

namespace mc {
	void Game::init(Renderer* renderer) {
		m_renderer = renderer;
		m_renderer->init(m_player.getCamera(), &m_world);
		Buffers::init();
		Textures::init();
		m_player.init(m_renderer->getWindow());
		m_world.init(m_player.getCamera());
		
		for (int i = 0; i < 100; i++)
			for (int y = 0; y < 100; y++)
				m_world.setBlock(i, 0, y);
	}

	void Game::start() {
		while (m_renderer->getWindow()->isOpen()) {
			m_player.update();
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