#pragma once

#include <Glfw/glfw3.h>
#include <Glm/glm.hpp>
#include <Glm/gtc/matrix_transform.hpp>
#include <Glm/gtc/type_ptr.hpp>

#include <iostream>

namespace mc {
	class Window {
	public:
		~Window();

		void init();
		void release();
		bool isOpen() { return !glfwWindowShouldClose(m_window); }
		GLFWwindow* getWindow() { return m_window; }
		glm::vec2 getWindowSize();

	private:
		GLFWwindow* m_window = nullptr;
	};
}