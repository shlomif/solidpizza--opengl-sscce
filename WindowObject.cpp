#include "ColoredCube.hpp"
#include "WindowObject.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <common/shader.hpp>
using namespace glm;

WindowObject::WindowObject(std::string _title)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		exit(1);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	_window = glfwCreateWindow(1024, 768, _title.c_str(), NULL, NULL);
	if (_window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		exit(1);
	}
}

void WindowObject::display(void)
{
	glfwMakeContextCurrent(_window);
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		exit(1);
	}
	glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	do
	{
		for (std::vector<ColoredCube>::iterator iter = cubes.begin(); iter != cubes.end(); ++iter)
		{
			(*iter).animation_step();
		}
		glfwSwapBuffers(_window);
		glfwPollEvents();

	} while (glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(_window) == 0);
	glfwTerminate();
}

void WindowObject::add_colored_cube(ColoredCube cube)
{
	cubes.push_back(cube);
}
