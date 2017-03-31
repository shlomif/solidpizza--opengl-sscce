#ifndef WINDOWOBJECT
#define WINDOWOBJECT

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <common/shader.hpp>

#include "ColoredCube.hpp"

using namespace glm;

class WindowObject
{
public:
	void display();
	void add_colored_cube(ColoredCube cube);

	WindowObject(std::string _title);
	~WindowObject() {};

private:
	GLFWwindow* _window;
	std::vector<ColoredCube> cubes;
};

#endif
