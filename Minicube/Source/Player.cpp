#include "Player.h"

namespace mc {
	void Player::init(Window* window) {
		m_window = window;
		m_camera.init(window);
	}


	void Player::update() {
		m_camera.update();
	}

}