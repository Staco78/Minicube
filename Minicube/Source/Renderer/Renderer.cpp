#include "Renderer/Renderer.h"


namespace mc {
	void Renderer::init(Camera* camera) {
		if (!glfwInit()) {
			std::cout << "Failed to initialize glfw" << std::endl;
			return;
		}

		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		m_window.init();

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			glfwTerminate();
			std::cout << "Failed to initialize glew" << std::endl;
			return;
		}

		std::cout << "Renderer initialized successfuly" << std::endl;

		glfwSwapInterval(1);
		glfwSetInputMode(m_window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetInputMode(m_window.getWindow(), GLFW_STICKY_KEYS, GL_TRUE);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);


		shader.load("Shaders/shader.vert", "Shaders/shader.frag");

		m_camera = camera;
		projection = glm::perspective(glm::radians(45.0f), m_window.getWindowSize().x / m_window.getWindowSize().y, 0.1f, 100.0f);

	}

	void Renderer::release() {
		glfwTerminate();

		std::cout << "Renderer released" << std::endl;
	}

	void Renderer::render() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();
		shader.setMat4("projection", projection);
		shader.setMat4("view", m_camera->getMatrix());

		block.draw(shader);
		glfwSwapBuffers(m_window.getWindow());
	}

	Renderer::~Renderer() {
		release();

	}
}