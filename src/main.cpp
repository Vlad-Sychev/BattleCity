#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int g_windowSize_X = 640;
int g_windowSize_Y = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height) 
{
	g_windowSize_X = width;
	g_windowSize_Y = height;
	glViewport(0, 0, g_windowSize_X, g_windowSize_Y); // 0,0 - нижний левый угол
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scanmode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && GLFW_PRESS)
	{
		glfwSetWindowShouldClose(pWindow, GL_TRUE);
	}
}
int main(void)
{
	 
	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "glfwInit fail" << std::endl;
		return -1;
	}
	// опции контекста OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* pWindow = glfwCreateWindow(g_windowSize_X, g_windowSize_Y, "Battle city", nullptr, nullptr);
	if (!pWindow)
	{
		glfwTerminate();
		std::cout << "glfwCreateWindow fail" << std::endl;
		return -1;
	}

	glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
	glfwSetKeyCallback(pWindow, glfwKeyCallback);

	/* Make the window's context current */
	glfwMakeContextCurrent(pWindow); // делаем контекст OpenGL текущим

	if (!gladLoadGL())
	{
		std::cout << "Can't load GLAD" << std::endl;
		return -1;
	}
	std::cout << "Renderer:  " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL version" << glGetString(GL_VERSION) << std::endl;
	glClearColor(0, 1, 0, 1);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(pWindow))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT); // очищается буфер цвета

		/* Swap front and back buffers */
		glfwSwapBuffers(pWindow);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}