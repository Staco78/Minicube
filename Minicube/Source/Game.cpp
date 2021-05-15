#include "Game.h"

namespace mc {
	void Game::init(Renderer* renderer) {
		m_renderer = renderer;
		m_renderer->init(m_player.getCamera(), &m_world);
		Textures::init();
		m_player.init(m_renderer->getWindow());
		m_world.init(m_player.getCamera());

		for (int x = 0; x < 100; x++)
			for (int z = 0; z < 100; z++)
				for (int y = 0; y < 20; y++)
					m_world.setBlock(x, y, z);



		m_world.update();


	}

	void Game::start() {

		int debugTimer = 20;

		bool lineModeEnable = false;

		while (m_renderer->getWindow()->isOpen()) {


			//timer

			double now = glfwGetTime();
			frameTime = now - lastFrame;
			lastFrame = now;

			std::cout << 1 / frameTime << std::endl;



			//debug

			glfwSetInputMode(m_renderer->getWindow()->getWindow(), GLFW_STICKY_KEYS, GL_FALSE);

			if (debugTimer == 0) {
				if (glfwGetKey(m_renderer->getWindow()->getWindow(), GLFW_KEY_F2) == GLFW_PRESS) {
					lineModeEnable = !lineModeEnable;
					debugTimer = 20;
				}
			}


			if (lineModeEnable)
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


			if (debugTimer > 0)
				debugTimer--;

			glfwSetInputMode(m_renderer->getWindow()->getWindow(), GLFW_STICKY_KEYS, GL_TRUE);


			//std::cout << m_player.getCamera()->getPosition().x << ":" << m_player.getCamera()->getPosition().y << ":" << m_player.getCamera()->getPosition().z << std::endl;



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