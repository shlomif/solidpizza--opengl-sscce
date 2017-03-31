#include "ColoredCube.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <common/shader.hpp>

ColoredCube::ColoredCube(GLfloat *g_vertex_buffer_data, int vertices_size, GLfloat *g_color_buffer_data, int colors_size)
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	programID = LoadShaders("TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader");
	MatrixID = glGetUniformLocation(programID, "MVP");

	Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	View = glm::lookAt(glm::vec3(4, 3, -3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	Model = glm::mat4(1.0f);
	MVP = Projection * View * Model;

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices_size, g_vertex_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, colors_size, g_color_buffer_data, GL_STATIC_DRAW);
}

ColoredCube::~ColoredCube()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorbuffer);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void ColoredCube::animation_step()
{
	static float incr = 0.01f, x = 0.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(programID);
	if (x >= 8 || x <= -4)
	{
		incr = -incr;
	}
	x += incr;
	Model = glm::rotate(Model, glm::degrees(0.00005f), glm::vec3(0, 1, 0));
	View = glm::translate(View, glm::vec3(0, 0, incr));
	MVP = Projection * View * Model;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
	glDrawArrays(GL_TRIANGLES, 2, 3);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}