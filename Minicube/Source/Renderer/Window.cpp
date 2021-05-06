#include "Renderer/Window.h"

namespace mc {

	void callbackFrameBufferSize(GLFWwindow* window, int x, int y) {
		glViewport(0, 0, x, y);
	}

	void Window::init() {
		m_window = glfwCreateWindow(720, 480, "Coucou", nullptr, nullptr);

		if (!m_window) {
			glfwTerminate();
			std::cout << "Failed to initialize the window" << std::endl;
			return;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, callbackFrameBufferSize);
		glViewport(0, 0, getWindowSize().x, getWindowSize().y);

		std::cout << "Window initialized successfuly" << std::endl;
	}

	void Window::release() {
		glfwTerminate();
		m_window = nullptr;
		std::cout << "Window released" << std::endl;
	}

	glm::vec2 Window::getWindowSize() {
		int x, y;
		glfwGetWindowSize(m_window, &x, &y);
		return glm::vec2(x, y);
	}

	Window::~Window() {
		release();
	}
}